#include <iostream>

using namespace std;

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

int main() {
    std::cout << STRINGIFY(1)"00" << endl;
    std::cout << "2""00" << endl;
    printf("3""00");
    return 0;
}
