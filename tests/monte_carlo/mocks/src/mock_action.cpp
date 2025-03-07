#include <mock_action.h>

#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::monte_carlo::mocks::MockAction;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::factories::ITreeFactory;
using std::shared_ptr;
using std::string;
using testing::Return;

MockAction::MockAction(shared_ptr<NodeBase<bool, int>> source,
        const std::shared_ptr<const ITreeFactory<bool, int>> &factory)
: ActionBase(source, 0, factory)
{

}

void MockAction::Setup(const shared_ptr<Node> &node) const
{
    EXPECT_CALL(*this, Target())
        .Times(::testing::AnyNumber())
        .WillRepeatedly(Return(node));
}






