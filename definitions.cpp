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
 *  11/3/21 - created methods for almost all the class, imported methods from PA1
 *  11/7/21 - added constructor and destructor, changed up readPetStore
 *  11/8/21 - fixed DisplaySummary and finished up readInfo from csv file
 *  11/8/21 - finished display petList, as well as write petList, removed unecessary methods
 * */

#include "header.h"

//constructor
PetStoreList::PetStoreList()
{
    headPtr = nullptr;
}


//destructor 
PetStoreList::~PetStoreList()
{
    PetStoreData* nodePtr;
    PetStoreData* nextPtr;
    //if headPtr is the only one in the linkedList
    if(headPtr == nullptr){
        delete headPtr;
        return;
    }
    //go through deleting every node
    else
    {
        nodePtr = headPtr;
        while(nodePtr != nullptr)
        {
            nextPtr = nodePtr->nextStore;
            delete nodePtr;
            nodePtr = nextPtr;
        }
    }
}


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
   PetStoreData* newNode = new PetStoreData; //on heap
   newNode->petStoreName = storeName;
   newNode->nextStore = nullptr;
   return newNode;
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
   PetStoreData* nodePtr = nullptr;
   //if header is empty
   if(headPtr == nullptr)
   {
      headPtr = newStoreData;
   }
   else
   {
       nodePtr = headPtr;
      //while the node still has something its pointing to
      while(nodePtr->nextStore != nullptr)
      {
         nodePtr = nodePtr->nextStore;
      }
      nodePtr->nextStore = newStoreData;
   }
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
   PetData petInfo;
   PetStoreData* nodePtr = headPtr;
   petInfo.numDaysAtStore = numDays;
   petInfo.petName = pName;
   petInfo.petType = pType;
   
   //while there is another pet store to look at
   while(nodePtr->nextStore != nullptr)
   {
      //if the store matches what is being added
      if(nodePtr->petStoreName == storeName)
      {
         nodePtr->petData.push_back(petInfo);
         break;
      }
      nodePtr = nodePtr->nextStore;
   }
}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/8/21
 * Description: prints the contents of the PetStoreList in forward order
 * @return nothing
 * @pre unprinted out data
 * @post printed data to console
 **/
void PetStoreList::displayPetList() const
{
    PetStoreData* nodePtr;
    PetData petInfo;
    displayPetSummary();
    if(headPtr == nullptr)
    {
        cout << "No stores read!";
    }
    else
    {
        nodePtr = headPtr;
        while (nodePtr != nullptr)
        {
            cout << "__________________________________" << endl;
            cout << "Pet Store Name: " << nodePtr->petStoreName << endl;
            cout << "**********************************" << endl;
            cout << "| Number of pets: " << nodePtr->petData.size()
                 << "\n| Pet Information: \n";
            for (int petIndex = 0; petIndex < nodePtr->petData.size(); petIndex++)
            {
                petInfo = nodePtr->petData.at(petIndex);
                cout << "> Pet " << (petIndex + 1) <<  " Name: " << petInfo.petName << endl;
                cout << "> Pet Type: " << petInfo.petType << endl;
                cout << "> Number of days at store: " << petInfo.numDaysAtStore << endl;
                cout << "----------------------------" << endl;
            }
            
            nodePtr = nodePtr->nextStore;
        }
        
    }
    
}

/**
 * Name: Joshua Venable 
 * Date created: 11/3/21
 * Date last modified: 11/8/21
 * Description: writes the contents of the PetStoreList in forward order to an output file
 * @param outfile the output stream by reference writing to output file
 * @return nothing
 * @pre an empty or uncreated output file
 * @post a filled up output file with pet data
 **/
