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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"
#include "person.h"
#include "liste.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif


// setup & cleanup
static int setup(void)
{
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}


// tests
static void test_insertItem(void){
    // arrange
    ListElement *listElement = newList();
    Person *person = (Person *) malloc(sizeof(Person));
				
    if(person)
    {
		person->name = "daniel";
		person->firstname = "Luetzel";
		person->age = 34;
     
        // act & Assert
        CU_ASSERT_EQUAL(insertItem(person, listElement), true);
        CU_ASSERT_EQUAL(insertItem(NULL, listElement), false);
    }
    
}
static void test_deleteItem(void){
    // arrange
    ListElement *listElement = newList();
    Person *person = (Person *) malloc(sizeof(Person));
				
    if(person)
    {
		person->name = "daniel";
		person->firstname = "luetzel";
		person->age = 34;
		
		Person *person2 = (Person *) malloc(sizeof(Person));
	    ListElement *index = listElement;
	    // Get added Person in List
    	while(index->next != listElement)
	    {
		    index = index->next;
		    
	    }
            
        // act & Assert
        CU_ASSERT_EQUAL(insertItem(person, listElement), true);
        CU_ASSERT_EQUAL(deleteItem(NULL, listElement), false);
        CU_ASSERT_EQUAL(deleteItem(index->content, listElement), false);    
    }
    
}
/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Personenverwaltung", setup, teardown
	               , test_insertItem
	               , test_deleteItem
				  );
}