cmake_minimum_required(VERSION 3.26)

# singleton target across multiple projects
if(TARGET CommonLib)
	return()
endif()

# info
project(
	CommonLib
	LANGUAGES CXX
)

# out-of-source builds only
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
	message(FATAL_ERROR "In-source builds are not allowed.")
endif()

add_subdirectory(CommonLibSF)
