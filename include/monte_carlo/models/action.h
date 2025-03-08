#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <ostream>

namespace sophia::monte_carlo::models
{
    class Node;
    using std::enable_shared_from_this;

    class Action : public enable_shared_from_this<Action>
    {
    protected:
        using node_ptr = std::shared_ptr<Node>;

    public:
        Action() = default;
        virtual ~Action() = default;

        [[nodiscard]] double UpperConfidenceBound() const;
        virtual void Generate() = 0;
        [[nodiscard]] virtual node_ptr Source() const = 0;
        [[nodiscard]] virtual node_ptr Target() const = 0;
    };
}

#endif //ACTION_H
