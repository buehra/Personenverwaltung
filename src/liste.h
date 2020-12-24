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
#ifndef LISTE_H
#define LISTE_H

typedef struct ListElement ListElement;

struct ListElement {
	Person *content;
	ListElement *next;
};

ListElement* newList();

bool insertItem(Person* person, ListElement* anchor);
bool deleteItem(Person* person, ListElement* anchor);
void outputList(ListElement* anchor);
void clearlist(ListElement* anchor);

#endif
