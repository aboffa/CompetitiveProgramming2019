//
// Created by boffa on 22/09/19.
//
#include <iostream>
#include <vector>

int trapping_rain_water(std::vector<int> const &v) {
    int to_return = 0;
    std::vector<int> max_left;
    std::vector<int> max_right;
    max_left.reserve(v.size());
    max_right.reserve(v.size());
    int max = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
        max_left[i] = max;
    }
    max = -1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] > max) {
            max = v[i];
        }
        max_right[i] = max;
    }
    for (int i = 1; i < v.size() - 1; i++) {
        to_return += std::min(max_right[i], max_left[i]) - v[i];
    }
    return to_return;
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
        std::cout << trapping_rain_water(v) << std::endl;
        v.clear();
    }
}
