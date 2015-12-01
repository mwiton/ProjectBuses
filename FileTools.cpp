#include "FileTools.h"

void readBusLines(const std::string string, TablePointers<BusLine> &tab) {
    std::ifstream input;
    std::string name, start, end;
    int len, t;
    int size;
    input.open(string);
    if(!(input.is_open())) return;
    input >> size;
    for (int i = 0; i < size; ++i) {
        input >> name >> start >> end >> len >> t;
        BusLine *line = new BusLine(name, start, end, len, t);
        tab.addElement(line);
    }
    input.close();
}

void readBuses(const std::string string, TablePointers<Bus> &tab) {
    std::ifstream input;
    std::string nameBuS;
    int size, amount;
    input.open(string);
    if(!(input.is_open())) return;
    input >> size;
    for (int i = 0; i < size; ++i) {
        input >> nameBuS >> amount;
        Bus *bus = new Bus(nameBuS, amount);
        tab.addElement(bus);
    }
    input.close();
}

void readPassengers(const std::string string, TablePointers<Passenger> &tab) {
    std::ifstream input;
    std::string name;
    int size;
    input.open(string);
    if(!(input.is_open())) return;
    input >> size;
    for (int i = 0; i < size; ++i) {
        input >> name;
        Passenger* passenger = new Passenger(name);
        tab.addElement(passenger);
    }
    input.close();
}

void readConnections(const std::string string, TablePointers<Connection> &tab,
                     const TablePointers<BusLine> &line, const TablePointers<Bus> &buses,
                     const TablePointers<Passenger> &passengers) {
    std::ifstream input;
    std::string name;
    int indexLine, indexBus, numbersOfPassengers, amount, size;
    Passenger *passenger;
    input.open(string);
    if(!(input.is_open())) return;
    input >> size;
    for (int i = 0; i < size; ++i) {
        input >> name >> indexLine >> indexBus;
        Connection *connection = new Connection(name, line[indexLine], buses[indexBus]);
        tab.addElement(connection);
        input >> numbersOfPassengers;
        for (int j = 0; j < numbersOfPassengers; ++j) {
            input >> name >> amount;
            int k=0;
            do{
                passenger = passengers[k++];
            } while (passenger->getName() != name);
            tab[i]->purchaseTicket(passenger, amount);
        }
    }
    input.close();
}

void writeBusLines(std::string string, const TablePointers<BusLine> &tab) {
    std::ofstream output;
    output.open(string);
    if(!(output.is_open())) return;
    output << tab.getSize() << std::endl;
    for (int i = 0; i < tab.getSize(); ++i) {
        output << tab[i]->getNameOfLine() << " " << tab[i]->getStartStop() << " " << tab[i]->getEndStop()
                << " " << tab[i]->getLength() << " " << tab[i]->getTime() << std::endl;
    }
}

void writeBuses(std::string string, const TablePointers<Bus> &tab) {
    std::ofstream output;
    output.open(string);
    if(!(output.is_open())) return;
    output << tab.getSize() << std::endl;
    for (int i = 0; i < tab.getSize(); ++i) {
        output << tab[i]->getNameOfBus() << " " << tab[i]->getAmountOfPlaces() << std::endl;
    }
}

void writePassengers(std::string string, const TablePointers<Passenger> &tab) {
    std::ofstream output;
    output.open(string);
    if(!(output.is_open())) return;
    output << tab.getSize() << std::endl;
    for (int i = 0; i < tab.getSize(); ++i) {
        output << tab[i]->getName() << std::endl;
    }
}

void writeConnections(std::string string, const TablePointers<Connection> &tab,
                      const TablePointers<BusLine> &line, const TablePointers<Bus> &buses) {
    std::ofstream output;
    int idbus=0, idline=0;
    output.open(string);
    if(!(output.is_open())) return;
    output << tab.getSize() << std::endl;
    for (int i = 0; i < tab.getSize(); ++i) {
        while(line[idline]->getNameOfLine() != tab[i]->getBusLine()->getNameOfLine()){
            idline++;
        }
        while(buses[idbus]->getNameOfBus() != tab[i]->getBus()->getNameOfBus()){
            idbus++;
        }
        output << tab[i]->getNameOfConnection() << " " << idline << " " << idbus << std::endl;
        output << tab[i]->getNumberPassengers() << std::endl << tab[i]->passangersToString();
    }
}
