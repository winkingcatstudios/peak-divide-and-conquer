//Program name: peak.cpp
//Author: Dan Kercher
//Date last updated: 11/13/2020
//Purpose: To find the peak integer from an input file using binary search principles for O(logn) time complexity
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Counter for recursion analysis
int counter = 0;

// Recursive binary search: calculate the mid point of the vector, 
int DivideAndConquerPeak(vector<int> vect, int start, int end, int length)
{
	// Global variable to count recusion calls
	++counter;

	// Vector mid point
	int mid = start + (end - start) / 2;

	// Is mid first or last element? If yes, return it as peak
	if (mid == 0 || mid == length-1)
		return mid;

	// Next, compare mid to neighbors. Is mid greater than both neighbors? If yes, return it as peak
	if ((vect[mid] >= vect[mid - 1]) && (vect[mid] >= vect[mid + 1]))
		return mid;

	// Did not find peak, rerun with new mid
	
	// Descending? Mid is to the left
	// Make vector end one less than current mid to binary search to the left
	if (vect[mid] < vect[mid - 1])
		return DivideAndConquerPeak(vect, start, (mid - 1), length);

	// Ascending? Mid is to the right
	// Make vector start one more than current mid to binrary search to the right
	if (vect[mid+1] > vect[mid])
		return DivideAndConquerPeak(vect, (mid + 1), end, length);
}

int main()
{
	// A vector to hold input
	vector<int> numbers;

	// Input file stream from peak.txt resource file
	ifstream in("peak.txt", ios::in);

	// Push input file stream to populate vector
	int number;		
	while (in >> number) 
	{
		numbers.push_back(number);
	}

	// Close the file stream
	in.close();

	// Vector length, used several times below
	int length = numbers.size();

	//Display the input vector
	cout << "*****Input Vector****\n";
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}

	// Run Binary Divide and Conquer Peak Search
	// Output the index and value of peak as required by assignment, and also the number of function calls for analysis
	int index = DivideAndConquerPeak(numbers, 0, length-1, length);
	cout << "\n\n*****Binary Search Results*****";
	cout << "\nIndex of the peak point is "
		<< index;
	cout << "\nValue of the peak point is "
		<< numbers[index];
	cout << "\nNumber of elements checked is "
		<< counter << "\n";

	return 0;
}
