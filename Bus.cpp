#include "Bus.h"

Bus& Bus::set(std::string number, int amount){
    //Setting fields of object
	numberOfBus = number;
	amountOfPlaces = amount;
	return *this;
}

std::string Bus::getNameOfBus() const{
	return numberOfBus;
}

int Bus::getAmountOfPlaces() const
{
	return amountOfPlaces;
}

void Bus::createFromInput(TablePointers<Bus> &tab) {
    //Creates a new object in table using data from console
    std::string name;
    int amount;
    std::cout << "Podaj nazwe: ";
    std::cin >> name;
    std::cout << "Podaj ilosc miejsc: ";
    std::cin >> amount;
    Bus *bus = new Bus(name, amount);
    tab.addElement(bus);
}

std::ostream& operator<<(std::ostream &os, const Bus &bus) {
    //Representing data in console
    os << "Numer autobusu: " << bus.getNameOfBus() << "\nIlosc miejsc: " << bus.getAmountOfPlaces();
    return os;
}
