/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:29 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 21:41:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <string>

class Form;

class Intern	{

	private:
		enum FormTable	{
			kPresidential,
			kRobotomy,
			kShrubbery,
			kError
		};

	public:
		Intern();
		~Intern();
		Intern(Intern const& from);
		Intern& operator=(Intern const& operand);

		Form*			makeForm(std::string const& name = "lorem", std::string const& target = "No_Target") const;

		Form*			pres(std::string const& target) const;
		Form*			robo(std::string const& target) const;
		Form*			shru(std::string const& target) const;

};

#endif
