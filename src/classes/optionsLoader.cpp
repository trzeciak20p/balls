#include "optionsLoader.h"
#include <fstream>
#include <ostream>

// OptionsLoader::OptionsLoader() {};

void OptionsLoader::displayOptions() // debug
{
    fprintf(stderr, "OPTIONS:\r\n");
    for (const auto& [key, value] : options)
    {
        fprintf(stderr, "%s %f\r\n", key.c_str(), value);
    }
}

void OptionsLoader::load()
{
    std::ifstream file(default_path);
    if (!file.is_open())
    {
        generateDefaultFile();
    }
    std::string key;
    float       value;
    while (file >> key, file >> value)
    {
        options.emplace(key, value);
    }
    validate();
    displayOptions();
    file.close();
    save();
}

void OptionsLoader::restoreDefault()
{
    options = default_options;
}

void OptionsLoader::validate()
{
    for (const auto& [key, value] : default_options)
    {
        if (!options.contains(key))
        {
            fprintf(stderr, "BRAK: %s\r\n", key.c_str());
            options.emplace(key, value);
        }
    }
}

void OptionsLoader::save()
{
    std::ofstream file(default_path);
    for (const auto& [key, value] : options)
    {
        file << key << "\t\t" << value << std::endl;
    }
    file.close();
}

void OptionsLoader::generateDefaultFile()
{
    restoreDefault();
    save();
}