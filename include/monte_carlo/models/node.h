#ifndef NODE_H
#define NODE_H

#include <monte_carlo/models/rollout_strategy_interface.h>
#include <vector>
#include <memory>

namespace sophia::monte_carlo::models
{
    class Action;

    class Node : public std::enable_shared_from_this<Node>
    {
    protected:
        using rollout_strategy_ptr = std::shared_ptr<RolloutStrategyInterface>;
        using action_ref = std::weak_ptr<Action>;
        using action_ptr = std::shared_ptr<Action>;
        using node_ptr = std::shared_ptr<Node>;

    public:
        explicit Node(std::string name);
        virtual ~Node() = default;

        void SetParent(const action_ptr& action);

        [[nodiscard]] action_ptr SelectBestAction() const;
        node_ptr Expand();
        double Rollout();
        void Backpropagate(double reward);

        [[nodiscard]] std::string Name() const;
        [[nodiscard]] double UpperConfidenceBound(int c) const;
        [[nodiscard]] bool IsLeafNode() const;
        [[nodiscard]] bool HasBeenSampled() const;
        [[nodiscard]] int VisitCount() const;
        [[nodiscard]] double TotalReward() const;
        [[nodiscard]] virtual bool IsTerminalState() const = 0;
        [[nodiscard]] virtual double Value() const = 0;

        virtual action_ptr SelectAction(std::string action_name) = 0;
        virtual action_ptr SelectAction();
        virtual void Print() const = 0;

    protected:
        [[nodiscard]] virtual std::vector<action_ptr> GetAvailableActions() = 0;
        virtual rollout_strategy_ptr RolloutStrategy() const = 0;

        action_ref m_parent_action_;
        std::vector<action_ptr> m_child_action_;
        unsigned long m_visit_count_ = 0;
        double m_total_reward_ = 0;

    private:
        std::string m_name_;
    };
}

#endif //NODE_H
