cmake_minimum_required(VERSION 3.2)
project(UMJI_VG101_Project_FoR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src_gui/control.cpp
    src_gui/form_control.cpp
    src_gui/label.cpp
    main.cpp
    src_gui/Screen.cpp
    src_gui/ui_properties.cpp
    src_gui/uibutton.cpp)

add_executable(UMJI_VG101_Project_FoR ${SOURCE_FILES}
                headers/button.h
                headers/button_simple.h
                headers/form.h
                headers/header_file.h
                headers/hw8.h
                headers/label.h
                headers/screen.h
                headers/uiproperty.h)