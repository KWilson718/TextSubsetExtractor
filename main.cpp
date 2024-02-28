#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::size_t;


string ExtractData(string fileName, size_t start, size_t end);

int main(int argc, char* argv[]) {
    bool StillGoing = true;
    string inputFileName;
    string outputFileName;
    int start;
    int end;

    
    while (StillGoing){
        cout << "Enter the File Name & Path that you'd like to convert" << endl;
        cin >> inputFileName;
        cout << "Enter the starting position you want to capture. The positions start from 1" << endl;
        cin >> start;
        cout << "Enter the ending position you want to capture" << endl;
        cin >> end;

        cout << "Searching for a file called: \"" << inputFileName << "\" and will start at positon " << start << " then capturing the text through position " << end << "." << endl;
        StillGoing = false;
    }

    return 0;
}

string ExtractData(string fileName, size_t start, size_t end){

}