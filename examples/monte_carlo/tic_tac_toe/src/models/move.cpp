#include <models/move.h>

#include <utility>

using sophia::examples::tic_tac_toe::models::Move;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::factories::ITreeFactory;
using std::shared_ptr;

Move::Move(const shared_ptr<NodeBase<Board, Position>> &source, Position position,
    std::shared_ptr<const ITreeFactory<Board, Position>> factory)
: ActionBase(source, position, std::move(factory))
{
}

shared_ptr<Node> Move::Target() const
{
    if (auto sp = m_source_.lock())
    {
        const auto board = sp->GetState();
        auto newBoard = board.WithMove(m_change_);

    }

    return nullptr;
}

