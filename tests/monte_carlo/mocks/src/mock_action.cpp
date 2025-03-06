#include <mock_action.h>

#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::monte_carlo::mocks::MockAction;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;
using std::string;
using testing::Return;

MockAction::MockAction(shared_ptr<Node> source)
: Action(source)
{

}

void MockAction::Setup(const shared_ptr<Node> &node) const
{
    EXPECT_CALL(*this, Target())
        .Times(::testing::AnyNumber())
        .WillRepeatedly(Return(node));
}






