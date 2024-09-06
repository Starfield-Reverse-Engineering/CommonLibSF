-- Local Usage:
--
-- add_deps("commonlibsf")
-- add_rules("commonlibsf.plugin", {
--     name = "Plugin Name",
--     author = "Author Name",
--     description = "Plugin Description",
--     email = "user@site.com"
--     options = {
--         -- disable all compatibility checks completely
--         sig_scanning = true,
--         no_struct_use = true
--     }
-- })

local PLUGIN_FILE = [[
#include <SFSE/SFSE.h>
#include <REL/Relocation.h>

using namespace std::literals;

extern "C" __declspec(dllexport)
constinit auto SFSEPlugin_Version = []() noexcept {
    SFSE::PluginVersionData v{};
    v.PluginVersion({ ${PLUGIN_VERSION_MAJOR}, ${PLUGIN_VERSION_MINOR}, ${PLUGIN_VERSION_PATCH} });
    v.PluginName("${PLUGIN_NAME}");
    v.AuthorName("${PLUGIN_AUTHOR}");
    v.UsesSigScanning(${OPTION_SIG_SCANNING});
    v.UsesAddressLibrary(${OPTION_ADDRESS_LIBRARY});
    v.HasNoStructUse(${OPTION_NO_STRUCT_USE});
    v.IsLayoutDependent(${OPTION_LAYOUT_DEPENDENT});
    return v;
}();]]

local PLUGIN_VERSION_FILE = [[
#include <winres.h>

1 VERSIONINFO
FILEVERSION ${PLUGIN_VERSION_MAJOR}, ${PLUGIN_VERSION_MINOR}, ${PLUGIN_VERSION_PATCH}, 0
PRODUCTVERSION ${PROJECT_VERSION_MAJOR}, ${PROJECT_VERSION_MINOR}, ${PROJECT_VERSION_PATCH}, 0
FILEFLAGSMASK 0x17L
#ifdef _DEBUG
    FILEFLAGS 0x1L
#else
    FILEFLAGS 0x0L
#endif
FILEOS 0x4L
FILETYPE 0x1L
FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904b0"
        BEGIN
            VALUE "FileDescription", "${PLUGIN_DESCRIPTION}"
            VALUE "FileVersion", "${PLUGIN_VERSION}.0"
            VALUE "InternalName", "${PLUGIN_NAME}"
            VALUE "LegalCopyright", "${PLUGIN_AUTHOR} | ${PLUGIN_LICENSE}"
            VALUE "ProductName", "${PROJECT_NAME}"
            VALUE "ProductVersion", "${PROJECT_VERSION}.0"
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x409, 1200
    END
END]]

rule("commonlibsf.plugin")
    add_deps("win.sdk.resource")

    on_config(function(target)
        import("core.base.semver")
        import("core.project.depend")
        import("core.project.project")

        target:set("arch", "x64")
        target:set("kind", "shared")

        local conf = target:extraconf("rules", "commonlibsf.plugin")
        local conf_dir = path.join(target:autogendir(), "rules", "commonlibsf", "plugin")
        
        if conf.options then
            if conf.options.sig_scanning then
                conf.options.address_library = false
            else
                conf.options.sig_scanning = false
                if conf.options.address_library == nil then
                    conf.options.address_library = true
                end
            end
            if conf.options.no_struct_use then
                conf.options.layout_dependent = false
            else
                conf.options.no_struct_use = false
                if conf.options.layout_dependent == nil then
                    conf.options.layout_dependent = true
                end
            end
        else
            conf.options = {
                sig_scanning = false,
                address_library = true,
                no_struct_use = false,
                layout_dependent = true
            }
        end

        local conf_map = {
            PLUGIN_AUTHOR           = conf.author or "",
            PLUGIN_DESCRIPTION      = conf.description or "",
            PLUGIN_EMAIL            = conf.email or "",
            PLUGIN_LICENSE          = (target:license() or "Unknown") .. " License",
            PLUGIN_NAME             = conf.name or target:name(),
            PLUGIN_VERSION          = target:version() or "0.0.0",
            PLUGIN_VERSION_MAJOR    = semver.new(target:version() or "0.0.0"):major(),
            PLUGIN_VERSION_MINOR    = semver.new(target:version() or "0.0.0"):minor(),
            PLUGIN_VERSION_PATCH    = semver.new(target:version() or "0.0.0"):patch(),
            PROJECT_NAME            = project.name() or "",
            PROJECT_VERSION         = project.version() or "0.0.0",
            PROJECT_VERSION_MAJOR   = semver.new(project.version() or "0.0.0"):major(),
            PROJECT_VERSION_MINOR   = semver.new(project.version() or "0.0.0"):minor(),
            PROJECT_VERSION_PATCH   = semver.new(project.version() or "0.0.0"):patch(),
            OPTION_SIG_SCANNING     = conf.options.sig_scanning,
            OPTION_ADDRESS_LIBRARY  = conf.options.address_library,
            OPTION_NO_STRUCT_USE    = conf.options.no_struct_use,
            OPTION_LAYOUT_DEPENDENT = conf.options.layout_dependent
        }

        local conf_parse = function(a_str)
            return a_str:gsub("(%${([^\n]-)})", function(_, a_var)
                local result = conf_map[a_var:trim()]
                if type(result) ~= "string" then
                    result = tostring(result)
                end
                assert(result ~= nil, "cannot get variable(%s)", a_var)
                return result
            end)
        end

        local add_file = function(a_path, a_data)
            local file_path = path.join(conf_dir, a_path)
            depend.on_changed(function()
                local file = io.open(file_path, "w")
                if file then
                    file:write(conf_parse(a_data), "\n")
                    file:close()
                end
            end, { dependfile = target:dependfile(file_path), files = project.allfiles()})
            target:add("files", file_path)
        end

        add_file("plugin.cpp", PLUGIN_FILE)
        add_file("version.rc", PLUGIN_VERSION_FILE)
    end)
