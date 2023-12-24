set(target_name "sketch_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::SKETCH ALIAS ${target_name})


target_include_directories(${target_name}
        INTERFACE

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_link_libraries(sketch_lib INTERFACE utils_lib)
target_link_libraries(sketch_lib INTERFACE filter_lib)



















