#ifndef TILE_STATE_H
#define TILE_STATE_H

#include <string>

/**
 * @class Symbol
 * @brief A Tic Tac Toe Symbol is an X, an O, or an empty space.
 */
enum class Symbol
{
    None = 0, ///< No Symbol has been placed.
    X, ///< First player in Tic Tac Toe an X.
    O ///< The Second player in Tic Tac Toe places an O.
};

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

#endif //TILE_STATE_H
