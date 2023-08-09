#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result_i;
    int result_j;
    int max_sum;

    for (int i = 0; i < a.size(); i++) {
        int total_sum = a[i];
        for (int j = i + 1; j < a.size(); j++ ) {
            total_sum += a[j];
            if (!max_sum) {
                max_sum = total_sum;
            } else if (total_sum > max_sum) {
                max_sum = total_sum;
                result_i = i;
                result_j = j;
            }
        }   
        
    }

    std::cout << result_i<< ' ' << result_j << std::endl;
}