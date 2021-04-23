//
// Created by Sakura on 4/11/2021.
//

#ifndef A67_913ALICEHINCU_CONSOLEUI_H
#define A67_913ALICEHINCU_CONSOLEUI_H


#include "../service/ServiceAdmin.h"

class ConsoleUI {
private:
    // for the while loop
    bool _unicorns_exist = true;

    // the service
    ServiceAdmin& _service;

    // for reading string with spaces
    std::string readString();

    // menu admin
    static void printMenuAdministrator();

    // menu user
    void printMenuUser();

    // run the loop for admin mode
    void runAdministrator();

    // run the loop for user mode
    //void runUser();

    // add 10 inputs
    void addTenDogs();

    // ----------- ADMIN MODE -----------
    void addDogUi();

    void removeDogUi();

    void listDogsUi();

    void updateDogUi();

    // ----------- USER MODE -----------
    /*void userListDogsUi();

    void userAdoptDogUi();

    void UserNotAdoptDogUi();

    void sortByBreedUi();

    void userAdoptionListUi();*/

public:
    // constructor;
    explicit ConsoleUI(ServiceAdmin& service);

    // main loop;
    void run();

    // destructor
    ~ConsoleUI();
};



#endif //A67_913ALICEHINCU_CONSOLEUI_H
