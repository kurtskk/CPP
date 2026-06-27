#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange
{
    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);

    private:

        std::map<std::string, float> _database;

        bool  isValidDate(const std::string& date) const;
        bool  isValidValue(const std::string& value) const;
        float getRate(const std::string& date) const;
};

#endif