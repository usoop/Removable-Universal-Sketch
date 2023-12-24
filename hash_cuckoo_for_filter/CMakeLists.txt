set(target_name "cuckoofilter_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::CUCKOO_FILTER ALIAS ${target_name})

target_include_directories(${target_name}
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_link_libraries(cuckoofilter_lib INTERFACE spdlog_lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -ansi -std=c++17 -mavx -march=native  -O0")


target_link_libraries(cuckoofilter_lib INTERFACE spdlog_lib)
target_link_libraries(cuckoofilter_lib INTERFACE utils_lib)
target_link_libraries(cuckoofilter_lib INTERFACE crypto)
target_link_libraries(cuckoofilter_lib INTERFACE ssl)
target_link_libraries(cuckoofilter_lib INTERFACE pthread)
add_subdirectory(include/utils)
