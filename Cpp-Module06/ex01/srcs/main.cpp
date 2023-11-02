/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:50 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 13:06:53 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

int main(void)
{
	Data *data;
	uintptr_t raw;

	data = new Data;
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "Data: " << data->s1 << " " << data->n << " " << data->s2 << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "Raw: " << raw << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "Data 2 : " << data2->s1 << " " << data2->n << " " << data2->s2 << std::endl;
	if (data == data2)
		std::cout << "Data and Data2 are the same" << std::endl;
	else
		std::cout << "Data and Data2 are not the same" << std::endl;
	delete data;
	return (0);
}