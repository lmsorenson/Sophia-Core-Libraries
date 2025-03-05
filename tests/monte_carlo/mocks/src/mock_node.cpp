#include <mock_node.h>

#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::monte_carlo::mocks::MockNode;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::factories::ITreeFactory;
using std::vector;
using std::shared_ptr;
using std::string;
using testing::Return;

MockNode::MockNode(const string& name, const shared_ptr<const ITreeFactory>& interface)
    : Node(std::move(name), std::move(interface))
{
}

void MockNode::Setup(const vector<shared_ptr<Node>> &node_expansion )
{
    vector<shared_ptr<Action>> actions = {};
    actions.reserve(node_expansion.size());

    for(const auto& node : node_expansion)
    {
        actions.push_back(m_factory_->CreateAction(shared_from_this(), node));
    }

    EXPECT_CALL(*this, GetAvailableActions())
        .Times(::testing::AnyNumber())
        .WillOnce(Return(actions));
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

std::shared_ptr<const Action> MockNode::GetParent() const
{
    return m_parent_action_;
}

void MockNode::SetVisitCount(const int newCount)
{
    m_visit_count_ = newCount;
}

void MockNode::SetTotalReward(const double newTotalReward)
{
    m_total_reward_ = newTotalReward;
}



