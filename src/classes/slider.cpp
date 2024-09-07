#include "slider.h"

Slider::Slider(int *_reference, std::string _name) : reference{_reference}
{
    text.setString(_name);
}
