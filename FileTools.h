#ifndef FILETOOLS_H
#define FILETOOLS_H
#include "Connection.h"
#include <fstream>
#include "TablePointers.h"

class ReadWriteFuctions{
public:
	static void readBusLines(std::string, TablePointers<BusLine>&);
	static void readBuses(std::string, TablePointers<Bus>&);
	static void readPassengers(std::string, TablePointers<Passenger>&);
	static void readConnections(std::string, TablePointers<Connection>&, const TablePointers<BusLine>&,
						 const TablePointers<Bus>&, const TablePointers<Passenger>&);

	static void writeBusLines(std::string, const TablePointers<BusLine>&);
	static void writeBuses(std::string, const TablePointers<Bus> &tab);
	static void writePassengers(std::string, const TablePointers<Passenger>&);
	static void writeConnections(std::string, const TablePointers<Connection>&, const TablePointers<BusLine>&, const TablePointers<Bus>&);
};

#endif

