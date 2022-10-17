/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:58:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 11:59:10 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RobotomyRequestForm_hpp__
# define __RobotomyRequestForm_hpp__

# include "Form.hpp"
# include <string>

class RobotomyRequestForm : public Form	{

	public:
	RobotomyRequestForm(std::string const& name = "RobotomyRequestForm");
	RobotomyRequestForm(RobotomyRequestForm const& from);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& operand);
	virtual ~RobotomyRequestForm();

	virtual void	workhorse() const;

};

#endif

