#pragma once

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream>
#include <map>
#include <string>

typedef enum error_state_e {
	bad_date = 0,
	bad_value,
	too_large,
	negative,
	none
} error_state_t;

typedef struct check_s {
	std::string	  date;
	double		  value;
	error_state_t error_state;
} check_t;

class BitcoinExchange {
public:
	typedef const BitcoinExchange&		  const_reference;
	typedef BitcoinExchange&			  reference;
	typedef std::map<std::string, double> container;

private:
	container data_;

	void find_and_exchange_(std::string date, double value);

public:
	BitcoinExchange(const char* csv_file = "./data.csv");
	~BitcoinExchange();
	BitcoinExchange(const_reference from);
	reference operator=(const_reference from);

	void exchange(const char* input);
};

#endif
