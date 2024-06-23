cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(omnTools VERSION 1.0.6.0)
add_executable(omnTools main.cpp src/install.cpp header/install.h src/clist.cpp header/clist.h src/stats.cpp header/stats.h lib/IniParser/IniParser.cpp lib/IniParser/IniParser.h lib/ProgressBar/ProgressBar.cpp lib/ProgressBar/ProgressBar.h src/extractor.cpp header/extractor.h)
configure_file(main.h.in main.h)

set(RESOURCE_FILES "omnTools.rc")

target_include_directories(omnTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
target_sources(omnTools PRIVATE ${RESOURCE_FILES})
