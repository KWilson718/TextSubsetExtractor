#include <iostream>
#include <fstream>
#include <filesystem>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::size_t;
using std::ifstream;
using std::ofstream;

namespace fs = std::filesystem;
using fs::exists;

void CollectInfo(string& input, string& output, size_t& start, int& end);
string ExtractData(string fileName, size_t start, int end);
bool WriteToFile(string fileName, string outputData);

int main(int argc, char* argv[]) {

    bool StillGoing = true;

    string inputFileName;
    string outputFileName;
    size_t start;
    int end;

    while (StillGoing){
        CollectInfo(inputFileName, outputFileName, start, end);

        string inputFilePath = "./InputFiles/" + inputFileName;
        string outputFilePath = "./OutputFiles/" + outputFileName;

        string extractedData = ExtractData(inputFilePath, start, end);

        cout << "Extracted: " << extractedData << " from " << inputFileName << endl;

        if (WriteToFile(outputFilePath, extractedData)){
            cout << "File Successfully Written" << endl;
        }
        else{
            cout << "ERROR in Writing Output File" << endl;
        }

        char continueChar;
        cout << "Do You Want to Extract More Data? (Y = Yes, N = No)" << endl;
        cin >> continueChar;
        if((continueChar == 'n')||(continueChar == 'N')){
            StillGoing = false;
        }
    }

    return 0;
}

// Collects the information for an input file name, an output file name, a start num, and an end num
void CollectInfo(string& input, string& output, size_t& start, int& end){
    bool SearchingForData = true;

    // Finds Input FileName, Repeating if File Doesn't Exist
    while (SearchingForData){
        cout << "Enter the File Name that you'd like to convert. Files should be in the InputFiles Folder:" << endl;
        cin >> input;
        
        // Checks to see if the file exists, if it doesn't, then it sets SearchingForData to true, outputs a message saying it wasn't found, and repeats collection
        SearchingForData = (!(exists("./InputFiles/" + input)));
        if (SearchingForData){
            cout << "ERROR Finding the File, please try again. Remember that it needs to be a file within the InputFiles Folder." << endl;
        }
    }

    SearchingForData = true;
    // Finds Output FileName, Verifying that User Wants to Override Data if File Already Exists
    while (SearchingForData){
        cout << "Enter the name of a file you want to write to. (Will Override Preexisting Files)" << endl;
        cin >> output;

        // Checks if a file with the same name exists, which will prompt for right to override if it does
        bool fileExists = exists("./OutputFiles/" + output);
        char confirmCheck;
        if (fileExists){
            cout << "A File with the same name already exists, do you wish to override? (Y = Yes, N = No)" << endl;
            cin >> confirmCheck;
            if ((confirmCheck == 'Y')||(confirmCheck == 'y')){
                SearchingForData = false;
            }
            else{
                cout << "In Order to Prevent Override, Please ";
            }
        }
        else{
            SearchingForData = false;
        }

    }

    SearchingForData = true;
    // Collects a number for where to start, makes sure it's above zero, asking again if it isn't
    while (SearchingForData){
        cout << "Please Enter A Position to Start Extraction At, The First Position is 1" << endl;
        cin >> start;

        if (start <= 0){
            cout << "Position Not Valid, ";
        }
        else{
            SearchingForData = false;
        }
    }

    SearchingForData = true;
    // Collects a number for output, makes sure it's equal to or greater than start, or that it's -1
    while (SearchingForData){
        cout << "Please Enter A Position to End Extraction At. If you Wish for the Rest of the File, enter -1" << endl;
        cin >> end;

        if (end == -1){
            SearchingForData = false;
        }
        else if(end >= start){
            SearchingForData = false;
        }
        else{
            cout << "Invalid Position, ";
        }
    }
}

string ExtractData(string fileName, size_t start, int end){
    string dataString;
    int dataLength = (end - (static_cast<int>(start)));
    ifstream fileInput;
    fileInput.open(fileName);

    if (fileInput.is_open()){
        if (start > 1){
            fileInput.ignore(start - 1, EOF);
        }
        if(end != -1){
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
        else{
            bool reading = true;
            while(reading){
                char c = fileInput.get();
                if (c != EOF){
                    dataString.push_back(c);
                }
                else{
                    reading = false;
                    break;
                }
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
