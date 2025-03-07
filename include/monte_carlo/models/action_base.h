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
        ActionBase(const std::shared_ptr<NodeBase<TState, TChange>> &state, TChange change,
            std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory);

        [[nodiscard]] std::shared_ptr<Node> Source() const override;

    protected:
        std::shared_ptr<const factories::ITreeFactory<TState, TChange>> m_factory_;
        std::weak_ptr<NodeBase<TState, TChange>> m_source_;
        std::shared_ptr<Node> m_target_;
        TChange m_change_;
    };

    template<typename TState, typename TChange>
    ActionBase<TState, TChange>::ActionBase(const std::shared_ptr<NodeBase<TState, TChange>> &state, TChange change,
        std::shared_ptr<const factories::ITreeFactory<TState, TChange>> factory)
        : Action()
        , m_source_(state)
        , m_change_(change)
        , m_factory_(factory)
    {
    }

    template<typename TState, typename TChange>
    std::shared_ptr<Node> ActionBase<TState, TChange>::Source() const
    {
        return m_source_.lock();
    }
}

#endif //ACTION_BASE_H