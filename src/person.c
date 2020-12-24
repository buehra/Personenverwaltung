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
 
Person* readPerson()
 {
	char *name = (char *) malloc(sizeof(char)*4);
	char *firstname = (char *) malloc(sizeof(char)*4);
	unsigned age = 0;

	(void) printf("Please provide a name:\n");
	
	if(scanf("%s", name) > 0)
	{
	    (void) clearInputBuffer();
		(void) printf("Please provide a firstname:\n");
		
		if(scanf("%s", firstname) > 0)
		{
		    (void) clearInputBuffer();
			(void) printf("Please provide a age:\n");

			if(scanf("%u", &age) > 0)
			{
			    (void) clearInputBuffer();
				Person *person = (Person *) malloc(sizeof(Person));
				
				if(person)
				{
					person->name = name;
					person->firstname = firstname;
					person->age = age;

					return person;
				}
			}
			else
			{
			    (void) clearInputBuffer();
				(void) printf("A not correct age value has been provided\n");
			}
		}
		else
		{
		    (void) clearInputBuffer();
			(void) printf("A not correct firstname value has been provided\n");
		}
	}
	else
	{
	    (void) clearInputBuffer();
		(void) printf("A not correct name value has been provided\n");
	}

	return NULL;
}

/**
 * Compares two Persons.
 * @param Pointer to Person 1
 * @param Pointer to Person 2
 * @return status of strcmp()
 */
int comparePerson(Person *personA, Person *personB)
{
    int result = strcmp(personA->name,personB->name);
    if(result==0)
    {
        result = strcmp(personA->firstname,personB->firstname);
        if(result==0)
        {
            result = personA->age - personB->age;
        }
    }

    return result;
}

/**
* Print Person
* @param Pointer to Person to print
*/
void printPerson(Person *person)
{
    (void) printf("Name: %s, Firstname: %s, Age: %i\n", person->name, person->firstname, person->age);
}