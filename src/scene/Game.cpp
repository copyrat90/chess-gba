#include "scene/Game.h"

using namespace chs::game;

namespace chs::scene
{

Game::Game(const GameOptions& options) : _options(options)
{
}

bn::optional<SceneType> Game::update()
{
    return bn::nullopt;
}

} // namespace chs::scene
