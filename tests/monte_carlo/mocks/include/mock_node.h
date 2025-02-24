#ifndef MOCK_NODE_H
#define MOCK_NODE_H

#include <gmock/gmock.h>
#include <monte_carlo/models/node.h>
#include <monte_carlo/models/action.h>
#include <monte_carlo/factories/tree_factory.h>

namespace sophia::monte_carlo::mocks
{
    using models::Node;
    using models::Action;
    using models::ActionSelectStrategyInterface;
    using factories::ITreeFactory;
    using std::string;
    using std::vector;
    using std::make_shared;
    using std::shared_ptr;

    class MockNode : public Node
    {
    public:
        explicit MockNode(const string& name, const shared_ptr<const ITreeFactory>& interface);
        ~MockNode() override = default;

        MOCK_METHOD(vector<shared_ptr<Node>>, GetAvailableActions, (), (const, override));
        MOCK_METHOD(bool, IsTerminalState, (), (const, override));
        MOCK_METHOD(double, Value, (), (const, override));

        void Setup( vector<shared_ptr<Node>> node_expansion );
        void Setup(double value ) const;
    };
}

#endif //MOCK_NODE_H
