#include <iostream>
#include <vector>

int main() {
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items {1, 1, 0, 3};
    float totalSum = 0.f;
    for (int n : items) {
        totalSum += prices[n];
    }

    std::cout << "Total price: " << totalSum << std::endl;
}