#include <iostream>
#include <vector>

void generatePermutations(std::vector<int>& digits, std::vector<int>& permutation, std::vector<bool>& chosen, bool withRepetition) {
    if (permutation.size() == digits.size()) {
        for (int digit : permutation) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = 0; i < digits.size(); ++i) {
            if (!withRepetition && chosen[i]) {
                continue;  
            }

            chosen[i] = true;
            permutation.push_back(digits[i]);

            generatePermutations(digits, permutation, chosen, withRepetition);

            chosen[i] = false;
            permutation.pop_back();

            if (!withRepetition) {
                while (i + 1 < digits.size() && digits[i] == digits[i + 1]) {
                    ++i;
                }
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of digits: ";
    std::cin >> n;

    std::vector<int> digits(n);
    std::cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> digits[i];
    }

    bool withRepetition;
    std::cout << "Generate permutations with repetition? (1 for Yes, 0 for No): ";
    std::cin >> withRepetition;

    std::vector<int> permutation;
    std::vector<bool> chosen(n, false);

    generatePermutations(digits, permutation, chosen, withRepetition);

    return 0;
}
