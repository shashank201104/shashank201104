#include <iostream>
#include <vector>

class RELATION {
private:
    std::vector<std::vector<bool>> matrix;
    int size;

public:
    RELATION(int n) : size(n) {
        matrix.resize(n, std::vector<bool>(n, false));
    }

    void setElement(int i, int j, bool value) {
        matrix[i][j] = value;
    }

    bool isReflexive() {
        for (int i = 0; i < size; ++i) {
            if (!matrix[i][i]) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] && matrix[j][i] && i != j) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j]) {
                    for (int k = 0; k < size; ++k) {
                        if (matrix[j][k] && !matrix[i][k]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void determineRelationType() {
        bool isEquivalence = isReflexive() && isSymmetric() && isTransitive();
        bool isPartialOrder = isReflexive() && isAntiSymmetric() && isTransitive();

        if (isEquivalence) {
            std::cout << "The given relation is an Equivalence relation." << std::endl;
        } else if (isPartialOrder) {
            std::cout << "The given relation is a Partial Order relation." << std::endl;
        } else {
            std::cout << "The given relation is None." << std::endl;
        }
    }
};

int main() {
    int n;

    std::cout << "Enter the size of the matrix: ";
    std::cin >> n;

    RELATION relation(n);

    std::cout << "Enter the matrix elements (0 or 1):" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            std::cin >> value;
            relation.setElement(i, j, value);
        }
    }

    std::cout << std::boolalpha;

    std::cout << "Reflexive: " << relation.isReflexive() << std::endl;
    std::cout << "Symmetric: " << relation.isSymmetric() << std::endl;
    std::cout << "Anti-Symmetric: " << relation.isAntiSymmetric() << std::endl;
    std::cout << "Transitive: " << relation.isTransitive() << std::endl;

    relation.determineRelationType();

    return 0;
}
