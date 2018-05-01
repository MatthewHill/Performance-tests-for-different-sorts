
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
//Sees "arr[]" as two subarrays.  a->b and b-> last
void merge(int arr[], int a, int b, int last)
{
	int x;
	int y;
	int Merged;
	int temp0 = b - a + 1;
	int temp1 = last - b;

	//breaks down "arr[]" into two temporary arrays
	int Left[temp0];
	int Right[temp1];
	//Copy data to the left subarray
	for (x = 0; x < temp0; x++)
	{
		Left[x] = arr[a + x];
	}
	//Copy data to the right subarray
	for (y = 0; y < temp1; y++)
	{
		Right[y] = arr[b + 1 + y];
	}
	
	x = 0; 
	y = 0; 
	Merged = a; //First value of the new merged array
	//Sorts into the merged array by comparing the leading values
	while (x < temp0 && y < temp1)
	{
		if (Left[x] <= Right[y])
		{
			arr[Merged] = Left[x];
			x++;
		}
		else
		{
			arr[Merged] = Right[y];
			y++;
		}
		Merged++; //Move to next value in array
	}
	while (x < temp0)
	{
		arr[Merged] = Left[x];
		x++;
		Merged++;  //Move to next value in array
	}
	while (y < temp1)
	{
		arr[Merged] = Right[y];
		y++;
		Merged++; //Move to next value in array
	}
}
//Recursive method for merging
void mergeSort(int arr[], int a, int last)
{
	if (a < last)
	{
		int b = a + (last - a) / 2;
		mergeSort(arr, a, b);
		mergeSort(arr, b + 1, last);
		merge(arr, a, b, last);
	}
}
//Driver
int main(int argc, char *argv[])
{
	if (argc == 1) {
		cout << "No command line argument given.\n"
			"Please provide the input file name as an argument.\n"
			"Ex: TODO:[your program's name] file.txt\n";
		return -1;
	}
	vector<int> vector;
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName(argv[1]);
	string outputFileName = inputFileName;
	inputFile.open(inputFileName);
	outputFileName.append("_sorted.txt");
	long inputNum;
	if (inputFile.is_open()) {
		while (inputFile >> inputNum) {
			 // adds each inputNum to your data structure
			vector.push_back(inputNum);
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open " << endl;
		return -1;
	}
	//perform sort here
	const int vectorsize = vector.size();
	int arr[vectorsize];
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	printf("Array has  %d  Elements. \n", arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = vector.back();
		vector.pop_back();
	}
	mergeSort(arr, 0, arrSize - 1);
	outputFile.open(outputFileName);
	int i = 0;
	while (arrSize > 0) {
		outputFile << arr[i] << endl;
		i++;
		arrSize = arrSize - 1;
	}
	outputFile.close();

	return 0;
}
