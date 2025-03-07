#ifndef MOCK_ACTION_H
#define MOCK_ACTION_H

#include <gmock/gmock.h>
#include <monte_carlo/models/action_base.h>

// namespace sophia::monte_carlo::models
// {
//     class Node;
// }

namespace sophia::monte_carlo::mocks
{
    using models::ActionBase;
    using models::Node;
    using factories::ITreeFactory;
    using std::shared_ptr;

    class MockAction : public ActionBase<bool, int>
    {
    public:
        explicit MockAction(shared_ptr<NodeBase<bool, int>> source,
        const std::shared_ptr<const ITreeFactory<bool, int>> &factory);
        ~MockAction() override = default;

        MOCK_METHOD(void, Generate, (), (override));
        MOCK_METHOD(shared_ptr<Node>, Target, (), (const, override));

        void Setup( const shared_ptr<Node> &node ) const;
    };
}

#endif //MOCK_ACTION_H
