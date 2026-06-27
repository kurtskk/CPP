#include "ScalarConverter.hpp"


// ============================================================
//  Detectores de tipo
// ============================================================

bool ScalarConverter::isChar(const std::string& literal)
{
    // formato: 'x' onde x é um único caractere
    return literal.length() == 3
        && literal[0] == '\''
        && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal)
{
    // só dígitos, com possível sinal no início
    int start = 0;

    if (literal[0] == '-' || literal[0] == '+')
        start = 1;

    if (literal.length() == (size_t)start)
        return false;

    for (size_t i = start; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    // termina com f: 4.2f, -inff, nanf
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    if (literal[literal.length() - 1] != 'f')
        return false;

    // remove o f do final e verifica se é número válido
    std::string withoutF = literal.substr(0, literal.length() - 1);
    bool hasDot = false;
    int  start  = 0;

    if (withoutF[0] == '-' || withoutF[0] == '+')
        start = 1;

    for (size_t i = start; i < withoutF.length(); i++)
    {
        if (withoutF[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!isdigit(withoutF[i]))
            return false;
    }
    return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    // sem f no final, mas com ponto
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    bool hasDot = false;
    int  start  = 0;

    if (literal[0] == '-' || literal[0] == '+')
        start = 1;

    for (size_t i = start; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!isdigit(literal[i]))
            return false;
    }
    return hasDot;
}


// ============================================================
//  Impressores (recebem o valor como double e convertem)
// ============================================================

void ScalarConverter::printChar(double value)
{
    // verifica se está fora do range do char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);

    // verifica se é exibível
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    // verifica se está fora do range do int
    if (std::isnan(value) || std::isinf(value)
        || value > INT_MAX || value < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    float f = static_cast<float>(value);

    // sempre mostra pelo menos uma casa decimal
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        std::cout << "float: " << f;
        // se não tem parte decimal visível, adiciona .0
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::cout << "double: " << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}


// ============================================================
//  Conversores (detectam o tipo e extraem o valor)
// ============================================================

void ScalarConverter::convertChar(const std::string& literal)
{
    // pega o caractere entre as aspas
    double value = static_cast<double>(literal[1]);

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertInt(const std::string& literal)
{
    double value = static_cast<double>(std::atoi(literal.c_str()));

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFloat(const std::string& literal)
{
    double value = static_cast<double>(std::atof(literal.c_str()));

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertDouble(const std::string& literal)
{
    double value = std::atof(literal.c_str());

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}


// ============================================================
//  Método principal
// ============================================================

void ScalarConverter::convert(const std::string& literal)
{
    if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "Error: invalid literal" << std::endl;
}