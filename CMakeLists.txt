cmake_minimum_required(VERSION 3.19)
project(a67_913AliceHincu)

set(CMAKE_CXX_STANDARD 14)

add_executable(a67_913AliceHincu main.cpp domain/Dog.cpp domain/Dog.h repository/RepositoryShelter.cpp repository/RepositoryShelter.h service/ServiceAdmin.cpp service/ServiceAdmin.h console/ConsoleUI.cpp console/ConsoleUI.h exceptions/Exception.cpp exceptions/Exception.h validation/Validator.cpp validation/Validator.h)