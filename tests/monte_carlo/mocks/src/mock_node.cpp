#include <mock_node.h>

#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::monte_carlo::mocks::MockNode;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::factories::ITreeFactory;
using std::vector;
using std::shared_ptr;
using std::string;
using testing::Return;

MockNode::MockNode(const string& name, const shared_ptr<const ITreeFactory>& interface)
    : Node(std::move(name), std::move(interface))
{
}

void MockNode::Setup( vector<shared_ptr<Node>> node_expansion )
{
    EXPECT_CALL(*this, GetAvailableActions())
        .Times(::testing::AnyNumber())
        .WillOnce(Return(std::move(node_expansion)));
}

void MockNode::Setup( const double value ) const
{
    EXPECT_CALL(*this, IsTerminalState())
                .Times(::testing::AnyNumber())
                .WillOnce(Return(true))
                .WillOnce(Return(false));
    EXPECT_CALL(*this, Value())
        .Times(::testing::AnyNumber())
        .WillRepeatedly(Return(value));
}
