/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Selbststudium implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "liste.h"

void clearInputBuffer(void);

/**
 * @brief main entry point
 * @returns Returns EXIT_SUCCESS (=0) on succcess or EXIT_FAILURE on ERROR
 */
int main(void)
{
	ListElement *listElement = newList();
	char word = 0;

	do
    {
        (void) printf("Enter cmd: (I(nsert), R(emove), S(how), C(lear) E(nd))\n");
        
        if(scanf("%c", &word) > 0)
        {
            (void) clearInputBuffer();
			switch(word) 
			{
				case 'I': 
					if(insertItem(readPerson(), listElement))
					{
						(void) printf("Personen added\n");
					}
					else
					{
						(void) printf("Personen NOT added\n");
					}
							

					break;

				case 'R': 
					if(deleteItem(readPerson(), listElement))
					{
						(void) printf("Personen removed\n");
					}
					else
					{
						(void) printf("Personen NOT removed\n");
					}

					break;

				case 'S': 
					(void) printf("Output\n"); 
					
					(void) outputList(listElement);

					break;

				case 'C': 
					(void) printf("Cleaning up\n");

					(void) clearlist(listElement);

					break;

				case 'E': 
					(void) printf("Bye..\n"); 
					break;

				default: 
					(void) printf("Please provide a suitble cmd\n"); 
					break;
			}
        }
        else
        {
            (void) clearInputBuffer();
            (void) printf("You entered a non valid value");
            return EXIT_FAILURE;
        }
	}while(word != 'E');
}

/*
* Source: https://stackoverflow.com/a/7898516
*The program will not work properly because at Line 1, when the user presses Enter, 
* it will leave in the input buffer 2 character: Enter key (ASCII code 13) and \n (ASCII code 10). 
* Therefore, at Line 2, it will read the \n and will not wait for the user to enter a character.
*/
void clearInputBuffer(void)
{
    int input = 0;
    while((input = getchar()) != '\n' && input != EOF)
    {
        
    }
}