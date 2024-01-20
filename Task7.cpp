#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Contact structure to store contact information
struct Contact {
    string name;
    string phone;
    string email;
};

// Function prototypes
void displayMenu();
void addContact(vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);
void updateContact(vector<Contact>& contacts);

int main() {
    vector<Contact> contacts;  // Vector to store contacts
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                deleteContact(contacts);
                break;
            case 3:
                updateContact(contacts);
                break;
            case 4:
                // Display contacts
                cout << "\nContacts:\n";
                for (const auto& contact : contacts) {
                    cout << "Name: " << contact.name << "\tPhone: " << contact.phone << "\tEmail: " << contact.email << "\n";
                }
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n*** Contact Management System ***\n";
    cout << "1. Add Contact\n";
    cout << "2. Delete Contact\n";
    cout << "3. Update Contact\n";
    cout << "4. Display Contacts\n";
    cout << "5. Exit\n";
}

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "\nEnter contact details:\n";
    cout << "Name: ";
    cin >> newContact.name;
    cout << "Phone: ";
    cin >> newContact.phone;
    cout << "Email: ";
    cin >> newContact.email;

    contacts.push_back(newContact);
    cout << "Contact added successfully!\n";
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete.\n";
        return;
    }

    string nameToDelete;
    cout << "\nEnter the name of the contact to delete: ";
    cin >> nameToDelete;

    auto it = find_if(contacts.begin(), contacts.end(), [nameToDelete](const Contact& c) {
        return c.name == nameToDelete;
    });

    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "Contact deleted successfully!\n";
    } else {
        cout << "Contact not found.\n";
    }
}

void updateContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to update.\n";
        return;
    }

    string nameToUpdate;
    cout << "\nEnter the name of the contact to update: ";
    cin >> nameToUpdate;

    auto it = find_if(contacts.begin(), contacts.end(), [nameToUpdate](const Contact& c) {
        return c.name == nameToUpdate;
    });

    if (it != contacts.end()) {
        cout << "Enter new contact details:\n";
        cout << "Name: ";
        cin >> it->name;
        cout << "Phone: ";
        cin >> it->phone;
        cout << "Email: ";
        cin >> it->email;

        cout << "Contact updated successfully!\n";
    } else {
        cout << "Contact not found.\n";
    }
}
