#include "Files.h"
#include <iomanip>
#include <ctime>
using namespace std;


bool FileFlagTest(string strFile){
	/*
	Function: Tests a file to see if it can be used
	Parameters:
		strFile - Name of the file to be tested
	Returns: True or false, depending upon whether or not the file passed or failed the test
	*/
	bool flag = false;
	fstream file;
	file.open(strFile, ios::in);	// Open the file
	if (file.good())	// Test if the file can be successfully opened
	{
		if (isEmpty(strFile))
		{
			file.close();
			file.clear();
			throw "File is empty";
		}
		else
			flag = true;
	}
	else
	{
		file.close();		// Close the file
		file.clear();
		throw "File cannot be opened";
	}
	file.close();		// Close the file
	file.clear();		// Clear all flags from the file so it can be used again
	return flag;
}
bool isEmpty(string strFile)
{	/*
	Function: Tests if a file is empty. If it is, it returns true. Otherwise it returns false
	Parameters:	
		strFile - Name of the file to be tested
	Returns: True or false, depending on whether the file is empty or not
	*/
	fstream file(strFile);
	return (file.peek() == ifstream::traits_type::eof());	// Peek into the file. If the result from the peek is the eof(), return true. Otherwise, return false
}
void DisplayItem(InventoryItem &item) {
	/*
	Function: Display a single InventoryItem object, formated for use in the database, report, and cashier modules
	Parameters:
		&item - An InventoryItem object, passed by reference to reduce overhead. The object is not modified in any way
	Returns: Nothing
	*/
	/*
	cout << endl
		<< left << setw(14) << "ISBN" << setw(15) << "Title" << right << setw(12) << "Author" << setw(10) << "Publisher" << endl << left
		<< setw(12) << "Date Added" << setw(10) << "Quantity" << setw(10) << "Wholesale" << setw(6) << "Price" << endl
		<< "--------------------------------------------------------------------------------";
		*/
		cout << left
			<< setw(14) << item.getBook().getISBN() << "\"" << item.getBook().getTitle() << "\"; " << right << setw(15) << item.getBook().getAuthor() << "; " << item.getBook().getPublisher() << endl << left
			<< setw(12) << item.getDateAdded() << setw(4) << item.getQuantity()
			<< setw(6) << fixed << setprecision(2) << item.getWholesale() << setw(6) << item.getPrice() << endl << endl;
}
void TextRead(string strFile, InventoryItem *&items)
{	/*
	Function: Reads values from a text file into an array of InventoryItem
			The first line of the file should be the number of lines of input in the file (excluding the line with this number)
			Each line of input should have all the values of an InventoryItem object, properly formated for input
	Parameters:
		strFile - Name of the file
		*items - Pointer for an array of InventoryItem objects
	Returns: Nothing
	*/
	int size;
	fstream inFile;
	inFile.open(strFile, ios::in);	// Open the file for input
	if (!inFile.good())		// If the file was not successfully opened
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else		// If the file was successfully opened
	{	// Variables for input
		inFile.clear();

		inFile >> size;		// Get the size of the file (the number of lines of input)
		items = new InventoryItem[size];	// Allocate memory for an array of objects big enough to read all the values from the file
		for (int k = 0; k < size && !inFile.eof(); k++)
			inFile >> items[k];	
		//	cout << "End of text read for Inventory Items" << endl;
		//	system("pause");
	}
	inFile.close();
	inFile.clear();
}
void TextRead(string strFile, vector<InventoryItem> &items)
{	/*
	Function: Reads values from a text file into an vectyor of InventoryItem
		The first line of the file should be the number of lines of input in the file (excluding the line with this number)
		Each line of input should have all the values of an InventoryItem object, properly formated for input
	Parameters:
		strFile - Name of the file
		*items - Vector of InventoryItems, passed by reference
	Returns: Nothing
	*/
	InventoryItem temp;
	int size;
	fstream inFile;
	inFile.open(strFile, ios::in);	// Open the file for input
	if (!inFile.good())		// If the file was not successfully opened
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else		// If the file was successfully opened
	{	// Variables for input
		inFile.clear();
		inFile >> size;		// Get the size of the file (the number of lines of input)
		for (int k = 0; k < size && !inFile.eof(); k++)
		{
			inFile >> temp;
			items.push_back(temp);
		}
		//	cout << "End of text read for Inventory Items" << endl;
		//	system("pause");
	}
	inFile.close();
	inFile.clear();
}
void TextWrite(string strFile, InventoryItem *items, int size)
{	/*
	Function: Write an array of InventoryItem objects to a text file, with the values of each object on an individual line
	Parameters:
		strFile - Name of the file to write to
		*items - Pointer to an array of InventoryItem objects
		size - Number of elements in the array
	*/
	fstream outFile;
	outFile.open(strFile, ios::out);	// Open the file for output
	if (!outFile.good())		// If the file was not successfully opened
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		outFile << size << endl;	// The first value written to the file is the number of objects
		for (int k = 0; k < size; k++)
			outFile << items[k] << endl;
		//	cout << "End of text write for Inventory Items" << endl;
		//	system("pause");
	}
	outFile.close();
	outFile.clear();
}
void TextWrite(string strFile, vector<InventoryItem> &items)
{	/*
	Function: Write an vector of InventoryItem objects to a text file, with the values of each object on an individual line
	Parameters:
	strFile - Name of the file to write to
	&items - Vector of InventoryItem objects, passed by reference
	*/
	fstream outFile;
	outFile.open(strFile, ios::out);	// Open the file for output
	if (!outFile.good())		// If the file was not successfully opened
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		outFile << items.size() << endl;	// The first value written to the file is the number of objects
		for (int k = 0; k < items.size(); k++)
			outFile << items[k] << endl;
		//	cout << "End of text write for Inventory Items" << endl;
		//	system("pause");
	}
	outFile.close();
	outFile.clear();
}
void TextRead(string strFile, Book *book)
{	/*
	Function: Read a text file into an array of Book objects
	Paramaters:
		strFile - Name of the input file
		*&book - Pointer to an array of Book objects, passed as reference
	Returns: Nothing
	*/
	fstream inFile;
	inFile.open(strFile, ios::in);
	if (!inFile.good())
	{
		cout << "Error opening file" << endl;
		system("pause");
	}
	else
	{
		int size;
	//	char temp;
	//	string ISBN;
	//	string title, first, last, publisher;
		inFile >> size;
		for (int index = 0; index < size; index++)
		{
			inFile >> book[index];
		}
	}
	inFile.close();
	inFile.clear();
}
char Choice(char low, char high)
{	/*
	Function: Allows user to input char values between two values, based on ASCII values
	Parameters:
	low - Lowest value char to be used
	high - Highest char value to be used
	Returns: Valid character input (characters between 'low' and 'high' based on ASCII values)
	*/
	char cI;
	do			// Loop runs until valid character input is received (characters between 'low' and 'high')
	{
		cout << "Choice: ";
		cin.get(cI);
		//cin.clear();
		cin.ignore(10000, '\n');
		if (cI < low || cI > high)
			cout << "Invalid choice, try again" << endl;
	} while (cI < low || cI > high);
	return cI;
}
int Choice(int low, int high)
{	/*
	Function: Allows user to input int values between two values
	Parameters:
	low - Lowest int value to be used
	high - Highest int value to be used
	Returns: Valid integer input (integers between 'low' and 'high') (including 'low' and 'high')
	*/
	int cI;
	do			// Loop runs until valid integer input is received (integers between 'low' and 'high')
	{
		cout << "Choice: ";
		cin >> cI;
		cin.ignore(10000, '\n');
		cin.clear();
		if (cI < low || cI > high)
			cout << "Invalid choice, try again" << endl;
	} while (cI < low || cI > high);
	return cI;
}
char YesNo()
{	/*
	Function: Allows user to input char values that corresponds to a yes/no decision
	Parameters:
	none
	Returns: Valid character input ('y', 'Y', 'n', or 'N')
	*/
	char cYN;
	do			// Loop runs until valid character input is received ('y', 'Y', 'n', or 'N') 
	{			// Uppercase characters are converted to lowercase solely for testing purposes. The function will still return an uppercase 'Y' or 'N'
		cout << "Y/N: ";
		cin.get(cYN);
		cin.ignore(10000, '\n');
		if (!(tolower(cYN) == 'y' || tolower(cYN) == 'n'))
			cout << "Invalid choice. Choice is either \"y\" for yes, or \"n\" for no" << endl;
	} while (!(tolower(cYN) == 'y' || tolower(cYN) == 'n'));
	return cYN;
}
void Pause(){
	cout << "Press <ENTER> to continue" << endl;
//	cin.get();
	cin.ignore(1,'\n');
}
//
//int Random(int min, int max)
//{	/*
//	Function: Generates a random integer value that is between two values
//	Parameters:
//	min - Minimum value for the random number
//	max - Maximum value for the random number
//	Returns: A random integer between min and max
//	*/
//	return (rand() % (max - min + 1)) + min;
//}
//Date RandomDate()
//{	/*
//	Function: Generates a Date object with random values (Between Jan 1, 1990 and Dec 31, 2005). Uses the Date object constructor to ensure valid dates
//	Parameters:
//	None
//	Returns: A Date object with random values
//	*/
//	Date ranDate = { Random(1990, 2005), Random(1, 12), Random(1, 31) };
//	return ranDate;
//}
//double RandomWholesale()
//{	/*
//	Function: Generates a randomly selected double value
//	The design is to generate a random value for a salary from a pool of pre-set values
//	Parameters:
//	none
//	Returns: A randomly selected double value from the salary[] array
//	*/
//	double wholesale[] = { 3, 3.25, 3.5, 3.75, 4, 4.25, 4.5, 4.75, 5, 5.25, 5.5, 5.75, 6 };
//	return wholesale[Random(0, sizeof(wholesale) / sizeof(wholesale[0]) -1)];
//}
//double RandomPrice()
//{	/*
//	Function: Generates a randomly selected double value
//	The design is to generate a random value for a salary from a pool of pre-set values
//	Parameters:
//	none
//	Returns: A randomly selected double value from the salary[] array
//	*/
//	double price[] = { 6.25, 6.5, 6.75, 7, 7.25, 7.50, 7.75, 8, 8.25, 9.5, 9.75, 10, 10.25, 10.5, 10.75, 11, 11.25, 11.5, 11.75, 12 };
//	return price[Random(0, sizeof(price) / sizeof(price[0]) -1)];
//}
//void BinaryRead(string strInFile, InventoryItem *&items)
//{	/*
//	Function: Reads a binary file of stored objects, reads the values into the passed array
//	The binary file must be properly formated. The first value must be the number of objects written to the file.
//	Parameters:
//	strInFile - Name of the file to be read from
//	*items - Pointer for an array of InventoryItem objects
//	Returns: Nothing
//	*/
//	fstream inBinary;
//	inBinary.open(strInFile, ios::in | ios::binary);	// Open the binary file for input
//	if (!inBinary.good())	// If the file was not successfully opened
//	{
//		cout << "Error opening file" << endl;
//		system("pause");
//	}
//	else		// If the file was successfully opened
//	{
//		int iSize;
//		inBinary.read(reinterpret_cast<char *>(&iSize), sizeof(iSize));	// Gets the first value in the binary file (which should be the number of objects in the file)
//		cout << "Number of Inventory Items: " << iSize << endl;
//		InventoryItem temp;
//		items = new InventoryItem[iSize];	// Allocate enough memory to hold all the objects in the file
//		for (int k = 0; k < iSize; k++)
//		{
//			inBinary.read(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));	// Read the file into the newly created objects
//		}
//		//	cout << "End of binary read" << endl;
//		//	delete reinterpret_cast<char *>(temp);
//	}
//	system("pause");
//	inBinary.close();
//	inBinary.clear();
//}
//void BinaryWrite(string strOutFile, InventoryItem *items, int size)
//{	/*
//	Function: Writes an array of objects to a binary file. The first value in the binary file will be the number of elements in the array
//	Parameters:
//	strOutFile - Name of the file to be written to
//	*items - Pointer to an array of InventoryItem objects, this array will be written to the file
//	size - Number of elements in the array
//	Returns: Nothing
//	*/
//	fstream outFile;
//	outFile.open(strOutFile, ios::out | ios::binary);	// Open the binary file for output
//	if (!outFile.good())		// If the file was not successfully opened
//	{
//		cout << "Error opening file" << endl;
//		system("pause");
//	}
//	else		// If the file was successfully opened
//	{
//		outFile.write(reinterpret_cast<char *>(&size), sizeof(size));	// Write the number of objects as the first value of the file
//		InventoryItem temp;
//		for (int k = 0; k < size; k++)
//		{
//			outFile.write(reinterpret_cast<char *>(&items[k]), sizeof(items[k]));	// Write all of the objects to the file
//		}
//		//	cout << "End of binary write" << endl;
//		//	system("pause");
//		//	delete reinterpret_cast<char *>(temp);
//	}
//	outFile.close();
//	outFile.clear();
//}