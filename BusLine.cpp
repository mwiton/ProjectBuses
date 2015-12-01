#include "BusLine.h"

BusLine& BusLine::set(std::string line, std::string st, std::string en, int len, int t){
	nameOfLine = line;
	startStop = st;
	endStop = en;
	length = len;
	time = t;
	price = length * PRICE_FOR_KM;
	return *this;
}

std::string BusLine::getNameOfLine() const{
	return nameOfLine;
}

std::string BusLine::getStartStop() const{
	return startStop;
}

std::string BusLine::getEndStop() const{
	return endStop;
}

int BusLine::getLength() const{
	return length;
}

int BusLine::getTime() const{
	return time;
}

void createFromInput(TablePointers<BusLine> &tab) {
	//Tworzy nowy objekt w tablicy wykorzystujac dane z konsoli
	std::string name, start, end;
	int len, time;
	std::cout << "Podaj nazwe: ";
	std::cin >> name;
	std::cout << "Podaj poczatek linii: ";
	std::cin >> start;
	std::cout << "Podaj koniec linii: ";
	std::cin >> end;
	std::cout << "Podaj dlugosc linii: ";
	std::cin >> len;
	std::cout << "Podaj czas przejazdu: ";
	std::cin >> time;
	BusLine *line = new BusLine(name, start, end, len, time);
	tab.addElement(line);
}

std::ostream &operator<<(std::ostream &os, const BusLine &line) {
	os <<"Linia " << line.getNameOfLine() <<" kursuje miedzy "<<line.getStartStop()<<" a "<<line.getEndStop()<<std::endl;
	os << "Jej dlugosc to " << line.getLength() << " km i czas przejazdu to " << line.getTime() << " min";
	return os;
}

double BusLine::getPrice() const {
	return price;
}
