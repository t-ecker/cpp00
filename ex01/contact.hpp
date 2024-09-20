/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:44 by tecker            #+#    #+#             */
/*   Updated: 2024/09/20 11:23:31 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phonenumber;
        std::string darkest_secret;

    public:
        void    set_fn(const std::string fn);
        void    set_ln(const std::string ln);
        void    set_nn(const std::string nn);
        void    set_phone(const std::string phone);
        void    set_ds(const std::string ds);
        
        std::string get_fn(void);
        std::string get_ln(void);
        std::string get_nn(void);
        std::string get_phone(void);
        std::string get_ds(void);


};


#endif