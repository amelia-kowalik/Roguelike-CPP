#ifndef LOTR_TILE_H
#define LOTR_TILE_H


class Tile {
public:
    enum TileType{
        WALL,
        FLOOR,
        CHARACTER,
        ITEM,
        ENEMY,
        DOOR,
        BOSS
    };

    Tile(char token);
    TileType getTileType();
    char getTileChar();

private:
    TileType type;
    char token;
};


#endif
