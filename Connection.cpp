#include "Connection.h"

Connection& Connection::set(std::string name, BusLine * lineBus, Bus * b){
	nameOfConnection = name;
	line = lineBus;
	bus = b;
	return *this;
}

std::string Connection::getNameOfConnection() const
{
	return nameOfConnection;
}

BusLine * Connection::getBusLine() const
{
	return line;
}

Bus * Connection::getBus() const
{
	return bus;
}

int Connection::getNumberPassengers() const{
	return numberPassengers;
}

int Connection::purchaseTicket(Passenger * passanger, int amountOfSeats){
	/* Funkcja zakupu biletow.
	* Do pasazera przypisana jest dana ilosc miejsc.
	* W wypadku braku zadanej ilosci miejsc wyswietla komunikat.
	*/
	if (amountOfSeats > freeSeats()){ 
		std::cout << "Pasazer " << passanger->getName() << " nie moze kupic biletow z powodu braku miejsc" << std::endl;
		return 0;
	}
	else {
		int pas = findPassenger(passanger);
		if(pas >= 0){
			++(passengersInBus[pas].amount);
		}
		else{
			++numberPassengers;
			PassengerInBus * newTab = new PassengerInBus[numberPassengers];
			for (int i = 0; i < numberPassengers - 1; ++i) {
				newTab[i] = passengersInBus[i];
			}
			delete passengersInBus;
			passengersInBus = newTab;
			passengersInBus[numberPassengers-1] = PassengerInBus(passanger, amountOfSeats);
		}
	}
	return 1;
}


Connection& Connection::cancelTickets(Passenger *passanger){
	/* Funkcja zwalnia wszystkie zajete miejsca
	* przez pasazera podanego w argumentach
	*/
	for (int i = 0; i < numberPassengers; ++i) {
		if (passengersInBus[i].passenger->getName() == passanger->getName()) {
			passengersInBus[i]=0;
			--numberPassengers;
			PassengerInBus * newTab = new PassengerInBus[numberPassengers];
			for (int j = 0; j < i; ++j) {
				newTab[j] = passengersInBus[j];
			}
			for (int j = i; j < numberPassengers; ++j) {
				newTab[j] = passengersInBus[j+1];
			}
			delete passengersInBus;
			passengersInBus = newTab;
		}
	}
	return *this;
}


int Connection::freeSeats() const
{
	// Zwraca ilosc wolnych miejsc w autobusie
	int numberOfReservedSeats = 0;
	for (int i = 0; i < numberPassengers; ++i) {
		numberOfReservedSeats += passengersInBus[i].amount;
	}
	return bus->getAmountOfPlaces() - numberOfReservedSeats;
}

std::string Connection::passangersToString() const{
	/*Zwraca string z lista pasazerow a autobusie 
	*i ilosc zajetych przez nich miejsc
	*/
	std::string ret("");
	for (int i = 0; i < numberPassengers; ++i) {
		ret+= passengersInBus[i].passenger->getName() + " " + std::to_string(passengersInBus[i].amount) + "\n";
	}
	return ret;
}

void createFromInput(TablePointers<Connection> &tab, const TablePointers<BusLine> &tabLine, const TablePointers<Bus> &tabBus) {
	//Tworzy nowy objekt w tablicy wykorzystujac dane z konsoli
	std::string name;
	int idbus, idline;
	std::cout << "Podaj nazwe: ";
	std::cin >> name;
	std::cout << "Podaj ID linii: ";
	std::cin >> idline;
	std::cout << "Podaj ID autobusu: ";
	std::cin >> idbus;
	Connection* connection = new Connection(name, tabLine[idline], tabBus[idbus]);
	tab.addElement(connection);
}

int Connection::findPassenger(const Passenger *passenger) const{
	//Znajduje pasazera w liscie pasazerow w autobusie i zwraca jego index
	//Gdy nie znajduje sie ten pasazer w liscie zwraca -1
	for (int i = 0; i < numberPassengers; ++i) {
		if (passengersInBus[i].passenger == passenger) return i;
	}
	return -1;
}

Connection::Connection(Connection &connection) {
	//konstruktor kopiujacy
	nameOfConnection = connection.nameOfConnection;
	line = connection.line;
	bus = connection.bus;
	numberPassengers = connection.numberPassengers;
	passengersInBus = new PassengerInBus[numberPassengers];
	for (int i = 0; i < numberPassengers; ++i) {
		passengersInBus[i] = PassengerInBus(connection.passengersInBus[i]);
	}
}

void Connection::operator=(Connection &connection) {
	nameOfConnection = connection.nameOfConnection;
	line = connection.line;
	bus = connection.bus;
	numberPassengers = connection.numberPassengers;
	passengersInBus = new PassengerInBus[numberPassengers];
	for (int i = 0; i < numberPassengers; ++i) {
		passengersInBus[i] = PassengerInBus(connection.passengersInBus[i]);
	}
}

std::ostream &operator<<(std::ostream &os, const Connection connection) {
	os << "Polaczenie " << connection.getNameOfConnection() << " na linii "
	<< connection.getBusLine()->getNameOfLine() << " obslugiwane autobusem "
	<< connection.getBus()->getNameOfBus() << std::endl;
	os << "Liczba zajetych miejsc:" << std::endl;
	os << connection.passangersToString();
	return os;
}
