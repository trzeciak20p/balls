#pragma once

#include "../vec2f.h"
#include "button.h"
#include "slider.h"
#include "widget.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

namespace gui
{

class Layer
{
public:
    enum Scenario : int8_t
    {
        menu,
        map_select,
        options,
        hud,
        pause,
        max_gui_scenario
    };

    static void mouseRelease();
    void        mousePress(Vec2f mouse);
    void        update(Vec2f mouse);
    void        draw(sf::RenderWindow& window);

    template <class T, class... U>
    void emplaceWidget(U&&... args);

private:
    bool m_visible{true};
    // Scenario m_scenario;

    std::vector<std::unique_ptr<Widget>> m_widgets;
};

template <class T, class... U>
void Layer::emplaceWidget(U&&... args)
{
    m_widgets.emplace_back(std::make_unique<T>(std::forward<U>(args)...));
}

} // namespace gui