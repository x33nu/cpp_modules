#include <iostream>
#include <string>

#include "AddressBook.hpp"
#include "Contact.hpp"

int main() {
    AddressBook address_book;

    while (true) {
        std::string query;
        getline(std::cin, query);
        if (query == "ADD") {
            Contact newContact;
            std::cin >> newContact;
            address_book.add(newContact);
        } else if (query == "SEARCH") {
            std::cout << address_book;
            if (address_book.getSizeNonEmpty() > 0) {
                std::string input;
                std::cout << "Enter the index of the desired contact "
                          << "or 0 to abort the current operation: ";
                getline(std::cin, input);
                address_book.search(input);
            }
        } else if (query == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. List of available commands:" << std::endl
                      << " - ADD" << std::endl
                      << " - SEARCH" << std::endl
                      << " - EXIT" << std::endl;
        }
    }
}