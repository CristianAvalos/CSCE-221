#include "CSVEditor.hpp"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

CSVEditor::CSVEditor(string& inputPath, string& rosterPath, string& outputPath, regex expr, regex expr2, int m) {
    input = ifstream(inputPath);
	roster = ifstream(rosterPath);
	output = ofstream(outputPath);
	regexPattern = expr;
	regexPattern2 = expr2;
	hashTable = new HashTable<string>(m);
}

CSVEditor::~CSVEditor(){
	delete hashTable;
	input.close();
	roster.close();
	output.close(); 
}

void CSVEditor::readCSVToTable() {
	string line;
	smatch parts;
    while (getline(input, line)) {
        if(regex_search(line, parts, regexPattern)) {
			hashTable->insert(stoi(parts[1]), parts[2]);
		}
    }
}

void CSVEditor::writeCSVToFile() {
	string line2;
	smatch parts2;
	while(getline(roster, line2)) {
		if (regex_search(line2, parts2, regexPattern2)) {
			if (hashTable->search(stoi(parts2[1])) != "nullptr") {
				output << parts2[0] << ", " << hashTable->search(stoi(parts2[1])) << endl;
			}
			else {
				output << parts2[0] << ", " << endl;
			}
		}
	}
}

std::tuple<int, int, double> CSVEditor::getStats(){
	int minLen = hashTable->minChainLen();
	int maxLen = hashTable->maxChainLen();
	double avgLen = hashTable->averageChainLen();
	return std::make_tuple(minLen, maxLen, avgLen);
}