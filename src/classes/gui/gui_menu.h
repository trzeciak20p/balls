#pragma once

#include "../simulation/board.h"
#include "../game.h"
#include "button.h"
#include "custom_but.h"
#include "widget.h"
#include "gui.h"
#include "slider.h"

namespace gui
{

class GuiMenu : public GUI
{
public:
    explicit GuiMenu(Game* game)
    {
        m_entities.emplace_back(std::make_unique<ButThatNeedsGame>(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM", game));
        m_entities.emplace_back(std::make_unique<Button>(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS"));
    }
};

class GuiOptions : public GUI
{
public:
    explicit GuiOptions(sim::Board* board)
    {
        m_entities.emplace_back(std::make_unique<ButThatNeedsBoard>(Vec2f{5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK", board));
        m_entities.emplace_back(std::make_unique<Slider>(Vec2f{350.F, 400.F}, 100, "ziuum"));
        m_entities.emplace_back(std::make_unique<Slider>(Vec2f{450.F, 400.F}, 100, "ziuum"));
    }
};

} // namespace gui