#include <tic_tac_toe/models/move.h>

#include <utility>
#include <monte_carlo/factories/tree_factory_interface.h>

using sophia::examples::tic_tac_toe::models::Move;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::factories::TreeFactoryBase;
using std::shared_ptr;

Move::Move(const node_base_ptr &source, const Position change, const_factory_ptr factory)
: ActionBase(source, change, std::move(factory))
{

}

void Move::Generate()
{
    if (const auto source = m_source_.lock())
    {
        const auto board = source->GetState();
        const auto newBoard = board.WithMove(m_change_);

        const std::string name = m_change_.Name();

        m_target_ = m_factory_->CreateNode(name, *newBoard);
    }
}

