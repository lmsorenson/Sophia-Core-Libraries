#ifndef TILE_STATE_H
#define TILE_STATE_H

#include <string>

enum class Symbol
{
    None = 0,
    X,
    O
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
