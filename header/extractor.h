#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

class ApkExtractor {
public:
    static void extractResourcesFromApk(const std::string& apkPath, bool flattenStructure = false);

private:
    static bool isImageFile(const std::string& extension);
    static bool isVideoFile(const std::string& extension);
    static bool isAudioFile(const std::string& extension);
    static void createDirectories(const std::filesystem::path& baseOutputDir, const std::filesystem::path& relativePath);
    static void copyFile(const std::filesystem::path& filePath, const std::filesystem::path& outputDir, const std::filesystem::path& relativePath);
    static void extractMediaFiles(const std::filesystem::path& extractedDir, const std::filesystem::path& outputDir, bool flattenStructure);
};

void extractor(int argc, char** argv);
#endif // EXTRACTOR_H
