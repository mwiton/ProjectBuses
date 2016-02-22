#include "Main.h"

int main() {
    ReadWriteFunctions::readBusLines("Lines.txt", lines);
    ReadWriteFunctions::readBuses("Buses.txt", buses);
    ReadWriteFunctions::readPassengers("Passangers.txt", passengers);
    ReadWriteFunctions::readConnections("Connections.txt", connections, lines, buses, passengers);

    menu1();

    ReadWriteFunctions::writeBusLines("Lines.txt", lines);
    ReadWriteFunctions::writeBuses("Buses.txt", buses);
    ReadWriteFunctions::writePassengers("Passangers.txt", passengers);
    ReadWriteFunctions::writeConnections("Connections.txt", connections, lines, buses);

    lines.removeAll();
    buses.removeAll();
    passengers.removeAll();
    connections.removeAll();

	return 0;
}

void menu1() {
    //Main menu of program
    int option;
    while (true){
        std::cout << MENU1;
        std::cin >> option;
        switch (option) {
            case 1:
                menu2();
                break;
            case 2:
                buyTicketsInConsole();
                break;
            case 3:
                cancelTicketsInConsole();
                break;
            case 4:
                menu3();
                break;
            case 5:
                menu4();
                break;
            case 6:
                return;
            default:
                std::cout << "Bledne wejscie\n";

        }
    }
}

void menu2() {
    //Menu with options to display tables
    int option;
    std::cout << MENU2;
    std::cin >> option;
    switch (option){
        case 1:
            std::cout << lines;
            break;
        case 2:
            std::cout << buses;
            break;
        case 3:
            std::cout << passengers;
            break;
        case 4:
            std::cout << connections;
            break;
        case 5:
            break;
        default:
            std::cout << "Bledne wejscie\n";
            menu2();
    }
}

void menu3() {
    //Menu with options to creating data
    int option;
    std::cout << MENU3;
    std::cin >> option;
    switch (option){
        case 1:
            BusLine::createFromInput(lines);
            break;
        case 2:
            Bus::createFromInput(buses);
            break;
        case 3:
            Passenger::createFromInput(passengers);
            break;
        case 4:
            Connection::createFromInput(connections, lines, buses);
            break;
        case 5:
            break;
        default:
            std::cout << "Bledne wejscie\n";
            menu3();
    }
}

void menu4() {
    //Menu with options to elements from tables
    int option, id;
    std::cout << MENU4;
    std::cin >> option;
    std::cout << "Numer ID:";
    std::cin >> id;
    switch (option){
        case 1:
            lines.removeElement(id);
            break;
        case 2:
            buses.removeElement(id);
            break;
        case 3:
            passengers.removeElement(id);
            break;
        case 4:
            connections.removeElement(id);
            break;
        case 5:
            break;
        default:
            std::cout << "Bledne wejscie\n";
            menu3();
    }
}

void buyTicketsInConsole() {
    //Option with buying a ticket for connection
    std::string name;
    int amount, id, i(0);
    Passenger* passenger;

    std::cout << "Podaj nazwe pasazera: ";
    std::cin >> name;
    do {
        if (i == passengers.getSize()) {
            std::cout << "Brak takiego pasazera\n";
            return;
        }
        passenger = passengers[i++];
    } while (passenger->getName() != name);

    std::cout << "Podaj ID polaczenia: ";
    std::cin >> id;
    if (id >= connections.getSize() || id < 0) {
        std::cout << "Nieprawidlowo podany id\n";
        return;
    }

    std::cout << "Podaj ilosc biletow: ";
    std::cin >> amount;
    if (amount < 0) {
        std::cout << "Nieprawidlowo podana ilosc\n";
        return;
    }

    int purchase = connections[id]->purchaseTicket(passenger, amount);
    if (purchase)
        std::cout << "Cena biletu: " << amount * connections[id]->getBusLine()->getPrice() *
                                        (1 - passenger->getDiscount()) << " zl\n";
}

void cancelTicketsInConsole() {
    //Option with canceling a ticket for connection
    std::string name;
    int id, i(0);
    Passenger* passenger;

    std::cout << "Podaj nazwe pasazera: ";
    std::cin >> name;
    do{
        if (i == passengers.getSize()) {
            std::cout << "Brak takiego pasazera\n";
            return;
        }
        passenger = passengers[i++];
    } while (passenger->getName() != name);

    std::cout << "Podaj ID polaczenia: ";
    std::cin >> id;
    if (id >= connections.getSize() || id < 0) {
        std::cout << "Nieprawidlowo podany id\n";
        return;
    }

    connections[id]->cancelTickets(passenger);
}
