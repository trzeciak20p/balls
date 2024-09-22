#pragma once

#include "gui.h"
#include <string>

namespace bnw
{
class Event
{
public:
    enum Tag
    {
        gui          = 1,
        gui_load     = 1 << 1,
        map          = 1 << 2,
        map_load     = 1 << 3,
        sfx_change   = 1 << 4,
        music_change = 1 << 5
    };

    Event(Tag tag, GUI::Scenario gui_scenario, std::string map = "", int sfx_vol = 0, int music_vol = 0);

    Tag           getTag();
    bool          checkTag(Tag tag) const;
    GUI::Scenario m_gui_scenario;
    std::string   m_map;
    int           m_sfx_vol   = 0;
    int           m_music_vol = 0;

private:
    Tag m_tag;
};
} // namespace bnw