#include <models/move.h>

#include <utility>
#include <monte_carlo/factories/tree_factory_interface.h>

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

void Move::Generate()
{
    if (const auto source = m_source_.lock())
    {
        const auto board = source->GetState();
        const auto newBoard = board.WithMove(m_change_);
        m_target_ = m_factory_->CreateNode("name", *newBoard);
    }

}

shared_ptr<Node> Move::Target() const
{
    return m_target_;
}

