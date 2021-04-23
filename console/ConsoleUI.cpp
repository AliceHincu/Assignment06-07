//
// Created by Sakura on 4/11/2021.
//

#include <limits>
#include "ConsoleUI.h"


ConsoleUI::ConsoleUI(ServiceAdmin& service): _unicorns_exist{true}, _service{service} {}


std::string ConsoleUI::readString() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}


void ConsoleUI::run() {
    this->_service.readFromShelterFile();
    while (this->_unicorns_exist){
        std::cout << "Choose a mode(administrator/user): ";
        std::string mode;
        mode = readString();
        std::cout << mode;
        if (mode == "administrator" or mode == "admin") {
            this->runAdministrator();
            continue;
        }
        if (mode == "user") {
            //this->runUser();
            continue;
        }
        std::cout << "Wrong mode!";
    }

}


void ConsoleUI::printMenuAdministrator() {
    std::string menu = "|-----------------------------------|\n"
                       "|   ~ Keep calm and adopt a pet ~   |\n"
                       "|-----------------------------------|\n"
                       "|         1. Add a new dog          |\n"
                       "|         2. Delete a dog           |\n"
                       "|         3. Update a dog           |\n"
                       "|         4. See all dogs           |\n"
                       "|         0. Exit                   |\n"
                       "|-----------------------------------|\n";
    std::cout << menu;

}

void ConsoleUI::printMenuUser() {
    std::string menu = "|-----------------------------------|\n"
                       "|   ~ Keep calm and adopt a pet ~   |\n"
                       "|-----------------------------------|\n"
                       "|         1. See the dogs           |\n"
                       "|         2. Adopt the dog          |\n"
                       "|         3. Don't adopt            |\n"
                       "|         4. See breed              |\n"
                       "|         4. See adoption list      |\n"
                       "|         0. Exit                   |\n"
                       "|-----------------------------------|\n";
    std::cout << menu;
}

void ConsoleUI::runAdministrator() {
    while (this->_unicorns_exist){
        this->printMenuAdministrator();
        std::cout << ">>> ";
        std::string option;
        option = readString();
        if (option == "0") {
            this->_unicorns_exist = false;
            this->_service.saveShelterFile();
            continue;
        }
        if (option == "1") {
            this->addDogUi();
            continue;
        }
        if (option == "2") {
            this->removeDogUi();
            continue;
        }
        if(option == "3"){
            this->updateDogUi();
            continue;
        }
        if(option=="4"){
            this->listDogsUi();
            continue;
        }
        std::cout << "\nWrong command!\n";
    }
}

void ConsoleUI::addDogUi() {
    Dog dog;
    std::cin >> dog;
    try {
        this->_service.addDog(dog.get_name(), dog.get_breed(), dog.get_age(), dog.get_photograph());
        std::cout << "Dog added!\n";
    }catch(Exceptions &serviceException){
        std::cout << serviceException.get_msg();
    }
}


void ConsoleUI::removeDogUi() {
    std::string name;
    std::cout << "Name of the existing dog: ";
    name = readString();

    try {
        this->_service.removeDog(name);
        std::cout << "Yaaay it got adopted o(^_^)o!!!! \n";
    }catch(Exceptions &serviceException){
        std::cout << serviceException.get_msg();
    }
}

void ConsoleUI::updateDogUi() {
    std::string breed, name, photograph;
    int age;

    std::cout << "Name of the existing dog: "; name = readString();
    std::cout << "New Breed: "; breed = readString();
    std::cout << "New Age: ";
    while(!Validator::validateAge(std::cin)){
        std::cout << "Invalid numerical value (age)!\n";
        std::cout << "Correct age: "; std::cin >> age;
    }
    std::cout << "New Photograph: "; std::cin>> photograph;

    try {
        this->_service.updateDog(name, breed, age, photograph);
        std::cout << "Dog updated!\n";
    }catch(Exceptions &serviceException){
        std::cout << serviceException.get_msg();
    }
}


void ConsoleUI::listDogsUi() {
    auto dogs = this->_service.getDogs();
    for (auto & i : dogs){
        std::cout << i;
    }
}

ConsoleUI::~ConsoleUI() = default;
