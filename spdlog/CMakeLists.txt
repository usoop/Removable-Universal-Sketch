set(target_name "spdlog_lib")

add_library(${target_name} INTERFACE)

add_library(${PROJECT_NAME}::SPDLOG ALIAS ${target_name})

target_include_directories(${target_name}
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )


