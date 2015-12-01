#include "Passenger.h"

Passenger &Passenger::set(std::string namePassanger){
	name = namePassanger;
	return *this;
}

std::string Passenger::getName() const{
	return name;
}

void insert(Passenger **&tab, int &size, int index){
	Passenger **newTab = new Passenger *[size+1];
	for(int i=0; i<index; ++i){
		newTab[i] = tab[i];
	}
	newTab[index] = new Passenger;
	for(int i=index; i<size; ++i){
		newTab[i+1] = tab[i];
	}
	delete[] tab;
	tab = newTab;
	size++;
}

void createFromInput(TablePointers<Passenger> &tab) {
	std::string name;
	std::cout << "Podaj nazwe: ";
	std::cin >> name;
	Passenger *passenger = new Passenger(name);
	tab.addElement(passenger);
}

Passenger::Passenger(Passenger &passenger) {
	name = passenger.name;
}

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {
	os << "Nazwa pasazera: " << passenger.getName();
	return os;
}
