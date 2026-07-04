#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

struct Contact
{
    int id;
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
};

void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();
void sortContacts();
int getNextId();

int main()
{
    int choice;

    while (1)
    {
        printf("\n=====================================================\n");
        printf("          CONTACT MANAGEMENT SYSTEM\n");
        printf("=====================================================\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Sort Contacts\n");
        printf("7. Exit\n");
        printf("-----------------------------------------------------\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            displayContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            updateContact();
            break;

        case 5:
            deleteContact();
            break;

        case 6:
            sortContacts();
            break;

        case 7:
            printf("\nThank You!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }
}

int getNextId()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return 1;

    struct Contact c;
    int last = 0;

    while (fread(&c, sizeof(c), 1, fp))
        last = c.id;

    fclose(fp);

    return last + 1;
}

void addContact()
{
    FILE *fp = fopen(FILE_NAME, "ab");

    struct Contact c;

    c.id = getNextId();

    printf("\nEnter Name : ");
    scanf(" %[^\n]", c.name);

    printf("Enter Phone : ");
    scanf("%s", c.phone);

    printf("Enter Email : ");
    scanf("%s", c.email);

    printf("Enter Address : ");
    scanf(" %[^\n]", c.address);

    fwrite(&c, sizeof(c), 1, fp);

    fclose(fp);

    printf("\nContact Added Successfully.\n");
}

void displayContacts()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("\nNo Contacts Found.\n");
        return;
    }

    struct Contact c;

    printf("\n-------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-25s %-20s\n",
           "ID", "Name", "Phone", "Email", "Address");
    printf("-------------------------------------------------------------------------------------\n");

    while (fread(&c, sizeof(c), 1, fp))
    {
        printf("%-5d %-20s %-15s %-25s %-20s\n",
               c.id,
               c.name,
               c.phone,
               c.email,
               c.address);
    }

    fclose(fp);
}

void searchContact()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("\nNo Contacts Found.\n");
        return;
    }

    char name[50];

    printf("\nEnter Name : ");
    scanf(" %[^\n]", name);

    struct Contact c;
    int found = 0;

    while (fread(&c, sizeof(c), 1, fp))
    {
        if (strcmp(c.name, name) == 0)
        {
            printf("\nContact Found\n");
            printf("----------------------------\n");
            printf("ID      : %d\n", c.id);
            printf("Name    : %s\n", c.name);
            printf("Phone   : %s\n", c.phone);
            printf("Email   : %s\n", c.email);
            printf("Address : %s\n", c.address);

            found = 1;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nContact Not Found.\n");
}

void updateContact()
{
    FILE *fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL)
    {
        printf("\nNo Contacts Found.\n");
        return;
    }

    int id;

    printf("\nEnter Contact ID : ");
    scanf("%d", &id);

    struct Contact c;
    int found = 0;

    while (fread(&c, sizeof(c), 1, fp))
    {
        if (c.id == id)
        {
            printf("\nEnter New Name : ");
            scanf(" %[^\n]", c.name);

            printf("Enter New Phone : ");
            scanf("%s", c.phone);

            printf("Enter New Email : ");
            scanf("%s", c.email);

            printf("Enter New Address : ");
            scanf(" %[^\n]", c.address);

            fseek(fp, -sizeof(c), SEEK_CUR);

            fwrite(&c, sizeof(c), 1, fp);

            found = 1;

            printf("\nContact Updated Successfully.\n");

            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nContact ID Not Found.\n");
}

void deleteContact()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("\nNo Contacts Found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");

    int id;

    printf("\nEnter Contact ID : ");
    scanf("%d", &id);

    struct Contact c;

    int found = 0;

    while (fread(&c, sizeof(c), 1, fp))
    {
        if (c.id != id)
        {
            fwrite(&c, sizeof(c), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("\nContact Deleted Successfully.\n");
    else
        printf("\nContact ID Not Found.\n");
}

void sortContacts()
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("\nNo Contacts Found.\n");
        return;
    }

    struct Contact contacts[100];
    int count = 0;

    while (fread(&contacts[count], sizeof(struct Contact), 1, fp))
        count++;

    fclose(fp);

    int i, j;

    struct Contact temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(contacts[i].name, contacts[j].name) > 0)
            {
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }

    fp = fopen(FILE_NAME, "wb");

    for (i = 0; i < count; i++)
        fwrite(&contacts[i], sizeof(struct Contact), 1, fp);

    fclose(fp);

    printf("\nContacts Sorted Successfully.\n");
}