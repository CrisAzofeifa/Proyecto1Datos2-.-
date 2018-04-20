cmake_minimum_required(VERSION 3.0)
set(TARGET_NAME Proyecto1Daaatos2)

project(${TARGET_NAME})

###################################################

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#find_package( Threads REQUIRED )

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})
add_executable(main main.cpp)
target_link_libraries(main ${JSONCPP_LIBRARIES})

######################

# Check the build type and ask the user to set concrete one
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    message(WARNING "CMAKE_BUILD_TYPE is not set, forcing to RelWithDebInfo")
endif()

# Set compiler flags
if(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g3")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os")
endif()

find_package(Qt5Widgets CONFIG
        PATHS /home/cris/Qt5.7.0/5.7/gcc_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH REQUIRED)


find_package(Qt5Network CONFIG
        PATHS /home/cris/Qt5.7.0/5.7/gcc_64/lib/cmake/Qt5Network
        NO_DEFAULT_PATH REQUIRED)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Source files
set(SOURCES
        main.cpp
        forms/ide_cfactorial.cpp
        Client.cpp Client.h
        Expresion.h
        List.h
        ui_ide_cfactorial.h)

# User interface files
set(FORMS
        forms/ide_cfactorial.ui
        )

# Shared libraries
set(LIBRARIES
        Qt5::Widgets
        Qt5::Network
        )

# Generate additional sources with MOC and UIC
qt5_wrap_ui(UIC_SOURCES ${FORMS})
qt5_add_resources(RCC_SOURCES ${RESOURCES})

# Set target
add_executable(${TARGET_NAME} ${SOURCES} ${HEADERS} ${UIC_SOURCES} ${RCC_SOURCES})

# Link with libraries
target_link_libraries(${TARGET_NAME} ${LIBRARIES})

# Installation
install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION bin)
install(FILES ${TARGET_NAME}.desktop DESTINATION share/applications)
