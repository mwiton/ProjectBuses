#include "Main.h"

/*
Projekt nr 3 - dynamiczne zarzadzanie pamiecia
praca na plikach
dodawanie elementow

void dodaj(B *&b, int &bsize){
	1.stworz lokalna tablice o rozmiarze bsize+1
	2. skopiuj stare dane do nowej
	3. usun pamiec stara tablice
	4. podpiac pod wskaznik nowa tablice
	5. zwieksz bsize o 1
	}

void dodaj(M **&m, int &msize){
	1.stworz lokalna tablice o rozmiarze msize+1
	2. skopiuj stare dane do nowej
	3. usun pamiec stara tablice
	4. podpiac pod wskaznik nowa tablice
	5. zwieksz msize o 1
	}

void usun(B *&b, int &bsize, int index){
*/

int main() {
	//Czytanie danych z plikow
    readBusLines("Lines.txt", lines);
    readBuses("Buses.txt", buses);
    readPassengers("Passangers.txt", passengers);
    readConnections("Connections.txt", connections, lines, buses, passengers);

    menu1();

    writeBusLines("Lines.txt", lines);
    writeBuses("Buses.txt", buses);
    writePassengers("Passangers.txt", passengers);
    writeConnections("Connections.txt", connections, lines, buses);

	return 0;
}

void menu1() {
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
    int option;
    std::cout << MENU3;
    std::cin >> option;
    switch (option){
        case 1:
            createFromInput(lines);
            break;
        case 2:
            createFromInput(buses);
            break;
        case 3:
            createFromInput(passengers);
            break;
        case 4:
            createFromInput(connections, lines, buses);
            break;
        case 5:
            break;
        default:
            std::cout << "Bledne wejscie\n";
            menu3();
    }
}

void menu4() {
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
    std::string name;
    int amount, id, i(0);
    Passenger* passenger;
    std::cout << "Podaj nazwe pasazera: ";
    std::cin >> name;
    std::cout << "Podaj ID polaczenia: ";
    std::cin >> id;
    std::cout << "Podaj ilosc biletow: ";
    std::cin >> amount;
    do{
        passenger = passengers[i++];
    } while (passenger->getName() != name);
    int purchase = connections[id]->purchaseTicket(passenger, amount);
    if(purchase) std::cout << "Cena biletu: " << amount * connections[id]->getBusLine()->getPrice() << " zl\n";
}

void cancelTicketsInConsole() {
    std::string name;
    int amount, id, i(0);
    Passenger* passenger;
    std::cout << "Podaj nazwe pasazera: ";
    std::cin >> name;
    std::cout << "Podaj ID polaczenia: ";
    std::cin >> id;
    do{
        passenger = passengers[i++];
    } while (passenger->getName() != name);
    connections[id]->cancelTickets(passenger);
}