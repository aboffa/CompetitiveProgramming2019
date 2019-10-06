//
// Created by boffa on 23/09/19.
//
#include <iostream>
#include <vector>
#include <deque>

// problem: https://practice.geeksforgeeks.org/problems/next-larger-element/0

// O(n) solution
std::vector<long long> next_larger_element(std::vector<long long> const &v) {
    std::vector<long long> result;
    result.reserve(v.size());
    std::deque<long long> deque;
    for (int i = v.size() - 1; i >= 0; i--) {
        while (!deque.empty() && v[i] >= v[deque.front()]) {
            deque.pop_front();
        }
        if (deque.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(v[deque.front()]);
        }
        deque.push_front(i);
    }
    return result;
}

int main() {
    int T = 0;
    std::vector<long long> v;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0;
        std::cin >> N;
        v.reserve(N);
        for (int j = 0; j < N; j++) {
            long long elem;
            std::cin >> elem;
            v.push_back(elem);
        }
        std::vector<long long> result(next_larger_element(v));
        for (std::vector<long long>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        v.clear();
    }
    return 0;
}
