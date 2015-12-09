#ifndef FILETOOLS_H
#define FILETOOLS_H
#include "Connection.h"
#include <fstream>
#include "TablePointers.h"

namespace ReadWriteFunctions {
	void readBusLines(std::string, TablePointers<BusLine> &);

	void readBuses(std::string, TablePointers<Bus> &);

	void readPassengers(std::string, TablePointers<Passenger> &);

	void readConnections(std::string, TablePointers<Connection> &, const TablePointers<BusLine> &,
						 const TablePointers<Bus>&, const TablePointers<Passenger>&);

	void writeBusLines(std::string, const TablePointers<BusLine> &);

	void writeBuses(std::string, TablePointers<Bus> &tab);

	void writePassengers(std::string, const TablePointers<Passenger> &);

	void writeConnections(std::string, const TablePointers<Connection> &, const TablePointers<BusLine> &,
						  const TablePointers<Bus> &);
};

#endif

