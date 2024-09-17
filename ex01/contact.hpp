/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:44 by tecker            #+#    #+#             */
/*   Updated: 2024/09/17 12:41:46 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phonenumber;
        std::string darkest_secret;
};


#endif