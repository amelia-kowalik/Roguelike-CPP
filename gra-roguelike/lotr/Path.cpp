#include "Path.h"
#include "MapTiles.h"

Path::Path(int distance, std::vector<int> indexes) : distance(distance) {
    for (int i = 0; i < indexes.size(); i++) {
        int index = MapTiles::TileIndex(indexes[i]);
        path_rows.push_back(MapTiles::allTiles[index].row);
        path_columns.push_back(MapTiles::allTiles[index].column);
    }
    MapTiles::allTiles.clear();
}

