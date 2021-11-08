/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/3/2021
 * Programming Assigment: PA5
 * Description: A pet store using Linked lists to store data
 * Notes: I will likely be writing everything from scratch again, to avoid the issue I held in the previous PAs with counting
 * 
 *  11/3/21 - Added variables
 *  11/8/21 - added display and write to file methods to main
 *  11/8/21 - removal of unneeded variables
 **/

#include "header.h"

int main()
{
    ifstream infile;
    ofstream outfile;
    string inputFileName = "petstoredata.csv";
    string outputFileName = "petreport.txt";
    vector<string> header; //vectors to store header row data
    bool firstRow = true;
    PetStoreList storeList; //the linked list object
    PetStoreList* storeListPtr = &storeList;
    if(openFiles(infile, outfile))
    {
        storeList.readPetStoreInfo(firstRow, infile, header, storeListPtr);
    }
    storeList.writePetList(outfile);
    storeList.displayPetList();
}