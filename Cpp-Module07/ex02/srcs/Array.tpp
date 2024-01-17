/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:47:59 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/17 12:48:09 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n) {
    data = new T[length]();
}

template <typename T>
Array<T>::Array(const Array<T> &other) : length(other.length) {
    data = new T[length]();
    for (unsigned int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new T[length]();
        for (unsigned int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw std::exception();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length) {
        throw std::exception();
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}
