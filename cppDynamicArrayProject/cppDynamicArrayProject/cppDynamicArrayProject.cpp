// C++ program to demonstrate
// Class

#include <iostream>
#include <string>
#include <array>
#include <iterator>
using namespace std;

//template initializer_list<int>::iterator it;



class DynamicArrayInt	
{
		// Access specifier
public:
	//global variables
	int arrSize;
	


	//if there is no input, i'm not sure how we can declare the size of the array when we don't even know the type
	//how can the user declare the type without declaring the size?
	DynamicArrayInt()
	{
	}


	//*****CONSTRUCTORSt*****

	//CONSTRUCTOR - takes in an int list, e.g. {1,2,3}
	DynamicArrayInt(std::initializer_list<int> list)
	{
		arrType = "int";
		intArrGlobal = new int[list.size()];
		std::copy(list.begin(), list.end(), intArrGlobal);
		arrSize = list.size();
		
	}

	


	//CONSTRUCTOR - takes in an int array
	DynamicArrayInt(int arr[])
	{
		arrSize = sizeof(arr) / sizeof(*arr);
		intArrGlobal = arr;
		arrType = "int";
	}

	

	//CONSTRUCTOR - takes in parameters for size and data type
	DynamicArrayInt(int size, string type)
	{
		
		intArrGlobal = new int[size];
		arrSize = size;
		arrType = "int";
		
	}

	//CONSTRUCTOR - takes in parameters for data type, sets size to 15 by default
	DynamicArrayInt(string type)
	{
		
		intArrGlobal = new int[15];
		arrSize = 15;
		arrType = "int";
		

		
	}

	//DESCRUCTOR - deletes the object
	~DynamicArrayInt()
	{
		delete[] intArrGlobal;
	}

	//[] operator overload, for accessing elements in the array
	int &operator[](int i) 
	{
		
		int size = arrSize;

		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			// return first element.
			return intArrGlobal[0];
		}
			
			
		return intArrGlobal[i];
		
    }


	//<< operator overload, for displaying the entire array
	friend std::ostream& operator<< (std::ostream& out, DynamicArrayInt& point);



	//*****Array operators*****

	//size - return the size of the array
	int size()
	{
		
		int size = sizeof(intArrGlobal) / sizeof(intArrGlobal[0]);
		return size;
		
	}

	//empty - is this array empty?
	bool empty()
	{
		
		if (NULL == intArrGlobal)
		{
			return true;
		}
		else return false;
		
	}

private:
	int* intArrGlobal;
	string* stringArrGlobal;
	double* doubleArrGlobal;
	char* charArrGlobal;
	bool* boolArrGlobal;

	string arrType;
};

ostream& operator<<(ostream& os, DynamicArrayInt& c)
{
	
	string arrayStr = "{ ";
	int tempArray;
	for (int i = 0; i < c.arrSize; i++)
	{
		tempArray = c[i];
		arrayStr += to_string(tempArray);
		if (i < c.arrSize - 1) arrayStr += ", ";
		
	}
	arrayStr += " }";
	os << arrayStr;
	return os;
}


class DynamicArrayDouble
{
	// Access specifier
public:
	//global variables
	int arrSize;



	//if there is no input, i'm not sure how we can declare the size of the array when we don't even know the type
	//how can the user declare the type without declaring the size?
	DynamicArrayDouble()
	{
	}


	//*****CONSTRUCTORSt*****

	//CONSTRUCTOR - takes in an double list, e.g. {1,2,3}
	DynamicArrayDouble(std::initializer_list<double> list)
	{
		arrType = "double";
		doubleArrGlobal = new double[list.size()];
		std::copy(list.begin(), list.end(), doubleArrGlobal);
		arrSize = list.size();

	}




	//CONSTRUCTOR - takes in an double array
	DynamicArrayDouble(double arr[])
	{
		arrSize = sizeof(arr) / sizeof(*arr);
		doubleArrGlobal = arr;
		arrType = "double";
	}



	//CONSTRUCTOR - takes in parameters for size and data type
	DynamicArrayDouble(int size, string type)
	{

		doubleArrGlobal = new double[size];
		arrSize = size;
		arrType = "double";

	}

	//CONSTRUCTOR - takes in parameters for data type, sets size to 15 by default
	DynamicArrayDouble(string type)
	{

		doubleArrGlobal = new double[15];
		arrSize = 15;
		arrType = "double";



	}

	//DESCRUCTOR - deletes the object
	~DynamicArrayDouble()
	{
		delete[] doubleArrGlobal;
	}

	//[] operator overload, for accessing elements in the array
	double &operator[](int i)
	{

		int size = arrSize;

		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			// return first element.
			return doubleArrGlobal[0];
		}


