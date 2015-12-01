#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <iostream>
#include "TablePointers.h"

class Passenger
{
private:
	std::string name;
public:
	Passenger(std::string nam = ""): name(nam) {}
	Passenger(Passenger&);
	Passenger & set(std::string);
	std::string getName() const;
};

void createFromInput(TablePointers<Passenger> &tab);
void insert(Passenger **&tab, int &size, int index);
std::ostream &operator<<(std::ostream &os, const Passenger &passenger);

#endif