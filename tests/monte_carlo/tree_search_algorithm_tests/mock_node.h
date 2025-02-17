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

        MOCK_METHOD(vector<shared_ptr<Node>>, GetAvailableActions, (), (const, override));
        MOCK_METHOD(bool, IsTerminalState, (), (const, override));
        MOCK_METHOD(double, Value, (), (const, override));

        void Setup( vector<shared_ptr<Node>> node_expansion )
        {
            EXPECT_CALL(*this, GetAvailableActions())
                .WillOnce(Return(std::move(node_expansion)));
        }

        void Setup( vector<shared_ptr<Node>> node_expansion, const double value )
        {
            shared_ptr<MockNode> st = make_shared<MockNode>("terminal", m_action_select_strategy_);
            vector<shared_ptr<Node>> t_nodes = { st };

            EXPECT_CALL(*this, GetAvailableActions())
                .WillOnce(Return(std::move(node_expansion)));
            EXPECT_CALL(*this, IsTerminalState())
                        // The first time fake the terminal state.
                        .WillOnce(Return(true))
                        .WillOnce(Return(false));
            EXPECT_CALL(*this, Value()).WillRepeatedly(Return(value));
        }
    };
}

#endif //MOCK_NODE_H
