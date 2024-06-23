#ifndef INIPARSER_H
#define INIPARSER_H

#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

class INIParser {
public:
    INIParser(const std::string& filename);
    ~INIParser();
    int getValue(const std::string& section, const std::string& key, std::string& value);
    int setValue(const std::string& section, const std::string& key, const std::string& value);
    int deleteValue(const std::string& section, const std::string& key);
    int moveValue(const std::string& srcSection, const std::string& srcKey,
        const std::string& destSection, const std::string& destKey);

private:
    void loadFile();
    void saveFile();
    bool sectionExists(const std::string& section);
    bool keyExists(const std::string& section, const std::string& key);

    std::string filename;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;
};

#endif // INIPARSER_H