#include "bn_assert.h"
#include "bn_core.h"
#include "bn_optional.h"
#include "bn_unique_ptr.h"

#include "game/GameOptions.h"
#include "scene/Game.h"

using namespace chs;

int main()
{

    bn::core::init();

    bn::unique_ptr<scene::IScene> scene;
    bn::optional<scene::SceneType> nextScene;

    // game scene test
    nextScene = scene::SceneType::GAME;

    game::GameOptions gameOptions(game::GameOptions::Mode::LOCAL_TWO_PLAYERS, game::GameOptions::PieceSize::SMALL);

    while (true)
    {
        if (scene)
            nextScene = scene->update();

        if (nextScene)
        {
            if (scene)
            {
                scene.reset();
            }
            else
            {
                switch (*nextScene)
                {
                    using SceneType = scene::SceneType;
                case SceneType::GAME:
                    scene.reset(new scene::Game(gameOptions));
                    break;
                default:
                    BN_ERROR("Unknown nextScene: ", (int)*nextScene);
                }
            }
        }

        bn::core::update();
    }
}
