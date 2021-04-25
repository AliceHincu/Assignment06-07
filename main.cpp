#include <iostream>
#include "console/ConsoleUI.h"
//#include "Tests.h"

int main() {
    RepositoryShelter repoShelter;
    ServiceAdmin serviceAdmin(repoShelter);
    ServiceUser serviceUser(repoShelter);
    ConsoleUI console(serviceAdmin, serviceUser);
    console.run();
    return 0;
}