		return doubleArrGlobal[i];

	}


	//<< operator overload, for displaying the entire array
	friend std::ostream& operator<< (std::ostream& out, DynamicArrayDouble& point);



	//*****Array operators*****

	//size - return the size of the array
	int size()
	{

		int size = arrSize;
		return size;

	}

	//empty - is this array empty?
	bool empty()
	{

		if (NULL == doubleArrGlobal)
		{
			return true;
		}
		else return false;

	}

private:
	double* doubleArrGlobal;

	string arrType;
};

ostream& operator<<(ostream& os, DynamicArrayDouble& c)
{

	string arrayStr = "{ ";
	double tempArray;
	for (int i = 0; i < c.arrSize; i++)
	{
		tempArray = c[i];
		arrayStr += to_string(tempArray);
		if (i < c.arrSize - 1) arrayStr += ", ";

	}
	arrayStr += " }";
	os << arrayStr;
	return os;
}


class DynamicArrayChar
{
	// Access specifier
public:
	//global variables
	int arrSize;



	//if there is no input, i'm not sure how we can declare the size of the array when we don't even know the type
	//how can the user declare the type without declaring the size?
	DynamicArrayChar()
	{
	}


	//*****CONSTRUCTORSt*****

	//CONSTRUCTOR - takes in an char list, e.g. {1,2,3}
	DynamicArrayChar(std::initializer_list<char> list)
	{
		arrType = "char";
		charArrGlobal = new char[list.size()];
		std::copy(list.begin(), list.end(), charArrGlobal);
		arrSize = list.size();

	}




	//CONSTRUCTOR - takes in an char array
	DynamicArrayChar(char arr[])
	{
		arrSize = sizeof(arr) / sizeof(*arr);
		charArrGlobal = arr;
		arrType = "char";
	}



	//CONSTRUCTOR - takes in parameters for size and data type
	DynamicArrayChar(char size, string type)
	{

		charArrGlobal = new char[size];
		arrSize = size;
		arrType = "char";

	}

	//CONSTRUCTOR - takes in parameters for data type, sets size to 15 by default
	DynamicArrayChar(string type)
	{

		charArrGlobal = new char[15];
		arrSize = 15;
		arrType = "char";



	}

	//DESCRUCTOR - deletes the object
	~DynamicArrayChar()
	{
		delete[] charArrGlobal;
	}

	//[] operator overload, for accessing elements in the array
	char &operator[](int i)
	{

		int size = arrSize;

		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			// return first element.
			return charArrGlobal[0];
		}


		return charArrGlobal[i];

	}


	//<< operator overload, for displaying the entire array
	friend std::ostream& operator<< (std::ostream& out, DynamicArrayChar& point);



	//*****Array operators*****

	//size - return the size of the array
	int size()
	{

		int size = arrSize;
		return size;

	}

	//empty - is this array empty?
	bool empty()
	{

		if (NULL == charArrGlobal)
		{
			return true;
		}
		else return false;

	}

private:
	char* charArrGlobal;

	string arrType;
};

ostream& operator<<(ostream& os, DynamicArrayChar& c)
{

	string arrayStr = "{ ";
	char tempArray;
	for (int i = 0; i < c.arrSize; i++)
	{
		tempArray = c[i];
		arrayStr += to_string(tempArray);
		if (i < c.arrSize - 1) arrayStr += ", ";

	}
	arrayStr += " }";
	os << arrayStr;
	return os;
}


class DynamicArrayString
{
	// Access specifier
public:
	//global variables
	int arrSize;



	//if there is no input, i'm not sure how we can declare the size of the array when we don't even know the type
	//how can the user declare the type without declaring the size?
	DynamicArrayString()
	{
	}


	//*****CONSTRUCTORSt*****

	//CONSTRUCTOR - takes in an string list, e.g. {1,2,3}
	DynamicArrayString(std::initializer_list<string> list)
	{
		arrType = "string";
		stringArrGlobal = new string[list.size()];
		std::copy(list.begin(), list.end(), stringArrGlobal);
		arrSize = list.size();

	}




	//CONSTRUCTOR - takes in an string array
	DynamicArrayString(string arr[])
	{
		arrSize = sizeof(arr) / sizeof(*arr);
		stringArrGlobal = arr;
		arrType = "string";
	}



	//CONSTRUCTOR - takes in parameters for size and data type
	DynamicArrayString(int size, string type)
	{

		stringArrGlobal = new string[size];
		arrSize = size;
		arrType = "string";

	}

