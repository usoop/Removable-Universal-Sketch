set(target_name "active_counter_stochastic_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::ACTIVE_COUNTER ALIAS ${target_name})

target_sources(${target_name}
        INTERFACE


        ${CMAKE_CURRENT_SOURCE_DIR}/include/active_counter/generic_counter_turnstile.hpp

        )

target_include_directories(${target_name}
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(active_counter_stochastic_lib INTERFACE utils_lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -ansi -std=c++17 -O0")
