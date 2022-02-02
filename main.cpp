#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

std::vector<int> inputArray(); 
void countSwaps(std::vector<int>& );

int main()
{
    std::vector<int> inputVector = inputArray();
    countSwaps(inputVector);
    return 0;
}

std::vector<int> inputArray() {
    int n = 0, temp = 0; std::vector<int> q;
    std::cout << "Input array size: " << std::endl; std::cin >> n;
    std::cout << "Input array integers" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp; q.push_back(temp);
    }
    temp = q.size();
    try {
        if (temp < 1 || temp > 100000 || std::cin.fail()) {
            throw std::invalid_argument("Too large queue");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return q;
};

void countSwaps(std::vector<int>& inputVector) {
    int numSwaps = 0;
    for (int i = 0; i < static_cast<int> (inputVector.size()); i++) {
        for (int j = 0; j < static_cast<int> (inputVector.size()) - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (inputVector[j] > inputVector[j + 1]) {
                std::swap(inputVector[j], inputVector[j + 1]);
                numSwaps++;
            }
        }
    }
    std::cout << "Array is sorted in " << numSwaps << " swaps." << std::endl;
    std::cout << "First Element: " << inputVector.front() << std::endl;
    std::cout << "Last Element: " << inputVector.back() << std::endl;
};