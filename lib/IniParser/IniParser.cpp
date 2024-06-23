#include "IniParser.h"

INIParser::INIParser(const std::string& filename) : filename(filename) {
    loadFile();
}

INIParser::~INIParser() {
    saveFile();
}

void INIParser::loadFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::ofstream newFile(filename);
        newFile.close();
        return;
    }

    std::string line, currentSection;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }
        if (line[0] == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.size() - 2);
        }
        else {
            std::istringstream lineStream(line);
            std::string key, value;
            if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
                data[currentSection][key] = value;
            }
        }
    }
    file.close();
}

void INIParser::saveFile() {
    std::ofstream file(filename);
    for (const auto& section : data) {
        file << "[" << section.first << "]\n";
        for (const auto& kvp : section.second) {
            file << kvp.first << "=" << kvp.second << "\n";
        }
    }
    file.close();
}

bool INIParser::sectionExists(const std::string& section) {
    return data.find(section) != data.end();
}

bool INIParser::keyExists(const std::string& section, const std::string& key) {
    if (!sectionExists(section)) return false;
    return data[section].find(key) != data[section].end();
}

int INIParser::getValue(const std::string& section, const std::string& key, std::string& value) {
    if (!sectionExists(section)) return 1;
    if (!keyExists(section, key)) return 2;
    value = data[section][key];
    return 0;
}

int INIParser::setValue(const std::string& section, const std::string& key, const std::string& value) {
    data[section][key] = value;
    return 0;
}

int INIParser::deleteValue(const std::string& section, const std::string& key) {
    if (!sectionExists(section)) return 1;
    if (!keyExists(section, key)) return 2;
    data[section].erase(key);
    return 0;
}

int INIParser::moveValue(const std::string& srcSection, const std::string& srcKey,
    const std::string& destSection, const std::string& destKey) {
    if (!sectionExists(srcSection)) return 1;
    if (!keyExists(srcSection, srcKey)) return 2;
    std::string value = data[srcSection][srcKey];
    data[destSection][destKey] = value;
    data[srcSection].erase(srcKey);
    return 0;
}
