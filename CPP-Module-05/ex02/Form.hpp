/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:00:50 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include "Bureaucrat.hpp"
# include <exception>
# include <string>
# include <iostream>

class Form	{

	private:
		enum BasicValue	{
			kHighest = 1,
			kLowest = 150
		};

		const std::string		name_;
		bool					check_sign_;
		const int				grade_sign_;
		const int				grade_execute_;

	public:
		Form(std::string const& name = "lorem_ipsum_form", int const& grade_sign = 75, int const& grade_execute = 75);
		virtual ~Form();
		Form(Form const &from);
		Form& operator=(Form const& operand);

		std::string				getName() const;
		bool					getSign() const;
		int						getGradeSign() const;
		int						getGradeExecute() const;

		void					beSigned(Bureaucrat const& bur);

		void					execute(Bureaucrat const& executor) const;
		virtual void			workhorse() const = 0;


		class GradeTooHighException : public std::exception	{

			private:
				bool			case_;

			public:
				explicit GradeTooHighException(bool excep_case = true) throw();
				virtual const char* what() const throw ();

		};

		class GradeTooLowException : public std::exception	{

			private:
				bool			case_;

			public:
				explicit GradeTooLowException(bool excep_case = true) throw();
				virtual const char* what() const throw ();

		};

};

std::ostream& operator<<(std::ostream& __out, Form const& Form);

#endif /* __FORM_HPP__ */
