#pragma once
#include <ratio>
namespace GraphicsConstants
{
    typedef std::ratio<9, 16> game_aspect_ratio;

    constexpr game_aspect_ratio aspect_ratio;

    constexpr auto aspect_ratio_gcf = 100;

    constexpr auto game_menu_height = 150;

    constexpr auto tile_square_dimension = 25;

    constexpr unsigned game_tiles_per_row = (aspect_ratio.den * aspect_ratio_gcf) / tile_square_dimension;

    constexpr unsigned game_tiles_per_column = (aspect_ratio.num * aspect_ratio_gcf - game_menu_height) / tile_square_dimension;

    constexpr auto getAbsoluteWidth()
    {
        return aspect_ratio_gcf * aspect_ratio.den;
    }

    constexpr auto getAbsoluteHeight()
    {
        return aspect_ratio_gcf * aspect_ratio.num;
    }
}