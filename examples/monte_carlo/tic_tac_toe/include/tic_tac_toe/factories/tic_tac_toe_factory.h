#ifndef TIC_TAC_TOE_FACTORY_H
#define TIC_TAC_TOE_FACTORY_H

#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/position.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node_base.h>

namespace sophia::monte_carlo::tic_tac_toe::factories
{
    /**
     * @class TicTacToeFactory
     * @brief Creates simulation nodes and actions for a Tic Tac Toe game.
     *
     * Example:
     * @code
     * std::shared_ptr<models::const_player_ptr> you;
     * auto f = std::make_shared<TicTacToeFactory>(you);
     * auto node = f->CreateNode();
     * @endcode
     */
    class TicTacToeFactory : public monte_carlo::factories::TreeFactoryBase<models::GameState, models::Position>
    {
    public:
        /**
         * @brief Creates an instance of TicTacToeFactory
         * @param you a shared pointer to the player that owns the simulation.
         * @param logger the logger for the factory to use.
         */
        explicit TicTacToeFactory(::tic_tac_toe::const_player_ptr you, const logger_ptr& logger);
        ~TicTacToeFactory() override = default;

        /**
         * @brief Creates a new Node.
         * @param name the name of the new Node being created.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] node_ptr CreateNode(std::string name) const override;

        /**
         * @brief Creates a new Node.
         * @param name the name of the new Node being created.
         * @param game_state the state represented by the Node being created.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] node_ptr CreateNode(std::string name, models::GameState game_state) const override;

        /**
         * @brief Creates a new Action.
         * @param node the source node for the action being created.
         * @param change the change being applied to the source node.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] action_ptr CreateAction(node_base_ptr<models::GameState, models::Position> node, models::Position change) const override;

        /**
         * @brief Creates a new Strategy.
         * @returns a shared pointer to a Rollout Strategy.
         */
        [[nodiscard]] rollout_strategy_ptr CreateStrategy() const override;

    private:
        ::tic_tac_toe::const_player_ptr you_;
        logger_ptr m_logger_; // Member to hold the logger instance
    };
}

#endif //TIC_TAC_TOE_FACTORY_H
