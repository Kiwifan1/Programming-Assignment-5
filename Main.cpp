/**
 * Name: Joshua Venable
 * Class: CPSC 122, Fall 2021
 * Date: 11/3/2021
 * Programming Assigment: PA5
 * Description: A pet store using Linked lists to store data
 * Notes: I will likely be writing everything from scratch again, to avoid the issue I held in the previous PAs with counting
 * 
 * 
 **/

#include "header.h"

int main()
{
    ifstream infile;
    ofstream outfile;
    string inputFileName = "petstoredata.csv";
    string outputFileName = "petreport.txt";
    vector<string> header; //vectors to store header row data
    stringstream lineToParse; //make use of ss to parse strings based on token
    string line = ""; //store each line

    //temp variables for parsing input file
    string tempString = "";
    string petType = "";
    string petName = "";
    string storeName = "";
    int daysAtStore = 0;
    double averageDaysAtStore = 0;
    bool firstRow = true;
    //PetStoreList storeList; //the linked list object
    cout << "hello world";
}