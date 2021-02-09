#include "jeans.h"
#include <iostream>
#include <fstream>

jeans::jeans(jeans_colors c, jeans_sizes s) {
    color = c;
    size = s;
}

jeans::jeans() {
    color = jeans_colors(rand() % 4);
    size = jeans_sizes(rand() % 4);
}

jeans_colors jeans::get_color() const {
    return color;
}

jeans_sizes jeans::get_size() const {
    return size;
}

bool jeans::operator==(const jeans& js) {
    if((js.color == this->color) && (js.size == this->size)){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& o, const jeans& js) {
    std::string colorOut, sizeOut;
    switch (js.get_color()) {
        case jeans_colors::black:
            colorOut = "black";
            break;
        case jeans_colors::white:
            colorOut = "white";
            break;
        case jeans_colors::grey:
            colorOut = "grey";
            break;
        case jeans_colors::blue:
            colorOut = "blue";
            break;            
    }
    switch (js.get_size()) {
        case jeans_sizes::small:
            sizeOut = "small";
            break;
        case jeans_sizes::medium: 
            sizeOut = "medium";
            break;
        case jeans_sizes::large:
            sizeOut = "large";
            break;
    }
    o << "(" << colorOut << ", " << sizeOut << ")";
    return o;
}