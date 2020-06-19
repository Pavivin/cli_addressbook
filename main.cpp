#include "my_lib.h"

int main() {

    AddressBook& instance = AddressBook::instance();
    string ans = " ";

    while (ans != "n") {

        try {
            cout << "Do you need to add contact in the address book? [y/n]:"; cin >> ans;
        }
        catch (const char* exception) {
            std::cerr << "Error: " << exception << '\n';
        }
        if (ans == "y") {   
            try {
                Contact data;
                cout << "Enter the name: ";   cin >> data.name; // adding data to class fields
                cout << "Enter the number: "; cin >> data.number;
                cout << "Enter the city: ";   cin >> data.city;

                instance.add(instance, data);
            }
            catch(const char* exception) { // handling unexpected exceptions
                std::cerr << "Error: " << exception << '\n';
            }

        }
        else if (ans != "n") {
            cout << "Enter 'y' or 'n' \n";
        }
    }
    if (instance.contacts.empty()) { // if there were no entries, a message is displayed
        cout << "No entries in the address book \n";
    }
    else {

        int field, sort_order;
        while (true) {
            cout << "Which field sort by? \n";
            cout << "0. name \n";
            cout << "1. number \n";
            cout << "2. city \n";
            cin >> field; // sort by selected field
            cout << "In what order to sort? \n";
            cout << "0. asc \n";
            cout << "1. desc \n";
            cin >> sort_order; // ascending or descending     

            auto _field = static_cast<Contact::Field>(field);
            auto _sort_order = static_cast<Contact::SortOrder>(sort_order);

            instance.sort(instance, _field, _sort_order);
            
            if ((field == 0 || field == 1 || field == 2)
                && (sort_order == 0 || sort_order == 1))
                break;
        }
        instance.print(instance);
    }
}
