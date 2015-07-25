cmake_minimum_required(VERSION 3.2)
project(UMJI_VG101_Project_FoR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src_gui/control.cpp
    src_gui/form_control.cpp
    src_gui/label.cpp
    main.cpp
    src_gui/screen.cpp
    src_gui/uiproperty.cpp
    src_gui/uibutton.cpp
    src_gui/textbox.cpp)

add_executable(UMJI_VG101_Project_FoR ${SOURCE_FILES}
                headers_gui/button.h
                headers_gui/form_control.h
                headers_gui/hw8_gui.h
                headers_gui/label.h
                headers_gui/screen.h
                headers_gui/uiproperty.h
                headers_gui/textbox.h
                src_school/College.cpp src_school/College.h
                src_school/hw8_college.h src_school/globaldef.h
                src_school/Database.h src_school/Database.cpp
                )