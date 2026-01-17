#ifndef MOVE_H
#define MOVE_H

#include <monte_carlo/models/action_base.h>
#include <monte_carlo/factories/tree_factory_interface.h>

#include <tic_tac_toe/models/game_state.h>
#include <tic_tac_toe/models/position.h>

namespace sophia::monte_carlo::tic_tac_toe::models
{
    using monte_carlo::models::Node;
    using monte_carlo::factories::TreeFactoryBase;

    /**
     * @class Move
     * @brief A move made on the Tic Tac Toe board.
     */
    class Move : public ActionBase<GameState, Position>
    {
    public:
        /**
         * @brief Creates an instance of a Move.
         * @param source A shared pointer to the source Node.
         * @param change The change being applied to the game.
         * @param factory A shared pointer to the Tree Factory.
         */
        explicit Move(const std::shared_ptr<NodeBase<GameState, Position>> &source, Position change,
                      std::shared_ptr<const TreeFactoryBase<GameState, Position>> factory);

        /**
         * @brief The Name of the move.
         * @return The Name of the move.
         */
        std::string Name() const override;

        /**
         * Generates the outcome of the move.
         */
        void Generate() override;
    };
}

#endif //MOVE_H