	//CONSTRUCTOR - takes in parameters for data type, sets size to 15 by default
	DynamicArrayString(string type)
	{

		stringArrGlobal = new string[15];
		arrSize = 15;
		arrType = "string";



	}

	//DESCRUCTOR - deletes the object
	~DynamicArrayString()
	{
		delete[] stringArrGlobal;
	}

	//[] operator overload, for accessing elements in the array
	string &operator[](int i)
	{

		int size = arrSize;

		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			// return first element.
			return stringArrGlobal[0];
		}


		return stringArrGlobal[i];

	}


	//<< operator overload, for displaying the entire array
	friend std::ostream& operator<< (std::ostream& out, DynamicArrayString& point);



	//*****Array operators*****

	//size - return the size of the array
	int size()
	{

		int size = arrSize;
		return size;

	}

	//empty - is this array empty?
	bool empty()
	{

		if (NULL == stringArrGlobal)
		{
			return true;
		}
		else return false;

	}

private:
	string* stringArrGlobal;

	string arrType;
};

ostream& operator<<(ostream& os, DynamicArrayString& c)
{

	string arrayStr = "{ ";
	string tempArray;
	for (int i = 0; i < c.arrSize; i++)
	{
		tempArray = c[i];
		arrayStr += tempArray
;
		if (i < c.arrSize - 1) arrayStr += ", ";

	}
	arrayStr += " }";
	os << arrayStr;
	return os;
}


class DynamicArrayBool
{
	// Access specifier
public:
	//global variables
	int arrSize;



	//if there is no input, i'm not sure how we can declare the size of the array when we don't even know the type
	//how can the user declare the type without declaring the size?
	DynamicArrayBool()
	{
	}


	//*****CONSTRUCTORSt*****

	//CONSTRUCTOR - takes in an bool list, e.g. {1,2,3}
	DynamicArrayBool(std::initializer_list<bool> list)
	{
		arrType = "bool";
		boolArrGlobal = new bool[list.size()];
		std::copy(list.begin(), list.end(), boolArrGlobal);
		arrSize = list.size();

	}




	//CONSTRUCTOR - takes in an bool array
	DynamicArrayBool(bool arr[])
	{
		arrSize = sizeof(arr) / sizeof(*arr);
		boolArrGlobal = arr;
		arrType = "bool";
	}



	//CONSTRUCTOR - takes in parameters for size and data type
	DynamicArrayBool(bool size, string type)
	{

		boolArrGlobal = new bool[size];
		arrSize = size;
		arrType = "bool";

	}

	//CONSTRUCTOR - takes in parameters for data type, sets size to 15 by default
	DynamicArrayBool(string type)
	{

		boolArrGlobal = new bool[15];
		arrSize = 15;
		arrType = "bool";



	}

	//DESCRUCTOR - deletes the object
	~DynamicArrayBool()
	{
		delete[] boolArrGlobal;
	}

	//[] operator overload, for accessing elements in the array
	bool &operator[](int i)
	{

		int size = arrSize;

		if (i > size)
		{
			cout << "Index out of bounds" << endl;
			// return first element.
			return boolArrGlobal[0];
		}


		return boolArrGlobal[i];

	}


	//<< operator overload, for displaying the entire array
	friend std::ostream& operator<< (std::ostream& out, DynamicArrayBool& point);



	//*****Array operators*****

	//size - return the size of the array
	int size()
	{

		int size = arrSize;
		return size;

	}

	//empty - is this array empty?
	bool empty()
	{

		if (NULL == boolArrGlobal)
		{
			return true;
		}
		else return false;

	}

private:
	bool* boolArrGlobal;

	string arrType;
};

ostream& operator<<(ostream& os, DynamicArrayBool& c)
{

	string arrayStr = "{ ";
	bool tempArray;
	for (int i = 0; i < c.arrSize; i++)
	{
		tempArray = c[i];
		arrayStr += to_string(tempArray);
		if (i < c.arrSize - 1) arrayStr += ", ";

	}
	arrayStr += " }";
	os << arrayStr;
	return os;
}

int main()
{
	// Declare an object of class geeks
	DynamicArrayInt dynamicArray = { 456,504,722 };

	cout << dynamicArray[0] << endl;
	cout << dynamicArray << endl;
	cout << "size of array is: " << dynamicArray.size() << endl;
	cout << "Is this array empty? " << dynamicArray.empty() << endl << endl;

	DynamicArrayDouble doubleDynamicArray = { 456.1,504.1,722.1 };

	cout << doubleDynamicArray[0] << endl;
	cout << doubleDynamicArray << endl;
	cout << "size of array is: " << doubleDynamicArray.size() << endl;
	cout << "Is this array empty? " << doubleDynamicArray.empty();

	return 0;
}