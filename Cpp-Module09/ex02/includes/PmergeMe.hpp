/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:54:33 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/09 11:07:44 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void displayResult(std::vector<int>& vec, std::list<int>& lst);
    void sortVector(std::vector<int>& vec);
    void sortList(std::list<int>& lst);

private:
    static const int K;
    static void insertionSortVector(std::vector<int>& vec, int p, int r);
    static void mergeVector(std::vector<int>& vec, int p, int q, int r);
    void internalSortVector(std::vector<int>& vec, int p, int r);

    static void insertionSortList(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator r);
    static void mergeList(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r);
    void internalSortList(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator r);
};

#endif // PMERGEME_HPP

