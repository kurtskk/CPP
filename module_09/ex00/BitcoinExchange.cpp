#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}


// ============================================================
//  Database
// ============================================================

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // pula o header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;

        std::getline(ss, date, ',');
        std::getline(ss, value);

        if (date.empty() || value.empty())
            continue;

        _database[date] = std::atof(value.c_str());
    }
}


// ============================================================
//  Validações
// ============================================================

bool BitcoinExchange::isValidValue(const std::string& value) const
{
    if (value.empty())
        return false;

    int dotCount   = 0;
    int minusCount = 0;
    size_t start   = 0;

    // sinal negativo so no inicio
    if (value[0] == '-')
    {
        minusCount++;
        start = 1;
    }

    // depois do sinal precisa ter pelo menos um digito
    if (start >= value.length())
        return false;

    for (size_t i = start; i < value.length(); i++)
    {
        if (value[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)  // mais de um ponto
                return false;
        }
        else if (!isdigit(value[i]))
            return false;
    }

    // nao pode terminar com ponto
    if (value[value.length() - 1] == '.')
        return false;

    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // verifica se ano, mes e dia sao todos digitos
    for (int i = 0; i < 4; i++)
        if (!isdigit(date[i])) return false;
    for (int i = 5; i < 7; i++)
        if (!isdigit(date[i])) return false;
    for (int i = 8; i < 10; i++)
        if (!isdigit(date[i])) return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}


// ============================================================
//  Busca no banco de dados
// ============================================================

float BitcoinExchange::getRate(const std::string& date) const
{
    // lower_bound retorna iterator pra primeira chave >= date
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    // se achou exatamente a data
    if (it != _database.end() && it->first == date)
        return it->second;

    // se não achou, volta uma posição (data imediatamente anterior)
    if (it == _database.begin())
        throw std::runtime_error("Error: date out of range.");

    --it;
    return it->second;
}


// ============================================================
//  Processamento do arquivo de entrada
// ============================================================
// estudar so essa parte
void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // pula o header

    while (std::getline(file, line))
    {
        // separa data e valor pelo " | "
        size_t separator = line.find(" | ");
        if (separator == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date  = line.substr(0, separator);
        std::string value = line.substr(separator + 3);

        // valida data
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // valida valor
        if (!isValidValue(value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        float amount = std::atof(value.c_str());

        if (amount < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (amount > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // busca a taxa e calcula
        try
        {
            float rate   = getRate(date);
            float result = amount * rate;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}