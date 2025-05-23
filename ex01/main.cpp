/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:27:47 by tecker            #+#    #+#             */
/*   Updated: 2024/09/19 15:07:51 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int main(void)
{
    PhoneBook   pbook;
    pbook.index = 0;
    int res;

    while (1)
    {
        res = pbook.std_prompt();
        if (res == -1)
            exit(0);
        else if (res == 1)
            pbook.add();
        else if (res == 2)
            pbook.search();
    }
    
    return (0);
}