#pragma once

namespace chs::game
{

class GameOptions
{
public:
    enum class Mode
    {
        PLAYER_VS_CPU,
        LOCAL_TWO_PLAYERS,
        LINK_TWO_PLAYERS
    };

    enum class PieceSize
    {
        SMALL,
        LARGE
    };

public:
    GameOptions(Mode mode, PieceSize pieceSize);

    Mode getMode() const;
    PieceSize getPieceSize() const;

    void setMode(Mode mode);
    void setPieceSize(PieceSize pieceSize);

private:
    Mode _mode;
    PieceSize _pieceSize;
};

} // namespace chs::game
