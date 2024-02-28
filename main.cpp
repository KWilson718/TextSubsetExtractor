#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::size_t;
using std::ifstream;
using std::ofstream;


string ExtractData(string fileName, size_t start, size_t end);
bool WriteToFile(string fileName, string outputData);

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
        cout << "Enter the output file name you'd like to have" << endl;
        cin >> outputFileName;

        cout << "Searching for a file called: \"" << inputFileName << "\" and will start at positon " << start << " then capturing the text through position " << end << "." << endl;

        extractedData = ExtractData(inputFileName, start, end);

        cout << "Found the Data: " << extractedData << endl;

        cout << "Outputting to File..." << endl;

        if (WriteToFile(outputFileName, extractedData)){
            cout << "Output Successful" << endl;
        }
        else{
            cout << "There was an Error Outputting Data to a File" << endl;
        }

        cout << "Would you like to continue? (1 = Yes, 0 = No)" << endl;

        size_t keepGoing = 0;
        cin >> keepGoing;
        if (keepGoing == 0){
            StillGoing = false;
        }
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

bool WriteToFile(string fileName, string outputData){
    bool successful = false;
    ofstream fileOutput;
    fileOutput.open(fileName);
    
    if (fileOutput.is_open()){
        fileOutput << outputData;
        successful = true;
    }

    fileOutput.close();
    return successful;
}