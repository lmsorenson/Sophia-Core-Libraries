#ifndef TIC_TAC_TOE_FACTORY_H
#define TIC_TAC_TOE_FACTORY_H

#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/position.h>
#include <monte_carlo/factories/tree_factory_interface.h>
#include <monte_carlo/models/node_base.h>

namespace sophia::examples::tic_tac_toe::factories
{
    class TicTacToeFactory : public monte_carlo::factories::TreeFactoryBase<models::GameState, models::Position>
    {
    public:
        explicit TicTacToeFactory(models::const_player_ptr you);
        ~TicTacToeFactory() override = default;

        /**
         * Creates a new Node.
         * @param name the name of the new Node being created.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] node_ptr CreateNode(std::string name) const override;

        /**
         * Creates a new Node.
         * @param name the name of the new Node being created.
         * @param game_state the state represented by the Node being created.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] node_ptr CreateNode(std::string name, models::GameState game_state) const override;

        /**
         * Creates a new Action.
         * @param node the source node for the action being created.
         * @param change the change being applied to the source node.
         * @returns a shared pointer to a Node
         */
        [[nodiscard]] action_ptr CreateAction(std::shared_ptr<NodeBase<models::GameState, models::Position>> node, models::Position change) const override;

        /**
         * Creates a new Strategy.
         * @returns a shared pointer to a Rollout Strategy.
         */
        [[nodiscard]] rollout_strategy_ptr CreateStrategy() const override;

    private:
        models::const_player_ptr you_;
    };
}

#endif //TIC_TAC_TOE_FACTORY_H
