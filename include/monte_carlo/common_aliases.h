#ifndef SOPHIA_MONTE_CARLO_COMMON_ALIASES_H
#define SOPHIA_MONTE_CARLO_COMMON_ALIASES_H

#include <logging/ilogger.h>
#include <memory> // Required for std::shared_ptr
#include <monte_carlo/fwd.h> // Centralized forward declarations

namespace sophia::monte_carlo
{
    using logger_ptr = std::shared_ptr<logging::ILogger>;
    using const_logger_ptr = std::shared_ptr<const logging::ILogger>;
    using node_ptr = std::shared_ptr<models::Node>;
    using const_node_ptr = std::shared_ptr<const models::Node>;
    using action_ptr = std::shared_ptr<models::Action>;
    using const_action_ptr = std::shared_ptr<const models::Action>;
}

#endif // SOPHIA_MONTE_CARLO_COMMON_ALIASES_H
