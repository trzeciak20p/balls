#pragma once

#include <map>
#include <string>

class Options
{

public:
    enum Option{
        window_heigth,
        widnow_width,
        fps,
        vol_music,
        vol_sfx,
    };

    // Options();
    static float get(const std::string& key);
    static void  load();
    static void  restoreDefault();
    static void  save();

private:
    static void generateDefaultFile();
    static void validate();
    static void display(); // debug
    
    // TODO: zamienić string na enum?
    inline static std::string                  m_default_path = "./options.txt";
    inline static std::map<std::string, float> m_default_options{
        std::pair<std::string, float>("window_w", 800.F),
        std::pair<std::string, float>("window_h", 700.F),
        std::pair<std::string, float>("fps", 60.F),
        std::pair<std::string, float>("vol_music", 60.F),
        std::pair<std::string, float>("vol_sfx", 60.F),
    };
    inline static std::map<std::string, float> m_options{};
};
