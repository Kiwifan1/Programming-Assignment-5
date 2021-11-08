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
 * Date last modified: 11/3/21
 * Description: prints the contents of the PetStoreList in forward order
 * @return nothing
 * @pre unprinted out data
 * @post printed data to console
 **/
void PetStoreList::displayPetList() const
{
   displayPetSummary();

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
    cout << "Generating summary report...\n";




    cout << "Done!";
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
    cout << "All pet store data processed!" << endl;
    calculatePetSummary();
}

//------------FUNCTION METHODS FOR MAIN-----------------------


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

/**
 * Function: averagePetDays()
 * Date Created: 9/4/21
 * Date Last Modified: 9/11/21
 * Description: adds the amount of total days that the pets have been in a store and divides by amount of pets
 * Input params: by reference of the vector holding all the number of days at a store
 * Return: the average number of days a pet stays at a store
 * Pre: vector of the total days spent by pets
 * Post: average days spent by all pets at all pet stores
 * */
int averagePetDays(vector<int>& numDaysAtStore)
{
    int numPets = 0;
    int numDays = 0;

    //for loop that goes through all the days at a store, and sums the total days by the amount of pets that stayed there
    for(int i = 0; i < numDaysAtStore.size(); i ++)
    {
        numPets ++;
        numDays += numDaysAtStore.at(i);
    }
    return (numDays/numPets);
}

/**
 * Function: uniquePetStores()
 * Date Created: 9/8/21
 * Date Last Modified: 9/11/21
 * Description: Takes the list of all pet stores, and adds non-duplicates to a list so that it will only contain unique pet stores
 * Input params: uniquePetStoreNames -> vector going to hold unique pet stores; uniquePetStoreNameCounts -> going tot hold the number of pets that each unique pet store has; 
 *               petStoreNames -> main vector
 *                  who's data is being grabbed
 * Return: nothing
 * Pre: empty uniquePetStoreNames and Counts
 * Post: filled uniquePetStoreNames and Counts from petStoreNames
 * */
void uniquePetStores(vector<string>& uniquePetStoreNames, vector<int>& uniquePetStoreNameCounts, vector<string>& petStoreNames)
{

    if(petStoreNames.size() == 0)
    {
        cout << "There are no pet stores!\n";
        return;
    }

    else
    {
        //for loop going for entire size of petStoreNames
        for(int i = 0; i < petStoreNames.size(); i++)
        {

            //if the petstore name does not already exist in the uniquePetStoreNames, then it will add it to the end of the vector
            if(find(uniquePetStoreNames.begin(), uniquePetStoreNames.end(), petStoreNames.at(i)) == uniquePetStoreNames.end())
            {
                uniquePetStoreNames.push_back(petStoreNames.at(i));
                uniquePetStoreNameCounts.push_back(1);
            }

            //else if it does exist
            else
            {
                //checks for index of the matching pet store name, and adds to the amount of duplicate names (ie. the amount of pets)
                for(int k = 0; k < uniquePetStoreNames.size(); k ++)
                {
                    // if the uniquePetStoreName matches the petStoreName at the 'i' index, it will increment the count of pets by 1
                    if(uniquePetStoreNames.at(k) == petStoreNames.at(i))
                    {
                        uniquePetStoreNameCounts.at(k) ++;
                    }
                }
            }
        }
    }
}


/**
 * Function: storeMostPets()
 * Date Created: 9/8/21
 * Date Last Modified: 9/11/21
 * Description: searches through the uniquePetStoreNameCounts vector, and finds the index containing the highest number
 * Input params: uniquePetStoreNameCounts --> parallel vector containing amount of pets for uniquePetStores
 * Return: the index of the petstore containing the most pets
 * Pre: unchosen index for most pets
 * Post: chosen index for most pets
 * */
int storeMostPets(vector<int>& uniquePetStoreNameCounts)
{
    int maxIndex = 0;
    int maxNum = 0;

    //for loop going through uniquePetStoreNameCounts entire vector
    for(int i = 0; i < uniquePetStoreNameCounts.size(); i ++)
    {
        //if the number is bigger than the previous maxNum (starting at 0) then hold the index
        if(uniquePetStoreNameCounts.at(i) > maxNum)
        {
            maxNum = uniquePetStoreNameCounts.at(i);
            maxIndex = i;
        }
    }
    return maxIndex;
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
 * Function: randomPet()
 * Date Created: 9/4/21
 * Date Last Modified: 9/11/21
 * Description: gets a random pet from the petName vector, this is for pet of the month
 * Input params: petNames -> vector holding petNames from file
 * Return: index of the pet chosen in petNames vector
 * Pre: unchosen pet of the month
 * Post: chosen index for pet of the month
 * */
int randomPet(vector<string>& petNames)
{
    srand(time(0)); //set random seed
    int randIndex = rand() % petNames.size(); //random index between 0 and petNames size
    return randIndex;
}