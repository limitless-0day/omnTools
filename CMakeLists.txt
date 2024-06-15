cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(omnTools VERSION 1.0.2.0)
add_executable(omnTools main.cpp lib/model/model.cpp lib/model/model.h lib/tip/tip.cpp lib/tip/tip.h lib/mas/mas.cpp lib/mas/mas.h lib/lang/lang.cpp lib/lang/lang.h)
configure_file(main.h.in main.h)

set(RESOURCE_FILES "omnTools.rc")

target_include_directories(omnTools PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
target_sources(omnTools PRIVATE ${RESOURCE_FILES})
