#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using std::string;

class Contact {
public:
    string name, number, city; // additional class for address book
	enum Field
	{
		Name,
		Number,
		City
	};
	enum SortOrder
	{
		Asc,
		Desc
	};
};

#endif // CONTACT_H
