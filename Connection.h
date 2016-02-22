#ifndef CONNECTION_H
#define CONNECTION_H
#include <string>
#include <iostream>
#include <vector>
#include "BusLine.h"
#include "Bus.h"
#include "Passenger.h"

class BusLine;

class PassengerInBus {
    friend class Connection;

    Passenger *passenger;
    int amount;

    PassengerInBus(Passenger *p = 0, int a = 0) : passenger(p), amount(a) { }

    int getPriority() {
        return passenger->getPriority();
    }
};


class Connection {
private:
	std::string nameOfConnection;
	BusLine* line;
	Bus* bus;
	int numberPassengers;
    std::vector<PassengerInBus> passengers;

    int findPassenger(const Passenger *) const;

public:
    Connection(std::string name = "", BusLine *l = 0, Bus *b = 0) :
            nameOfConnection(name), line(l), bus(b), numberPassengers(0) { }

    Connection(Connection &);

    void operator=(Connection &);

    Connection &set(std::string, BusLine *, Bus *);

    std::string getNameOfConnection() const;

    BusLine *getBusLine() const;

    Bus *getBus() const;

    bool purchaseTicket(Passenger *, int);

    Connection &cancelTickets(Passenger *);

    int freeSeats() const;

    std::string passangersToString() const;

    int getNumberPassengers() const;

    static void createFromInput(TablePointers<Connection> &tab, const TablePointers<BusLine> &tabLine,
                                const TablePointers<Bus> &tabBus);
};

std::ostream &operator<<(std::ostream &os, const Connection connection);

/*class Hour{
        friend class Connection;
        int hour;
        int minute;
        Hour(int h, int m): hour(h), minute(m) {}
        Hour(int m) {
            hour = m / 60;
            minute = m % 60;
        }
        Hour() { Hour(0, 0);}
        Hour operator+=(Hour rightHour){
            hour += rightHour.hour;
            int newMinute = minute + rightHour.minute;
            if(newMinute >= 60){
                ++hour;
                minute = newMinute - 60;
            }
            else minute = newMinute;
            return *this;
        }
    };*/
#endif