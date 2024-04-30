cmake_minimum_required(VERSION 3.5)

project(milkDistributionSystem_main LANGUAGES C)

add_executable(milkDistributionSystem_main main.c
    milkDistributionSystem_header.h
    milkDistributionSystem_implementation.cpp)

include(GNUInstallDirs)
install(TARGETS milkDistributionSystem_main
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
