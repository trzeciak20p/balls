#include "optionsLoader.h"
#include <fstream>
#include <ostream>

// Options::Options() = default;

float Options::get(const std::string& key)
{
    return m_options[key];
}

void Options::load()
{
    std::ifstream file(m_default_path);
    if (!file.is_open())
    {
        generateDefaultFile();
    }
    std::string key;
    float       value;
    while (file >> key, file >> value)
    {
        m_options.emplace(key, value);
    }
    validate();
    display();
    file.close();
    save();
}

void Options::restoreDefault()
{
    m_options = m_default_options;
}

void Options::validate()
{
    for (const auto& [key, value] : m_default_options)
    {
        if (!m_options.contains(key))
        {
            fprintf(stderr, "BRAK: %s\r\n", key.c_str()); // debug
            m_options.emplace(key, value);
        }
    }
}

void Options::save()
{
    std::ofstream file(m_default_path);
    for (const auto& [key, value] : m_options)
    {
        file << key << " " << value << std::endl;
    }
    file.close();
}

void Options::generateDefaultFile()
{
    restoreDefault();
    save();
}

void Options::display() // debug
{
    fprintf(stderr, "OPTIONS:\r\n");
    for (const auto& [key, value] : m_options)
    {
        fprintf(stderr, "%s %f\r\n", key.c_str(), value);
    }
}