#include <iostream>
#include <cstdlib>


enum class Stress_ball_colors {
    red, blue, yellow, green
};

enum class Stress_ball_sizes {
    small, medium, large
};

class Stress_ball {
private:
    Stress_ball_colors color;
    Stress_ball_sizes size;
public:
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
    Stress_ball();
    Stress_ball_colors get_color() const;
    Stress_ball_sizes get_size() const;
    bool operator==(const Stress_ball& sb);
};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);
