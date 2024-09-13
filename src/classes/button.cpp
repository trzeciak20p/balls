#include "button.h"
#include "fontLoader.h"

Button::Button(int pos_x, int pos_y, int size_x, int size_y, std::string name)
{
    m_pos = {pos_x, pos_y};
    m_text.setFont(bnw::font1);
    m_text.setString(name);
    m_text.setCharacterSize(20);
    m_text.setOrigin({m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2});
    m_text.setPosition(m_pos.x + size_x / 2, m_pos.y + size_y / 2);
    m_body.setPosition(m_pos.x, m_pos.y);
    m_body.setSize(sf::Vector2f(size_x, size_y));
    this->onHoverRelease(); // sets default colors for text and body
}

void Button::setActive()
{
    this->onHover();
    Button::m_active_button = this;
};
Button *Button::getActive()
{
    return m_active_button;
};
void Button::clearActive()
{
    if (m_active_button != nullptr)
    {
        Button::m_active_button->onHoverRelease();
        Button::m_active_button = nullptr;
    }
};

sf::Text Button::getText()
{
    return m_text;
};
sf::RectangleShape Button::getBody()
{
    return m_body;
};

bool Button::checkHover(sf::Vector2i pos)
{
    if (pos.x >= m_body.getPosition().x && pos.x <= m_body.getPosition().x + m_body.getSize().x &&
        pos.y >= m_body.getPosition().y && pos.y <= m_body.getPosition().y + m_body.getSize().y)
    {
        return true;
    }
    return false;
};
void Button::onUse()
{
    std::fprintf(stderr, "clicked  :D \r\n");
};
void Button::onHover()
{
    m_body.setFillColor(sf::Color::Cyan);
    m_text.setFillColor(sf::Color::Yellow);
};
void Button::onHoverRelease()
{
    m_body.setFillColor(sf::Color::Black);
    m_text.setFillColor(sf::Color::White);
};