#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <iostream>
#include "TablePointers.h"

class Passenger
{
protected:
	std::string name;
double discount;
int priority;
char type;
public:
char getType() const {
return type; }

double getDiscount() const {
return discount; }

int getPriority() const {
return priority; }

Passenger() = default;
	Passenger(Passenger&);
	Passenger & set(std::string);
	std::string getName() const;
	bool operator==(Passenger passenger);
	static void createFromInput(TablePointers<Passenger> &tab);
};

    class NormalPassenger :
    public Passenger {
    public:
    NormalPassenger(std::string n = "");
    };

    class GroupPassenger :
    public Passenger {
    public:
    GroupPassenger(std::string n = "");
    };

    class DisabledPassenger :
    public Passenger {
    public:
    DisabledPassenger(std::string n = "");
    };


std::ostream &operator<<(std::ostream &os, const Passenger &passenger);
//void insert(Passenger **&tab, int &size, int index);
#endif
