//
// Created by boffa on 22/09/19.
//

//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/?ref=self
#include <iostream>
#include <vector>

int missing_number(std::vector<int> const &v) {
    int sum = 0;
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    int size = v.size() + 1;
    int should_be_sum = (size * (size + 1)) / 2;
    return should_be_sum - sum;
}

int main() {
    int T = 0;
    std::vector<int> v;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        std::cin >> N;
        v.reserve(N - 1);
        for (int j = 0; j < N - 1; ++j) {
            int elem;
            std::cin >> elem;
            v.push_back(elem);
        }
        std::cout << missing_number(v) << std::endl;
        v.clear();
    }
    return 0;
}