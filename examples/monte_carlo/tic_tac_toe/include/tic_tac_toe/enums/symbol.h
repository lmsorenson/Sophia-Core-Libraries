#ifndef TILE_STATE_H
#define TILE_STATE_H

#include <string>

namespace sophia::monte_carlo::tic_tac_toe::enums
{
    /**
     * @class Symbol
     * @brief A Tic Tac Toe Symbol is an X, an O, or an empty space.
     */
    enum class Symbol
    {
        None = 0, ///< No Symbol has been placed.
        X, ///< The first player in Tic Tac Toe places an X.
        O ///< The second player in Tic Tac Toe places an O.
    };

    /**
     * @brief Converts a symbol to a string.
     * @param state The Symbol to be converted to a string.
     * @return Returns a string version of the Symbol
     */
    inline std::string TileStateToString(const Symbol state)
    {
        switch (state)
        {
            case Symbol::X: return "X";
            case Symbol::O: return "O";
            default:
            case Symbol::None: return " ";
        }
    }
}

#endif //TILE_STATE_H
