#include "tip.h"

using namespace std;

void tip(int argc, char **argv) {
    system("curl -s -o tip.omn https://mirrors.yunduanjianzhan.cn/omn/tip.omn");
    ifstream file("tip.omn");

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    if (argc == 2) {
        string line;
        while (getline(file, line)) {
            line.erase(0, line.find_first_not_of("\n\r\f\v"));
            line.erase(line.find_last_not_of("\n\r\f\v") + 1);

            if (line.empty() || line[0] == ';' || line[0] == '#') {
                continue;
            }

            if (line[0] == '[' && line[line.size() - 1] == ']') {
                cout << line.substr(1, line.size() - 2) << endl;
            }
        }
    } else if (argc > 2) {
        string section = "[" + string(argv[2]) + "]";
        string filter = " ";
        if (argc > 3) filter = argv[3];

        string line;
        bool inUrlSection = false;

        while (getline(file, line)) {
            line.erase(0, line.find_first_not_of("\n\r\f\v"));
            line.erase(line.find_last_not_of("\n\r\f\v") + 1);

            if (line.empty() || line[0] == ';' || line[0] == '#') {
                continue;
            }

            if (line[0] == '[') {
                if (inUrlSection) {
                    break;
                }
                inUrlSection = (line == section);
            } else if (inUrlSection) {
                if (filter.empty() || line.find(filter) != string::npos) {
                    cout << line << endl;
                }
            }
        }
    }

    file.close();
    system("del tip.omn > nul");
}