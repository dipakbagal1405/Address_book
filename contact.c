#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

int isvalidphone(char *phone) {
    int len = strlen(phone);

    if(len != 10) {
        printf("phone number must be exactly 10 digits\n ");
        return 0;
    }
    for(int i = 0;i<len;i++) {
        if(phone[i] < '0' || phone[i] > '9') {
            printf("phone number must contain only digits\n");
            return 0;
        }
    }
    return 1;
}
int isvalidEmail(char *email) {
    int at_flag = 0;
    int dot_flag = 0;

    for(int i = 0; email[i] != '\0'; i++) {
        if(email[i] == '@') {
            at_flag = 1;
        }
        if(at_flag == 1 && email[i] == '.') {
            dot_flag = 1;
        }
    }

    if(at_flag && dot_flag) {
        return 1;
    } 
    else {
        printf("Invalid email format!\n");
        return 0;
    }
}
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("1. sort by name\n2. sort by phone\n3. sort by email\n4. Exit\n");
    int sortchoise;
    printf("Enter your choise for sorting: ");
    scanf("%d",&sortchoise);
    switch(sortchoise)
    {
        case 1:
            for(int i = 0; i < addressBook->contactCount - 1; i++) {
                for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
                    if(strcasecmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0){
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
            case 2:
            for(int i = 0; i < addressBook->contactCount - 1; i++) {
                for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
                    if(strcasecmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0){
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
            case 3:
            for(int i = 0; i < addressBook->contactCount - 1; i++) {
                for(int j = 0; j < addressBook->contactCount - i - 1; j++) {
                    if(strcasecmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0){
                        Contact temp = addressBook->contacts[j];
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                        addressBook->contacts[j + 1] = temp;
                    }
                }
            }
            break;
            case 4:
                 return;
    }

   printf("\n");
   printf("--------------------------------------------------------------------------------\n");
   printf("                          ADDRESS BOOK CONTACT LIST\n");
   printf("--------------------------------------------------------------------------------\n");
   printf("%-5s %-20s %-15s %-35s\n","S.No", "Name", "Phone", "Email");
   printf("--------------------------------------------------------------------------------\n");
   for(int i = 0; i < addressBook->contactCount; i++)
   {
       printf("%-5d %-20s %-15s %-35s\n",
           i + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
   }

   printf("--------------------------------------------------------------------------------\n");
   printf("Total Contacts : %d\n", addressBook->contactCount);
   printf("--------------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter the name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    do{
      printf("Enter the phone number: ");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
    }while(!isvalidphone(addressBook->contacts[addressBook->contactCount].phone));
    do{
       printf("Enter the email id: ");
       scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
    }while(!isvalidEmail(addressBook->contacts[addressBook->contactCount].email));
    addressBook->contactCount++;
    printf("contact added successfuly.\n");
}

int searchContact(AddressBook *addressBook) 
{
    printf("1. search by name\n2. search by phone\n3. search by email\n4. Exit\n");
    int choise;
    printf("Enter your choise: ");
    scanf("%d",&choise);
    char name[50],phone[15],email[50];
    switch(choise)
    {
        case 1:
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
        for(size_t i = 0; i < addressBook->contactCount;i++)
        {
            if(strcasecmp(addressBook->contacts[i].name, name) == 0)
            {
               printf("Name: %s, phone: %s, Email: %s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
               return i;  
            }
        }
            return -2;
            break;
        case 2:
                printf("Enter the phone: ");
                scanf(" %[^\n]", phone);
                for(size_t i = 0; i < addressBook->contactCount;i++)
                {
                    if(strcasecmp(addressBook->contacts[i].phone, phone) == 0)
                    {
                    printf("Name: %s, phone: %s, Email: %s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);
                    return i;  
                    }
                }
             return -2;
             break;
        case 3:
                printf("Enter the Email: ");
                scanf(" %[^\n]", email);
                for(size_t i = 0; i < addressBook->contactCount;i++)
                {
                    if(strcasecmp(addressBook->contacts[i].email, email) == 0)
                    {
                    printf("Name: %s, phone: %s, Email: %s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);
                    return i;  
                    }
                }
             return -2;
             break;
        case 4:
             return -1;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
    printf("1. Edit by name\n2. Edit by phone\n3. Edit by email\n4. Exit\n");
    int choise;
    printf("Enter your choise: ");
    scanf("%d",&choise);
    int index =  searchContact(addressBook);
    if(index == -1)
           printf("Exit from search contact\n");
    else if(index == -2)
          printf("contact not found\n");
    else
     {   
        switch(choise)
        {
           case 1:
                printf("Enter the edit name: ");
                 scanf(" %[^\n]", addressBook->contacts[index].name);
                 break;
           case 2:
                printf("Enter the edit phone no: ");
                 scanf(" %[^\n]", addressBook->contacts[index].phone);
                 break;
           case 3:
                printf("Enter the edit email id: ");
                 scanf(" %[^\n]", addressBook->contacts[index].email);
                 break;
           case 4:
                return;
        }
     }
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   int index =  searchContact(addressBook);
    if(index == -1)
           printf("Exit from search contact\n");
    else if(index == -2)
          printf("contact not found\n");
    else
     {   
       for(int i = index; i < addressBook->contactCount;i++)
       addressBook->contacts[i] = addressBook->contacts[i+1];
       addressBook->contactCount--;
     }
}
