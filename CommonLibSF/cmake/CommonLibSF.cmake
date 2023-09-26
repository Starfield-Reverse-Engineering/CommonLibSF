function(commonlibsf_parse_version VERSION)
    message("${version_match_count}")
    string(REGEX MATCHALL "^([0-9]+)(\\.([0-9]+)(\\.([0-9]+)(\\.([0-9]+))?)?)?$" version_match "${VERSION}")
    unset(COMMONLIBSF_VERSION_MAJOR PARENT_SCOPE)
    unset(COMMONLIBSF_VERSION_MINOR PARENT_SCOPE)
    unset(COMMONLIBSF_VERSION_PATCH PARENT_SCOPE)
    unset(COMMONLIBSF_VERSION_TWEAK PARENT_SCOPE)

    if("${version_match} " STREQUAL " ")
        set(COMMONLIBSF_VERSION_MATCH FALSE PARENT_SCOPE)
        return()
    endif()

    set(COMMONLIBSF_VERSION_MATCH TRUE PARENT_SCOPE)
    set(COMMONLIBSF_VERSION_MAJOR "${CMAKE_MATCH_1}" PARENT_SCOPE)
    set(COMMONLIBSF_VERSION_MINOR "0" PARENT_SCOPE)
    set(COMMONLIBSF_VERSION_PATCH "0" PARENT_SCOPE)
    set(COMMONLIBSF_VERSION_TWEAK "0" PARENT_SCOPE)

    if(DEFINED CMAKE_MATCH_3)
        set(COMMONLIBSF_VERSION_MINOR "${CMAKE_MATCH_3}" PARENT_SCOPE)
    endif()
    if(DEFINED CMAKE_MATCH_5)
        set(COMMONLIBSF_VERSION_PATCH "${CMAKE_MATCH_5}" PARENT_SCOPE)
    endif()
    if(DEFINED CMAKE_MATCH_7)
        set(COMMONLIBSF_VERSION_TWEAK "${CMAKE_MATCH_7}" PARENT_SCOPE)
    endif()
endfunction()

