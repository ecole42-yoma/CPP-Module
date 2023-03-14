#pragma once
#ifndef __RPN__FT__HPP__
#define __RPN__FT__HPP__

#include <stack>
#include <string>

class RPN {
public:
  typedef const RPN &const_reference;
  typedef RPN &reference;

private:
  std::string expression_;

  void process_();

public:
  RPN(const char *exp = NULL);
  ~RPN();
  RPN(const_reference from);
  reference operator=(const_reference from);
};

#endif
