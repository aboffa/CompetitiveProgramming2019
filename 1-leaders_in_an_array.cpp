//
// Created by boffa on 22/09/19.
//
#include <iostream>
#include <vector>

// problem: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

std::vector<int> reserve_leaders_in_an_array(const std::vector<int> &v) {
    std::vector<int> result;
    int max = -1;
    for (std::vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        if (*it >= max) {
            result.push_back(*it);
            max = *it;
        }
    }
    return result;
}

int main() {
    int T = 0;
    std::vector<int> v;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        std::cin >> N;
        v.reserve(N);
        for (int j = 0; j < N; j++) {
            int elem;
            std::cin >> elem;
            v.push_back(elem);
        }
        std::vector<int> result(reserve_leaders_in_an_array(v));
        for (std::vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        v.clear();
    }
    return 0;
}
