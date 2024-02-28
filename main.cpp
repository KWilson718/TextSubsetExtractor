#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::size_t;
using std::ifstream;


string ExtractData(string fileName, size_t start, size_t end);

int main(int argc, char* argv[]) {
    bool StillGoing = true;
    string inputFileName;
    string outputFileName;
    int start;
    int end;

    string extractedData;

    
    while (StillGoing){
        cout << "Enter the File Name & Path that you'd like to convert" << endl;
        cin >> inputFileName;
        cout << "Enter the starting position you want to capture. The positions start from 1" << endl;
        cin >> start;
        cout << "Enter the ending position you want to capture" << endl;
        cin >> end;

        cout << "Searching for a file called: \"" << inputFileName << "\" and will start at positon " << start << " then capturing the text through position " << end << "." << endl;

        extractedData = ExtractData(inputFileName, start, end);

        cout << "Found the Data: " << extractedData << endl;

        StillGoing = false;
    }

    return 0;
}

string ExtractData(string fileName, size_t start, size_t end){
    string dataString;
    size_t dataLength = (end - start);
    ifstream fileInput;
    fileInput.open(fileName);

    if (fileInput.is_open()){
        if (start > 1){
            fileInput.ignore(start - 1, EOF);
        }

        for (size_t i = 0; i <= dataLength; i++){
            char c = fileInput.get();
            if (c != EOF){
                dataString.push_back(c);
            }
            else{
                break;
            }
        }
    }
    fileInput.close();
    return dataString;
}