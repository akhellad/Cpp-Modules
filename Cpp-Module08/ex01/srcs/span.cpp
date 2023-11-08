#include "../includes/span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int n) : _N(n) {
    _numbers.reserve(n);
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N) {
        throw std::runtime_error("Span is full");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::runtime_error("Not enough numbers to calculate the span");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = sortedNumbers[1] - sortedNumbers[0];

    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::runtime_error("Not enough numbers to calculate the span");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    return sortedNumbers.back() - sortedNumbers.front();
}

