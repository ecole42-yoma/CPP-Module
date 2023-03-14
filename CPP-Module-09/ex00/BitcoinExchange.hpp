#pragma once

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream>
#include <map>
#include <string>

typedef std::map<int, float> day_map;
typedef std::map<int, day_map> month_map;
typedef std::map<int, month_map> year_map;
typedef year_map data_set_t;

struct day {};

class BitcoinExchange {
public:
  typedef const BitcoinExchange &const_reference;
  typedef BitcoinExchange &reference;

private:
  data_set_t data_;
  //   float search(int, int, int);

public:
  BitcoinExchange(const char *csv_file = "./data.csv");
  ~BitcoinExchange();
  BitcoinExchange(const_reference from);
  reference operator=(const_reference from);

  void exchange(const char *input);
};

#endif
