#include "event.h"

namespace bnw
{
Event::Event(Tag tag, GUI::Scenario gui_scenario, std::string map = 0, int sfx_vol = 0, int music_vol = 0)
    : m_tag{tag}, m_gui_scenario{gui_scenario}, m_map{map}, m_sfx_vol{sfx_vol}, m_music_vol{music_vol}
{
}

Event::Tag Event::getTag()
{
    return m_tag;
}

bool Event::checkTag(Tag tag) const
{
    return m_tag & tag;
}

} // namespace bnw