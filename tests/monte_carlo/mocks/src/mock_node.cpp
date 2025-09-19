#include <mock_action.h>
#include <mock_node.h>

#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::monte_carlo::mocks::MockNode;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::factories::TreeFactoryBase;
using std::vector;
using std::shared_ptr;
using std::string;
using testing::Return;

MockNode::MockNode(const string& name, const shared_ptr<const TreeFactoryBase<bool, int>>& interface)
    : NodeBase(std::move(name), true, std::move(interface))
{
}

void MockNode::Setup(const vector<shared_ptr<Node>> &node_expansion )
{
    vector<shared_ptr<Action>> actions = {};
    actions.reserve(node_expansion.size());

    for(const auto& node : node_expansion)
    {
        auto _this_ = std::static_pointer_cast<MockNode>(shared_from_this());
        auto action = m_factory_->CreateAction(_this_, 1);
        const auto ma = std::dynamic_pointer_cast<MockAction>(action);
        ma->Setup(node);
        actions.push_back(action);
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
    return m_parent_action_.lock();
}

void MockNode::SetVisitCount(const int newCount)
{
    m_visit_count_ = newCount;
}

void MockNode::SetTotalReward(const double newTotalReward)
{
    m_total_reward_ = newTotalReward;
}



