#include "address_book.h"
#include "contact.h"
#include "my_lib.h"

using namespace std;

std::ostream& operator<< (std::ostream& out, const AddressBook& instance)
{
    for (Contact data : instance.contacts) {
        cout << data.name << "\t" << data.number << "\t" << data.city << "\n";
    }
    return out;
}

void AddressBook::print(const AddressBook& instance) {
    cout << "Name" << "\t" << "Number" << "\t" << "City" << "\n\n";
    cout << instance;
}

void AddressBook::add(AddressBook& instance, Contact& data) {

    instance.contacts.push_back(data);
}
void AddressBook::sort(AddressBook& instance, Contact::Field field, Contact::SortOrder sort_order) {
    // creating an interactive session
    try {
        switch (field)
        {
        case 0: {
            if (sort_order == 0) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& next) {
                        return curr.name < next.name;
                    });
            }
            else if (sort_order == 1) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& next) {
                        return curr.name > next.name;
                    });
            }
            else {
                cout << "Enter 'asc' or 'desc'\n";
            }
        }
        case 1: {
            if (sort_order == 0) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& b) {
                        return curr.number < b.number;
                    });
            }
            else if (sort_order == 1) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& b) {
                        return curr.number > b.number;
                    });
            }
            else { // on error, returns to the beginning of input
                cout << "Enter 'asc' or 'desc'\n";
            }
        }
        case 2: {
            if (sort_order == 0) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& b) {
                        return curr.city < b.city;
                    });
            }
            else if (sort_order == 1) {
                std::sort(instance.contacts.begin(), instance.contacts.end(),
                    [](const Contact& curr, const Contact& b) {
                        return curr.city > b.city;
                    });
            }
            else {
                cout << "Enter 'asc' or 'desc'\n";
            }
        }
        default: {
            cout << "Enter 'name', 'number' or 'city'\n";
        }
        }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