void PetStoreList::writePetList(ofstream &outfile)
{
    PetStoreData* nodePtr;
    PetData petInfo;
    cout << "Generating summary report...\n\n";

    writePetSummary(outfile);
    if(headPtr == nullptr)
    {
        outfile << "No stores read!";
    }
    else
    {
        nodePtr = headPtr;
        while (nodePtr != nullptr)
        {
            outfile << "__________________________________" << endl;
            outfile << "Pet Store Name: " << nodePtr->petStoreName << endl;
            outfile << "**********************************" << endl;
            outfile << "| Number of pets: " << nodePtr->petData.size()
                 << "\n| Pet Information: \n";
            for (int petIndex = 0; petIndex < nodePtr->petData.size(); petIndex++)
            {
                petInfo = nodePtr->petData.at(petIndex);
                outfile << "> Pet " << (petIndex + 1) <<  " Name: " << petInfo.petName << endl;
                outfile << "> Pet Type: " << petInfo.petType << endl;
                outfile << "> Number of days at store: " << petInfo.numDaysAtStore << endl;
                outfile << "----------------------------" << endl;
            }
            
            nodePtr = nodePtr->nextStore;
        }
        
    }
    cout << "Done!" << endl << endl;
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
   PetStoreData* nodePtr = headPtr;
   if(nodePtr == nullptr)
   {
      return false;
   }
   else
   {
      //while there is another store in the linked list
      while(nodePtr != nullptr)
      {
         if(name == nodePtr->petStoreName)
         {
            return true;
         }
         nodePtr = nodePtr->nextStore;
      }
   }
   return false;
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
   PetStoreData* nodePtr = headPtr;
   PetData petData;
   int totalDays = 0;
   summaryData.numPets = 0;
   summaryData.minDaysAtStore = INT_MAX;
   summaryData.maxDaysAtStore = INT_MIN;
   summaryData.averageDaysAtStore = 0;
   //while there is another store to look at
   while (nodePtr != nullptr)
   {
      //for every pet in the pet store
      for (int i = 0; i < nodePtr->petData.size(); i++)
      {
         petData = nodePtr->petData.at(i);
         totalDays += petData.numDaysAtStore;
         //if the days at this store is lower than previous
         if(petData.numDaysAtStore < summaryData.minDaysAtStore)
         {
            summaryData.minDaysAtStore = petData.numDaysAtStore;
         }
         //if the days at this store is higher than previous
         if(petData.numDaysAtStore > summaryData.maxDaysAtStore)
         {
            summaryData.maxDaysAtStore = petData.numDaysAtStore;
         }
      }
      summaryData.numPets += nodePtr->petData.size();
      nodePtr = nodePtr->nextStore;
   }
   summaryData.averageDaysAtStore = totalDays/summaryData.numPets;
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
   cout << "__________________________________" << endl;
   cout << "Total number of pets: " << summaryData.numPets << endl;
   cout << "Average number of days at pet store: " << summaryData.averageDaysAtStore << endl;
   cout << "Shortest stay at pet store: " << summaryData.minDaysAtStore << endl;
   cout << "Longest stay at pet store: " << summaryData.maxDaysAtStore << endl;
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
    outfile << "Pet Store CSV Summary Report" << endl;
    outfile << "__________________________________" << endl;
    outfile << "Total number of pets: " << summaryData.numPets << endl;
    outfile << "Average number of days at pet store: " << summaryData.averageDaysAtStore << endl;
    outfile << "Shortest stay at pet store: " << summaryData.minDaysAtStore << endl;
    outfile << "Longest stay at pet store: " << summaryData.maxDaysAtStore << endl;
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
   PetStoreData* nodePtr = nullptr;
   newStoredata->nextStore = headPtr;
   headPtr = newStoredata;
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
   PetStoreData* nodePtr = headPtr;
   int pos;
   //while there is another store to point to
   while(nodePtr->nextStore != nullptr)
   {
      //if we are at the index to insert
      if(pos == position)
      {
         newStoredata->nextStore = nodePtr->nextStore;
         nodePtr->nextStore = newStoredata;
         return true;
      }
      pos++;
      nodePtr = nodePtr->nextStore;
   }
   return false;
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
   PetStoreData* nodePtr = headPtr;
   PetStoreData* prevNodePtr = headPtr;
   //while there is another store to point to 
   while(nodePtr->nextStore != nullptr)
   {
      //if the name of the pet store matches what needs to be removed
      if(nodePtr->petStoreName == nameOfStoreToRemove)
      {
         prevNodePtr->nextStore = nodePtr->nextStore;
         nodePtr->nextStore = nullptr; //sets reference to the node 
         delete nodePtr;
         return true;
      }
      prevNodePtr = nodePtr;
      nodePtr = nodePtr->nextStore;
   }
   return false;
}


/**
 * Name: Joshua Venable
 * Date created: 11/7/21
 * Date last modified: 11/7/21
 * Description: reads total amount of pets for entire storeList
 * @param storeList the linkedList being traversed
 * @return number of pets as an integer
 * @pre unknown amount of pets
 * @post counted pets for every element in storeList
 **/
void PetStoreList::totalPets() const
{
    int totalPetAmount = 0;
    PetStoreData* nodePtr;
    if(headPtr == nullptr)
    {
        cout << "0";
        return;
    }
    else
    {
        nodePtr = headPtr;
        while(nodePtr != nullptr)
        {
            totalPetAmount += nodePtr->petData.size();
            nodePtr = nodePtr->nextStore;
        }
    }
    cout << totalPetAmount;
}

/**
 * Name: Joshua Venable
 * Date created: 11/7/21
 * Date last modified: 11/7/21
 * Description: helper method to print out processing of a pet
 * @param pet the pet data to be written from
 * @return  nothing
 * @pre unprinted pet data
 * @post processed pet data
 **/
