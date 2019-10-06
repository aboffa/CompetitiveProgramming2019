//
// Created by boffa on 30/09/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

// Input length = n^2 = M.
// Complexity = O(M*log(M))
std::vector<int> finding_team_member(std::vector<std::vector<int>> &v) {
    std::vector<int> result((v.size() + 1), 0);
    std::vector<std::tuple<int, int, int>> aux;
    aux.reserve((v.size() * (v.size() + 1 )) / 2);
    for (int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++){
            aux.push_back(std::make_tuple(v[i][j],i+2,j+1));
        }
    }
    std::sort(aux.begin(), aux.end(),
              [](std::tuple<int, int, int> a, std::tuple<int, int, int> b) { return std::get<0>(a) > std::get<0>(b); });
    for (auto it = aux.begin(); it != aux.end(); ++it) {
        //std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << " " << std::get<2>(*it) << " - ";
        if (result[std::get<1>(*it)-1] == 0 && result[std::get<2>(*it)-1] == 0) {
            result[std::get<1>(*it)-1] = std::get<2>(*it);
            result[std::get<2>(*it)-1] = std::get<1>(*it);
        }

    }
    return result;
}

int main() {
    int N = 0;
    std::vector<std::vector<int>> v;
    std::cin >> N;
    v.reserve(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; i++) {
        std::vector<int> row;
        row.reserve(i + 1);
        for (int j = 0; j <= i; j++) {
            int elem;
            std::cin >> elem;
            row.push_back(elem);
        }
        v.push_back(row);
    }
    std::vector<int> result(finding_team_member(v));
    for (std::vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}