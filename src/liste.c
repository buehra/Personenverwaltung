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

ListElement* newList()
{
	ListElement *listElement = (ListElement *) malloc(sizeof(ListElement));
	
	if(listElement)
	{
	    listElement->next = listElement;
		return listElement;
	}
	else
	{
		return NULL;
	}
}

bool insertItem(Person* person, ListElement* anchor)
{
    // Check if Person is set
    if(person == NULL)
    {
        return false;
    }
	ListElement *listElement = (ListElement *) malloc(sizeof(ListElement));
		
	if(listElement)
	{
		if(anchor->next == NULL)
		{
			anchor->next = listElement;
			listElement->content = person;
			listElement->next = anchor;
		}
		else
		{
			ListElement *tmp = anchor;

			while(tmp->next != anchor && comparePerson(person, tmp->next->content) > 0)
			{
				tmp = tmp->next;
			}

            listElement->next = tmp->next;
			tmp->next = listElement;
			listElement->content = person;
		}
	}
	return true;
}

bool deleteItem(Person* person, ListElement* anchor)
{
    // Check if Person is set
    if(person == NULL)
    {
        return false;
    }
	ListElement *lastElement = anchor;
	ListElement *index = anchor;

	while(index->next != anchor)
	{
		index = index->next;

		if(comparePerson(person, index->content) == 0)
		{
			lastElement->next = index->next;
			
			(void) free(index->content);
			(void) free(index->content->name);
			(void) free(index->content->firstname);
			(void) free(index);

			return true;
		}

		lastElement = index;
	}

	return false;
}

void outputList(ListElement* anchor)
{
	ListElement *index = anchor;

	while(index->next != anchor)
	{
		index = index->next;
		(void) 	printPerson(index->content);	
	}
}

void clearlist(ListElement* anchor)
{
	ListElement *firstElement = anchor;
    
    anchor = firstElement->next;
    while(anchor != firstElement)
    {
        ListElement *next = anchor->next;
        free(anchor);
        anchor = next;
    }
    anchor = firstElement;
    anchor->next = firstElement;
}