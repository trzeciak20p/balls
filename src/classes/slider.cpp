#include "slider.h"
#include "fontLoader.h"

Slider::Slider(float pos_x, float pos_y, float size, std::string name)
    : m_name{name}
{
    m_pos = {pos_x, pos_y};
    m_text.setPosition(m_pos);
    m_text.setString(m_name + ": " + std::to_string(m_value));
    m_text.setFont(bnw::font1);
    m_text.setCharacterSize(bnw::font1_size);
    m_text.setOrigin(m_text.getLocalBounds().width / 2, 0);
    m_body.setSize(sf::Vector2f(5.f, size));
    m_body.setOrigin(m_body.getSize().x / 2, 0);
    m_body.setPosition(pos_x, pos_y + m_text.getLocalBounds().height + 10);
    m_controler.setSize(sf::Vector2f(15.f, 5.f));
    m_controler.setOrigin(m_controler.getSize().x / 2, m_controler.getSize().y / 2);
    onUse(m_pos.y);
}

void Slider::setActive()
{
    this->onHover();
    Slider::m_active_slider = this;
}

Slider *Slider::getActive()
{
    return m_active_slider;
}

void Slider::clearActive()
{
    if (m_active_slider != nullptr)
    {
        Slider::m_active_slider->onHoverRelease();
        Slider::m_active_slider = nullptr;
    }
}

sf::Text Slider::getText()
{
    return m_text;
}

sf::RectangleShape Slider::getBody()
{
    return m_body;
}

sf::RectangleShape Slider::getControler()
{
    return m_controler;
}

bool Slider::checkHover(sf::Vector2i pos)
{
    int x_range = 5;
    if (pos.x >= m_body.getPosition().x - m_body.getOrigin().x - x_range &&
        pos.x <= m_body.getPosition().x - m_body.getOrigin().x + m_body.getSize().x + x_range &&
        pos.y >= m_body.getPosition().y && pos.y <= m_body.getPosition().y + m_body.getSize().y)
    {
        return true;
    }
    return false;
}

void Slider::onUse(float height)
{
    m_value = (height - m_body.getPosition().y) / m_body.getSize().y * 100;
    if (m_value <= 0)
    {
        m_value = 0;
        m_controler.setPosition(m_pos.x, m_body.getPosition().y);
    }
    else if (m_value >= 100)
    {
        m_value = 100;
        m_controler.setPosition(m_pos.x, m_body.getPosition().y + m_body.getSize().y);
    }
    else
    {
        m_controler.setPosition(m_pos.x, height);
    }

    m_text.setString(m_name + ": " + std::to_string(m_value));
}

void Slider::onHover()
{
    m_body.setFillColor(sf::Color::Cyan);
    m_text.setFillColor(sf::Color::Yellow);
}

void Slider::onHoverRelease()
{
    m_body.setFillColor(sf::Color::Black);
    m_text.setFillColor(sf::Color::White);
}