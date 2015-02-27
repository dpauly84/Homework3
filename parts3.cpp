// File Name: parts3.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 3
// Last Changed: February 26, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "parts3.hpp"
#include "utils.hpp"

using namespace std; // Allows all Standard Library items to be used

int main() {

    Partlist plist; // list for parts
    char outFileName[] = "part_list.txt"; // output file
    double weight; // User input weight to use for comparison
    int userSelection; // user input to be used for choices
    ifstream inFile(IN_FILENAME); // input file

    // Ensure files opened successfully, exit otherwise
    if (!(inFile.is_open())) {
        cout << "Error opening file\n" << "Goodbye" << endl;
        exit(EXIT_FAILURE);
    }

    // Store part information from file into Part list, exit otherwise
    get_part_data_from_file(inFile, plist);
    if (plist.end() == 0) { // Ensure data was read from file exit program otherwise
        cout << "No parts loaded from file, GoodyBye." << endl;
        exit(EXIT_FAILURE);
    }
    inFile.close(); // close input file

    // Begin running program if data loaded from file successfully
    cout << plist.end();
    while (true) {
        cout << INSTRUCTIONS << endl;
        do {
            userSelection = get_int("Enter the number of your choice: ");
            if (userSelection < 1 || userSelection > 4) // ensure selection is valid
                cout << "You must enter comparison type 1, 2, 3 or 4!" << endl;
        } while (userSelection < 1 || userSelection > 4);

        switch (userSelection) {
            case 1:
                add_part(plist); // add part to list
                break;
            case 2:
                delete_part(plist); // delete part from list
                break;
            case 3:
                save_part_list(plist, outFileName); // save part list to file
                break;
            case 4:
                return EXIT_SUCCESS; // exit program
        }
    }

} // End main

// Read part file and stores Part structure data into a Part array
int get_part_data_from_file(ifstream &inFile, Partlist &p) {
    int numRecords = 0; // Number of parts stored in partArray
    string line; // Line from part text file

    while (!inFile.eof()) { // stop when end of file (EOF) is reached
        getline(inFile, line);
        if (line.length() > 0) { // ensure something was read into the line
            p.add(read_part_record(line));
            numRecords++;
        }
    }
    return numRecords;
}

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line) {
    Part part; // Part to be filled and returned
    stringstream ss; // Stringstream to hold line from part_data.txt
    string partName; // Part name to be trimmed of whitespaces

    ss << line; // Insert line into Stringstream
    partName = read_from_string_stream(ss, NAME_LENGTH);
    rtrim(partName); // Remove whitespace characters

    // Assign values to part to be returned
    part.pname = partName;
    ss >> part.pnumber >> part.weight >> part.supplier1 >> part.supplier2 >> part.inStock;
    return part;
}

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
string read_from_string_stream(stringstream &fromStr, int length) {
    char tmp[LINE_LENGTH] = ""; // Temporary C_String
    fromStr.read(tmp, length);
    string returnStr(tmp); // convert tmp C_String to string for return
    return returnStr;
}

// remove whitespaces from end of string
void rtrim(string &s) {
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}

// Sends part data to file based on user selection and weight


// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part part) {
    // Set precision
    os.setf(ios::fixed);
    os.setf(ios::showpoint);
    os.precision(2);

    // Send part out output stream
    os << part.pname << " "
            << part.pnumber << ", "
            << part.weight << " N, "
            << part.inStock << " "
            << "in stock" << endl;
}

// Adds part from user input to parts list
bool add_part(Partlist &parts) {
    Part addPart; // part to be added
    char tempName[17]; // temporary hold part name in c-string
    cout << "\nAdding a new part..." << endl;
    cout << "\tEnter part name: ";

    // get user input and store in part to be saved to the list
    cin.getline(tempName, 17); // read 17 characters
    addPart.pname = tempName;  // convert c-string to std::string
    addPart.pnumber = get_string("\tEnter a part number: ", 7);
    addPart.weight = get_double("\tEnter weight: ");
    addPart.supplier1 = get_string("\tEnter supplier code of primary supplier: ", 4);
    addPart.supplier2 = get_string("\tEnter supplier code of secondary supplier: ", 4);
    addPart.inStock = get_int("\tEnter number in stock: ");
    cout << endl;
    parts.add(addPart); // add part to the parts list

}

// delete part with matching part number from parts list
void delete_part(Partlist &parts) {
    string partNumCompare;
    Part temp;
    partNumCompare = get_string("\nEnter the part number of the part to delete: ", 7);

    for (int i = 1; i <= parts.end(); ++i) {
        if (parts.retrieve(i).pnumber == partNumCompare) {
            cout << "Deleted the part: ";
            print_part(cout, parts.retrieve(i));
            parts.remove(i);
            break;
        }
    }
}

// output parts list to file(outfile_name[])
void save_part_list(Partlist &parts, char outfile_name[]) {
    ofstream outFile(outfile_name);

    if (!(outFile.is_open())) {
        cout << "Error opening file\n" << "Goodbye" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= parts.end(); ++i) {
        print_part(outFile, parts.retrieve(i));
    }

    cout << "\nThe current list of parts was saved in the file "
            << outfile_name << "." << endl;

    outFile.close();

}

// returns string with a set length of characters
string get_string(string prompt, int length) {
    string returnString;
    bool isValidString = true; // conversion status

    do {
        if (!isValidString) {
            cout << "You must enter " << length << " characters." << endl;
        }
        cout << prompt;
        cin >> returnString;
        if (returnString.length() == length) {
            isValidString = true;
        } else isValidString = false;
    } while (!isValidString);
    return returnString;
}