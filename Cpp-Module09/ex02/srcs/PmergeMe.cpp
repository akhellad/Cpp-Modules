/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:37 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/09 13:33:37 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

const int PmergeMe::K = 5;


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        *this = other;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (!vec.empty()) {
        internalSortVector(vec, 0, vec.size() - 1);
    }
}

void PmergeMe::sortList(std::list<int>& lst) {
    if (!lst.empty()) {
        internalSortList(lst, lst.begin(), lst.end());
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& vec, int p, int r) {
    for (int i = p; i < r; i++) {
        int tempVal = vec[i + 1];
        int j = i + 1;
        while (j > p && vec[j - 1] > tempVal) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tempVal;
    }
}

void PmergeMe::mergeVector(std::vector<int>& vec, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> leftArray(vec.begin() + p, vec.begin() + q + 1);
    std::vector<int> rightArray(vec.begin() + q + 1, vec.begin() + r + 1);

    int leftIndex = 0, rightIndex = 0, mergeIndex = p;
    while (leftIndex < n1 && rightIndex < n2) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            vec[mergeIndex++] = leftArray[leftIndex++];
        } else {
            vec[mergeIndex++] = rightArray[rightIndex++];
        }
    }

    while (leftIndex < n1) {
        vec[mergeIndex++] = leftArray[leftIndex++];
    }

    while (rightIndex < n2) {
        vec[mergeIndex++] = rightArray[rightIndex++];
    }
}

void PmergeMe::internalSortVector(std::vector<int>& vec, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        internalSortVector(vec, p, q);
        internalSortVector(vec, q + 1, r);
        mergeVector(vec, p, q, r);
    } else if (r > p) {
        insertionSortVector(vec, p, r);
    }
}

void PmergeMe::insertionSortList(std::list<int>& , std::list<int>::iterator p, std::list<int>::iterator r) {
    for (std::list<int>::iterator it = p; it != r; ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != p && *--j > key) {
            std::list<int>::iterator next = j;
            *++next = *j;
        }
        *++j = key;
    }
}

void PmergeMe::mergeList(std::list<int>& , std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r) {
    std::list<int> leftList(p, q);
    std::list<int> rightList(q, r);

    std::list<int>::iterator leftIt = leftList.begin();
    std::list<int>::iterator rightIt = rightList.begin();
    std::list<int>::iterator mergeIt = p;

    while (leftIt != leftList.end() && rightIt != rightList.end()) {
        if (*leftIt <= *rightIt) {
            *mergeIt++ = *leftIt++;
        } else {
            *mergeIt++ = *rightIt++;
        }
    }

    while (leftIt != leftList.end()) {
        *mergeIt++ = *leftIt++;
    }

    while (rightIt != rightList.end()) {
        *mergeIt++ = *rightIt++;
    }
}

void PmergeMe::internalSortList(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator r) {
    if (std::distance(p, r) > 1) {  // Plus d'un élément à trier
        std::list<int>::iterator q = p;
        std::advance(q, std::distance(p, r) / 2);

        internalSortList(lst, p, q);
        internalSortList(lst, q, r);
        mergeList(lst, p, q, r);
    }
}

void PmergeMe::displayResult(std::vector<int>& vec, std::list<int>& lst) {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    clock_t start = clock();
    internalSortVector(vec, 0, vec.size() - 1);
    clock_t end = clock();
    double vectorDuration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After with vector: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process with std::vector: " << vectorDuration << " us" << std::endl;

    start = clock();
    internalSortList(lst, lst.begin(), lst.end()); // Utilisation de lst.end() directement
    end = clock();
    double listDuration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After with list: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process with std::list: " << listDuration << " us" << std::endl;
}