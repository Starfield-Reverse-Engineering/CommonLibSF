set_xmakever("2.8.2")

-- set project
set_project("commonlibsf")
set_arch("x64")
set_languages("c++23")
set_optimize("faster")
set_warnings("allextra")
set_encodings("utf-8")

-- add rules
add_rules("mode.debug", "mode.release")

-- require packages
add_requires("xbyak")
add_requires("spdlog", { configs = { header_only = false, std_format = true } })

-- include subprojects
includes("CommonLibSF")
