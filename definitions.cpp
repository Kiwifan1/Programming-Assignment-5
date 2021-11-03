/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/3/2021
 * Programming Assigment: PA5
 * Description: A pet store using Linked lists to store data
 * Notes: I will likely be writing everything from scratch again, to avoid the issue I held in the previous PAs with counting
 * 
 *  11/3/21 - created definitions.cpp
 *  11/3/21 - created skeleton methods
 **/

#include "header.h"


/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: creates a new PetStoreData variable and initializes the store name
 * @param storeName the string data goingto be stored in the new Node
 * @return a pointer to the dynamically allocated memory.
 * @pre an uncreated node
 * @post a node with data contained stored on the heap
 **/
PetStoreList::PetStoreData* PetStoreList::createNode(string storeName)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: creates a new PetStoreData variable and initializes the store name
 * @param newStoreData the store data passed through that the node is going to be added to
 * @return nothing
 * @pre an unchanged linkedList
 * @post a linkedlist with a new node at the end
 **/
void PetStoreList::insertAtEnd(PetStoreData* newStoreData)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: adds pet name, pet type, and number of days that pet has been at the store
 * @param storeName the name of the store as a string
 * @param pName name of the pet as a string
 * @param pType type of the pet as a string
 * @param numDays total days spent at store as an int
 * @return nothing
 * @pre an empty petData type
 * @post a filled petData type
 **/
void PetStoreList::addPetData(string storeName, string pName, string pType, int numDays)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: prints the contents of the PetStoreList in forward order
 * @return nothing
 * @pre unprinted out data
 * @post printed data to console
 **/
void PetStoreList::displayPetList() const
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: writes the contents of the PetStoreList in forward order to an output file
 * @param outfile the output stream by reference writing to output file
 * @return nothing
 * @pre an empty or uncreated output file
 * @post a filled up output file with pet data
 **/
void PetStoreList::writePetList(ofstream &outfile)
{
    
}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: accepts a string store name
 * @param name of the store as a string
 * @return boolean of whether store is found in the linkedList
 * @pre unsearched linkedList
 * @post knowledge of whether a store is in the linkedlist
 **/
bool PetStoreList::storeInList(string name)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: calculates/updates this object's PetSummary values
 * @return nothing
 * @pre unknown total amount of petSummary values
 * @post known and calculated petSummary values
 **/
void PetStoreList::calculatePetSummary()
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: prints this object's PetSummary values of the PetStoreList
 * @return nothing
 * @pre unprinted out summary of pets calculated
 * @post printed to console summary of pets
 **/
void PetStoreList::displayPetSummary() const
{
    
}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: writes this object's PetSummary values of the PetStoreList to an output 
    file
 * @param outfile the outfile stream to write to the output file
 * @return nothing
 * @pre unwritten/uncreated output file
 * @post written and created output file of petSummary
 **/
void PetStoreList::writePetSummary(ofstream &outfile)
{

}

//------------------BONUS FUNCTIONS---------------------------

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: inserts the PetStoreData "node" at the front of the list
 * @param newStoredata the data of the newStore going to be added to the front of the list
 * @return nothing
 * @pre unchanged linkedList
 * @post linkedList with new head pointer to the new storeData
 **/
void PetStoreList::insertAtFront(PetStoreData* newStoredata)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: inserts the PetStoreData "node" at the position location in the list
 * @param newStoredata as a data pointer going to be added to linkedList
 * @param poisition the position to put newStoredata into as an int
 * @return true or false if the position is a valid position or not
 * @pre unadded storeData
 * @post added storeData or returned value of whether it can be added
 **/
bool PetStoreList::insertAtPosition(PetStoreData* newStoredata, int position)
{

}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/3/21
 * Description: deletes a store and all of its petData
 * @param nameOfStoreToRemove name of the store that is going to be deleted as a string
 * @return true or false if store could be found and if deletion could happen
 * @pre store that may or may not be in linkedList
 * @post deleted store in linkedList or confirmation its not in the list
 **/
bool PetStoreList::deleteStore(string nameOfStoreToRemove)
{

}
