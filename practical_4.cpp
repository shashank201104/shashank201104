#include <iostream>
#include <vector>

void generateSolutions(int n, int C, std::vector<int>& solution, int currentIndex, int currentSum) {
    if (currentIndex == n) {
        if (currentSum == C) {
            for (int i = 0; i < n; ++i) {
                std::cout << solution[i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 0; i <= C - currentSum; ++i) {
            solution[currentIndex] = i;
            generateSolutions(n, C, solution, currentIndex + 1, currentSum + i);
        }
    }
}

int main() {
    int n, C;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Enter the value of C (C <= 10): ";
    std::cin >> C;

    std::vector<int> solution(n, 0);

    generateSolutions(n, C, solution, 0, 0);

    return 0;
}
