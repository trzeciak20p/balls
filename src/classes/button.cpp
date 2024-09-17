#include "button.h"
#include "fontLoader.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <string>

Button::Button(sf::Vector2f pos, sf::Vector2f size, const std::string &name)
    : sf::RectangleShape{size}, m_text{name, bnw::font1, bnw::font1_size}
{
    setPosition(pos);
    m_text.setOrigin({m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2});
    m_text.setPosition(pos.x + size.x / 2, pos.y + size.y / 2);
    onHoverRelease(); // sets default colors for text and body
}

void Button::setActive()
{
    onHover();
    m_active_button = this;
}

Button *Button::getActive()
{
    return m_active_button;
}

void Button::clearActive()
{
    if (m_active_button == nullptr)
    {
        return;
    }

    m_active_button->onHoverRelease();
    m_active_button = nullptr;
}

sf::Text Button::getText()
{
    return m_text;
}

bool Button::checkHover(sf::Vector2f pos)
{
    return pos.x >= getPosition().x && pos.x <= getPosition().x + getSize().x && pos.y >= getPosition().y &&
           pos.y <= getPosition().y + getSize().y;
}

void Button::onUse()
{
}

void Button::onHover()
{
    setFillColor(sf::Color::Cyan);
    m_text.setFillColor(sf::Color::Yellow);
}

void Button::onHoverRelease()
{
    setFillColor(sf::Color::Black);
    m_text.setFillColor(sf::Color::White);
}