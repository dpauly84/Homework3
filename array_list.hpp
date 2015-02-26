// File Name: array_list.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 3
// Last Changed: February 26, 2015

#ifndef _ARRAY_LIST_HPP
#define _ARRAY_LIST_HPP

#include <string> // provides std::string

const int MAX_PARTS = 100;

struct Part // TODO
{
    std::string pname; // part name
    std::string pnumber; // part number format DDDD-DD where D is a digit
    double weight; // part weight
    std::string supplier1; // part suppllier1 format CDDD where C is a character
    std::string supplier2; // part supplier2 format CDDD
    int inStock; // Quantity of parts in stock
};

class Partlist
{
public:
    Partlist();
    int first();
    int end();
    int next(int current_pos);
    bool is_full();
    Part retrieve(int position);
    void remove(int position);
    void add(Part newpart);
private:
    Part m_elements[MAX_PARTS];
    int m_last;
};

#endif