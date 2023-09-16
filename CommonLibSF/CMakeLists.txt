cmake_minimum_required(VERSION 3.26)
message("Using toolchain file ${CMAKE_TOOLCHAIN_FILE}.")

# singleton target across multiple projects
if(TARGET CommonLibSF)
	return()
endif()

# options if not defined
option(SFSE_SUPPORT_XBYAK "Enables trampoline support for Xbyak." OFF)

# standards & flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# info
project(
	CommonLibSF
	LANGUAGES CXX
	VERSION 1.0.0
)

include(GNUInstallDirs)

# out-of-source builds only
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
	message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# dependencies
find_package(spdlog CONFIG REQUIRED)

# source files
execute_process(COMMAND powershell -ExecutionPolicy Bypass -File "${CMAKE_CURRENT_SOURCE_DIR}/cmake/make-sourcelist.ps1" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")
include(${CMAKE_CURRENT_BINARY_DIR}/sourcelist.cmake)
source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${SOURCES}
)

add_library(
	${PROJECT_NAME}
	STATIC
	${SOURCES}
	.clang-format
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_definitions(
	${PROJECT_NAME}
	PUBLIC
		WINVER=0x0A00	# windows 10, minimum supported version by starfield
		_WIN32_WINNT=0x0A00
		"$<$<BOOL:${SFSE_SUPPORT_XBYAK}>:SFSE_SUPPORT_XBYAK=1>"
)

# FIXME: https://gitlab.kitware.com/cmake/cmake/-/issues/24922
set_property(
	TARGET
	${PROJECT_NAME}
	PROPERTY VS_USER_PROPS
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/build_stl_modules.props"
)

if (MSVC)
	target_compile_options(
		${PROJECT_NAME}
		PUBLIC
			/bigobj # support large object file format
			/utf-8  # assume UTF-8 sources even without a BOM

			# warnings -> errors
			/we4715	# 'function' : not all control paths return a value

			# disable warnings
			/wd4005 # macro redefinition
			/wd4061 # enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label
			/wd4068 # unknown pragma
			/wd4200 # nonstandard extension used : zero-sized array in struct/union
			/wd4201 # nonstandard extension used : nameless struct/union
			/wd4265 # 'type': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly
			/wd4266 # 'function' : no override available for virtual member function from base 'type'; function is hidden
			/wd4267 # 'var' : conversion from 'size_t' to 'type', possible loss of data
			/wd4371 # 'classname': layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
			/wd4514 # 'function' : unreferenced inline function has been removed
			/wd4582 # 'type': constructor is not implicitly called
			/wd4583 # 'type': destructor is not implicitly called
			/wd4623 # 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
			/wd4625 # 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted
			/wd4626 # 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted
			/wd4710 # 'function' : function not inlined
			/wd4711 # function 'function' selected for inline expansion
			/wd4820 # 'bytes' bytes padding added after construct 'member_name'
			/wd4996
			/wd5026 # 'type': move constructor was implicitly defined as deleted
			/wd5027 # 'type': move assignment operator was implicitly defined as deleted
			/wd5045 # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
			/wd5053 # support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension
			/wd5204 # 'type-name': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
			/wd5220 # 'member': a non-static data member with a volatile qualified type no longer implies that compiler generated copy / move constructors and copy / move assignment operators are not trivial
	)
endif()

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
		"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
		spdlog::spdlog
		Version.lib
		Dbghelp.lib
)

if (SFSE_SUPPORT_XBYAK)
find_package(xbyak CONFIG REQUIRED)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
		xbyak::xbyak
)
endif()

target_precompile_headers(
	${PROJECT_NAME}
	PRIVATE
		include/SFSE/Impl/PCH.h
)

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
		include/SFSE
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
