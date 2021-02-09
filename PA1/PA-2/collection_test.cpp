#include "collection.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //////////////// creating first two objects ////////////////
    cout << "------------------------" << endl;
    cout << "Creating two collections" << endl;
    cout << "------------------------" << endl;
    Collection object1;
    Collection object2;
    string color;
    string size;

    // reading from first file
    ifstream firstObj("collectionOne.txt"); // file name, can be changed
    if(!firstObj.is_open()) {
        throw "Invalid file.";
    }
    firstObj >> object1;
    firstObj.close();
    cout << "First Object" << endl;
    object1.print_items();
    cout << endl;

    // reading from second file
    ifstream secondObj("collectionTwo.txt"); // file name, can be changed
    if(!secondObj.is_open()) {
        throw "Invalid file.";
    }
    secondObj >> object2;
    secondObj.close();
    cout << "Second Object" << endl;
    object2.print_items();
    cout << endl;

    //////////////// sorting the first two objects ////////////////
    cout << "------------------------" << endl;
    cout << "Sort by size:" << endl;
    cout << "------------------------" << endl;

    //first object
    cout << "First object sorted:" << endl;
    sort_by_size(object1, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object1.print_items(); 
    cout << endl;
    int objSize = object1.total_items();
    cout << "First object size: " << objSize << endl;
    int colorSize = object1.total_items(Stress_ball_colors::red);
    cout << "First object size in red: " << colorSize << endl;
    int sameSize = object1.total_items(Stress_ball_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //second object
    cout << "Second object sorted:" << endl;
    sort_by_size(object2, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object2.print_items();
    cout << endl;
    objSize = object2.total_items();
    cout << "Second object size: " << objSize << endl;
    colorSize = object2.total_items(Stress_ball_colors::red);
    cout << "Second object size in red: " << colorSize << endl;
    sameSize = object2.total_items(Stress_ball_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //////////////// creating the third object ////////////////
    cout << "------------------------" << endl;
    cout << "Third object:" << endl;
    cout << "------------------------" << endl;
    Collection object3;
    object3 = make_union(object1, object2);
    object3.print_items();
    cout << endl;
    objSize = object3.total_items();
    cout << "Third object size: " << objSize << endl;
    colorSize = object3.total_items(Stress_ball_colors::red);
    cout << "Second object size in red: " << colorSize << endl;
    sameSize = object3.total_items(Stress_ball_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //////////////// swaping the first two objects ////////////////
    cout << "------------------------" << endl;
    cout << "Swap first object and second object" << endl;
    cout << "------------------------" << endl;
    swap(object1, object2);
    cout << "New first object" << endl;
    object1.print_items();
    cout << endl;

    cout << "New second object" << endl;
    object2.print_items();
    cout << endl;

    //////////////// sorting the first two objects ////////////////
    cout << "------------------------" << endl;
    cout << "Sort by size:" << endl;
    cout << "------------------------" << endl;
    //first object
    cout << "First object sorted:" << endl;
    sort_by_size(object1, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object1.print_items();
    cout << endl;
    objSize = object1.total_items();
    cout << "First object size: " << objSize << endl;
    colorSize = object1.total_items(Stress_ball_colors::red);
    cout << "First object size in red:" << colorSize << endl;
    sameSize = object1.total_items(Stress_ball_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //second object
    cout << "Second object sorted:" << endl;
    sort_by_size(object2, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object2.print_items();
    cout << endl;
    objSize = object2.total_items();
    cout << "Second object size: " << objSize << endl;
    colorSize = object2.total_items(Stress_ball_colors::red);
    cout << "Second object size in red:" << colorSize << endl;
    sameSize = object1.total_items(Stress_ball_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl << "Done." << endl;
}
