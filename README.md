# Address Book Application

A robust, console-based Address Book application developed in C. This project allows users to securely store, search, and manage contact information (Name, Phone Number, and Email). It features active data persistence using CSV file handling to ensure records are saved across sessions.

## 🚀 Features
* **Add Contact:** Insert new contacts with unique validation for name, mobile number, and email.
* **Search Contact:** Instantly locate any contact using their name, phone number, or email ID.
* **Edit Contact:** Seamlessly update existing contact details.
* **Delete Contact:** Remove outdated or unwanted contact entries from the system.
* **List All Contacts:** View a clean, structured list of all saved contacts.
* **Data Persistence:** Automatically saves all records to a `contacts.csv` file so data is never lost when the program closes.

## 🛠️ Technologies Used
* **Language:** C Programming
* **Key Concepts:** File Handling (CSV parsing), Pointers, Structures, Strings, Dynamic Arrays
* **Environment:** GCC Compiler / Linux Terminal / Command Prompt

## 📂 File Structure
* `main.c` - Entry point of the application containing the primary user interface and menu loops.
* `contact.c` & `contact.h` - Core contact management logic (Add, Search, Delete, Edit).
* `file.c` & `file.h` - File I/O operations for reading from and writing to the CSV file.
* `populate.c` & `populate.h` - Utility functions to automatically seed initial dummy data for testing.
* `contacts.csv` - The persistent database file storing all contact entries.

## 💻 How to Run
To compile and run this project locally, ensure you have the GCC compiler installed and run the following commands in your terminal:

1. **Compilation:**
   ```bash
   gcc main.c contact.c file.c populate.c -o address_book
   ```

2. **Execution:**
   ```bash
   ./address_book
   ```
