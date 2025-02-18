#ifndef MOCK_NODE_H
#define MOCK_NODE_H
#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>

#include <utility>

namespace sophia::monte_carlo::tree_search_algorithm_tests
{
    using models::Node;
    using models::Action;
    using models::ActionSelectStrategyInterface;
    using std::string;
    using std::vector;
    using std::make_shared;
    using std::shared_ptr;
    using std::move;
    using ::testing::Return;

    class MockNode : public Node
    {
    public:
        explicit MockNode(string name, shared_ptr<ActionSelectStrategyInterface> interface)
            : Node(move(name), move(interface))
        {
        }
        virtual ~MockNode() = default;

        MOCK_METHOD(vector<shared_ptr<Node>>, GetAvailableActions, (), (const, override));
        MOCK_METHOD(bool, IsTerminalState, (), (const, override));
        MOCK_METHOD(double, Value, (), (const, override));

        void Setup( vector<shared_ptr<Node>> node_expansion )
        {
            EXPECT_CALL(*this, GetAvailableActions())
                .Times(::testing::AnyNumber())
                .WillOnce(Return(std::move(node_expansion)));
        }

        void Setup( const double value )
        {
            EXPECT_CALL(*this, IsTerminalState())
                        // The first time fake the terminal state.
                        .Times(::testing::AnyNumber())
                        .WillOnce(Return(true))
                        .WillOnce(Return(false));
            EXPECT_CALL(*this, Value())
                .Times(::testing::AnyNumber())
                .WillRepeatedly(Return(value));
        }

        void ClearSetup() {
            ::testing::Mock::VerifyAndClearExpectations(this);
        }
    };
}

#endif //MOCK_NODE_H
