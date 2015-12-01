#ifndef BUS_H
#define BUS_H
#include <string>
#include <iostream>
#include "TablePointers.h"

class Bus
{
private:
	std::string numberOfBus;
	int amountOfPlaces;
public:
	Bus(std::string number = "", int amount = 0) : numberOfBus(number), amountOfPlaces(amount) {}
	Bus(Bus& bus): numberOfBus(bus.numberOfBus), amountOfPlaces(bus.amountOfPlaces) {} ;
	Bus& set(std::string, int);
	std::string getNameOfBus() const;
	int getAmountOfPlaces() const;
};

void createFromInput(TablePointers<Bus>&);
std::ostream &operator<<(std::ostream&, const Bus&);

#endif