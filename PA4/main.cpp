#include <iostream>
#include <string>
#include <regex>
#include "HashTable.hpp"
#include "CSVEditor.hpp"
using namespace std;
/*
Name: Cristian Avalos
UIN: 627003137
Section: 501
*/

int main(int argc, const char * argv[]) {
    regex expr(".*,.*,(.*),(.*)");
	regex expr2(".*,(.*)");
    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";
	
    //OBTAIN M HERE
	int m = 0; 
	string line;
    ifstream file(rosterPath);
    while (getline(file, line)) {
        m++;
    }
    if (m == 0) {
        cout << "Input file size is empty." << endl;
        return 0;
    }

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, expr2, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();
	
	std::tuple<int, int, double> stats = editor.getStats();
	
	cout << "minimum chain len = " << std::get<0>(stats) << endl;
	cout << "maximum chain len = " << std::get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;
	
    return 0;    
}