void PetStoreList::processPet(PetData pet, string storeName)
{
    cout << "Process a " << pet.petType << ", " "\"" << pet.petName << "\" ... " << pet.numDaysAtStore 
        << " day(s) on site at store \"" <<  storeName << "\"" << endl; 
}

/**
 * Function: readPetStoreInfo()
 * Date Created: 9/4/21
 * Date Last Modified: 11/17/21
 * Description: Reads the incoming pet store info and separates it as needed, adding it to a linked list
 * Input params: a by-ref input file
 * Return: nothing
 * Pre: an opened input file
 * Post: a opened, and processed input file
 * */
void PetStoreList::readPetStoreInfo(bool firstRow, ifstream& input, vector<string>& header, PetStoreList* storeListPtr)
{
    PetStoreData* petStoreInfo;
    PetStoreData* nodePtr;
    PetData petInfo;
    string word;
    string tempWord;
    string headerWords;
    stringstream lineToParse;
    int count = 0;
    int dataLine = 0;
    bool inLinkedList = false;

    //if this is the first row then read it, and place into header vector, otherwise dictate to another vector
    while(input.good())
    {
        if(firstRow)
        {
            firstRow = false;
            getline(input, headerWords); // get the whole line at the file
            lineToParse.str(headerWords); // turn the line into something that we can parse

            //loops until the line hits its end line point
            while(lineToParse.good())
            {
                getline(lineToParse, tempWord, ','); // separates word by comma
                header.push_back(tempWord);

            }

            cout << "Processed " << header.size() << " header columns: ";

            //for loop that simply adds the commas for console print
            for (int i = 0; i < header.size(); i++)
            {
                cout << header.at(i);
                if(i < header.size() - 1)
                {
                    cout << ", ";
                }
                else
                {
                    cout << "\n\n";
                }
            }        
        }
        else
        {
            getline(input, word);  // get the whole line of the file
            lineToParse.clear(); // clear stringstream
            lineToParse.str(word); // replace stringstream with the new line

            while(lineToParse.good())
            {
                getline(lineToParse, word, ','); // cuts line at point with comma

                //switch statement going through each line
                switch (count)
                {
                //getting store and making the node
                case 0:
                    //checks if the pet store is already in the system
                    inLinkedList = storeInList(word);
                    if(!inLinkedList)
                    {
                        petStoreInfo = createNode(word);
                    }
                    else
                    {
                        nodePtr = headPtr;
                        while(nodePtr != nullptr)
                        {
                            if(nodePtr->petStoreName == word)
                            {
                                petStoreInfo = nodePtr;
                                break;
                            }
                            nodePtr = nodePtr->nextStore;
                        }
                    }
                    break;
                //pet name
                case 1:
                    petInfo.petName = word;
                    break;
                //pet type
                case 2:
                    petInfo.petType = word;
                    break;
                //num days at the store and adding info to the store
                case 3:
                    petInfo.numDaysAtStore = stringToInteger(word);
                    petStoreInfo->petData.push_back(petInfo);
                    if(!inLinkedList)
                    {
                        this->insertAtEnd(petStoreInfo);
                    }
                    processPet(petInfo, petStoreInfo->petStoreName);
                    count = -1;
                    break;
                default:
                    break;
                }

                count++;
            }
        }
    }
    cout << "All pet store data processed!\n" << endl;
    calculatePetSummary();
}

//------------FUNCTION METHODS FOR MAIN-----------------------

/**
 * Function: openFiles()
 * Date Created: 9/4/21
 * Date Last Modified: 9/10/21
 * Description: Opens and reads the header file for the input file, as well as opening up the output file for later use
 * Input params: ifstream& input: which is the variable (by-ref) being passed to open up petstore.csv; ifstream& output: the variable (by-ref) being passed to open up petreport.txt
 * Return: pass or fail of function to open up both files
 * Pre: unopened files
 * Post: opened petstore.csv, and opened petreport.txt
 * */
bool openFiles(ifstream& input, ofstream& output)
{
    bool pass = false;
    input.open("petstoredata.csv");
    output.open("petreport.txt");

    //pass/fail conditions
    if(output.is_open() && input.is_open()){
        pass = true;
    }

    return pass;
}

/**
 * Function: stringToInteger()
 * Date Created: 9/6/21
 * Date Last Modified: 9/11/21
 * Description: Takes an incoming string value and returns it as an integer
 * Input params: a string 'substring'
 * Return: an integer formatted version of 'substring'
 * Pre: a string of a number
 * Post: an integer version of the string
 * */
int stringToInteger(string substring)
{
    int tempInt;
    stringstream toInteger(substring); // allows for parsing into an integer
    toInteger >> tempInt;
    return tempInt;
}