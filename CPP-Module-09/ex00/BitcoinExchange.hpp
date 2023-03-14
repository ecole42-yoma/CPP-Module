#pragma once

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream>
#include <map>
#include <string>

struct day { };

class BitcoinExchange {
public:
	typedef const BitcoinExchange&		  const_reference;
	typedef BitcoinExchange&			  reference;
	typedef std::map<std::string, double> container;

private:
	container data_;

public:
	BitcoinExchange(const char* csv_file = "./data.csv");
	~BitcoinExchange();
	BitcoinExchange(const_reference from);
	reference operator=(const_reference from);

	void exchange(const char* input);
};

#endif
