#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 1){
        cout<<"No command line argument given.\n"
                "Please provide the input file name as an argument.\n"
                "Ex: TODO:[your program's name] file.txt\n";
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
            // TODO: add each inputNum to your data structure, e.g. list.push(inputNum);
        }
        inputFile.close();
    }else{
        cout<<"Unable to open "<<inputFileName<<endl;
        return -1;
    }
    
    // TODO: perform sort here
    
    // File output. It prints every element of list onto its own line
    // in a file named "[inputFileName]_sorted.txt"
    outputFile.open(outputFileName);
    // TODO: have your data structure ptint each element to the file. Example below.
    //while(list.getSize() > 0){
    //    
    //    outputFile<<list.readHead()<<endl;
    //    list.deleteHead();
    //}
    outputFile.close();
    
    return 0; 
}
