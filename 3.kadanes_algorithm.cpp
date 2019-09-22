//
// Created by boffa on 22/09/19.
//
#include <iostream>
#include <vector>

// problem: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

/*
    Property 1, Property 2 ...
*/
int max_sum_subarray(std::vector<int> const &v) {
    int sum = v.front(); // skip first element
    int max = sum;
    for (std::vector<int>::const_iterator it = v.begin() + 1; it != v.end(); ++it) {
        if (sum > 0) {
            sum += *it;
        } else {
            sum = *it;
        }

        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int main() {
    int T = 0;
    std::vector<int> v;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        std::cin >> N;
        v.reserve(N);
        for (int j = 0; j < N; ++j) {
            int elem;
            std::cin >> elem;
            v.push_back(elem);
        }
        std::cout << max_sum_subarray(v) << std::endl;
        v.clear();
    }
    return 0;
}