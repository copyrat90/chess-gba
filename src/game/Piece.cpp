#include "game/Piece.h"

#include "bn_assert.h"
#include "bn_camera_ptr.h"
#include "bn_log.h"
#include "bn_sprite_item.h"

#include "constants.h"
#include "game/GameOptions.h"

#include "bn_sprite_items_spr_black_pieces_16x16.h"
#include "bn_sprite_items_spr_black_pieces_16x32.h"
#include "bn_sprite_items_spr_white_pieces_16x16.h"
#include "bn_sprite_items_spr_white_pieces_16x32.h"

namespace chs::game
{

Piece::Piece(int idx, bool isWhite, Type type, bn::point boardPos, const bn::camera_ptr& camera,
             const GameOptions& gameOptions)
    : _idx(idx), _isWhite(isWhite), _type(type), _boardPos(boardPos), _camera(camera), _gameOptions(gameOptions),
      _isAlive(true)
{
    allocSprite();
}

int Piece::getIdx() const
{
    return _idx;
}

bool Piece::isWhite() const
{
    return _isWhite;
}

bool Piece::isAlive() const
{
    return _isAlive;
}

void Piece::setAlive(bool isAlive)
{
    _isAlive = isAlive;
    if (!isAlive)
        _sprite.reset();
}

void Piece::allocSprite()
{
    if (!_isAlive)
    {
        BN_LOG("Tried to alloc dead piece sprite (y=", _boardPos.y(), ", x=", _boardPos.x(), ")");
        return;
    }

    const bn::sprite_item& spriteItem =
        (_gameOptions.getPieceSize() == GameOptions::PieceSize::SMALL
             ? (_isWhite ? bn::sprite_items::spr_white_pieces_16x16 : bn::sprite_items::spr_black_pieces_16x16)
             : (_isWhite ? bn::sprite_items::spr_white_pieces_16x32 : bn::sprite_items::spr_black_pieces_16x32));

    const auto& RELATIVE_POSITIONS =
        (_gameOptions.getPieceSize() == GameOptions::PieceSize::SMALL ? consts::RELATIVE_16x16_PIECE_POSITIONS
                                                                      : consts::RELATIVE_16x32_PIECE_POSITIONS);
    const bn::fixed_point& position = RELATIVE_POSITIONS[_boardPos.y()][_boardPos.x()];

    _sprite = bn::sprite_ptr::create(position, spriteItem, (int)_type);
    _sprite->set_camera(_camera);
}

void Piece::moveSprite(bn::point boardPos)
{
    if (!_isAlive)
    {
        BN_LOG("Tried to move dead piece sprite (y=", _boardPos.y(), ", x=", _boardPos.x(), ")");
        return;
    }

    BN_ASSERT(0 <= boardPos.x() && boardPos.x() < 8 && 0 <= boardPos.y() && boardPos.y() < 8,
              "move piece sprite OOB (y=", boardPos.y(), ", x=", boardPos.x(), ")");

    const auto& RELATIVE_POSITIONS =
        (_gameOptions.getPieceSize() == GameOptions::PieceSize::SMALL ? consts::RELATIVE_16x16_PIECE_POSITIONS
                                                                      : consts::RELATIVE_16x32_PIECE_POSITIONS);
    const bn::fixed_point& position = RELATIVE_POSITIONS[_boardPos.y()][_boardPos.x()];

    _sprite->set_position(position);
}

} // namespace chs::game
