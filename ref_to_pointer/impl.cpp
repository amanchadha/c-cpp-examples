#include <iostream>
int main () {
    char *str1 = "Hello ";
    char *str2 = "World!";
    char *ptr = str1;
    char *&rptr = str1;
    rptr = str2;
    std::cout << ptr << str1 << std::endl;
    printf("\n\n%s\n\n", ptr);
    std::cout << ptr << rptr << std::endl;

    char x[2];
    scanf("%s", &x);
    std::cin >> x;
    std::cout << x;
}
