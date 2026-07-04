 Contact Management System

 Internship Project

---

 1. Internship Details

| Field                    | Details                           |
| ------------------------ | --------------------------------- |
| **Full Name**            | **Abantika Sen**              |
| **Intern ID**            | **CITS4804**              |
| **Project Name**         | Contact Management System         |
| **Project Duration**     | [4 Weeks]                 |
| **Programming Language** | C Programming                     |
| **Compiler Used**        | GCC Compiler                      |
| **IDE Used**             | Visual Studio Code / Code::Blocks |
| **Organization**      |Codtech IT Solution private Limited                     |

---

 2. Project Overview

The **Contact Management System** is a console-based application developed using the C programming language. The application allows users to store and manage contact information efficiently using binary file handling. It supports adding, displaying, searching, updating, deleting, and sorting contact records. All contact details are stored permanently in a binary file (`contacts.dat`), ensuring data persistence even after the program is closed.

---

 3. Project Scope

The Contact Management System is designed to provide an efficient way to organize and manage personal or professional contacts. The application demonstrates file handling concepts while offering essential contact management operations.

 The project allows users to:

* Add new contacts
* Display all saved contacts
* Search contacts by name
* Update contact information
* Delete contacts
* Sort contacts alphabetically
* Store data permanently using binary files

---

 4. Objectives

* Develop a menu-driven application in C.
* Implement CRUD operations.
* Learn Binary File Handling.
* Use Structures for storing data.
* Understand modular programming.
* Demonstrate Searching and Sorting techniques.

---

 5. Features

* Add Contact
* Display Contacts
* Search Contact
* Update Contact
* Delete Contact
* Sort Contacts Alphabetically
* Automatic Contact ID Generation
* Permanent Data Storage

---

 6. Software Requirements

* Windows 11
* GCC Compiler
* Visual Studio Code / Code::Blocks
* C Standard Library

---

7. Hardware Requirements

* Intel/AMD Processor
* Minimum 4 GB RAM
* 100 MB Free Disk Space

---

 8. Project Folder Structure

``text
Contact-Management-System/
│
├── contact_management.c
├── contacts.dat
├── README.md
├── Documentation.pdf
├── Screenshots/
│
│   ├── Main_Menu.png
│   ├── Add_Contact.png
│   ├── Display_Contacts.png
│   ├── Search_Contact.png
│   ├── Update_Contact.png
│   ├── Delete_Contact.png
│   ├── Sort_Contacts.png
│   └── Exit.png
│
└── Output Images/
`

---

9. Source Code

``
contact_management.c
`

---

 10. Contact Structure

``c
struct Contact
{
    int id;
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
};
`

Each contact contains:

* Contact ID
* Name
* Phone Number
* Email Address
* Address

---

 11. Functions Used

| Function          | Description                   |
| ----------------- | ----------------------------- |
| main()            | Controls the complete program |
| getNextId()       | Generates a unique Contact ID |
| addContact()      | Adds a new contact            |
| displayContacts() | Displays all contacts         |
| searchContact()   | Searches a contact by name    |
| updateContact()   | Updates contact details       |
| deleteContact()   | Deletes a contact             |
| sortContacts()    | Sorts contacts alphabetically |

---

 12. Working of the Code

 Step 1

The program starts by displaying the main menu.

↓

 Step 2

The user selects an operation from the menu.

↓

 Step 3

The selected function is executed.

↓

 Step 4

The program performs file operations on `contacts.dat`.

↓

 Step 5

The updated result is displayed.

↓

 Step 6

The menu appears again until the user chooses **Exit**.

---

 13. File Handling Functions Used

* fopen()
* fclose()
* fread()
* fwrite()
* fseek()
* remove()
* rename()

---

 14. Program Flow

``
Start
   │
   ▼
Display Menu
   │
   ▼
Read User Choice
   │
   ├── Add Contact
   ├── Display Contacts
   ├── Search Contact
   ├── Update Contact
   ├── Delete Contact
   ├── Sort Contacts
   └── Exit
   │
   ▼
Return to Main Menu
   │
   ▼
End
`

