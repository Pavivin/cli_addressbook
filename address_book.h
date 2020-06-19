#pragma once
#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "contact.h"
#include "my_lib.h"

using std::string;
using std::vector;

class AddressBook {
public:
    static AddressBook& instance() {
        static AddressBook theSingleInstance;
        return theSingleInstance;
    }

    friend std::ostream& operator<< (std::ostream& out, const AddressBook& instance);

    vector <Contact> contacts; // vector which stores the address book

    void add(AddressBook&, Contact&);
    void print(const AddressBook& instance);
    void sort(AddressBook& instance, string field, string sort_order);


private:
    AddressBook() {}
    AddressBook(const AddressBook& root) = delete;
    AddressBook& operator=(const AddressBook& c) = delete;
};

#endif // ADDRESS_BOOK_H
