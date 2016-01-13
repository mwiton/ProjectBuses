#ifndef PROJECTBUSES_PASSANGERWITHDISCOUNT_H
#define PROJECTBUSES_PASSANGERWITHDISCOUNT_H

#include "Passenger.h"

class PassengerWithDiscount : public Passenger {
public:
    PassengerWithDiscount(std::string n = "", double d = 0.0) : Passenger(n), discount(d) { }

private:
    double discount;
};

#endif //PROJECTBUSES_PASSANGERWITHDISCOUNT_H
