#include <tic_tac_toe/models/bot.h>
#include <tic_tac_toe/models/board.h>
#include <monte_carlo/tree_search_algorithm.h>
#include <tic_tac_toe/factories/tic_tac_toe_factory.h>
#include <cmath>

using sophia::monte_carlo::tic_tac_toe::models::Bot;
using sophia::monte_carlo::tic_tac_toe::models::Position;
using sophia::monte_carlo::tic_tac_toe::enums::Symbol;
using sophia::monte_carlo::MonteCarloTreeSearch;
using sophia::monte_carlo::models::Node;
using sophia::monte_carlo::models::Action;
using std::shared_ptr;

Bot::Bot(const Symbol symbol, const double difficulty, const logger_ptr& logger)
: Player(symbol)
, m_logger_(logger)
{
    if (m_logger_) m_logger_->info("Creating bot with difficulty: {}", difficulty);
    if (difficulty > 1 || difficulty < 0)
    {
        if (m_logger_) m_logger_->error("Difficulty must be a percentage between 0 and 1. Received: {}", difficulty);
        throw std::invalid_argument("Difficulty must be a percentage between 0 and 1.");
    }

    iterations_ = std::max(1, static_cast<int>(std::round(20000 * difficulty)));
    if (m_logger_) m_logger_->info("Bot will perform {} iterations per move.", iterations_);
}

std::shared_ptr<const Position> Bot::NextMove() const
{
    if (node_ == nullptr)
    {
        if (m_logger_) m_logger_->error("Bot's internal node is null. Cannot determine next move.");
        return nullptr;
    }

    if (m_logger_) m_logger_->info("Bot is thinking...");
    const shared_ptr<Action> best_action = MonteCarloTreeSearch::run(node_, iterations_, m_logger_);

    if (!best_action || !best_action->Target())
    {
        if (m_logger_) m_logger_->error("MCTS returned no valid action. Bot cannot move.");
        return nullptr;
    }

    const auto target_node = best_action->Target();
    const std::string move_name = target_node->Name();

    if (m_logger_) m_logger_->info("Bot chose move: {}", move_name);

    if (Position::IsValid(move_name))
    {
        auto coords = Position::ParseMove(move_name);
        if (m_logger_) m_logger_->debug("Parsed move '{}' to row {}, column {}", move_name, coords.first, coords.second);
        return std::make_shared<Position>(coords, m_player_symbol_);
    }

    if (m_logger_) m_logger_->error("MCTS returned an invalid move name: {}", move_name);
    return nullptr;
}

void Bot::Update(const std::string message)
{
    if (m_logger_) m_logger_->info("Bot received message: {}", message);

    // If the node is empty create a new one.
    if (node_ == nullptr)
    {
        if (m_logger_) m_logger_->info("Bot is initializing its root node.");
        const auto factory = std::make_shared<factories::TicTacToeFactory>(shared_from_this(), m_logger_);
        node_ = factory->CreateNode("root");
    }

    if (m_logger_) m_logger_->debug("Current tree node is '{}'.", node_->Name());

    // Select the action corresponding to the opponent's move.
    const auto action = node_->SelectAction(message);
    if (!action || !action->Target())
    {
        if (m_logger_) m_logger_->error("Bot could not find a valid action for move '{}'. Current node is '{}'.", message, node_->Name());
        // This can happen if the opponent makes a move that the bot didn't consider.
        // A more robust implementation might need to regenerate the tree or handle this gracefully.
        return;
    }
    
    node_ = action->Target();
    if (m_logger_) m_logger_->info("Bot tree updated. New current node is '{}'.", node_->Name());
}
