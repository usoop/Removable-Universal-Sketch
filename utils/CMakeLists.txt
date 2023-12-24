set(target_name "utils_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::UTILS ALIAS ${target_name})


target_include_directories(${target_name}
        INTERFACE

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_link_libraries(utils_lib INTERFACE active_counter_stochastic_lib)







