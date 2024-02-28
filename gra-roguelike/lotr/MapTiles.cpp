#include "MapTiles.h"

std::vector<MapTiles> MapTiles::allTiles;

MapTiles::MapTiles() {}

MapTiles::MapTiles(int id, int row, int column, int distance, int monitors, std::vector<int> path_)
        : id(id), row(row), column(column), distance(distance), monitors(monitors), path(path_) {
    path.push_back(id);
}

int MapTiles::TileIndex(int &id){
    for(int i = 0; i < MapTiles::allTiles.size(); i++){
        if(allTiles[i].id == id){
            return i;
        }
    }
    return 0;
}

bool MapTiles::operator<(const MapTiles& other) const {
    if(distance == other.distance){
        return monitors > other.monitors;
    }
    return distance > other.distance;
}
