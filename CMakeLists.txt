
cmake_minimum_required(VERSION 3.12.0)

project(moment_estimation
        VERSION 0.12.0

        LANGUAGES C CXX)

include(GNUInstallDirs)
include(CMakeDependentOption)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


set(CMAKE_BUILD_TYPE "Debug")


include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)


if (COMPILER_SUPPORTS_CXX11)#


    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mavx2 -O0")
    message("c++11")
elseif (COMPILER_SUPPORTS_CXX0X)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    message("c++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()


add_subdirectory(active_counter)


add_subdirectory(sketch)


add_subdirectory(filter)


add_subdirectory(utils)

add_subdirectory(lus)


add_subdirectory(augmented_sketch)


add_subdirectory(spdlog)


add_subdirectory(hash_cuckoo_for_filter)


#
