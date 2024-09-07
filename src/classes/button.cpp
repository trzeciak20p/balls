#include "button.h"
#include "fontLoader.h"

Button::Button(int _pos_x, int _pos_y, int _size_x, int _size_y, std::string _name) : pos_x{_pos_x}, pos_y{_pos_y}
{
    text.setFont(bnw::font1);
    text.setString(_name);
    text.setCharacterSize(20);
    text.setPosition(_pos_x, _pos_y);
    text.setFillColor(sf::Color::Yellow);
    body.setPosition(_pos_x, _pos_y);
    body.setSize(sf::Vector2f(_size_x, _size_y));
    body.setFillColor(sf::Color::Cyan);
}

Button::~Button()
{
}

sf::Text Button::getText()
{
    return text;
};
sf::RectangleShape Button::getBody()
{
    return body;
};

bool Button::checkHover(sf::Vector2i pos)
{
    if (pos.x >= body.getPosition().x && pos.x <= body.getPosition().x + body.getSize().x &&
        pos.y >= body.getPosition().y && pos.y <= body.getPosition().y + body.getSize().y)
    {
        return true;
    }
    return false;
};
void Button::onClick()
{
    std::fprintf(stderr, "clicked  :D \r\n");
};
void Button::onHover()
{
    body.setFillColor(sf::Color::Black);
};