#include <logging/console_logger.h>
#include <iostream>

namespace sophia::logging
{
    ConsoleLogger::ConsoleLogger(LogLevel min_level) : min_level_(min_level) {}

    void ConsoleLogger::log(LogLevel level, const std::string& message)
    {
        if (level < min_level_)
        {
            return;
        }

        const char* level_str;
        switch (level)
        {
            case LogLevel::DEBUG:
                level_str = "[DEBUG]";
                break;
            case LogLevel::INFO:
                level_str = "[INFO] ";
                break;
            case LogLevel::WARN:
                level_str = "[WARN] ";
                break;
            case LogLevel::ERROR:
                level_str = "[ERROR]";
                break;
            default:
                level_str = "[UNKN] ";
                break;
        }

        // For errors, log to std::cerr. For all others, log to std::cout.
        if (level == LogLevel::ERROR)
        {
            std::cerr << level_str << " " << message << std::endl;
        }
        else
        {
            std::cout << level_str << " " << message << std::endl;
        }
    }

} // namespace sophia::logging
