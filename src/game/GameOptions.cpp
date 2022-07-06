#include "game/GameOptions.h"

namespace chs::game
{

GameOptions::GameOptions(Mode mode, PieceSize pieceSize) : _mode(mode), _pieceSize(pieceSize)
{
}

GameOptions::Mode GameOptions::getMode() const
{
    return _mode;
}

GameOptions::PieceSize GameOptions::getPieceSize() const
{
    return _pieceSize;
}

void GameOptions::setMode(Mode mode)
{
    _mode = mode;
}

void GameOptions::setPieceSize(PieceSize pieceSize)
{
    _pieceSize = pieceSize;
}

} // namespace chs::game
