/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:38 by tecker            #+#    #+#             */
/*   Updated: 2024/09/20 11:22:26 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

void    Contact::set_fn(const std::string fn)
{
    this->first_name = fn;
}

void    Contact::set_ln(const std::string ln)
{
    this->last_name = ln;
}

void    Contact::set_nn(const std::string nn)
{
    this->nickname = nn;
}

void    Contact::set_phone(const std::string phone)
{
    this->phonenumber = phone;
}

void    Contact::set_ds(const std::string ds)
{
    this->darkest_secret = ds;   
}

std::string Contact::get_fn(void)
{
    return (first_name);
}

std::string Contact::get_ln(void)
{
    return (last_name);
}

std::string Contact::get_nn(void)
{
    return (nickname);
}

std::string Contact::get_phone(void)
{
    return (phonenumber);
}

std::string Contact::get_ds(void)
{
    return (darkest_secret);
}