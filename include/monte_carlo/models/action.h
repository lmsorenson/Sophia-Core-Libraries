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
        Action(const std::shared_ptr<Node>& source, const std::shared_ptr<Node>& target);
        virtual ~Action() = default;

        [[nodiscard]] double UpperConfidenceBound() const;
        [[nodiscard]] std::shared_ptr<Node> Source() const;
        [[nodiscard]] std::shared_ptr<Node> Target() const;

    private:
        std::weak_ptr<Node> m_source_node_;
        std::weak_ptr<Node> m_target_node_;
    };
}

#endif //ACTION_H
