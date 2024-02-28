//
// Created by melka on 24.01.2024.
//

#ifndef LOTR_PATH_H
#define LOTR_PATH_H
#include <vector>
using namespace std;


class Path {
public:
    std::vector<int> path_rows;
    std::vector<int> path_columns;
    int distance;

    Path(int distance, std::vector<int> indexes);
    Path() {
        distance = -1;
    }
};


#endif //LOTR_PATH_H
