#ifndef ACTION_H
#define ACTION_H
#include <memory>

namespace sophia::monte_carlo::models
{
    class Node;

    class Action
    {
    public:
        Action(std::shared_ptr<Node> source, std::shared_ptr<Node> target);
        virtual ~Action() = default;

        [[nodiscard]] double UpperConfidenceBound() const;
        [[nodiscard]] std::shared_ptr<Node> Source() const;
        [[nodiscard]] std::shared_ptr<Node> Target() const;

    private:
        std::shared_ptr<Node> m_source_node_;
        std::shared_ptr<Node> m_target_node_;
    };
}

#endif //ACTION_H
