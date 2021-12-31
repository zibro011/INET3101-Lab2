Author Name: Nick Kjolsing, Adelaide Zibrowski
Author Email: kjols017@umn.edu, zibro011@umn.edu
Author Student ID: 5480022, 5442587
Author Internet ID: kjols017, zibro011

Program Description:
    - This program is designed to show the use of structures, pointers, and allocating and freeing memory
    - The purpose of this program is to store Birthday values in a simple database that can be accessed and manipulated via the Menu.
    - This program can add and delete records as well as receive and print their attributes.

Data type definitions: 
    - struct: composite data type that stores a list of variables in a block of memory
    - static databaseAccesses: the use of static allows the value of databaseAccesses to be stored in statically allocated memory, therefore retaining its value outside of scope

Menu definition:
    - 1. Print records
        - calls printBirthdays()
        - Prints every record in the database.
        - Includes record number, day, month, year, and combined date.
    - 2. Print number of records
        - Prints the amount of records in the database at that time, stored in numRecs.
    - 3. Print size of database
        - calls getSize()
        - Calculates the size of the database by multiplying the size of one birthday structure by the number of records present in the database.
        - Prints that calculated size in bytes.
    - 4. Add record
        - calls addBirthdays()
        - Creates a new birthday structure and allocates memory for that structure.
        - This new structure becomes entry 1 in the database.
        - Takes day, month, and year as input which is passed to the structure members.
    - 5. Delete record
        - calls deleteBirthday()
        - Prompts user to choose which record to delete.
        - Deletes the user-entered record.
        - Frees up the memory taken by the last structure, then moves the remaining structure information into the remaining memory spaces.
    - 6. Print number of accesses to database
        - Accesses to database increments each time the database is edited or analyzed via the Menu.
        - Prints this number of accesses, stored in databaseAccesses.
    - 7. Exit
        - Terminates program.


Functions (in order of the way they appear in the code):
    void addBirthdays()
        - Input: none
        - Output: none/void
        - Description:
            - Asks user to input their birthday, these are saved as ints
            - If there are no entries in the database, it places the birthday as the first entry
            - If existing extries, places this birthday after the one previously entered
    void deleteBirthday()
        - Input: none
        - Output: none/void
        - Description:
            - If the database is empty, it will not let you delete anything and tells you it is empty
            - Takes input on which entry you would like to delete
            - It then deletes the selected entry
    void getSize()
        - Input: none
        - Output: none/void
        - Description:
            - Returns the size of the current database in bytes
    void printBirthdays()
        - Input: none
        - Output: none/void
        - Description:
            - Prints all entries in the database
    int main()
        - Input: none
        - Output: returns 0, prints many things
            - Prints:
                - Menu for the user to decide what they would like to do with the database
                - When selection within scope is chosen, the appropriate output is derived and printed.
                - It will tell you if the database is empty when choosing an option that requires entries
        - Description:
            - Case statement:
                - Takes input based on what user is looking to have the program calculate
                - Makes sure the selection is valid, 1 - 7...keeps looping if invalid


Files Required:
    - stdio.h
        - Standard input / output header.
        - Allows program to get input from user and output text to the screen.
    - stdlib.h
        - Header that brings in memory allocation, random number generation, and integer math.
    - time.h 
        - Brings in the idea of time into the program.
    - string.h
        - Header that brings in memcpy() function.
    - lab2.h
        - Defines global variables and a structure of type birthdays.
    - lab2.c
        - Includes all functions for the program.