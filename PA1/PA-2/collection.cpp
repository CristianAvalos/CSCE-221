#include "collection.h"
using namespace std;

Collection::Collection() {
    size = capacity = 0;
    array = nullptr;
}

Collection::Collection(int s) {
    size = s;
}

Collection::Collection(const Collection &rhs) { //copy cunstructor
    size = rhs.size;
    capacity = rhs.capacity;
    array = new Stress_ball[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = rhs.array[i];
    }
}

Collection& Collection:: operator=(const Collection &rhs) { //copy assignment
    if (this != &rhs) {
        if (array != nullptr) {
            delete [] array;
        }
        size = rhs.size;
        capacity = rhs.capacity;
        array = new Stress_ball[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

Collection::~Collection() {
    make_empty();
}

Collection::Collection(Collection&& other) { //move constructor
    array = other.array;
    size = other.size;
    capacity = other.capacity;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Collection& Collection:: operator=(Collection&& other) { //move assingment
    if (this != &other) {
        if (array != nullptr) {
            delete [] array;
        }
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
} 

void Collection::insert_item(const Stress_ball& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
}

bool Collection::contains(const Stress_ball& sb) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}

Stress_ball Collection::remove_any_item() {
    if (size == 0) {
        throw "Collection is empty.";
    }
    int index = rand() % size;
    Stress_ball sb = array[index];
    for (int i = index + 1; i < size; i++) {
        array[i - 1] = array[i];
    }
    size--;
    return sb;
}

void Collection::remove_this_item(const Stress_ball& sb) {
    if (size == 0) {
        throw "Collection is empty.";
    }
    int idx;
    for (idx = 0; idx < size; idx++) {
        if (array[idx] == sb) {
            break;
        }
    } 
    for (int i = idx + 1; i < size; i++) {
        array[i - 1] = array[i];
    }
}

void Collection::make_empty() {
    if (array != nullptr) {
        delete [] array;
        size = 0;
        capacity = 0;
        array = nullptr;
    }
}

bool Collection::is_empty() const {
    return size == 0;
}

int Collection::total_items() const {
    return size;
}

int Collection::total_items(Stress_ball_sizes s) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_size() == s) {
            count++;
        }
    }
    return count;
}

int Collection::total_items(Stress_ball_colors t) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_color() == t) {
            count++;
        }
    }
    return count;
}

void Collection::print_items() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

Stress_ball& Collection::operator[](int i){
    return array[i];
}

const Stress_ball& Collection::operator[](int i) const {
    return array[i];
}

istream& operator>>(istream& is, Collection& c) {
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
}

ostream& operator<<(ostream& os, const Collection& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << c[i] << endl;
    }
}

Collection make_union(const Collection& c1, const Collection& c2) {
    Collection c3 = c1;
    for (int i = 0; i < c2.total_items(); i++) {
        c3.insert_item(c2[i]);
    }
    return c3;
}

void swap(Collection& c1, Collection& c2) {
    Collection c3 = move(c1);
    c1 = move(c2);
    c2 = move(c3);
}

void sort_by_size(Collection&c, Sort_choice sort) {
    switch (sort) {
        case Sort_choice::bubble_sort:
            bool swapped; 
            for (int i = 0; i < c.total_items() - 1; i++) { 
                swapped = false; 
                for (int j = 0; j < c.total_items() - i - 1; j++) { 
                    if (c[j].get_size() > c[j + 1].get_size()) { 
                        Stress_ball temp = c[j];
                        c[j] = c[j + 1];
                        c[j + 1] = temp;
                        swapped = true; 
                    } 
                } 
                if (swapped == false) {
                    break; 
                }
            } 
            break;
        case Sort_choice::insertion_sort: {
            int j;
            Stress_ball key;
            for (int i = 1; i < c.total_items(); i++) {  
                j = i - 1;
                key = c[i];
                while (j >= 0 && (c[j].get_size() > key.get_size())) {  
                    c[j + 1] = c[j];  
                    j = j - 1;  
                }  
                c[j + 1] = key;  
            }  
            break;
        }
        case Sort_choice::selection_sort:
            int minIdx;
            for (int i = 0; i < c.total_items() - 1; i++) {  
                minIdx = i;  
                for (int j = i + 1; j < c.total_items(); j++) {
                    if (c[j].get_size() < c[minIdx].get_size()) { 
                        minIdx = j;  
                    }
                }
                Stress_ball temp = c[i];
                c[i] = c[minIdx];
                c[minIdx] = temp;
            }
            break;
        default:
            throw "Invalid input.";
            break;
    }
}
