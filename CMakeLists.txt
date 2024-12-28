cmake_minimum_required(VERSION 3.16)

project(FREEPBX_MySQLTables VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Core)

find_package(Libssh REQUIRED)
find_package( Wt REQUIRED )

# define source and destination folder
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/docroot")
set(DESTINATION_DIR "${CMAKE_BINARY_DIR}/docroot")

# find all files
file(GLOB ALL_FILES "${SOURCE_DIR}/*")

# # make destination folder
# file(MAKE_DIRECTORY "${DESTINATION_DIR}")

# define unwanted extensions (example, .log ve .tmp)
set(EXCLUDED_EXTENSIONS ".TMP" ".tmp")

# copy files via by filtering extensions
foreach(file ${ALL_FILES})
    get_filename_component(extension ${file} EXT) # take extensions
    string(TOLOWER "${extension}" extension)      # extension to lower

    # check file extension
    set(exclude_file OFF)
    foreach(excluded_ext ${EXCLUDED_EXTENSIONS})
        if ("${extension}" STREQUAL "${excluded_ext}")
            set(exclude_file ON)
            break()
        endif()
    endforeach()

    # copy file if extensions if not exist in list EXCLUDED_EXTENSIONS
    if (NOT exclude_file)
        message(STATUS "INFO. ${file} ")
        if (EXISTS "${file}")
            file(COPY ${file} DESTINATION "${DESTINATION_DIR}")
        else()
                message(STATUS "file not exist: ${file}")
        endif()
    endif()
endforeach()



# file(COPY           ${CMAKE_SOURCE_DIR}/docroot
#     DESTINATION    ${CMAKE_BINARY_DIR}/)

file(COPY           ${CMAKE_SOURCE_DIR}/approot
    DESTINATION    ${CMAKE_BINARY_DIR}/)


set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/lib/cmake/bsoncxx-3.10.2" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/lib/cmake/mongocxx-3.10.2" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/lib/cmake/mongoc-1.0" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/lib/cmake/bson-1.0" ${CMAKE_PREFIX_PATH})


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/include/bsoncxx/v_noabi)
include_directories(${CMAKE_SOURCE_DIR}/mongo-cxx-r.3.10.2-mingw-13.1.0-win64/Release/include/mongocxx/v_noabi)

add_subdirectory(MongoCoreItem)
include_directories(${CMAKE_SOURCE_DIR})


add_library(Bootstrap
    Web/Bootstrap/Bootstrap5ThemeKeys.h
    Web/Bootstrap/Bootstrap5ThemeKeys.cpp
    Web/Bootstrap/inlinestyle.h
    Web/Bootstrap/NavTabs.h
)


add_library(MongoCore
    MongoCore/db.h
    MongoCore/db.cpp
    MongoCore/listitem.h
    MongoCore/listitem.cpp
    MongoCore/mongoheaders.h
    MongoCore/MongoCore.h MongoCore/MongoCore.cpp
    MongoCore/ListItemNoDB.h
)

target_link_libraries(MongoCore PUBLIC Qt${QT_VERSION_MAJOR}::Core MongoCoreItem mongo::mongocxx_shared Bootstrap)


set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui

        Web/CustomWidget/PushButton.h Web/CustomWidget/PushButton.cpp
        Web/CustomWidget/ComboBox.h Web/CustomWidget/ComboBox.cpp
        Web/CustomWidget/Panel.h Web/CustomWidget/Panel.cpp
        Web/CustomWidget/ContainerWidget.h Web/CustomWidget/ContainerWidget.cpp
        Web/CustomWidget/Theme.h Web/CustomWidget/Theme.cpp
        Web/CustomWidget/LineEdit.h Web/CustomWidget/LineEdit.cpp
        Web/CustomWidget/Text.h Web/CustomWidget/Text.cpp
        Web/CustomWidget/FileUploaderWidget.h Web/CustomWidget/FileUploaderWidget.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FREEPBX_MySQLTables
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FREEPBX_MySQLTables APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FREEPBX_MySQLTables SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FREEPBX_MySQLTables
            ${PROJECT_SOURCES}
            SQLToNoSQL.h SQLToNoSQL.cpp
            CDRTableModel.h CDRTableModel.cpp
            CDRTableItem.h CDRTableItem.cpp
            SystemItem.h SystemItem.cpp
            WebServer.h WebServer.cpp
            Web/MainApplication.h Web/MainApplication.cpp
            CDRTableManager.h CDRTableManager.cpp
            Web/CDRTableManagerContainer.h Web/CDRTableManagerContainer.cpp
            Web/CSSGenerator.h
            Web/LoginPanel.h Web/LoginPanel.cpp
            Web/User.h Web/User.cpp
            Web/UserManager.h Web/UserManager.cpp
        )
    endif()
endif()

target_link_libraries(FREEPBX_MySQLTables PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql ssh MongoCore wt wthttp)
target_compile_definitions(FREEPBX_MySQLTables PRIVATE QT_NO_KEYWORDS)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.FREEPBX_MySQLTables)
endif()
set_target_properties(FREEPBX_MySQLTables PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS FREEPBX_MySQLTables
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FREEPBX_MySQLTables)
endif()
