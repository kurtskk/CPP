#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(char op, int a, int b) const
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero.");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator.");
}

void RPN::calculate(const std::string& expression)
{
    while (!_stack.empty())
        _stack.pop();

    std::istringstream ss(expression);
    std::string        token;

    while (ss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands.");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            _stack.push(applyOperator(token[0], a, b));
        }
        else
        {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression.");

    std::cout << _stack.top() << std::endl;
}