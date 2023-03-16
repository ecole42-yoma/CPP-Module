#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>

#define __NS__ RPN

namespace {

	inline void
	log_(const char* s1, const char* s2 = NULL) {
		std::cout << s1;
		if (s2 != NULL) {
			std::cout << ": " << s2;
		}
		std::cout << std::endl;
		std::exit(1);
	}

	inline bool
	syntax_(const int table[8], char c) {
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

#define __type__ template <typename _Tp>

	__type__ inline _Tp
	add_(_Tp a, _Tp b) { return a + b; }
	__type__ inline _Tp
	sub_(_Tp a, _Tp b) { return a - b; }
	__type__ inline _Tp
	mul_(_Tp a, _Tp b) { return a * b; }
	__type__ inline _Tp
	div_(_Tp a, _Tp b) { return a / b; }

#undef __type__

	inline size_t
	select_oper_(const char op) {
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

	inline void
	internal_process__(std::string::const_iterator it, std::stack<double>& stack, const std::string& expression) {
		static double (*calcul_[5])(double, double) = {
			add_,
			sub_,
			mul_,
			div_,
			NULL,
		};
		state_t state = rpn_skip;

		while (state != rpn_end) {
			switch (state) {
			case rpn_skip: {
				while (it != expression.end() && *it == ' ') {
					++it;
				}
				if (it == expression.end()) {
					state = rpn_end;
				} else {
					state = rpn_validation;
				}
				break;
			}
			case rpn_validation: {
				if (syntax_(accepted_, *it)) {
					if (std::isdigit(*it)) {
						state = rpn_number;
					} else {
						state = rpn_op;
					}
				} else {
					state = rpn_error;
				}
				break;
			}
			case rpn_number: {
				stack.push(*it - '0');
				++it;
				state = rpn_skip;
				break;
			}
			case rpn_op: {
				if (stack.size() < 2) {
					state = rpn_error;
				} else {
					double b = stack.top();
					stack.pop();
					double a = stack.top();
					stack.pop();
					stack.push(calcul_[select_oper_(*it)](a, b));
					++it;
					state = rpn_skip;
				}
				break;
			}
			case rpn_error: {
				log_("Error", "Invalid character or syntax");
				state = rpn_end;
				break;
			}
			case rpn_end: {
			} break;
			default: {
				log_("Error", "Unknown state");
				state = rpn_end;
				break;
			}
			}
		}
		if (stack.size() != 1) {
			log_("Error", "some operands are missing");
		}
	}
} // namespace

__NS__::RPN(const char* exp)
	: expression_(exp) {
	if (exp == NULL) {
		log_("Error", "expression is NULL");
	}
	this->process_();
}

__NS__::~RPN() { }

__NS__::RPN(__NS__::const_reference from) { *this = from; }

__NS__::reference
__NS__::operator=(__NS__::const_reference from) {
	if (this != &from) {
		expression_ = from.expression_;
	}
	return *this;
}

void
__NS__::process_() {
	std::string::const_iterator it = expression_.begin();
	std::stack<double>			stack;

	internal_process__(it, stack, expression_);
	std::cout << "> Result: " << stack.top() << std::endl;
}

#undef __NS__
