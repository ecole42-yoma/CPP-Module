/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:38:42 by yongmkim          #+#    #+#             */
/*   Updated: 2022/09/19 14:39:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PresidentialPardonForm_hpp__
# define __PresidentialPardonForm_hpp__

# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form	{

	public:
	PresidentialPardonForm(std::string const& name = "PresidentialPardonForm");
	PresidentialPardonForm(PresidentialPardonForm const& from);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& operand);
	virtual ~PresidentialPardonForm();

	virtual void	workhorse() const;

};

#endif

