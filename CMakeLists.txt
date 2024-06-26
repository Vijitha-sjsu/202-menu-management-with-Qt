cmake_minimum_required(VERSION 3.5)

project(menu-management VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Boost REQUIRED COMPONENTS random)  # Assuming you only need the random component for UUIDs
include_directories(${Boost_INCLUDE_DIRS})

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Enums.h
        Enums.cpp
        Menu.h
        Menu.cpp
        MenuItem.cpp
        MenuItem.h
        MenuItemAdapter.cpp
        MenuItemAdapter.h
        MenuListModel.h
        MenuListModel.cpp
        MenuListView.h
        MenuListView.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(menu-management
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        Enums.h
        MenuItem.h
        MenuItemAdapter.h
        Enums.cpp
        Menu.cpp
        MenuItem.cpp
        MenuItemAdapter.cpp
        Menu.h
        MenuListModel.h
        MenuListView.h
        MenuListView.cpp
        MenuListModel.cpp
        menuitems.csv
        MenuItemDelegate.h
        MenuItemDelegate.cpp
        MenuController.h
        MenuController.cpp
        MenuItemDialog.h
        MenuItemDialog.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET menu-management APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(menu-management SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(menu-management
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(menu-management PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(menu-management PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${Boost_LIBRARIES})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.menu-management)
endif()
set_target_properties(menu-management PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS menu-management
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(menu-management)
endif()
