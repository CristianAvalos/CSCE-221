#include "Stress_ball.h"
#include "jeans.h"
#include <fstream>
#include <exception>
#include <iostream>
using namespace std;

enum class Sort_choice {
    bubble_sort, insertion_sort, selection_sort
};

template <class Obj, class F1, class F2>
class Collection {
private:
    Obj *array;
    int size;
    int capacity;
    void resize() {
        if (capacity == 0) {
            capacity = 2;
        }
        else {
            capacity *= 2;
        }
        Obj *temp = new Obj[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = array[i];
        }
        delete [] array;
        array = temp;
    }
public:
    Collection();
    Collection(int s);
    Collection(const Collection &rhs); // copy constructor
    Collection& operator=(const Collection &rhs); // copy assignment
    ~Collection();
    Collection(Collection&& other); // move contructor
    Collection& operator=(Collection&& other); // move assingment
    void insert_item(const Obj& sb);
    bool contains(const Obj& sb) const;
    Obj remove_any_item();
    void remove_this_item(const Obj& sb);
    void make_empty();
    bool is_empty() const;
    int total_items() const;
    int total_items(F2 s) const;
    int total_items(F1 t) const;
    void print_items();
    Obj& operator[](int idx);
    const Obj& operator[](int i) const;
};

template <class Obj, class F1, class F2>
ostream& operator<<(ostream& os, const Collection<Obj, F1, F2>& c);

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2);

template <class Obj, class F1, class F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2);

template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2>&c, Sort_choice sort);

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection() {
    size = capacity = 0;
    array = nullptr;
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(int s) {
    size = s;
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(const Collection &rhs) { //copy cunstructor
    size = rhs.size;
    capacity = rhs.capacity;
    array = new Obj[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = rhs.array[i];
    }
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>:: operator=(const Collection &rhs) { //copy assignment
    if (this != &rhs) {
        if (array != nullptr) {
            delete [] array;
        }
        size = rhs.size;
        capacity = rhs.capacity;
        array = new Obj[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::~Collection() {
    make_empty();
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(Collection&& other) { //move constructor
    array = other.array;
    size = other.size;
    capacity = other.capacity;
    other.array = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>:: operator=(Collection&& other) { //move assingment
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

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::insert_item(const Obj& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
}

template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::contains(const Obj& sb) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}

template <class Obj, class F1, class F2>
Obj Collection<Obj, F1, F2>::remove_any_item() {
    if (size == 0) {
        throw "Collection is empty.";
    }
    int index = rand() % size;
    Obj sb = array[index];
    for (int i = index + 1; i < size; i++) {
        array[i - 1] = array[i];
    }
    size--;
    return sb;
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1,  F2>::remove_this_item(const Obj& sb) {
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

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::make_empty() {
    if (array != nullptr) {
        delete [] array;
        size = 0;
        capacity = 0;
        array = nullptr;
    }
}

template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::is_empty() const {
    return size == 0;
}

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items() const {
    return size;
}

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F2 s) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_size() == s) {
            count++;
        }
    }
    return count;
}

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F1 t) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].get_color() == t) {
            count++;
        }
    }
    return count;
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::print_items() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

template <class Obj, class F1, class F2>
Obj& Collection<Obj, F1, F2>::operator[](int i){
    return array[i];
}

template <class Obj, class F1, class F2>
const Obj& Collection< Obj, F1, F2>::operator[](int i) const {
    return array[i];
}

template <class Obj, class F1, class F2>
ostream& operator<<(ostream& os, const Collection<Obj, F1, F2>& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << c[i] << endl;
    }
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> c3 = c1;
    for (int i = 0; i < c2.total_items(); i++) {
        c3.insert_item(c2[i]);
    }
    return c3;
}

template <class Obj, class F1, class F2> 
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> c3 = move(c1);
    c1 = move(c2);
    c2 = move(c3);
}

template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2>&c, Sort_choice sort) {
    switch (sort) {
        case Sort_choice::bubble_sort:
            bool swapped; 
            for (int i = 0; i < c.total_items() - 1; i++) { 
                swapped = false; 
                for (int j = 0; j < c.total_items() - i - 1; j++) { 
                    if (c[j].get_size() > c[j + 1].get_size()) { 
                        Obj temp = c[j];
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
            Obj key;
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
                Obj temp = c[i];
                c[i] = c[minIdx];
                c[minIdx] = temp;
            }
            break;
        default:
            throw "Invalid input.";
            break;
    }
}
