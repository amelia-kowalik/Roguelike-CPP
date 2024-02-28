#include "Enemy.h"
#include <cmath>

Enemy::Enemy() {
    setWeakness();
    isFree = true;
}

void Enemy::setWeakness() {
    weakness = rand() % traits.size();
}

Enemy::Enemy(int manipulation, int charisma, int intelligence, int charm) : Entity(
        manipulation, charisma, intelligence, charm) {
    setWeakness();
}

void Enemy::makeAMove(vector<vector<Tile>> &mapData, vector<vector<Tile>> &levelData, Character &character) {
    if (isFree) {
        int distance = 6;
        int diff_x = _row - character._row;
        int diff_y = _column - character._column;
        int distanceFromPlayer = static_cast<int>(sqrt((diff_x * diff_x) + (diff_y * diff_y)));

        if (distance > distanceFromPlayer) {

            vector<pair<int, int>> possibleMoves = {
                    {_row - 1, _column - 1},
                    {_row - 1, _column},
                    {_row - 1, _column + 1},
                    {_row, _column - 1},
                    {_row, _column + 1},
                    {_row + 1, _column - 1},
                    {_row + 1, _column},
                    {_row + 1, _column + 1}
            };

            vector<pair<int, int>> validMoves;
            for (const auto& move : possibleMoves) {
                int x = move.first;
                int y = move.second;
                if (x >= 0 && x < mapData.size() && y >= 0 && y < mapData[0].size() &&
                    levelData[x][y].getTileType() == Tile::FLOOR) {
                    validMoves.push_back(move);
                }
            }

            if (!validMoves.empty()) {
                int randIndex = rand() % validMoves.size();

                mapData[_row][_column] = Tile(' ');
                levelData[_row][_column] = Tile(' ');

                _row = validMoves[randIndex].first;
                _column = validMoves[randIndex].second;

                mapData[_row][_column] = Tile('A');
                levelData[_row][_column] = Tile('A');
            }
        }
    }
}

