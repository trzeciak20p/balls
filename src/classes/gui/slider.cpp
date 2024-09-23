#include "slider.h"
#include "../fontLoader.h"

namespace gui
{

Slider::Slider(Vec2f pos, float size, const std::string& name)
    : RectangleShape{{5.F, size}}, m_name{name}, m_text{name + ": ", bnw::font1, bnw::font1_size}
{
    setPosition(pos.x, pos.y + m_text.getLocalBounds().height + 10);
    setOrigin(getSize().x / 2, 0);

    m_text.setPosition(pos);
    m_text.setOrigin(m_text.getLocalBounds().width / 2, 0);

    m_controler.setSize({15.F, 5.F});
    m_controler.setOrigin(m_controler.getSize().x / 2, m_controler.getSize().y / 2);

    onUse(pos.y);
    colorDefault();
}

void Slider::setActive()
{
    colorActive();
    Slider::m_active_slider = this;
}

Slider* Slider::getActive()
{
    return m_active_slider;
}

void Slider::clearActive()
{
    if (m_active_slider == nullptr)
    {
        return;
    }

    Slider::m_active_slider->colorDefault();
    Slider::m_active_slider = nullptr;
}

bool Slider::checkHover(Vec2f pos)
{
    const int x_range = 5;
    return pos.x >= getPosition().x - getOrigin().x - x_range &&
           pos.x <= getPosition().x - getOrigin().x + getSize().x + x_range && pos.y >= getPosition().y &&
           pos.y <= getPosition().y + getSize().y;
}

void Slider::mousePress()
{
    setActive();
}

void Slider::update(Vec2f pos)
{
    if (Slider::getActive() != nullptr)
    {
        Slider::getActive()->onUse(pos.y);
    }
}

void Slider::draw(sf::RenderWindow* window)
{
    window->draw(*this);
    window->draw(m_text);
    window->draw(m_controler);
}

void Slider::onUse(float height)
{
    m_value = (height - getPosition().y) / getSize().y * 100;
    if (m_value <= 0)
    {
        m_value = 0;
        m_controler.setPosition(getPosition());
    }
    else if (m_value >= 100)
    {
        m_value = 100;
        m_controler.setPosition(getPosition().x, getPosition().y + getSize().y);
    }
    else
    {
        m_controler.setPosition(getPosition().x, height);
    }

    m_text.setString(m_name + ": " + std::to_string(m_value));
}

void Slider::colorActive()
{
    setFillColor(sf::Color::Cyan);
    m_text.setFillColor(sf::Color::Yellow);
}

void Slider::colorDefault()
{
    setFillColor(sf::Color::Black);
    m_text.setFillColor(sf::Color::White);
}

} // namespace gui