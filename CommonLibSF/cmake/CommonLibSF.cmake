function(add_commonlibsf_plugin TARGET)
    set(options OPTIONAL USE_SIGNATURE_SCANNING)
    set(oneValueArgs AUTHOR)
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(ADD_COMMONLIBSF_PLUGIN "${options}" "${oneValueArgs}" "${multiValueArgs}")

    add_library("${TARGET}" SHARED ${ADD_COMMONLIBSF_PLUGIN_SOURCES})
    
    target_link_libraries(${TARGET}
        PRIVATE
        CommonLibSF::CommonLibSF)
endfunction()
