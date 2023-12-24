set(target_name "augmented_sketch_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::AUGMENTED_SKETCH ALIAS ${target_name})


target_include_directories(${target_name}
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(augmented_sketch_lib INTERFACE sketch_lib)
target_link_libraries(augmented_sketch_lib INTERFACE filter_lib)
target_link_libraries(augmented_sketch_lib INTERFACE active_counter_stochastic_lib)








