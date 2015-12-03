#ifndef BUSLINE_H
#define BUSLINE_H
#include <string>
#include <iostream>
#include "Connection.h"
#include "TablePointers.h"

class BusLine {
private:
	std::string nameOfLine;
	std::string startStop;
	std::string endStop;
	int length;
	int time;
	double price;
	static double PRICE_FOR_KM;
public:
	BusLine(std::string name = "", std::string start = "", std::string end = "", int len = 0, int t = 0) :
		nameOfLine(name), startStop(start), endStop(end), length(len), time(t)
		{ price = PRICE_FOR_KM * length; }
	BusLine(BusLine& line):nameOfLine(line.nameOfLine), startStop(line.startStop), 
		endStop(line.endStop), length(line.length), time(line.time), price(line.price) {}
	BusLine& set(std::string, std::string, std::string, int, int);
	static setPriceForKM(int n) {PRICE_FOR_KM=n;}
	std::string getNameOfLine() const;
	std::string getStartStop() const;
	std::string getEndStop() const;
	int getLength() const;
	int getTime() const;
	static getPriceForKM() {return PRICE_FOR_KM;}
	double getPrice() const;
	static void createFromInput(TablePointers<BusLine>&);
};
std::ostream &operator<<(std::ostream &os, const BusLine &line);
#endif