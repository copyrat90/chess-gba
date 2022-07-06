#pragma once

#include "bn_array.h"
#include "bn_fixed_point.h"

namespace chs::consts
{

inline constexpr bn::array<bn::array<bn::fixed_point, 8>, 8> RELATIVE_16x16_PIECE_POSITIONS = []() {
    bn::array<bn::array<bn::fixed_point, 8>, 8> result;
    bn::fixed_point leftTop{-64, -64};

    for (int y = 0; y < 8; ++y)
        for (int x = 0; x < 8; ++x)
            result[y][x] = {leftTop.x() + 16 * x, leftTop.y() + 16 * y};

    return result;
}();

inline constexpr bn::array<bn::array<bn::fixed_point, 8>, 8> RELATIVE_16x32_PIECE_POSITIONS = []() {
    bn::array<bn::array<bn::fixed_point, 8>, 8> result;
    bn::fixed_point leftTop{-64, -64};

    for (int y = 0; y < 8; ++y)
        for (int x = 0; x < 8; ++x)
            result[y][x] = {leftTop.x() + 16 * x, leftTop.y() + 16 * y};

    return result;
}();

} // namespace chs::consts
