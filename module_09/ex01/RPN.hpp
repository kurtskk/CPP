#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>

class RPN
{
    public:

        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void calculate(const std::string& expression);

    private:

        std::stack<int> _stack;

        bool isOperator(char c) const;
        int  applyOperator(char op, int a, int b) const;
};

#endif