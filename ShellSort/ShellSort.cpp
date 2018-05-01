/*
 * ShellSort.cpp, implementation of shell sort using Hibbards
 * @author jbschmi3
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include "ShellSort.h"

using namespace std;

//implementation of shellsort using Hibbard's sequence
void shellSort(std::vector<long>& vect) {
  int k = 0;
  size_t j;
  size_t gap = 1;  //gap we will use for shellsort
  
  //traverse vector until gap size is found
  while(gap <= vect.size() + 1) {
    for(size_t i = gap; i < vect.size(); i++) {
      int temp = vect.at(i);
      j = i;
      
      while(j >= gap && vect.at(j - gap) > temp) {
	vect.at(j) = vect.at(j - gap);
	j = j - gap;
      }
      
      //vector at traversal position 
      vect.at(j) = temp;
    }
    //increment k counter
    k++;
    //set gap to hibbard's
    gap = pow(2,k) - 1;
  }  
}

int main(int argc, char *argv[]) {  
    if(argc == 1){
        cout<<"No command line argument given.\n"
                "Please provide the input file name as an argument.\n"
                "Ex: ShellSort file.txt\n";
        return -1;
    }
    
    std::vector<long> aVector; //vector to be sorted
    ifstream inputFile;
    ofstream outputFile;
    std::string inputFileName(argv[1]);
    std::string outputFileName = inputFileName;
    outputFileName.append("_sorted.txt");
    long inputNum;
    
    // File input. It reads every line of the argued file into a long, then
    // adds it to the list.
    inputFile.open(inputFileName);
    if(inputFile.is_open()){
        while(inputFile >> inputNum){
            // Adds each inputNum to the vector
	        aVector.push_back(inputNum);
        }
        inputFile.close();
    }else{
        cout<<"Unable to open "<<inputFileName<<endl;
        return -1;
    }
    
    // Performs the sort
    shellSort(aVector);
    
    // File output. It prints every element of list onto its own line
    // in a file named "[inputFileName]_sorted.txt"
    outputFile.open(outputFileName);
    if(outputFile.good()) {
      for(size_t i = 0; i < aVector.size(); i++) {
        outputFile << aVector.at(i) << endl;
      } 
      cout << "Success!\n";
    } else {
        cout << "Error opening file. " << endl;
    }
    outputFile.close();
    
    return 0; 
}



