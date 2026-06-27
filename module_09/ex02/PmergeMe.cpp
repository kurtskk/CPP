#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}


// ============================================================
//  Parse
// ============================================================

void PmergeMe::parse(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::istringstream ss(argv[i]);
        long n;

        if (!(ss >> n) || n <= 0 || n > INT_MAX)
            throw std::runtime_error("Error: invalid argument.");

        std::string leftover;
        if (ss >> leftover)
            throw std::runtime_error("Error: invalid argument.");

        if (std::find(_vec.begin(), _vec.end(), (int)n) != _vec.end())
            throw std::runtime_error("Error: duplicate number.");

        _vec.push_back((int)n);
        _deq.push_back((int)n);
    }
}


// ============================================================
//  Jacobsthal
// ============================================================

std::vector<int> PmergeMe::jacobsthal(int n)
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    while (seq.back() < n)
    {
        int size = seq.size();
        seq.push_back(seq[size - 1] + 2 * seq[size - 2]);
    }

    return seq;
}


// ============================================================
//  Vector
// ============================================================

void PmergeMe::mergeInsertVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasLeftover = false;
    int  leftover    = -1;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    if (vec.size() % 2 != 0)
    {
        leftover    = vec.back();
        hasLeftover = true;
    }

    // extrai os maiores
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].first);

    // ordena os maiores recursivamente
    mergeInsertVector(larger);

    // ordena os pairs pelo first (maior) usando sort
    // assim ficam na mesma ordem que larger apos recursao
    std::vector<std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end());

    // extrai smaller e pairValues na ordem correta
    std::vector<int> smaller;
    std::vector<int> pairValues;
    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        smaller.push_back(sortedPairs[i].second);
        pairValues.push_back(sortedPairs[i].first);
    }

    // b1 vai pro inicio
    larger.insert(larger.begin(), smaller[0]);

    if (smaller.size() == 1)
    {
        if (hasLeftover)
        {
            std::vector<int>::iterator pos = std::lower_bound(
                larger.begin(), larger.end(), leftover);
            larger.insert(pos, leftover);
        }
        vec = larger;
        return;
    }

    std::vector<int>  jacob    = jacobsthal(smaller.size());
    std::vector<bool> inserted(smaller.size(), false);
    inserted[0] = true;

    for (size_t i = 2; i < jacob.size(); i++)
    {
        int idx = jacob[i] - 1;
        if (idx >= (int)smaller.size())
            idx = smaller.size() - 1;

        for (int j = idx; j >= 0; j--)
        {
            if (inserted[j])
                continue;

            std::vector<int>::iterator pairPos = std::lower_bound(
                larger.begin(), larger.end(), pairValues[j]);

            std::vector<int>::iterator pos = std::lower_bound(
                larger.begin(), pairPos + 1, smaller[j]);

            larger.insert(pos, smaller[j]);
            inserted[j] = true;
        }
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator pos = std::lower_bound(
            larger.begin(), larger.end(), leftover);
        larger.insert(pos, leftover);
    }

    vec = larger;
}


// ============================================================
//  Deque
// ============================================================

void PmergeMe::mergeInsertDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasLeftover = false;
    int  leftover    = -1;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }

    if (deq.size() % 2 != 0)
    {
        leftover    = deq.back();
        hasLeftover = true;
    }

    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].first);

    mergeInsertDeque(larger);

    // ordena os pairs pelo first usando sort
    std::vector<std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end());

    std::deque<int>  smaller;
    std::vector<int> pairValues;
    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        smaller.push_back(sortedPairs[i].second);
        pairValues.push_back(sortedPairs[i].first);
    }

    larger.insert(larger.begin(), smaller[0]);

    if (smaller.size() == 1)
    {
        if (hasLeftover)
        {
            std::deque<int>::iterator pos = std::lower_bound(
                larger.begin(), larger.end(), leftover);
            larger.insert(pos, leftover);
        }
        deq = larger;
        return;
    }

    std::vector<int>  jacob    = jacobsthal(smaller.size());
    std::vector<bool> inserted(smaller.size(), false);
    inserted[0] = true;

    for (size_t i = 2; i < jacob.size(); i++)
    {
        int idx = jacob[i] - 1;
        if (idx >= (int)smaller.size())
            idx = smaller.size() - 1;

        for (int j = idx; j >= 0; j--)
        {
            if (inserted[j])
                continue;

            std::deque<int>::iterator pairPos = std::lower_bound(
                larger.begin(), larger.end(), pairValues[j]);

            std::deque<int>::iterator pos = std::lower_bound(
                larger.begin(), pairPos + 1, smaller[j]);

            larger.insert(pos, smaller[j]);
            inserted[j] = true;
        }
    }

    if (hasLeftover)
    {
        std::deque<int>::iterator pos = std::lower_bound(
            larger.begin(), larger.end(), leftover);
        larger.insert(pos, leftover);
    }

    deq = larger;
}


// ============================================================
//  Sort
// ============================================================

void PmergeMe::sort()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertVector(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertDeque(_deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
