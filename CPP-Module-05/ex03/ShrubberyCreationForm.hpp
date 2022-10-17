/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:25:54 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 10:23:02 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ShrubberyCreationForm_hpp__
# define __ShrubberyCreationForm_hpp__

# include "Form.hpp"
# include <string>

class ShrubberyCreationForm : public Form	{

	public:
	ShrubberyCreationForm(std::string const& name = "ShrubberyCreationForm");
	ShrubberyCreationForm(ShrubberyCreationForm const& from);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& operand);
	virtual ~ShrubberyCreationForm();

	virtual void	workhorse() const;

};

#endif