---

 15. How to Run the Program

 Step 1

Open the project folder.

 Step 2

Compile the program.

```bash
gcc contact_management.c -o contact_management
```

Step 3

Run the executable.

Windows

```bash
contact_management.exe
```

Linux/macOS

```bash
./contact_management
```

---

 16. Program Outputs

 16.1 Main Menu


============================================================
                CONTACT MANAGEMENT SYSTEM
============================================================

1. Add Contact
2. Display Contacts
3. Search Contact
4. Update Contact
5. Delete Contact
6. Sort Contacts
7. Exit

------------------------------------------------------------
Enter Choice :
``



---

 16.2 Add Contact


Enter Choice : 1

Enter Name    : Biswa Sen
Enter Phone   : 807700
Enter Email   : biswa40@gmail.com
Enter Address : Kolkata

✓ Contact Added Successfully.
``


 16.3 Display Contacts

`
============================================================
                    CONTACT LIST
============================================================

ID    Name                 Phone          Email                     Address
--------------------------------------------------------------------------------
1     Biswa Sen            807700         biswa40@gmail.com         Kolkata
``




 16.4 Search Contact

``text
Enter Choice : 3

Enter Name : Biswa Sen

Contact Found

ID      : 1
Name    : Biswa Sen
Phone   : 807700
Email   : biswa40@gmail.com
Address : Kolkata
``

-

 16.5 Update Contact

``
Enter Choice : 4

Enter Contact ID : 1

Enter New Name    : Mahua Sen
Enter New Phone   : 900755
Enter New Email   : mahua90@gmail.com
Enter New Address : Haldia

✓ Contact Updated Successfully.
``


16.6 Delete Contact

``
Enter Choice : 5

Enter Contact ID : 1

✓ Contact Deleted Successfully.
``

 16.7 Sort Contacts

`
Enter Choice : 6

Sorting Contacts...

✓ Contacts Sorted Successfully.
``


---

16.8 Exit

``
Enter Choice : 7

Thank You!

Program Terminated Successfully.
``


---

 17. Test Cases

| Test Case        | Input            | Expected Output        | Result |
| ---------------- | ---------------- | ---------------------- | ------ |
| Add Contact      | Valid Details    | Contact Added          | Pass   |
| Display Contacts | Existing Data    | Contact List Displayed | Pass   |
| Search Contact   | Existing Name    | Contact Found          | Pass   |
| Update Contact   | Valid ID         | Contact Updated        | Pass   |
| Delete Contact   | Valid ID         | Contact Deleted        | Pass   |
| Sort Contacts    | Multiple Records | Contacts Sorted        | Pass   |

---

18. Advantages

* Easy to use
* Simple user interface
* Permanent data storage
* Fast searching
* Efficient record management
* Automatic Contact ID generation
* Modular program design

---

19. Limitations

* Console-based interface
* Maximum of 100 contacts during sorting
* Search is case-sensitive
* No password protection
* No phone/email validation

---

 20. Future Enhancements

* Login Authentication
* Password Protection
* Phone Number Validation
* Email Validation
* Search by Phone Number
* Export Contacts to CSV
* Backup and Restore
* GUI-Based Interface
* Database Integration
* Cloud Synchronization

---

 21. Learning Outcomes

After completing this project, the following concepts were learned:

* C Programming Fundamentals
* Structures
* Functions
* Arrays
* Binary File Handling
* Searching Algorithms
* Sorting Algorithms
* Menu-Driven Programming
* Modular Programming
* Data Management

---

 22. Conclusion

The **Contact Management System** successfully demonstrates the practical implementation of **C programming**, **structures**, **functions**, and **binary file handling**. The application provides an efficient way to manage contact records by supporting operations such as adding, displaying, searching, updating, deleting, and sorting contacts. This project strengthened the understanding of modular programming and persistent data storage, making it a valuable academic and internship project that can be further enhanced with advanced features such as authentication, database connectivity, and a graphical user interface.

