//
// Created by boffa on 22/09/19.
//
#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>

// problem: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

// O(n) solution
std::vector<int> max_subarrays_size_k(std::vector<int> const &v, int k) {
    std::vector<int> result;
    result.reserve(v.size() - k + 1);
    std::deque<int> deque;
    for (int i = 0; i < v.size(); i++) {
        while (!deque.empty() && deque.front() <= i - k) {
            deque.pop_front();
        }
        while (!deque.empty() && v[deque.back()] <= v[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
        if (i >= k - 1) {
            result.push_back(v[deque.front()]);
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
        int K = 0;
        std::cin >> N;
        std::cin >> K;
        v.reserve(N);
        for (int j = 0; j < N; j++) {
            int elem;
            std::cin >> elem;
            v.push_back(elem);
        }
        std::vector<int> result(max_subarrays_size_k(v, K));
        for (std::vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        v.clear();
    }
}
