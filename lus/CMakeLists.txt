set(target_name "lus_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::LUS ALIAS ${target_name})


target_include_directories(${target_name}
        INTERFACE

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

        )

target_link_libraries(lus_lib INTERFACE sketch_lib)
target_link_libraries(lus_lib INTERFACE filter_lib)
target_link_libraries(lus_lib INTERFACE utils_lib)
target_link_libraries(lus_lib INTERFACE augmented_sketch_lib)
target_link_libraries(lus_lib INTERFACE spdlog_lib)
target_link_libraries(lus_lib INTERFACE cuckoofilter_lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -ansi -std=c++17  -mavx2 -O3")

