/* 
 * File:   InsertionSort.cpp
 * Author: jerry
 *
 * Created on March 1, 2018, 1:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 1){
        cout<<"No command line argument given.\n"
                "Please provide the input file name as an argument.\n"
                "Ex: InsersionSort file.txt\n";
        return -1;
    }
    
    LinkedList list;
    ifstream inputFile;
    ofstream outputFile;
    string inputFileName(argv[1]);
    string outputFileName = inputFileName;
    outputFileName.append("_sorted.txt");
    long inputNum;
    
    // File input. It reads every line of the argued file into a long, then
    // adds it to the list.
    inputFile.open(inputFileName);
    if(inputFile.is_open()){
        while(inputFile >> inputNum){
            list.push(inputNum);
        }
        inputFile.close();
    }else{
        cout<<"Unable to open "<<inputFileName<<endl;
        return -1;
    }
    
    list.insertionSort();
    
    // File output. It prints every element of list onto its own line
    // in a file named "[inputFileName]_sorted.txt"
    outputFile.open(outputFileName);
    while(list.getSize() > 0){
        outputFile<<list.readHead()<<endl;
        list.deleteHead();
    }
    outputFile.close();
    
    cout<<"Success!\n";
    return 0; 
}



