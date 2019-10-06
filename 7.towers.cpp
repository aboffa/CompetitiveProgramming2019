//
// Created by boffa on 27/09/19.
//

// problem: http://codeforces.com/problemset/problem/37/A?locale=en
#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> towers_solver_1(std::vector<int> const &v, int max) {
    std::pair<int, int> result(1, 0);
    std::vector<int> newV(max,0);
    for (int i = 0; i < v.size(); i++) {
        newV[v[i]]++;
    }
    for (int i = 0; i < newV.size(); i++) {
        if(newV[i] != 0) {
            result.second++;
        }
        if (newV[i] > result.first) {
            result.first = newV[i];
        }
    }
    return result;
}

std::pair<int, int> towers_solver_2(std::vector<int> const &v) {
    std::pair<int, int> result(1, 0);
    std::unordered_map<int, int> umap;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (umap.find(*it) == umap.end()) {
            umap[*it] = 1;
        } else {
            umap[*it]++;
        }
    }
    for (auto it = umap.begin(); it != umap.end(); ++it) {
        result.second++;
        if (it->second > result.first) {
            result.first = it->second;
        }

    }
    return result;
}

int main() {
    int N = 0;
    int MAX_VALUE = 1001;
    std::vector<int> v;
    std::cin >> N;
    v.reserve(N);
    for (int j = 0; j < N; j++) {
        int elem;
        std::cin >> elem;
        v.push_back(elem);
    }
    std::pair<int, int> result(towers_solver_2(v));
    std::cout << result.first << " " << result.second << std::endl;
    return 0;
}