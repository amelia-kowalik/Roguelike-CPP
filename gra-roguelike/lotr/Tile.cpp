#include "Tile.h"

Tile::Tile(char token) {
    this->token = token;

    switch(token) {
        case '#':
            type = WALL;
            break;
        case '.':
            type = FLOOR;
            break;
        case '@':
            type = CHARACTER;
            break;
        case '?':
            type = ITEM;
            break;
        case 'A':
            type = ENEMY;
            break;
        default:
            type = FLOOR;
            break;
    }
}

Tile::TileType Tile::getTileType() {
    return type;
}

char Tile::getTileChar() {
    return token;
}

