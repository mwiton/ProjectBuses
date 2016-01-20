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
return passengers.size();
}

bool Connection::purchaseTicket(Passenger *passanger, int amountOfSeats) {
	/* Funkcja zakupu biletow.
	* Do pasazera przypisana jest dana ilosc miejsc.
	* W wypadku braku zadanej ilosci miejsc wyswietla komunikat.
	*/
	if (amountOfSeats > freeSeats()){ 
		std::cout << "Pasazer " << passanger->getName() << " nie moze kupic biletow z powodu braku miejsc" << std::endl;
return false;
	}
	else {
		int pas = findPassenger(passanger);
		if(pas >= 0){
		passengers[pas].amount += amountOfSeats;
		}
		else{
		PassengerInBus newPassenger(passanger, amountOfSeats);
	passengers.push_back(newPassenger);
		}
	}
		return true;
}


Connection& Connection::cancelTickets(Passenger *passanger){
	/* Funkcja zwalnia wszystkie zajete miejsca
	* przez pasazera podanego w argumentach
	*/
for (int i = 0; i < passengers.size(); ++i) {
	if (passengers[i].passenger == passanger) {
	passengers.erase(passengers.begin() + i);
	break;
		}
	}
	return *this;
}


int Connection::freeSeats() const
{
	// Zwraca ilosc wolnych miejsc w autobusie
	int numberOfReservedSeats = 0;
for (int i = 0; i < passengers.size(); ++i) {
numberOfReservedSeats += passengers[i].amount;
	}
	return bus->getAmountOfPlaces() - numberOfReservedSeats;
}

std::string Connection::passangersToString() const{
	/*Zwraca string z lista pasazerow a autobusie 
	*i ilosc zajetych przez nich miejsc
	*/
	std::string ret("");
for (int i = 0; i < passengers.size(); ++i) {
ret += passengers[i].passenger->getName() + " " + std::to_string(passengers[i].amount) + "\n";
	}
	return ret;
}

void Connection::createFromInput(TablePointers<Connection> &tab, const TablePointers<BusLine> &tabLine, const TablePointers<Bus> &tabBus) {
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
for (int i = 0; i < passengers.size(); ++i) {
if (passengers[i].passenger == passenger) return i;
	}
	return -1;
}

Connection::Connection(Connection &connection) {
	//konstruktor kopiujacy
	nameOfConnection = connection.nameOfConnection;
	line = connection.line;
	bus = connection.bus;
	numberPassengers = connection.numberPassengers;
passengers = connection.passengers;
}

void Connection::operator=(Connection &connection) {
	nameOfConnection = connection.nameOfConnection;
	line = connection.line;
	bus = connection.bus;
	numberPassengers = connection.numberPassengers;
	passengers = connection.passengers;
}

std::ostream &operator<<(std::ostream &os, const Connection connection) {
	os << "Polaczenie " << connection.getNameOfConnection() << " na linii "
	<< connection.getBusLine()->getNameOfLine() << " obslugiwane autobusem "
	<< connection.getBus()->getNameOfBus() << std::endl;
	os << "Liczba zajetych miejsc:" << std::endl;
	os << connection.passangersToString();
	return os;
}
