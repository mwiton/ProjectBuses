#include "Bus.h"

Bus& Bus::set(std::string number, int amount){
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

void createFromInput(TablePointers<Bus> &tab) {
	//Tworzy nowy objekt w tablicy wykorzystujac dane z konsoli
    std::string name;
    int amount;
    std::cout << "Podaj nazwe: ";
    std::cin >> name;
    std::cout << "Podaj ilosc miejsc: ";
    std::cin >> amount;
    Bus *bus = new Bus(name, amount);
    tab.addElement(bus);
}

std::ostream &operator<<(std::ostream &os, const Bus &bus) {
    //Reprezentacja obiektu w konsoli
    os << "Numer autobusu: " << bus.getNameOfBus() << "\nIlosc miejsc: " << bus.getAmountOfPlaces();
    return os;
}
