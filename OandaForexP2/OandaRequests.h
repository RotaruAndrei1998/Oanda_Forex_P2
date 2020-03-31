#ifndef OANDA_REQUESTS_H
#define OANDA_REQUESTS_H
#include <string>

std::string getAccountId();
std::string getAccountInfo();
std::string getLastPricesForInstrument(std::string instrument, int count);

#endif