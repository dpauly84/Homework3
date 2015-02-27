// File Name: array_list.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 3
// Last Changed: February 26, 2015

#include <iostream>
#include <cstdlib>
#include "array_list.hpp"

using namespace std;

// constructor
Partlist::Partlist() {
    m_last = 0;
}

// return "one past the end" position of the array list
int Partlist::end() {
    return m_last;
}

// returns position one after the current position of array list
int Partlist::next(int current_pos) {
    return current_pos + 1;
}

// returns true if the array list is full, and false if not full
bool Partlist::is_full() {
    if (m_last == MAX_PARTS) return true;
    else return false;
}

// return elemenent at position of array list
Part Partlist::retrieve(int position) {
    if (position > 0 && position <= m_last) {
        return m_elements[position - 1];
    } else {
        std::cout << "Cannot retrieve position " << position << ". It is out of bounds\n"
                "Program exiting.\nGoodbye" << std::endl;
        exit(EXIT_FAILURE);
    }

}

// delete element at position of array list
void Partlist::remove(int position) {
    if (position >= 0 && position <= m_last) {
        m_elements[position - 1] = m_elements[--m_last];
    }
}

// add element to array list
void Partlist::add(Part newpart) {
    if(m_last != (MAX_PARTS)) {
        m_elements[m_last++] = newpart;
    }
}