#ifndef MOCK_ACTION_H
#define MOCK_ACTION_H

#include <gmock/gmock.h>
#include <monte_carlo/models/action.h>

// namespace sophia::monte_carlo::models
// {
//     class Node;
// }

namespace sophia::monte_carlo::mocks
{
    using models::Action;
    using models::Node;
    using std::shared_ptr;

    class MockAction : public Action
    {
    public:
        explicit MockAction(shared_ptr<Node> source);
        ~MockAction() override = default;

        MOCK_METHOD(shared_ptr<Node>, Target, (), (const, override));

        void Setup(const shared_ptr<Node> &node ) const;
    };
}

#endif //MOCK_ACTION_H
