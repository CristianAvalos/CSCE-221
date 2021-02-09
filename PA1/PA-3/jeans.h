#include <iostream>
#include <cstdlib>
#include <fstream>

enum class jeans_colors {
    black, white, grey, blue
};

enum class jeans_sizes {
    small, medium, large
};

class jeans {
private:
    jeans_colors color;
    jeans_sizes size;
public:
    jeans(jeans_colors c, jeans_sizes s);
    jeans();
    jeans_colors get_color() const;
    jeans_sizes get_size() const;
    bool operator==(const jeans& js);
};

std::ostream& operator<<(std::ostream& o, const jeans& js);
