#include "event.h"

#include <utility>
#include <string>

namespace bnw
{
Event::Event(Tag tag, bnw::Scenario gui_scenario, std::string  map, int sfx_vol, int music_vol)
    : m_tag{tag}, m_gui_scenario{gui_scenario}, m_map{std::move(map)}, m_sfx_vol{sfx_vol}, m_music_vol{music_vol}
{
}

Event::Tag Event::getTag()
{
    return m_tag;
}

bool Event::checkTag(Tag tag) const
{
    return (m_tag & tag) != 0;
}

} // namespace bnw