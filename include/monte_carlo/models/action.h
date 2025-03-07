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
        Action() = default;
        virtual ~Action() = default;

        [[nodiscard]] double UpperConfidenceBound() const;
        virtual void Generate() = 0;
        [[nodiscard]] virtual std::shared_ptr<Node> Source() const = 0;
        [[nodiscard]] virtual std::shared_ptr<Node> Target() const = 0;
    };
}

#endif //ACTION_H
