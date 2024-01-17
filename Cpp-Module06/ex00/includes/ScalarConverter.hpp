/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:08:02 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/16 14:32:40 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>

class ScalarConverter
{
	public:
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);

		enum	argType {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			UNKNOWN
		};
		static void setArgType(argType type);
		static argType getArgType();
		static void convert(std::string &input);
		static void CharConverter(std::string const &input);
		static void IntConverter(std::string const &input);
		static void FloatConverter(std::string &input);
		static void DoubleConverter(std::string const &input);

	private:
		static argType _argType;
};

bool check_input(std::string &input);
void parsing(std::string const &input);

#endif