function(target_commonlibsf_properties TARGET)
    # EXCLUDE_FROM_ALL and SOURCES are supported here to simplify passing arguments from add_commonlibsf_plugin.
    set(options OPTIONAL USE_ADDRESS_LIBRARY USE_SIGNATURE_SCANNING STRUCT_DEPENDENT EXCLUDE_FROM_ALL)
    set(oneValueArgs NAME AUTHOR EMAIL VERSION MINIMUM_SFSE_VERSION)
    set(multiValueArgs COMPATIBLE_RUNTIMES SOURCES)

    cmake_parse_arguments(PARSE_ARGV 1 ADD_COMMONLIBSF_PLUGIN "${options}" "${oneValueArgs}"
            "${multiValueArgs}")

    set(commonlibsf_plugin_file "${CMAKE_CURRENT_BINARY_DIR}/Plugin.h")

    # Set the plugin name.
    set(commonlibsf_plugin_name "${TARGET}")
    if(DEFINED ADD_COMMONLIBSF_PLUGIN_NAME)
        set(commonlibsf_plugin_name "${ADD_COMMONLIBSF_PLUGIN_NAME}")
    endif()

    # Setup version number of the plugin.
    set(commonlibsf_plugin_version "${PROJECT_VERSION}")
    if(DEFINED ADD_COMMONLIBSF_PLUGIN_VERSION)
        set(commonlibsf_plugin_version "${ADD_COMMONLIBSF_PLUGIN_VERSION}")
    endif()

    commonlibsf_parse_version("${commonlibsf_plugin_version}")

    if(NOT DEFINED COMMONLIBSF_VERSION_MAJOR)
        message(FATAL_ERROR "Unable to parse plugin version number ${commonlibsf_plugin_version}.")
    endif()

    set(commonlibsf_plugin_version "REL::Version{${COMMONLIBSF_VERSION_MAJOR}, ${COMMONLIBSF_VERSION_MINOR}, ${COMMONLIBSF_VERSION_PATCH}, ${COMMONLIBSF_VERSION_TWEAK}}")

    # Handle minimum SFSE version constraints.
    if(NOT DEFINED ADD_COMMONLIBSF_PLUGIN_MINIMUM_SFSE_VERSION)
        set(ADD_COMMONLIBSF_PLUGIN_MINIMUM_SFSE_VERSION 0)
    endif()

    commonlibsf_parse_version("${ADD_COMMONLIBSF_PLUGIN_MINIMUM_SFSE_VERSION}")

    if(NOT COMMONLIBSF_VERSION_MATCH)
        message(FATAL_ERROR "Unable to parse SFSE minimum SFSE version number "
                "${ADD_COMMONLIBSF_PLUGIN_MINIMUM_SFSE_VERSION}.")
    endif()

    set(commonlibsf_min_sfse_version "REL::Version{${COMMONLIBSF_VERSION_MAJOR}, ${COMMONLIBSF_VERSION_MINOR}, ${COMMONLIBSF_VERSION_PATCH}, ${COMMONLIBSF_VERSION_TWEAK}}")

    # Setup compatibility configuration.
    if(NOT ADD_COMMONLIBSF_PLUGIN_STRUCT_DEPENDENT)
        set(commonlibsf_is_layout_dependent "true")
    else()
        set(commonlibsf_is_layout_dependent "false")
    endif()

    if(NOT ADD_COMMONLIBSF_PLUGIN_USE_SIGNATURE_SCANNING)
        set(ADD_COMMONLIBSF_PLUGIN_USE_ADDRESS_LIBRARY TRUE)
    endif()

    if(ADD_COMMONLIBSF_PLUGIN_USE_ADDRESS_LIBRARY OR ADD_COMMONLIBSF_PLUGIN_USE_SIGNATURE_SCANNING)
        if(NOT ADD_COMMONLIBSF_PLUGIN_USE_ADDRESS_LIBRARY)
            set(commonlibsf_uses_address_library "false")
        else()
            set(commonlibsf_uses_address_library "true")
        endif()
    endif()

    if(NOT DEFINED ADD_COMMONLIBSF_PLUGIN_COMPATIBLE_RUNTIMES)
        set(commonlibsf_plugin_compatibility "{ SFSE::RUNTIME_LATEST }")
    else()
        list(LENGTH ${ADD_COMMONLIBSF_PLUGIN_COMPATIBLE_RUNTIMES} commonlibsf_plugin_compatibility_count)
        if(commonlibsf_plugin_compatibility_count GREATER 16)
            message(FATAL_ERROR "No more than 16 version numbers can be provided for COMPATIBLE_RUNTIMES.")
        endif()
        foreach(STARFIELD_VERSION ${ADD_COMMONLIBSF_PLUGIN_COMPATIBLE_RUNTIMES})
            if(DEFINED commonlibsf_plugin_compatibility)
                set(commonlibsf_plugin_compatibility "${commonlibsf_plugin_compatibility}, ")
            endif()
            commonlibsf_parse_version("${STARFIELD_VERSION}")
            if(NOT COMMONLIBSF_VERSION_MATCH)
                message(FATAL_ERROR "Unable to parse Starfield runtime version number ${STARFIELD_VERSION}.")
            endif()
            set(commonlibsf_plugin_compatibility "${commonlibsf_plugin_compatibility}REL::Version{${COMMONLIBSF_VERSION_MAJOR}, ${COMMONLIBSF_VERSION_MINOR}, ${COMMONLIBSF_VERSION_PATCH}, ${COMMONLIBSF_VERSION_TWEAK}}")
        endforeach()
        set(commonlibsf_plugin_compatibility "{ ${commonlibsf_plugin_compatibility} }")
    endif()

    file(WRITE "${commonlibsf_plugin_file}"
            "#pragma once\n\n"
            "namespace Plugin\n"
            "{\n"
            "    using namespace std::string_view_literals;\n\n"
            "    static constexpr auto Name{ \"${commonlibsf_plugin_name}\"sv };\n"
            "    static constexpr auto Author{ \"${ADD_COMMONLIBSF_PLUGIN_AUTHOR}\"sv };\n"
            "    static constexpr auto Version{\n"
            "        ${commonlibsf_plugin_version}\n"
            "    };\n"
            "}\n\n"
            "SFSEPluginVersion = []() noexcept {\n"
            "    SFSE::PluginVersionData data{};\n"
            "\n"
            "    data.PluginVersion(Plugin::Version.pack());\n"
            "    data.PluginName(Plugin::Name);\n"
            "    data.AuthorName(Plugin::Author);\n"
            "    data.UsesAddressLibrary(${commonlibsf_uses_address_library});\n"
            "    data.IsLayoutDependent(${commonlibsf_is_layout_dependent});\n"
            "    data.CompatibleVersions(${commonlibsf_plugin_compatibility});\n"
            "\n"
            "    return data;\n"
            "}();\n")

    target_compile_definitions("${TARGET}" PRIVATE __CMAKE_COMMONLIBSF_PLUGIN=1)
    target_link_libraries("${TARGET}" PUBLIC CommonLibSF::CommonLibSF)
    target_include_directories("${TARGET}" PUBLIC CommonLibSF_INCLUDE_DIRS)
    target_include_directories("${TARGET}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
endfunction()

function(add_commonlibsf_plugin TARGET)
    set(options OPTIONAL USE_ADDRESS_LIBRARY USE_SIGNATURE_SCANNING STRUCT_DEPENDENT EXCLUDE_FROM_ALL)
    set(oneValueArgs NAME AUTHOR VERSION MINIMUM_SFSE_VERSION)
    set(multiValueArgs COMPATIBLE_RUNTIMES SOURCES)

    cmake_parse_arguments(PARSE_ARGV 1 ADD_COMMONLIBSF_PLUGIN "${options}" "${oneValueArgs}"
            "${multiValueArgs}")

    add_library("${TARGET}" SHARED $<$<BOOL:${ADD_COMMONLIBSF_PLUGIN_EXCLUDE_FROM_ALL}>:EXCLUDE_FROM_ALL>
            ${ADD_COMMONLIBSF_PLUGIN_SOURCES})

    target_commonlibsf_properties("${TARGET}" ${ARGN})
endfunction()
