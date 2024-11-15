cmake_minimum_required(VERSION 3.30)
message("Using toolchain file ${CMAKE_TOOLCHAIN_FILE}.")

# singleton target across multiple projects
if(TARGET CommonLibSF)
  return()
endif()

# options if not defined
option(REX_OPTION_INI "Enables ini config support for REX." OFF)
option(REX_OPTION_JSON "Enables json config support for REX." OFF)
option(REX_OPTION_TOML "Enables toml config support for REX." OFF)
option(SFSE_SUPPORT_XBYAK "Enables trampoline support for xbyak." OFF)
option(SFSE_BUILD_TESTS "Builds the tests." OFF)

# info
project(
  CommonLibSF
  LANGUAGES CXX
)

# standards & flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OPTIMIZE_DEPENDENCIES ON)

include(GNUInstallDirs)

# out-of-source builds only
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# dependencies
find_package(spdlog CONFIG REQUIRED)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*
)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/SFSE/Impl/PCH.h)

source_group(
  TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES ${SOURCES}
)

function(configure_target TARGET_NAME)
  if(SFSE_SUPPORT_XBYAK)
    find_package(xbyak CONFIG REQUIRED)
  endif()

  target_compile_definitions(
    ${TARGET_NAME}
    PUBLIC
    WINVER=0x0A00 # windows 10, minimum supported version by starfield
    _WIN32_WINNT=0x0A00
    "$<$<BOOL:${REX_OPTION_INI}>:REX_OPTION_INI=1>"
    "$<$<BOOL:${REX_OPTION_JSON}>:REX_OPTION_JSON=1>"
    "$<$<BOOL:${REX_OPTION_TOML}>:REX_OPTION_TOML=1>"
    $<$<BOOL:${SFSE_SUPPORT_XBYAK}>:SFSE_SUPPORT_XBYAK=1>
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    _ITERATOR_DEBUG_LEVEL=0
  )

  # FIXME: https://gitlab.kitware.com/cmake/cmake/-/issues/24922
  set_property(
    TARGET ${TARGET_NAME}
    PROPERTY VS_USER_PROPS
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/build_stl_modules.props
  )

  target_compile_options(
    ${TARGET_NAME}
    PUBLIC
    /bigobj # support large object file format
    /wd4005 # macro redefinition
    /wd4068 # unknown pragma
    /wd4200 # nonstandard extension used: zero-sized array in struct/union
    /wd4201 # nonstandard extension used: nameless struct/union
  )

  if(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL MSVC AND CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    set(CLIBSF_COMPILEFLAGS_RELEASE /Ob3 /GR- /Gw /Qvec -flto -fsplit-lto-unit -fvirtual-function-elimination -fwhole-program-vtables)

    target_compile_options(
      ${TARGET_NAME} PRIVATE
      /Zc:alignedNew
      /Zc:char8_t
      /Zc:sizedDealloc
      /Zc:strictStrings
      /Zc:threadSafeInit
      -fansi-escape-codes
      -fcolor-diagnostics
      -fcomplete-member-pointers
      -fexperimental-library
      -fforce-emit-vtables
      -fms-compatibility
      -fms-extensions
      -fstrict-aliasing
      -Wno-overloaded-virtual
      -Wno-delete-non-abstract-non-virtual-dtor
      -Wno-inconsistent-missing-override
      -Wno-reinterpret-base-class
      -Wno-return-type
      -Wno-invalid-offsetof
      -Wno-switch
      -Wno-unused-command-line-argument
      $<$<CONFIG:Release>:${CLIBSF_COMPILEFLAGS_RELEASE}>
    )
  elseif(CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL MSVC AND CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    set(CLIBSF_COMPILEFLAGS_RELEASE /fp:fast /Ob3 /GL /GR- /Gw /Qpar)

    target_compile_options(
      ${TARGET_NAME}
      PRIVATE
      /cgthreads8
      /diagnostics:caret
      /jumptablerdata
      /MP
      /W4
      /Zc:__cplusplus
      /Zc:enumTypes
      /Zc:inline
      /Zc:templateScope
      $<$<CONFIG:Release>:${CLIBSF_COMPILEFLAGS_RELEASE}>
    )
  endif()

  target_include_directories(
    ${TARGET_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  target_precompile_headers(
    ${TARGET_NAME}
    PRIVATE
    include/SFSE/Impl/PCH.h
  )

  target_link_libraries(
    ${TARGET_NAME}
    PUBLIC
    spdlog::spdlog
    advapi32.lib
    bcrypt.lib
    dbghelp.lib
    dxgi.lib
    ole32.lib
    version.lib
    ws2_32.lib
  )
endfunction()

if(SFSE_BUILD_TESTS)
  # add a custom library target that just builds test.cpp
  add_library(
    ${PROJECT_NAME}-test
    STATIC
    ${SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp
  )
  configure_target(${PROJECT_NAME}-test)
  set(PROJECT_NAME ${PROJECT_NAME}-test)
else()
  add_library(
    ${PROJECT_NAME}
    STATIC
    ${SOURCES}
  )
  add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
  configure_target(${PROJECT_NAME})
endif()

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-targets
)

install(
  EXPORT ${PROJECT_NAME}-targets
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

configure_file(
  cmake/config.cmake.in
  ${PROJECT_NAME}Config.cmake
  @ONLY
)

install(
  FILES cmake/CommonLibSF.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
  DIRECTORY
  include/RE
  include/REL
  include/REX
  include/SFSE
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
