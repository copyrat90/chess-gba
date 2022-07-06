#pragma once

#include "IScene.h"

#include "game/GameOptions.h"

namespace chs::scene
{

class Game final : public IScene
{
public:
    Game(const game::GameOptions& options);

    [[nodiscard]] bn::optional<SceneType> update() final;

private:
    game::GameOptions _options;
};

} // namespace chs::scene
