#include <iostream>

int main() {
    int coefficients[] = {4, 2, 9}; 
    int n;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = 0;
    int powerOfN = 1;

    for (int i = 0; i < sizeof(coefficients) / sizeof(coefficients[0]); i++) {
        result += coefficients[i] * powerOfN;
        powerOfN *= n;
    }

    std::cout << "The value of f(" << n << ") is: " << result << std::endl;

    return 0;
}
