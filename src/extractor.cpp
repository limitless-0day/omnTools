#include "..\header\extractor.h"
#include "..\lib\ProgressBar\ProgressBar.h"

namespace fs = std::filesystem;

void ApkExtractor::extractResourcesFromApk(const std::string& apkPath, bool flattenStructure) {
    fs::path apkFilePath(apkPath);
    if (!fs::exists(apkFilePath)) {
        std::cerr << "APK file not found: " << apkPath << std::endl;
        return;
    }
	
	std::cout << "Initializing..." << std::endl;

    fs::path zipFilePath = apkFilePath;
    zipFilePath.replace_extension(".zip");
    fs::copy(apkFilePath, zipFilePath, fs::copy_options::overwrite_existing);

    fs::path extractedDir = apkFilePath.parent_path() / "apk_extracted";
    if (fs::exists(extractedDir)) {
        fs::remove_all(extractedDir);
    }
    fs::create_directory(extractedDir);

    std::string command = "tar -xf " + zipFilePath.string() + " -C " + extractedDir.string();
    std::system(command.c_str());
    
    std::string outname = apkFilePath.stem().string() + "_apkout";
    fs::path outputDir = apkFilePath.parent_path() / outname;
    if (fs::exists(outputDir)) {
        fs::remove_all(outputDir);
    }
    fs::create_directory(outputDir);

    extractMediaFiles(extractedDir, outputDir, flattenStructure);

    fs::remove(zipFilePath);
    fs::remove_all(extractedDir);

    std::cout << std::endl << "Resource extraction completed." << std::endl;
}

bool ApkExtractor::isImageFile(const std::string& extension) {
    static const std::vector<std::string> imageExtensions = {".jpg", ".jpeg", ".png", ".gif", ".bmp"};
    return std::find(imageExtensions.begin(), imageExtensions.end(), extension) != imageExtensions.end();
}

bool ApkExtractor::isVideoFile(const std::string& extension) {
    static const std::vector<std::string> videoExtensions = {".mp4", ".avi", ".mov", ".mkv", ".flv"};
    return std::find(videoExtensions.begin(), videoExtensions.end(), extension) != videoExtensions.end();
}

bool ApkExtractor::isAudioFile(const std::string& extension) {
    static const std::vector<std::string> audioExtensions = {".mp3", ".wav", ".ogg", ".flac"};
    return std::find(audioExtensions.begin(), audioExtensions.end(), extension) != audioExtensions.end();
}

void ApkExtractor::createDirectories(const fs::path& baseOutputDir, const fs::path& relativePath) {
    fs::path fullPath = baseOutputDir / relativePath;
    if (!fs::exists(fullPath)) {
        fs::create_directories(fullPath);
    }
}

void ApkExtractor::copyFile(const fs::path& filePath, const fs::path& outputDir, const fs::path& relativePath) {
    fs::path fullOutputPath = outputDir / relativePath;
    fs::copy(filePath, fullOutputPath, fs::copy_options::overwrite_existing);
}

void ApkExtractor::extractMediaFiles(const fs::path& extractedDir, const fs::path& outputDir, bool flattenStructure) {
    size_t allfile = 0, thefile = 0;
    for (const auto& entry : fs::recursive_directory_iterator(extractedDir)) allfile++;
    ProgressBar pb(0, int(allfile), '=');
    
    for (const auto& entry : fs::recursive_directory_iterator(extractedDir)) {
        pb.setCurrentValue(++thefile);
        pb.display();

        if (fs::is_regular_file(entry.path())) {
            std::string extension = entry.path().extension().string();
            fs::path fileName = entry.path().filename();
            fs::path relativePath = flattenStructure ? fileName : fs::relative(entry.path(), extractedDir);

            if (isImageFile(extension)) {
                createDirectories(outputDir / "images", flattenStructure ? "" : relativePath.parent_path());
                copyFile(entry.path(), outputDir / "images", relativePath);
            } else if (isVideoFile(extension)) {
                createDirectories(outputDir / "videos", flattenStructure ? "" : relativePath.parent_path());
                copyFile(entry.path(), outputDir / "videos", relativePath);
            } else if (isAudioFile(extension)) {
                createDirectories(outputDir / "audios", flattenStructure ? "" : relativePath.parent_path());
                copyFile(entry.path(), outputDir / "audios", relativePath);
            }
        }
    }
}
 


void extractor(int argc,char**argv){
	if(argc>2){
		if(argc==4&&std::string(argv[2])=="apk"&&fs::exists(argv[3]))ApkExtractor::extractResourcesFromApk(argv[3]);
		if(argc==5&&std::string(argv[2])=="apk"&&fs::exists(argv[3])&&std::string(argv[4])=="-r")ApkExtractor::extractResourcesFromApk(argv[3],true);
	}
}
