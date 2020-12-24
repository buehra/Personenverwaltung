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
 * @brief Lab implementation
 */
#ifndef PERSON_H
#define PERSON_H

typedef enum {false = 0, true = 1} bool;

//Define structure
typedef struct {
	char *name;
	char *firstname;
	unsigned age;
} Person;

Person* readPerson();

int comparePerson(Person *personA, Person *personB);

void printPerson(Person *person);

void clearInputBuffer(void);

#endif
