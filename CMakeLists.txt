cmake_minimum_required(VERSION 3.10)
project(omn VERSION 1.0.0.0)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

<<<<<<< HEAD



add_executable(omn bootstrap.cpp src/Install/install.cpp lib/install.h src/Bash/tip.cpp lib/tip.h src/Install/mas.cpp lib/mas.h src/Utils/statistics.cpp lib/statistics.h)
=======
project(omnTools VERSION 1.0.4.0)
add_executable(omnTools main.cpp src/install.cpp header/install.h src/tip.cpp header/tip.h src/mas.cpp header/mas.h src/lang.cpp header/lang.h)
>>>>>>> 7206842962c04da07ef98d6f24454e12fe252f6e
configure_file(main.h.in main.h)

set(RESOURCE_FILES "omnTools.rc")

target_include_directories(omn PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


target_sources(omn PRIVATE ${RESOURCE_FILES})




