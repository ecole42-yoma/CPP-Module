/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:37:53 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/21 17:40:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat	{

	private:

		enum BasicValue	{
			kHighest = 1,
			kLowest = 150
		};

		const std::string		name_;
		mutable std::size_t		grade_;

	public:
		Bureaucrat(	std::string const& name		= "lorem_ipsum",
					std::size_t const& grade	= kLowest);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const& from);
		Bureaucrat& operator=(Bureaucrat const& operand);

		std::string				getName() const;
		std::size_t				getGrade() const;
		void					levelUp() const;
		void					levelDown() const;

		class GradeTooHighException : public std::exception	{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception	{
			public:
				virtual const char* what() const throw();

		};

};

std::ostream& operator<<(std::ostream& __out, Bureaucrat const& bureaucat);

#endif /* Bureaucrat hpp */
