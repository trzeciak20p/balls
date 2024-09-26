#pragma once

#include <map>
#include <string>

class OptionsLoader
{

public:
    // OptionsLoader();

    static void load();
    static void restoreDefault();
    static void save();

private:
    static void generateDefaultFile();
    static void validate();
    static void displayOptions(); // debug

    inline static std::string                  default_path = "./options.txt";
    inline static std::map<std::string, float> default_options{
        std::pair<std::string, float>("window_x", 700.F),
        std::pair<std::string, float>("window_y", 800.F),
        std::pair<std::string, float>("vol_music", 60.F),
        std::pair<std::string, float>("vol_sfx", 60.F),
    };
    inline static std::map<std::string, float> options{};
};
