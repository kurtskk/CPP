#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	private:

		unsigned int        _maxSize;
		std::vector<int>    _numbers;

    public:

        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw SpanFullException();

            _numbers.insert(_numbers.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;

        class SpanFullException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

#endif