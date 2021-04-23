#include <iostream>
#include "console/ConsoleUI.h"
//#include "Tests.h"

int main() {
    //Tests t;
    //t.runAllTests();


    RepositoryShelter repository;
    ServiceAdmin service(repository);
    ConsoleUI console(service);
    console.run();

    return 0;
}
