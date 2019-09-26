//
// Created by boffa on 23/09/19.
//
#include <iostream>
#include <vector>
#include <deque>

std::vector<int> next_larger_element(std::vector<int> const &v) {
    std::vector<int> result;
    result.reserve(v.size());
    std::deque<int> deque;
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
        std::vector<int> result(next_larger_element(v));
        for (std::vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        v.clear();
    }
}
