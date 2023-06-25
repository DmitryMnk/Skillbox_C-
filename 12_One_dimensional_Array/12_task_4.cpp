#include <iostream>

int main() {
    int numbers[15]     = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int totalSum        = 0;
    int saveArray[2]{0, 0};

    saveArray[0] = numbers[0];
    saveArray[1] = numbers[1];
    for (int i = 0; i < 15; i++) {
        if (saveArray[0] < numbers[i]) {
            saveArray[0] = numbers[i];
        }

        if (saveArray[1] > numbers[i]) {
            saveArray[1] = numbers[i];
        }
        totalSum += numbers[i];
    }
    int arithmeticSum = (saveArray[0] + saveArray[1]) * 7;
    std::cout << totalSum - arithmeticSum << std::endl;
}