#include <iostream>
#include "collection.h"
#include <fstream>
#include <exception>
#include <iostream>
using namespace std;
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using CollectionJN = Collection<jeans, jeans_colors, jeans_sizes>;

  //////////////////////////////////
 //          Stress Balls        //
//////////////////////////////////
istream& operator>>(istream& is, CollectionSB& c) {
    string colorIn, sizeIn;
    Stress_ball_colors tempColor;
    Stress_ball_sizes tempSize;
    while (is.good()) {
        is >> colorIn >> sizeIn;
        if (colorIn == "red") {
            tempColor = Stress_ball_colors::red;
        }
        else if (colorIn == "blue") {
            tempColor = Stress_ball_colors::blue;
        }
        else if (colorIn == "yellow") {
            tempColor = Stress_ball_colors::yellow;
        }
        else if (colorIn == "green") {
            tempColor = Stress_ball_colors::green;
        }
        else {
            throw "Invalid option.";
        }
        if (sizeIn == "small") {
            tempSize = Stress_ball_sizes::small;
        }
        else if (sizeIn == "medium") {
            tempSize = Stress_ball_sizes::medium;
        }
        else if (sizeIn == "large") {
            tempSize = Stress_ball_sizes::large;
        }    
        else {
            throw "Invalid option.";
        }
        Stress_ball ball(tempColor, tempSize);
        c.insert_item(ball);
    }
    return is;
};

void test_stress_balls() {
    //////////////// creating first two objects ////////////////
    cout << "You selected stress_ball" << endl << endl;
    cout << "------------------------" << endl;
    cout << "Creating two collections" << endl;
    cout << "------------------------" << endl;
    CollectionSB object1;
    CollectionSB object1Copy;
    CollectionSB object2;
    string color;
    string size;

    // reading from first file
    ifstream firstObj("SBcollection.txt"); // file name, can be changed
    if(!firstObj.is_open()) {
        throw "Invalid file.";
    }
    firstObj >> object1;
    firstObj.close();
    cout << "First Object" << endl;
    object1.print_items();
    cout << endl;

    // making a copy of the first one
    object1Copy = object1;
    cout << "Object One Copy" << endl;
    object1Copy.print_items();
    cout << endl;
    
    // reading from second file
    ifstream secondObj("SBcollection2.txt"); // file name, can be changed
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
    CollectionSB object3;
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
};

  //////////////////////////////////
 //            Jeans             //
//////////////////////////////////
istream& operator>>(istream& is, CollectionJN& c) {
    string colorIn, sizeIn;
    jeans_colors tempColor;
    jeans_sizes tempSize;
    while (is.good()) {
        is >> colorIn >> sizeIn;
        if (colorIn == "black") {
            tempColor = jeans_colors::black;
        }
        else if (colorIn == "white") {
            tempColor = jeans_colors::white;
        }
        else if (colorIn == "grey") {
            tempColor = jeans_colors::grey;
        }
        else if (colorIn == "blue") {
            tempColor = jeans_colors::blue;
        }
        else {
            throw "Invalid option.";
        }
        if (sizeIn == "small") {
            tempSize = jeans_sizes::small;
        }
        else if (sizeIn == "medium") {
            tempSize = jeans_sizes::medium;
        }
        else if (sizeIn == "large") {
            tempSize = jeans_sizes::large;
        }    
        else {
            throw "Invalid option.";
        }
        jeans pair(tempColor, tempSize);
        c.insert_item(pair);
    }
    return is;
};

void test_jeans() {
    //////////////// creating first two objects ////////////////
    cout << "You selected jeans" << endl << endl;
    cout << "------------------------" << endl;
    cout << "Creating two collections" << endl;
    cout << "------------------------" << endl;
    CollectionJN object1;
    CollectionJN object1Copy;
    CollectionJN object2;
    string color;
    string size;

    // reading from first file
    ifstream firstObj("JScollection.txt"); // file name, can be changed
    if(!firstObj.is_open()) {
        throw "Invalid file.";
    }
    firstObj >> object1;
    firstObj.close();
    cout << "First Object" << endl;
    object1.print_items();
    cout << endl;

    // making a copy of the first one
    object1Copy = object1;
    cout << "Object One Copy" << endl;
    object1Copy.print_items();
    cout << endl;
    
    // reading from second file
    ifstream secondObj("JScollection2.txt"); // file name, can be changed
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
    int colorSize = object1.total_items(jeans_colors::black);
    cout << "First object size in black: " << colorSize << endl;
    int sameSize = object1.total_items(jeans_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //second object
    cout << "Second object sorted:" << endl;
    sort_by_size(object2, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object2.print_items();
    cout << endl;
    objSize = object2.total_items();
    cout << "Second object size: " << objSize << endl;
    colorSize = object2.total_items(jeans_colors::black);
    cout << "Second object size in black: " << colorSize << endl;
    sameSize = object2.total_items(jeans_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //////////////// creating the third object ////////////////
    cout << "------------------------" << endl;
    cout << "Third object:" << endl;
    cout << "------------------------" << endl;
    CollectionJN object3;
    object3 = make_union(object1, object2);
    object3.print_items();
    cout << endl;
    objSize = object3.total_items();
    cout << "Third object size: " << objSize << endl;
    colorSize = object3.total_items(jeans_colors::black);
    cout << "Second object size in black: " << colorSize << endl;
    sameSize = object3.total_items(jeans_sizes::small);
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
    colorSize = object1.total_items(jeans_colors::black);
    cout << "First object size in black: " << colorSize << endl;
    sameSize = object1.total_items(jeans_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl;

    //second object
    cout << "Second object sorted:" << endl;
    sort_by_size(object2, Sort_choice::bubble_sort); // sorting, can be changed to selection or insertion
    object2.print_items();
    cout << endl;
    objSize = object2.total_items();
    cout << "Second object size: " << objSize << endl;
    colorSize = object2.total_items(jeans_colors::black);
    cout << "Second object size in black: " << colorSize << endl;
    sameSize = object1.total_items(jeans_sizes::small);
    cout << "First object amount that are small: " << sameSize;
    cout << endl << endl << "Done." << endl;
};

int main() {
    int answer;
    cout << "What version to test: stress_ball (= 0) or jeans (= 1): ";
    cin >> answer;
    cout << endl;
    if (answer == 0)
        test_stress_balls();
    else if (answer == 1)
        test_jeans();
    else
        cout << "Wrong value: " << answer << endl;
    return 0;
}