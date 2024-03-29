#include "InterfaceChooser.h"
#include "ConsoleInterface.h"

void InterfaceChooser::write(Interface type, const std::string& answer, std::vector<int>* values,
                  std::vector<std::string*>* strings) {
    if (type == Interface::Console) {
        ConsoleInterface::write(answer, values, strings);
    }
    if (type == Interface::Graphic) {
        //write(answer, values, strings);
    }
    if (type == Interface::Network) {
        //write(answer, values, strings);
    }
}
void InterfaceChooser::showMap(Interface type, Map& map, std::pair<int, int>& position) {
    if (type == Interface::Console) {
        ConsoleInterface::showMap(map, position);
    }
    if (type == Interface::Graphic) {
        //::showMap(map, position);
    }
    if (type == Interface::Network) {
        //::showMap(map, position);
    }
}
void InterfaceChooser::showPaths(Interface type, Map& map, std::pair<int, int>& position) {
    if (type == Interface::Console) {
        ConsoleInterface::showPaths(map, position);
    }
    if (type == Interface::Graphic) {
        //::showPaths(map, position);
    }
    if (type == Interface::Network) {
        //::showPaths(map, position);
    }
}
void InterfaceChooser::showCombatStatus(Interface type, std::vector<int>& values) {
    if (type == Interface::Console) {
        ConsoleInterface::showCombatStatus(values);
    }
    if (type == Interface::Graphic) {
        //::showCombatStatus(values);
    }
    if (type == Interface::Network) {
        //::showCombatStatus(values);
    }
}
void InterfaceChooser::showCard(Interface type, int number, int damage, int defence, std::string* description) {
    if (type == Interface::Console) {
        ConsoleInterface::showCard(number, damage, defence, description);
    }
    if (type == Interface::Graphic) {
        //::showCard(number, damage, defence, description);
    }
    if (type == Interface::Network) {
        //::showCard(number, damage, defence, description);
    }
}
int InterfaceChooser::read(Interface type) {
    if (type == Interface::Console) {
        return ConsoleInterface::readNumber();
    }
    if (type == Interface::Graphic) {
        //::read();
    }
    if (type == Interface::Network) {
        //::read();
    }
    return 0;
}
