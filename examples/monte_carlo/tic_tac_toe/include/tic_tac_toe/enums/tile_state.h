#ifndef TILE_STATE_H
#define TILE_STATE_H

#include <string>

enum class TileState
{
    X,
    O,
    E
};

inline std::string TileStateToString(TileState state)
{
    switch (state)
    {
        case TileState::X: return "X";
        case TileState::O: return "O";
        default:
        case TileState::E: return " ";
    }
}

#endif //TILE_STATE_H
