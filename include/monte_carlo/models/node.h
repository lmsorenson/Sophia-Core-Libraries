#ifndef NODE_H
#define NODE_H

#include <vector>
#include <ostream>
#include <memory>

namespace sophia::monte_carlo::factories
{
    class ITreeFactory;
}

namespace sophia::monte_carlo::models
{
    class Action;

    class Node : public std::enable_shared_from_this<Node>
    {
    public:
        explicit Node(std::string name, std::shared_ptr<const factories::ITreeFactory> factory);
        virtual ~Node() = default;

        void SetParent(std::shared_ptr<Action> action);
        [[nodiscard]] double UpperConfidenceBound() const;
        [[nodiscard]] bool IsLeafNode() const;
        [[nodiscard]] bool HasBeenSampled() const;

        [[nodiscard]] virtual std::vector<std::shared_ptr<Node>> GetAvailableActions() const = 0;
        [[nodiscard]] virtual bool IsTerminalState() const = 0;
        [[nodiscard]] virtual double Value() const = 0;

        [[nodiscard]] std::shared_ptr<Action> SelectBestAction() const;
        std::shared_ptr<Node> Expand();
        double Rollout();
        void Backpropagate(double reward);

        [[nodiscard]] std::string Name() const;
        [[nodiscard]] int VisitCount() const;
        [[nodiscard]] int TotalReward() const;

    protected:
        std::shared_ptr<const factories::ITreeFactory> m_factory_;

    private:
        std::string m_name_;
        int m_visit_count_ = 0;
        double m_total_reward_ = 0;
        std::shared_ptr<Action> m_parent_action_;
        std::vector<std::shared_ptr<Action>> m_child_action_;
    };
}

#endif //NODE_H
