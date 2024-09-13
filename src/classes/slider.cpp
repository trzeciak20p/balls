#include "slider.h"

Slider::Slider(int *reference, std::string name)
{
    m_reference = reference;
    m_text.setString(name);
}
