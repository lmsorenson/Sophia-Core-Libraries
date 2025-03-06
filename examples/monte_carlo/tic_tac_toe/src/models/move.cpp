#include <models/move.h>

using sophia::examples::tic_tac_toe::models::Move;
using sophia::monte_carlo::models::Action;
using sophia::monte_carlo::models::Node;
using std::shared_ptr;

Move::Move(const shared_ptr<Node> &source)
    : Action(source)
{
}

shared_ptr<Node> Move::Target() const
{
    return nullptr;
}

