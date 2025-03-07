#ifndef ACTION_BASE_H
#define ACTION_BASE_H
#include <iostream>
#include <memory>
#include <ostream>

#include <monte_carlo/models/action.h>

#include "node_base.h"

namespace sophia::monte_carlo::models
{
    template<typename TState, typename TChange>
    class ActionBase : public Action
    {
    public:
        ActionBase(const std::shared_ptr<NodeBase<TChange>> &state, TChange change);

        [[nodiscard]] std::shared_ptr<Node> Source() const override;

    private:
        std::weak_ptr<NodeBase<TChange>> m_source_;
        TChange m_change_;
    };

    template<typename TState, typename TChange>
    ActionBase<TState, TChange>::ActionBase(const std::shared_ptr<NodeBase<TChange>> &state, TChange change)
        : Action()
        , m_source_(state)
        , m_change_(change)
    {
    }

    template<typename TState, typename TChange>
    std::shared_ptr<Node> ActionBase<TState, TChange>::Source() const
    {
        return m_source_.lock();
    }
}

#endif //ACTION_BASE_H