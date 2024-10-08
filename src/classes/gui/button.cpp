#include "button.h"

namespace gui
{

Button::Button(Vec2f pos, Vec2f size, const std::string& name)
    : sf::RectangleShape{size}, m_text{name, bnw::font1, bnw::font1_size}
{
    setPosition(pos);
    m_text.setOrigin({m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2});
    m_text.setPosition(pos.x + size.x / 2, pos.y + size.y / 2);
    colorDefault();
}

void Button::setActive()
{
    colorActive();
    m_active_button = this;
}

Button* Button::getActive()
{
    return m_active_button;
}

void Button::clearActive()
{
    if (m_active_button == nullptr)
    {
        return;
    }

    m_active_button->colorDefault();
    m_active_button = nullptr;
}

bool Button::checkHover(Vec2f pos)
{
    return pos.x >= getPosition().x && pos.x <= getPosition().x + getSize().x && pos.y >= getPosition().y &&
           pos.y <= getPosition().y + getSize().y;
}

void Button::mousePress()
{
    onUse();
}

void Button::update(Vec2f pos)
{
    if (checkHover(pos))
    {
        setActive();
    }
}

void Button::draw(sf::RenderWindow* window)
{
    window->draw(*this);
    window->draw(m_text);
}

void Button::onUse()
{
}

void Button::colorActive()
{
    setFillColor(sf::Color::Cyan);
    m_text.setFillColor(sf::Color::Yellow);
}

void Button::colorDefault()
{
    setFillColor(sf::Color::Black);
    m_text.setFillColor(sf::Color::White);
}

} // namespace gui