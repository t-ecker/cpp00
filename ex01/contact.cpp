/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:38 by tecker            #+#    #+#             */
/*   Updated: 2024/09/20 13:02:59 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

void    Contact::set_fn(const std::string fn)
{
    this->_first_name = fn;
}

void    Contact::set_ln(const std::string ln)
{
    this->_last_name = ln;
}

void    Contact::set_nn(const std::string nn)
{
    this->_nickname = nn;
}

void    Contact::set_phone(const std::string phone)
{
    this->_phonenumber = phone;
}

void    Contact::set_ds(const std::string ds)
{
    this->_darkest_secret = ds;   
}

std::string Contact::get_fn(void)
{
    return (_first_name);
}

std::string Contact::get_ln(void)
{
    return (_last_name);
}

std::string Contact::get_nn(void)
{
    return (_nickname);
}

std::string Contact::get_phone(void)
{
    return (_phonenumber);
}

std::string Contact::get_ds(void)
{
    return (_darkest_secret);
}