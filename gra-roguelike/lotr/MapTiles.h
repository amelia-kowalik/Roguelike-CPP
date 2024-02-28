//
// Created by melka on 24.01.2024.
//

#ifndef LOTR_MAPTILES_H
#define LOTR_MAPTILES_H
#include <vector>
using namespace std;


class MapTiles {
public:
    static vector<MapTiles> allTiles;
    int id;
    int row;
    int column;
    int distance;
    int monitors;
    vector<int> path;

    MapTiles ();
    MapTiles (int id, int row, int column, int distance, int monitors, std::vector<int> path_);

    static int TileIndex(int &id);

    bool operator<(const MapTiles & other) const;
};

#endif //LOTR_MAPTILES_H
