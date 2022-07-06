#pragma once

#include "bn_optional.h"
#include "bn_point.h"
#include "bn_sprite_ptr.h"

namespace bn
{
class camera_ptr;
}

namespace chs::game
{

class GameOptions;

class Piece
{
public:
    enum class Type
    {
        // !!! DO NOT CHANGE ORDER !!!
        // It is used as a sprite sheet index.
        PAWN,
        KNIGHT,
        ROOK,
        BISHOP,
        QUEEN,
        KING
    };

public:
    Piece(int idx, bool isWhite, Type type, bn::point boardPos, const bn::camera_ptr& camera,
          const GameOptions& gameOptions);

    int getIdx() const;

    bool isWhite() const;
    bool isAlive() const;

    void setAlive(bool isAlive);

    void allocSprite();
    void moveSprite(bn::point boardPos);

private:
    const int _idx;
    bool _isWhite;
    Type _type;
    bn::point _boardPos;
    const bn::camera_ptr& _camera;
    const GameOptions& _gameOptions;

    bn::optional<bn::sprite_ptr> _sprite;

    bool _isAlive;
};

} // namespace chs::game
