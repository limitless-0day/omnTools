#include "lang.h"

using namespace std;
namespace fs = filesystem;

struct LanguageInfo {
    vector<string> extensions;
    vector<string> filenames;
};

unordered_map<string, LanguageInfo> languageDefinitions = {
    {"C", { {".c"}, {} }},
    {"C++", { {".cpp",".hpp",".cc",".cxx",".ipp","hxx"}, {} }},
    {"C#", { {".cs"}, {} }},
    {"Objective-C", { {".m"}, {} }},
    {"Python", { {".py"}, {} }},
    {"Java", { {".java"}, {} }},
    {"Go", { {".go",".mod",".sum"}, {} }},
    {"Ruby", { {".rb"}, {} }},
    {"Perl", { {".pl",".pm",".pl6",".pod"}, {} }},
    {"Lua", { {".lua"}, {} }},
    {"Rust", { {".rs",".toml"}, {} }},
    {"Scala", { {".sc",".scala"}, {} }},
    {"VBScript", { {".vbs"}, {} }},
    {"R", { {".r",".rmd"}, {} }},
    {"Juila", { {".jl"}, {} }},
    {"Visual Basic", { {".vb",".vbp"}, {} }},
	
    {"HTML", { {".html", ".htm"}, {} }},
    {"CSS", { {".css"}, {} }},
    {"JavaScript", { {".js"}, {} }},
    {"JSON", { {".json"}, {} }},
    {"PHP", { {".php"}, {} }},
    {"JSP", { {".jsp"}, {} }},
    {"ASP", { {".asp"}, {} }},
    {"SQL", { {".sql",".ddl",".dml",".dcl"}, {} }},
    {"XML", { {".xml", ".xsd",".svg",".xhtml",".xslt"}, {} }},
	
    {"WindowsCommand", { {".cmd",".bat"}, {} }},
    {"Powershell", { {".ps1"}, {} }},
    {"LinuxShell", { {".sh"}, {} }},
	
    {"CMake", { {}, {"CMakeLists.txt"} }},
	
    {"C/C++", { {".h"}, {} }},
};

struct LanguageStats {
    int fileCount = 0;
    size_t totalChars = 0;
};

string getFileContent(const fs::path& filePath) {
    ifstream file(filePath, ios::in | ios::binary);
    if (!file) {
        cerr << "Failed to open file: " << filePath << endl;
        return "";
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

string determineLanguageForHeader(const fs::path& headerFilePath) {
    string baseName = headerFilePath.stem().string();
    fs::path directory = headerFilePath.parent_path();
    bool hasCppFile = fs::exists(directory / (baseName + ".cpp"));
    bool hasCFile = fs::exists(directory / (baseName + ".c"));

    if (hasCppFile && !hasCFile) {
        return "C++";
    } else if (!hasCppFile && hasCFile) {
        return "C";
    } else {
        return "Unknown";
    }
}
void lang(int argc,char **argv) {
	fs::path directory = fs::current_path();
	if(argc>2&&fs::exists(argv[2]))directory=argv[2];
    unordered_map<string, LanguageStats> stats;
    size_t totalChars = 0;

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            string extension = entry.path().extension().string();
            string filename = entry.path().filename().string();
            string language = "Unknown";
            
            for (const auto& [lang, info] : languageDefinitions) {
                if (find(info.extensions.begin(), info.extensions.end(), extension) != info.extensions.end() ||
                    find(info.filenames.begin(), info.filenames.end(), filename) != info.filenames.end()) {
                    if (extension == ".h" && lang == "C/C++") {
                        language = determineLanguageForHeader(entry.path());
                    } else {
                        language = lang;
                    }
                    break;
                }
            }
            
            if (language != "Unknown") {
                string content = getFileContent(entry.path());
                size_t charCount = content.size();

                stats[language].fileCount++;
                stats[language].totalChars += charCount;
                totalChars += charCount;
            }
        }
    }
	
    cout << setw(15) << "Language" 
              << setw(15) << "File Count" 
              << setw(20) << "Total Characters" 
              << setw(10) << "Percentage" 
              << endl;

    for (const auto& [language, stat] : stats) {
        double percentage = (totalChars > 0) ? (static_cast<double>(stat.totalChars) / totalChars * 100.0) : 0.0;
        cout << setw(15) << language 
                  << setw(15) << stat.fileCount 
                  << setw(20) << stat.totalChars 
                  << setw(9)  << setprecision(2) << fixed << percentage << "%" 
                  << endl;
    }
}


