// File Name: array_list.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 3
// Last Changed: February 26, 2015

#include "array_list.hpp"
using namespace std;

// constructor
Partlist::Partlist() {
    m_last = -1;
}

// return "one past the end" position of the array list
int Partlist::end() {
    return m_last + 1;
}

// returns position one after the current position of array list
int Partlist::next(int current_pos) {
    return m_last + 1;
}

// returns true if the array list is full, and false if not full
bool Partlist::is_full() {
    if (m_last == MAX_PARTS) return true;
    else return false;
}

// return elemenent at position of array list
Part Partlist::retrieve(int position) {
    if( position >= 0 && position <= m_last){
        return m_elements[position];
    } // TODO System exit

}

// delete element at position of array list
void Partlist::remove(int position) {
    if( position >= 0 && position <= m_last){
        m_elements[position] = m_elements[m_last--];
    }
}

// add element to array list
void Partlist::add(Part newpart) {
    m_elements[++m_last] = newpart;
}