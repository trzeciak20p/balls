#pragma once

#include "button.h"
#include "entity.h"
#include "gui.h"
#include "slider.h"

namespace gui
{

class GuiMenu : public GUI
{
public:
    GuiMenu()
    {
        m_entities.emplace_back(std::make_unique<Button>(Button(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM")));
        m_entities.emplace_back(std::make_unique<Button>(Button(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS")));
    }
};

class GuiOptions : public GUI
{
public:
    GuiOptions()
    {
        m_entities.emplace_back(std::make_unique<Button>(Button({5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK")));
        m_entities.emplace_back(std::make_unique<Slider>(Slider({350.F, 400.F}, 100, "ziuum")));
        m_entities.emplace_back(std::make_unique<Slider>(Slider({450.F, 400.F}, 100, "ziuum")));
    }
};

} // namespace gui