#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <ctime>
# include <algorithm>
# include <climits>

class PmergeMe
{
    public:

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parse(int argc, char* argv[]);
        void sort();

    private:

        std::vector<int> _vec;
        std::deque<int>  _deq;

        std::vector<int> jacobsthal(int n);

        void mergeInsertVector(std::vector<int>& vec);
        void mergeInsertDeque(std::deque<int>& deq);
};

#endif