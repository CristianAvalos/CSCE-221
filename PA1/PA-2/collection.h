#include "Stress_ball.h"
#include <fstream>
#include <exception>
#include <iostream>
using namespace std;

enum class Sort_choice {
    bubble_sort, insertion_sort, selection_sort
};

class Collection {
private:
    Stress_ball *array;
    int size;
    int capacity;
    void resize() {
        if (capacity == 0) {
            capacity = 2;
        }
        else {
            capacity *= 2;
        }
        Stress_ball *temp = new Stress_ball[capacity];
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
    void insert_item(const Stress_ball& sb);
    bool contains(const Stress_ball& sb) const;
    Stress_ball remove_any_item();
    void remove_this_item(const Stress_ball& sb);
    void make_empty();
    bool is_empty() const;
    int total_items() const;
    int total_items(Stress_ball_sizes s) const;
    int total_items(Stress_ball_colors t) const;
    void print_items();
    Stress_ball& operator[](int idx);
    const Stress_ball& operator[](int i) const;
};

istream& operator>>(istream& is, Collection& c);
ostream& operator<<(ostream& os, const Collection& c);
Collection make_union(const Collection& c1, const Collection& c2);
void swap(Collection& c1, Collection& c2);
void sort_by_size(Collection&c, Sort_choice sort);
