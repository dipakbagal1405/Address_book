#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    // create the file pointer in write mode
    FILE *fp = fopen("contacts.csv","w");
    
    fprintf(fp, "%d\n",addressBook->contactCount);
    // print the data in file(contacts.csv)
    for(int i= 0; i < addressBook->contactCount; ++i )
    {
        fprintf(fp, "%s,%s,%s\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }
}

void loadContactsFromFile(AddressBook *addressBook) {
    //create the file pointer in read mode
   FILE *fp = fopen("contacts.csv","r");

  fscanf(fp, "%d\n",&addressBook->contactCount);

    // Read the data in file(contacts.csv)
   for(int i= 0; i < addressBook->contactCount; ++i )
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }
        
    
}
