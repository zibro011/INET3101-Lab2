#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab2.h"
#include <string.h>

struct birthdays *head;
struct birthdays *mover;

void addBirthdays() {
    
    fprintf(stderr, "Enter day: ");
    int firstInputDay;
    scanf("%d", &firstInputDay);

    fprintf(stderr, "Enter month: ");
    int secondInputMonth;
    scanf("%d", &secondInputMonth);

    fprintf(stderr, "Enter year: ");
    int thirdInputYear;
    scanf("%d", &thirdInputYear);
    
    if (numRecs == 0) {
        head = (struct birthdays *) malloc(sizeof(struct birthdays));               
        memcpy(head, &firstInputDay, sizeof(firstInputDay));
        memcpy(&head->month, &secondInputMonth, sizeof(secondInputMonth));
        memcpy(&head->year, &thirdInputYear, sizeof(thirdInputYear));
        numRecs++;
    }

    else {
        numRecs++;
        struct birthdays *newBirthdays = (struct birthdays *) malloc(numRecs * sizeof(struct birthdays));
        int i;
        mover = head;
        struct birthdays *moverTemp = newBirthdays;
        for (i = 0; i < (numRecs - 1); i++) {
            memcpy(moverTemp++, mover++, sizeof(struct birthdays));
        }
            memcpy(moverTemp, &firstInputDay, sizeof(firstInputDay));
            memcpy(&moverTemp->month, &secondInputMonth, sizeof(secondInputMonth));
            memcpy(&moverTemp->year, &thirdInputYear, sizeof(thirdInputYear));
        free(head);
        head = newBirthdays;
        mover = head;
        for (i = 0; i < numRecs; i++) {
            mover++;
        }
    }
    databaseAccesses++;
}

void deleteBirthday() {
    if (numRecs == 0) {
        fprintf(stderr, "\nDatabase empty. No records avaliable to delete.\n");
        return;
    }
    
    fprintf(stderr, "\nWhich record do you want to delete? Enter 1 - %d: ", numRecs);
    int selection;
    scanf("%d", &selection);
    
    if (selection == 1 & numRecs == 1) {
        free(head);
        numRecs--;
    }
    else if (selection == 1 & numRecs > 1) {
        struct birthdays *tempBirthdays = (struct birthdays *) malloc((numRecs - 1) * sizeof(struct birthdays));
        mover = head;
        memcpy(tempBirthdays, mover+1, sizeof(struct birthdays));
        free(head);
        head = tempBirthdays;
        fprintf(stderr, "Record %d deleted successfully.\n", selection);
        numRecs--;
    }
    if (selection > 1) {
        //struct birthdays *tempBirthdays = (struct birthdays *) malloc((numRecs-1) * sizeof(struct birthdays));
        mover = head;
        
        if (selection == numRecs) {
            struct birthdays *tempBirthdays = (struct birthdays *) malloc((numRecs-1) * sizeof(struct birthdays));
            memcpy(tempBirthdays, mover, ((numRecs-1) * sizeof(struct birthdays)));
            free(head);
            head = tempBirthdays;
        }
        
        fprintf(stderr, "Record %d deleted successfully.\n", selection);
        numRecs--;
    }
    return;
}

void getSize() {
    size = numRecs * sizeof(struct birthdays);
    fprintf(stderr, "\nSize of database: %d bytes\n", size);
    databaseAccesses++;
}

void printBirthdays() { 
    if (numRecs == 1) {
        fprintf(stderr, "\n\n");
        fprintf(stderr, "Record Number: %d\n", numRecs);
        fprintf(stderr, "----------------\n");
        fprintf(stderr, "Birth Day: %d\n", head->day);
        fprintf(stderr, "Birth Month: %d\n", head->month);
        fprintf(stderr, "Birth Year: %d\n", head->year);
        fprintf(stderr, "Combined Birthday: %d/%d/%d\n", head->day, head->month, head->year);
    }
    if (numRecs > 1) {
        mover = head;
        for(int i = 0; i < numRecs; i++) {
            fprintf(stderr, "\n\n");
            fprintf(stderr, "Record Number: %d\n", i+1);
            fprintf(stderr, "----------------\n");
            fprintf(stderr, "Birth Day: %d\n", mover->day);
            fprintf(stderr, "Birth Month: %d\n", mover->month);
            fprintf(stderr, "Birth Year: %d\n", mover->year);
            fprintf(stderr, "Combined Birthday: %d/%d/%d\n", mover->day, mover->month, mover->year);
            mover++;
        }
    }
    databaseAccesses++;
}


int main() { 
//--------------Print Menu--------------
    int sel;
    bzero(&head, sizeof(head));
    bzero(&mover, sizeof(mover));
    do {
        printf("\nMENU\n");
        printf("====================\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Print number of accesses to database\n");
        printf("7. Exit\n");
        printf("\n");
        printf("Enter selection: ");

//--------------Determining Selection--------------
        scanf("%d", &sel);
        switch(sel) {
            case 1 :
                if(numRecs == 0) {
                    fprintf(stderr, "\nThe database is currently empty. Please add records.\n");
                }
                else {
                    printBirthdays();
                }
                break;
            case 2 :
                if(numRecs == 0) {
                    fprintf(stderr, "\nThe database is currently empty. Please add records.\n");
                }
                else {
                    fprintf(stderr, "\nNumber of records: %d\n", numRecs);
                }
                break;
            case 3 :
                getSize();
                break;
            case 4 :
                addBirthdays();
                break;
            case 5 :
                deleteBirthday();
                break;
            case 6 :
                fprintf(stderr, "\nNumber of database accesses: %d\n", databaseAccesses);
                break;
            case 7 :
                break;
            default :
                break;
        }
    } while (sel != 7);
    return 0;
}
