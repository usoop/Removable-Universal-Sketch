


#pragma once

#include "registry.h"

namespace spdlog {


    class logger;

    struct synchronous_factory {
        template<typename Sink, typename... SinkArgs>
        static std::shared_ptr<spdlog::logger> create(std::string logger_name, SinkArgs &&... args) {
            auto sink = std::make_shared<Sink>(std::forward<SinkArgs>(args)...);
            auto new_logger = std::make_shared<spdlog::logger>(std::move(logger_name), std::move(sink));
            details::registry::instance().initialize_logger(new_logger);
            return new_logger;
        }
    };
}
