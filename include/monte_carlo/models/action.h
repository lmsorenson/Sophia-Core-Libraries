#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <memory>
#include <ostream>

namespace sophia::monte_carlo::models
{
    class Node;

    class Action : public std::enable_shared_from_this<Action>
    {
    public:
        Action(const std::shared_ptr<Node>& source);
        virtual ~Action() = default;

        [[nodiscard]] double UpperConfidenceBound() const;
        [[nodiscard]] std::shared_ptr<Node> Source() const;
        [[nodiscard]] virtual std::shared_ptr<Node> Target() const = 0;

    private:
        std::weak_ptr<Node> m_source_node_;
        std::shared_ptr<Node> m_target_state_;
    };
}

#endif //ACTION_H
