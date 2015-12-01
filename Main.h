#ifndef MAIN_H
#define MAIN_H
#include "Connection.h"
#include "FileTools.h"
#include "TablePointers.h"

TablePointers<BusLine> lines;
TablePointers<Bus> buses;
TablePointers<Passenger> passengers;
TablePointers<Connection> connections;

const std::string MENU1 = "Menu glowne\n1. Wyswietl\n2. Kup bilet\n3. Anuluj bilety\n4. Dodaj\n5. Usun\n6. Wyjscie\n";
const std::string MENU2 = "Wyświetl ...\n1. Linie\n2. Autobusy\n3. Pasazerow\n4. Polaczenia\n5. Cofnij\n";
const std::string MENU3 = "Dodaj ...\n1. Linie\n2. Autobus\n3. Pasazera\n4. Polaczenie\n5. Cofnij\n";
const std::string MENU4 = "Usun ...\n1. Linie\n2. Autobus\n3. Pasazera\n4. Polaczenie\n5. Cofnij\n";

void menu1();
void menu2();
void menu3();
void menu4();

void buyTicketsInConsole();
void cancelTicketsInConsole();

int main();
#endif
