#pragma once

#include "../game.h"
#include "../simulation/board.h"
#include "button.h"
#include "custom_but.h"
#include "gui.h"
#include "slider.h"
#include "widget.h"

namespace gui
{

Layer createMenuLayer(Game* game)
{
    Layer layer;
    layer.emplaceWidget<ButThatNeedsGame>(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM", game);
    layer.emplaceWidget<Button>(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS");
    return layer;
}

Layer createOptionLayer()
{
    Layer layer;
    // layer.emplaceWidget<ButThatNeedsBoard>(Vec2f{5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK", board);
    layer.emplaceWidget<Slider>(Vec2f{350.F, 400.F}, 100, "ziuum");
    layer.emplaceWidget<Slider>(Vec2f{450.F, 400.F}, 100, "ziuum");
    return layer;
}

} // namespace gui