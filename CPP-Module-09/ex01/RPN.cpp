#include "RPN.hpp"
#include <cctype>
#include <iostream>

#define __NS__ RPN

namespace {

inline void log_(const char *s1, const char *s2 = NULL) {
  std::cout << s1;
  if (s2 != NULL) {
    std::cout << ": " << s2;
  }
  std::cout << std::endl;
}

inline bool syntax_(const int table[8], char c) {
  return (table[(c >> 5)] & (1U << (c & 0x1f)));
}

const int accepted_[] = {
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    /*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
    0x03ffac00, /*	0000 0011 1111 1111  1010 1100 0000 0000 */
    /*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
    0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
    /*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
};

inline int add_(int a, int b) { return a + b; }
inline int sub_(int a, int b) { return a - b; }
inline int mul_(int a, int b) { return a * b; }
inline int div_(int a, int b) { return a / b; }

inline int select_oper_(const char op) {
  switch (op) {
  case '+':
    return 0;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 3;
  default:
    return 4;
  }
}

} // namespace

__NS__::RPN(const char *exp) : expression_(exp) {
  if (exp == NULL) {
    log_("Error");
    exit(1);
  }
  this->process_();
}

__NS__::~RPN() {}

__NS__::RPN(__NS__::const_reference from) { *this = from; }

__NS__::reference __NS__::operator=(__NS__::const_reference from) {
  if (this != &from) {
    expression_ = from.expression_;
  }
  return *this;
}

void __NS__::process_() {
  std::string::const_iterator it = expression_.begin();

  int (*calcul_[5])(int, int) = {
      add_, sub_, mul_, div_, NULL,
  };

  enum {
    rpn_start = 0,
    rpn_validation,
    rpn_number,
    rpn_op,
    rpn_space,
    rpn_error,
    rpn_end
  } state,
      prev_state;

  typedef enum { add = 0, sub, mul, div, error } op_e;
  op_e current_operator;

  std::stack<int> pool;

  state = rpn_start;
  while (state != rpn_end) {
    switch (state) {
    case rpn_start: {
      state = rpn_validation;
      break;
    }

    case rpn_validation: {
      if (it != expression_.end() && syntax_(accepted_, *it)) {
        if (std::isdigit(*it)) {
          state = rpn_space;
          pool.push(*it - '0');
        } else {
          if (pool.size() < 2) {
            state = rpn_error;
          } else {
            state = rpn_op;
            current_operator = static_cast<op_e>(select_oper_(*it));
            if (current_operator == error) {
              state = rpn_error;
            }
          }
        }
        ++it;
      } else {
        state = rpn_error;
      }
      prev_state = state;
      break;
    }

    case rpn_number: {
      break;
    }

    case rpn_op: {
      int b = pool.top();
      pool.pop();
      int a = pool.top();
      pool.pop();

      int result = calcul_[current_operator](a, b);
      pool.push(result);

      prev_state = state;
      state = rpn_space;
      break;
    }

    case rpn_space: {
      if (it == expression_.end()) {
        state = rpn_end;
        break;
      } else if (*it != ' ') {
        state = rpn_error;
      } else {
        state = rpn_validation;
      }
      ++it;
      break;
    }

    case rpn_end: {
      break;
    }

    case rpn_error: {
      log_("Error");
      exit(1);
    }

    default: {
      log_("Error");
      exit(1);
    }
    }
  }

  if (pool.size() != 1) {
    log_("Error");
    exit(1);
  } else {
    std::cout << pool.top() << std::endl;
  }
}

#undef __NS__
