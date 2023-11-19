#include <stdio.h>
    #include <string.h>
    
    // Maximum number of contacts
    #define MAX_CONTACTS 100
    
    // Structure to represent a contact
    struct Contact {
        char name[50];
        char phoneNumber[20];
        char emailAddress[50];
    };
    
    // Function prototypes
    void addContact(struct Contact contacts[], int *numContacts);
    void viewContacts(const struct Contact contacts[], int numContacts);
    void editContact(struct Contact contacts[], int numContacts);
    void deleteContact(struct Contact contacts[], int *numContacts);
    
    int main() {
        struct Contact contacts[MAX_CONTACTS];
        int numContacts = 0;
        int choice;
    
        do {
            printf("\nContact Management System\n");
            printf("1. Add Contact\n");
            printf("2. View Contacts\n");
            printf("3. Edit Contact\n");
            printf("4. Delete Contact\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
    
            switch (choice) {
                case 1:
                    addContact(contacts, &numContacts);
                    break;
                case 2:
                    viewContacts(contacts, numContacts);
                    break;
                case 3:
                    editContact(contacts, numContacts);
                    break;
                case 4:
                    deleteContact(contacts, &numContacts);
                    break;
                case 5:
                    printf("Exiting program. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a valid option.\n");
            }
        } while (choice != 5);
    
        return 0;
    }
    
    void addContact(struct Contact contacts[], int *numContacts) {
        if (*numContacts < MAX_CONTACTS) {
            printf("Enter contact details:\n");
            printf("Name: ");
            scanf("%s", contacts[*numContacts].name);
            printf("Phone Number: ");
            scanf("%s", contacts[*numContacts].phoneNumber);
            printf("Email Address: ");
            scanf("%s", contacts[*numContacts].emailAddress);
            (*numContacts)++;
            printf("Contact added successfully.\n");
        } else {
            printf("Contact list is full. Cannot add more contacts.\n");
        }
    }
    
    void viewContacts(const struct Contact contacts[], int numContacts) {
        if (numContacts > 0) {
            printf("Contact List:\n");
            for (int i = 0; i < numContacts; i++) {
                printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phoneNumber, contacts[i].emailAddress);
            }
        } else {
            printf("Contact list is empty.\n");
        }
    }
    
    void editContact(struct Contact contacts[], int numContacts) {
        if (numContacts > 0) {
            int index;
            printf("Enter the index of the contact to edit (1 to %d): ", numContacts);
            scanf("%d", &index);
    
            if (index >= 1 && index <= numContacts) {
                index--;  // Adjust index to array index (0-based)
                printf("Enter new contact details:\n");
                printf("Name: ");
                scanf("%s", contacts[index].name);
                printf("Phone Number: ");
                scanf("%s", contacts[index].phoneNumber);
                printf("Email Address: ");
                scanf("%s", contacts[index].emailAddress);
                printf("Contact edited successfully.\n");
            } else {
                printf("Invalid index. Please enter a valid index.\n");
            }
        } else {
            printf("Contact list is empty. Cannot edit.\n");
        }
    }
    
    void deleteContact(struct Contact contacts[], int *numContacts) {
        if (*numContacts > 0) {
            int index;
            printf("Enter the index of the contact to delete (1 to %d): ", *numContacts);
            scanf("%d", &index);
    
            if (index >= 1 && index <= *numContacts) {
                index--;  // Adjust index to array index (0-based)
                // Shift elements to fill the gap
                for (int i = index; i < *numContacts - 1; i++) {
                    strcpy(contacts[i].name, contacts[i + 1].name);
                    strcpy(contacts[i].phoneNumber, contacts[i + 1].phoneNumber);
                    strcpy(contacts[i].emailAddress, contacts[i + 1].emailAddress);
                }
                (*numContacts)--;
                printf("Contact deleted successfully.\n");
            } else {
                printf("Invalid index. Please enter a valid index.\n");
            }
        } else {
            printf("Contact list is empty. Cannot delete.\n");
        }
    }