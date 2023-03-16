#pragma once

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream>
#include <map>
#include <string>

#include "util.hpp"

typedef enum error_state_e {
	bad_date = 0,
	bad_value,
	too_large,
	negative,
	none,
	end
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

	void init_db_(std::string db_file);
	void find_and_exchange_(check_t check);
	void exchange_(const char* input);

public:
	BitcoinExchange(char** argv = NULL);
	~BitcoinExchange();
	BitcoinExchange(const_reference from);
	reference operator=(const_reference from);
};

#endif
