#include "Passenger.h"

Passenger &Passenger::set(std::string namePassanger){
	name = namePassanger;
	return *this;
}

std::string Passenger::getName() const{
	return name;
}

void Passenger::createFromInput(TablePointers<Passenger> &tab) {
	std::string name;
int type;
Passenger *passenger;
	std::cout << "Podaj nazwe: ";
	std::cin >> name;
std::cout << "Wybierz rodzaj:\n1. Normalny\n2. Grupa\n3. Niepelnosprawny\n";
std::cin >> type;
switch (type) {
case 1:
passenger = new NormalPassenger(name);
break;
case 2:
passenger = new GroupPassenger(name);
break;
case 3:
passenger = new DisabledPassenger(name);
break;
default:
std::cout << "Bledne wejscie\n";
return;
}
	tab.addElement(passenger);
}

Passenger::Passenger(Passenger &passenger) {
	name = passenger.name;
discount = passenger.discount;
priority = passenger.priority;
}

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {
os << "Nazwa pasazera: " << passenger.getName() << "\n";
os << "Rodzaj pasazera: " << passenger.getType();
	return os;
}

bool Passenger::operator==(Passenger passenger) {
	return name == passenger.name;
}

NormalPassenger::NormalPassenger(std::string n) {
name = n;
discount = 0.0;
priority = 1;
type = 'N';
}

GroupPassenger::GroupPassenger(std::string n) {
name = n;
discount = 0.5;
priority = 2;
type = 'G';
}

DisabledPassenger::DisabledPassenger(std::string n) {
name = n;
discount = 0.75;
priority = 3;
type = 'D';
}

/*void insert(Passenger **&tab, int &size, int index){
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
}*/
