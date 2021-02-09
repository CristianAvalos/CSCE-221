#include "Stress_ball.h"
#include <iostream>

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) {
    color = c;
    size = s;
}

Stress_ball::Stress_ball() {
    color = Stress_ball_colors(rand() % 4);
    size = Stress_ball_sizes(rand() % 3);
}

Stress_ball_colors Stress_ball::get_color() const {
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const {
    return size;
}

bool Stress_ball::operator==(const Stress_ball& sb) {
    if((sb.color == this->color) && (sb.size == this->size)){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb) {
    std::string colorOut, sizeOut;
    switch (sb.get_color()) {
        case Stress_ball_colors::red:
            colorOut = "red";
            break;
        case Stress_ball_colors::blue:
            colorOut = "blue";
            break;
        case Stress_ball_colors::yellow:
            colorOut = "yellow";
            break;
        case Stress_ball_colors::green:
            colorOut = "green";
            break;            
    }
    switch (sb.get_size()) {
        case Stress_ball_sizes::small:
            sizeOut = "small";
            break;
        case Stress_ball_sizes::medium: 
            sizeOut = "medium";
            break;
        case Stress_ball_sizes::large:
            sizeOut = "large";
            break;
    }
    o << "(" << colorOut << ", " << sizeOut << ")";
    return o;
}