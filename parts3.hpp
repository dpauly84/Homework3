// File Name: parts3.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 3
// Last Changed: February 26, 2015

#ifndef _PART1_HPP_
#define _PART1_HPP_
#include <string>
#include "array_list.hpp"


// CONSTANT VARIABLES
const int LINE_LENGTH = 45; // length of line from part file
const int NAME_LENGTH = 17; // Max length of part name (pname) in part file

const char *IN_FILENAME = // name of part input file to be read from
        "/home/shockerpc/ClionProjects/Homework3/part_data.txt";

const std::string INSTRUCTIONS =
        "\nAvailable choices:\n"
                "\t1. Add part\n"
                "\t2. Delete part\n"
                "\t3. Save part list\n"
                "\t4. Quit\n";

// Read part file and stores Part structure data into a Part array
int get_part_data_from_file(std::ifstream &inFile, Partlist& p);

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line);

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
std::string read_from_string_stream(std::stringstream &from_str, int length);

// remove whitespaces from end of string
void rtrim(std::string &s);

// Sends part data to file based on user selection and weight
int send_part_data_to_file
        (std::ofstream &outFile, Part partArray[], int records, int selection, double weight);

// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part part);

// Adds part from user input to parts list
bool add_part(Partlist &parts);

// delete part with matching part number from parts list
void delete_part(Partlist &parts);

// output parts list to file(outfile_name[])
void save_part_list(Partlist &parts, char outfile_name[]);

// returns string with a set length of characters
std::string get_string(std::string prompt, unsigned int length);

#endif