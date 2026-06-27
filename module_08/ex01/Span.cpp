#include "Span.hpp"

const char* Span::SpanFullException::what() const throw()
{
    return "Error: span is full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "Error: not enough numbers to find a span";
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}