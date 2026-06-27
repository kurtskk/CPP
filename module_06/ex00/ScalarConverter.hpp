#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);

		static void convertChar(const std::string& literal);
		static void convertInt(const std::string& literal);
		static void convertFloat(const std::string& literal);
		static void convertDouble(const std::string& literal);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

    public:

        static void convert(const std::string& literal);

};

#endif