#pragma once

#include "bn_optional.h"

#include "SceneType.h"

namespace chs::scene
{

class IScene
{
public:
    virtual ~IScene() = default;

    [[nodiscard]] virtual bn::optional<SceneType> update() = 0;
};

} // namespace chs::scene
