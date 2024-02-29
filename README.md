# TextSubsetExtractor

## Purpose

- After a Friend Voiced an issue with creating PCR Primers from a Genome Sequence, where one needed to find a series of characters from a string of text that had no spaces or other delimiters, it seemed as though there wasn't a good way to easily find a subset of data from such at a certain character position. In this, the search for a method of quickly and concisely finding a subset of text came about. This small & quickly developed program wishes to solve such.

- The main goal is to have an efficient method of finding a subset of characters from a file starting at a certain character position, and then going for a certain amount of characters.

- Additionally, this provides expereince for trying to make C++ Programs work within VS Code, as well as distributing it to someone who doesn't use GitHub

## Usage

The program is a simple Command Line one that prompts a user for a few pieces of information

- InputFile: The text document that holds the information that needs to have a subset extracted from it. Please place this in the "InputFiles" folder so that the program can access it. Additionally, please include the file ending (.txt) for efficiency of coding
- OutputFile: The name of a document where the subset will be outputted, can be found in the output file
- Start: The first position (not index) of the character starting the extraction subset. The counter starts at 1 and goes up from there rather than indexes starting at 0
- End: The ending position, this character will be the final character included within the subset. If you want the rest of the file to be captured, please enter -1

## Technologies Used

- C++ Programming Language
- VS Code
- MinGW Compiler