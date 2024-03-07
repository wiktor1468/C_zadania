//
// Created by wikto on 05.03.2024.
//
#include <stdio.h>
#include <string.h>


#define MAX_CONTACTS 100


typedef struct {
    char name[50];
    char surname[30];
    char number[9];
} Contact;


typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count; //  liczba kontaktów
} ContactBook;


void addContact(ContactBook *addressBook, const char *name, const char *surname, const char *number) {
    if (addressBook->count < MAX_CONTACTS) {
        strcpy(addressBook->contacts[addressBook->count].name, name);
        strcpy(addressBook->contacts[addressBook->count].surname, surname);
        strcpy(addressBook->contacts[addressBook->count].number, number);
        addressBook->count++;
        printf("Kontakt zostal  dodany .\n");
    } else {
        printf("Ksiazka adresowa jest pelna.\n");
    }
}


void searchContact(const ContactBook *addressBook, const char *surname) {
    int found = 0;
    for (int i = 0; i < addressBook->count; i++) {
        if (strcmp(addressBook->contacts[i].surname, surname) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", addressBook->contacts[i].name);
            printf("Nazwisko: %s\n", addressBook->contacts[i].surname);
            printf("Numer telefonu: %s\n", addressBook->contacts[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", surname);
    }
}


void deleteContact(ContactBook *addressBook, const char *surname) {
    int found = 0;
    for (int i = 0; i < addressBook->count; i++) {
        if (strcmp(addressBook->contacts[i].surname, surname) == 0) {
            // przesuniecie pozostalych kontaktow
            for (int j = i; j < addressBook->count - 1; j++) {
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
                strcpy(addressBook->contacts[j].surname, addressBook->contacts[j + 1].surname);
                strcpy(addressBook->contacts[j].number, addressBook->contacts[j + 1].number);
            }
            addressBook->count--;
            printf("Kontakt  usunięty pomyślnie.");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu o takim nazwisku");
    }
}

void displayAllContacts(const ContactBook *addressBook) {
    printf("Wszystkie kontakty:\n");
    for (int i = 0; i < addressBook->count; i++) {
        printf("Imie: %s\n", addressBook->contacts[i].name);
        printf("Nazwisko: %s\n", addressBook->contacts[i].surname);
        printf("Numer telefonu: %s\n", addressBook->contacts[i].number);
        printf("\n");
    }
}

int main() {
    ContactBook myAddressBook = { .count = 0 };

    // interfejs
    int choice;
    char surname[30];
    char name[15];
    char number[9];

    do {
        printf("\nWybierz opcje:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl  kontakty\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Podaj imie: ");
                scanf("%s", name);
                printf("Podaj nazwisko: ");
                scanf("%s", surname);
                printf("Podaj numer telefonu: ");
                scanf("%s", number);
                addContact(&myAddressBook, name, surname, number);
                break;
            case 2:
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", surname);
                searchContact(&myAddressBook, surname);
                break;
            case 3:
                printf("Podaj nazwisko do usuniecia: ");
                scanf("%s", surname);
                deleteContact(&myAddressBook, surname);
                break;
            case 4:
                displayAllContacts(&myAddressBook);
                break;
            case 0:
                break;
            default:
                printf("Zly wybor.\n");
        }
    } while (choice != 0);

    return 0;
}
