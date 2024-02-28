#include "Level.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

#include "MapTiles.h"
using namespace std;


Level::Level(){}

vector<vector<Tile>> Level::createLevel() {
    int x = 28;
    int y = 20;
    vector<vector<bool>> map(x, vector<bool>(y, false));
    int howManyRooms = rand() % 5 + 3;

    int tries = 10;
    int density = 2;
    vector<int>pointX;
    vector<int>pointY;

    while(tries > 0 && pointX.size() < howManyRooms){
        int randX = rand() % (x - 2) + 1; //randomowe koordynaty dla pokoji
        int randY = rand() % (y - 2) + 1;

        bool tooClose = false;
        for(int p=0; p < pointX.size(); p++){
            Path pathway = Pathway(map, randX, randY, pointX[p], pointY[p]);
            int distance = pathway.distance;

            if(distance < density){ //jesli dystans jest mniejszy niz gestosc(odleglosc pokoji od siebie) to sa za blisko
                tooClose = true;
                tries--;
                break;
            }
        }

        if(!tooClose){
            pointX.push_back(randX); //jesli pokoje nie sa zbyt blisko siebie to dodaje ich kordy do vektorow
            pointY.push_back(randY);
            map[randX][randY] = true; //oznacza floor jako 1
            tries = 10;
            makeRoom(map, randX, randY);
        }

        makeCorridors(map, pointX, pointY); //laczy pokoje

    }


        for (int height = y - 1; height >= 0; height--) {
            vector<Tile> line;
            for (int width = 0; width < x; width++) {
                if (map[width][height]) {
                    Tile tile(' ');
                    line.push_back(tile);
                } else {
                    Tile tile('#');
                    line.push_back(tile);
                }
            }
            mapData.push_back(line);
            //cout << endl;
        }
    if(stage != 6) {
        for (int numberOfItems = 0; numberOfItems < 2; numberOfItems++) {
            int tries2 = 50;
            while (tries2 > 0) {
                int x_rand = rand() % (x - 5) + 1;
                int y_rand = rand() % (y - 5) + 1;
                //cout << x_rand << " " << y_rand << endl;
                if (x_rand < x - 5 && y_rand < y - 5) {
                    if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                        Tile item('X');
                        mapData[y_rand][x_rand] = item;
                        //map[x_rand][y_rand] = true;
                        break;
                    }
                }
                tries2--;
            }
        }

        for (int numberOfEnemies = 0; numberOfEnemies < 3; numberOfEnemies++) {
            int tries2 = 50;
            while (tries2 > 0) {
                int x_rand = rand() % (x - 5) + 1;
                int y_rand = rand() % (y - 5) + 1;
                //cout << x_rand << " " << y_rand << endl;
                if (x_rand < x - 5 && y_rand < y - 5) {
                    if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                        Tile enemy('A');
                        mapData[y_rand][x_rand] = enemy;
                        //map[x_rand][y_rand] = true;
                        break;
                    }
                }
                tries2--;
            }
        }


        int tries3 = 50;
        while (tries3 > 0) {
            int x_rand = rand() % (x - 5) + 1;
            int y_rand = rand() % (y - 5) + 1;
            //cout << x_rand << " " << y_rand << endl;
            if (x_rand < x - 5 && y_rand < y - 5) {
                if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                    Tile door('/');
                    mapData[y_rand][x_rand] = door;
                    //map[x_rand][y_rand] = true;
                    break;
                }
            }
            tries3--;
        }

        int tries4 = 50;
        while (tries4 > 0) {
            int x_rand = rand() % (x - 5) + 1;
            int y_rand = rand() % (y - 5) + 1;
            //cout << x_rand << " " << y_rand << endl;
            if (x_rand < x - 5 && y_rand < y - 5) {
                if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                    Tile character('@');
                    mapData[y_rand][x_rand] = character;
                    //map[x_rand][y_rand] = true;
                    break;
                }
            }
            tries4--;
        }
    } else {
        int tries = 50;
        while (tries > 0) {
            int x_rand = rand() % (x - 5) + 1;
            int y_rand = rand() % (y - 5) + 1;
            //cout << x_rand << " " << y_rand << endl;
            if (x_rand < x - 5 && y_rand < y - 5) {
                if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                    Tile character('@');
                    mapData[y_rand][x_rand] = character;
                    break;
                }
            }
            tries--;
        }

        int tries2 = 50;
        while (tries2 > 0) {
            int x_rand = rand() % (x - 5) + 1;
            int y_rand = rand() % (y - 5) + 1;
            //cout << x_rand << " " << y_rand << endl;
            if (x_rand < x - 5 && y_rand < y - 5) {
                if (mapData[y_rand][x_rand].getTileChar() == ' ') {
                    Tile boss('P');
                    mapData[y_rand][x_rand] = boss;
                    break;
                }
            }
            tries2--;
        }

    }

return mapData;
}


void Level::makeRoom(vector<vector<bool>> &map, int &positionOfX, int &positionOfY){
    int roomWidth = rand() % 13 + 5;
    int roomHeight = rand() % 13 + 5;

    int halfX = roomWidth / 2;
    int halfY = roomHeight / 2;
    for(int makingY = positionOfY - halfY; makingY <= positionOfY + halfY; makingY++){
        for(int makingX = positionOfX - halfX; makingX <= positionOfX + halfX - 1; makingX++){
            if (makingX >= 2 && makingX < map.size() - 2) {
                if (makingY >= 2 && makingY < map[0].size() - 2) {
                    map[makingX][makingY] = true;
                }
            }
        }
    }
}

void Level::makeCorridors(vector<vector<bool>> &map, vector<int> &xPoints, vector<int> &yPoints){

    for(int point = 0; point < xPoints.size() - 1; point++){
        Path shortestWay;
        for(int checkingPoint = point + 1; checkingPoint < xPoints.size(); checkingPoint++){
            if(point != checkingPoint){
                Path pathway = Pathway(map, xPoints[point], yPoints[point], xPoints[checkingPoint], yPoints[checkingPoint]);
                if(shortestWay.distance == -1){
                    shortestWay = pathway;
                }
                else if(pathway.distance < shortestWay.distance){
                    shortestWay = pathway;
                }
            }
        }
        for(int tile=0; tile < shortestWay.path_rows.size(); tile++){
            map[shortestWay.path_rows[tile]][shortestWay.path_columns[tile]] = true;
        }
    }
}

Path Level::Pathway(vector<vector<bool>> &map, int startX, int startY, int endX, int endY){

    int n = map.size(), m = map[0].size();
    vector<int> pathway;
    MapTiles start(0, startX, startY, 0, 0, pathway);


    vector<vector<char>> matrix(n, vector<char>(m));
    matrix[endX][endY] = 'X';
    matrix[startX][startY] = 'M';
    //zaznaczanie odwiedzonych Tiles
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int minDistance = -1;
    int monitorCount = -1;
    priority_queue<MapTiles> queue; //algorytm BFS
    queue.push(start);
    visited[start.row][start.column] = true;
    int currentId = 1;
    MapTiles trafionyTile;

    while(!queue.empty()){
        MapTiles pom = queue.top();
        MapTiles::allTiles.push_back(MapTiles(pom.id, pom.row, pom.column,pom.distance, pom.monitors, pom.path));

        queue.pop();

        if (matrix[pom.row][pom.column] == 'X') {
            if (minDistance == -1 || pom.distance < minDistance || (pom.distance == minDistance && pom.monitors < monitorCount)) {
                minDistance = pom.distance;
                monitorCount = pom.monitors;
                trafionyTile = pom;
                //cout << "Wielkosc: " << pom.sciezka.size() << endl;
                break;
            }
        }
        //up
        if(pom.row - 1 >= 0 && !visited[pom.row - 1][pom.column]){
            queue.push(MapTiles(currentId,pom.row - 1, pom.column,pom.distance+1, pom.monitors + (matrix[pom.row - 1][pom.column] == 'M'), pom.path));
            visited[pom.row - 1][pom.column] = true;
            currentId++;
        }
        //down
        if(pom.row + 1 < n && !visited[pom.row + 1][pom.column]){
            queue.push(MapTiles(currentId,pom.row + 1, pom.column, pom.distance+1, pom.monitors + (matrix[pom.row + 1][pom.column] == 'M'), pom.path));
            visited[pom.row + 1][pom.column] = true;
            currentId++;
        }
        //left
        if(pom.column - 1 >= 0 && !visited[pom.row][pom.column - 1]){
            queue.push(MapTiles(currentId,pom.row, pom.column - 1, pom.distance+1, pom.monitors + (matrix[pom.row][pom.column - 1] == 'M'), pom.path));
            visited[pom.row][pom.column - 1] = true;
            currentId++;
        }
        //right
        if(pom.column + 1 < m && !visited[pom.row][pom.column + 1]){
            queue.push(MapTiles(currentId,pom.row, pom.column + 1, pom.distance+1, pom.monitors + (matrix[pom.row][pom.column + 1] == 'M'), pom.path));
            visited[pom.row][pom.column + 1] = true;
            currentId++;
        }
    }
    return Path(trafionyTile.distance, trafionyTile.path);
}


void Level::readLevel(Character &character, int &stage, vector<vector<Tile>> &mapData) {
    for (int i = 0; i < mapData.size(); ++i) {
        vector<Tile> row;
        for (int j = 0; j < mapData[i].size(); ++j) {
            char tileChar = mapData[i][j].getTileChar();
            Tile tile(tileChar);
            row.push_back(tile);



            if(tile.getTileType() == Tile::CHARACTER){
                character.setPos(levelData.size(),j);
            }


            if(tile.getTileType() == Tile::ENEMY){
                Enemy en;
                switch(stage){
                    case 1:
                        en = Enemy(rand() % 2 + 1,rand() % 2 + 1,rand() % 2 + 1,rand() % 2 + 1);
                        break;
                    case 2:
                        en = Enemy(rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1);
                        break;
                    case 3:
                        en = Enemy(rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1);
                        break;
                    case 4:
                        en = Enemy(rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1);
                        break;
                    case 5:
                        en = Enemy(rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1);
                        break;
                }
                en.setPos(levelData.size(),j);
                enemies.push_back(en);
            }

            if(tile.getTileType() == Tile::ITEM){
                Item it;

                int randRarity = rand() % 100 + 1;
                if(randRarity <= 50){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Gloves", Entity::CHARM, 1);
                            break;
                        case 2:
                            it.makeItem("Narcissus", Entity::MANIPULATION, 1);
                            break;
                        case 3:
                            it.makeItem("Handkerchief", Entity::CHARISMA, 1);
                            break;
                    }
                }
                else if(randRarity <= 70){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Blush", Entity::CHARM, 2);
                            break;
                        case 2:
                            it.makeItem("Emma's Drawings", Entity::INTELLIGENCE, 2);
                            break;
                        case 3:
                            it.makeItem("Shawl", Entity::CHARM, 2);
                            break;
                    }
                }
                else if(randRarity <= 80){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Frances Burney's novel", Entity::INTELLIGENCE, 3);
                            break;
                        case 2:
                            it.makeItem("Fan", Entity::CHARISMA, 3);
                            break;
                    }
                }
                else if(randRarity <= 98){
                    it.makeItem("Perfume", Entity::MANIPULATION, 4);
                }
                else {
                    it.makeItem("Hibiscus tea", Entity::NOTRAIT, 1);
                }
                it.setPos(levelData.size(),j);
                itemsOnMap.push_back(it);
            }

        }
        levelData.push_back(row);
    }


}



void Level::printLevel(){
    for(int i=0; i<levelData.size(); i++){
        for(int j=0; j<levelData[i].size(); j++){
            cout << levelData[i][j].getTileChar();
        }
        cout << endl;
    }
    cout << endl;
}


void Level::moveCharacter(char input, Character &character) {
    for (int i = 0; i < 30; ++i) {
        cout << endl;
    }
    int charaRow;
    int charaColumn;

    character.getPos(charaRow, charaColumn);



    switch (input) {
        case 'w':
            processMove(character, charaRow-1, charaColumn);
            break;
        case 's':
            processMove(character, charaRow+1, charaColumn);
            break;
        case 'a':
            processMove(character, charaRow, charaColumn-1);
            break;
        case 'd':
            processMove(character, charaRow, charaColumn+1);
            break;
        case 'f':
            character.displayStats();
            break;
        case 'r':
            character.addPoints();
            break;
        case 'e':
            Inventory::showInventory();
            break;
        default:
            cout << "Unknow ipnut" << endl;
    }
}

char Level::getTile(int row, int column){
    return levelData[row][column].getTileChar();
}

void Level::setTile(int row, int column, char tile){
    levelData[row][column] = Tile(tile);
}

void Level::processMove(Character &character, int targetRow, int targetColumn) {
    int charaRow;
    int charaColumn;
    character.getPos(charaRow, charaColumn);

    Tile moveToTile = getTile(targetRow, targetColumn);

    switch (moveToTile.getTileType()) {
        case Tile::WALL://running into a wall
        character.setPos(charaRow, charaColumn);
        cout << "THAT'S A WALL !!!" << endl;
            break;
        case Tile::FLOOR://walking on the floor
            character.setPos(targetRow, targetColumn); //target tile
            setTile(charaRow, charaColumn,' '); //old placement changes to 'floor'
            setTile(targetRow,targetColumn,'@'); //target placement changes to 'character'
            break;
        case Tile::ITEM:
            int itemIndex;
            for(size_t i=0; i<itemsOnMap.size(); i++){
                int itemRow, itemColumn;
                itemsOnMap[i].getPos(itemRow,itemColumn);

                if(itemRow == targetRow && itemColumn == targetColumn){
                    itemIndex = i;
                }

            }
            if(itemIndex != -1) {
                if(itemsOnMap[itemIndex].getTrait() == Entity::NOTRAIT){
                    character._chances++;
                    setTile(charaRow, charaColumn, ' ');
                    setTile(targetRow, targetColumn, '@');
                    cout << "You found [Hibiscus Tea] and drank it right away :-O It gave you +1 to chances!" << endl;
                } else {
                    cout << "You found " << itemsOnMap[itemIndex].getName() << " [" << itemsOnMap[itemIndex].getTraitName() << " +" << itemsOnMap[itemIndex].getPower() << "] just laying there. Would you like to take it?" << endl;
                    cout << "Yes or No" << endl;
                    string choice;
                    cin >> choice;
                    if (choice == "Yes" || choice == "yes" || choice == "y") {
                        character.setPos(targetRow, targetColumn);
                        setTile(charaRow, charaColumn, ' ');
                        setTile(targetRow, targetColumn, '@');
                        Inventory::addItem(itemsOnMap[itemIndex], character);
                        itemsOnMap.erase(itemsOnMap.begin() + itemIndex);
                    }
                }
            }
            break;

            case Tile::ENEMY:
                for (size_t i = 0; i < enemies.size(); i++) {
                int enemyRow, enemyColumn;
                enemies[i].getPos(enemyRow, enemyColumn);

                if (enemyRow == targetRow && enemyColumn == targetColumn) {
                    if(!enemies[i].isFree){
                        cout << "This gentleman is already yours." << endl;
                        character.setPos(charaRow, charaColumn);
                    } else {
                        BattleSystem::seduction(character, enemies[i]);
                        break;
                    }
                }
            }
            break;
                case Tile::DOOR:
                character.setPos(targetRow, targetColumn);
                setTile(charaRow, charaColumn,' ');
                setTile(targetRow,targetColumn,'@');
                changeLevel(character, stage);
                break;
        case Tile::BOSS:
            character.setPos(targetRow, targetColumn);
            BattleSystem::megaSeduction(character);
            break;
        default:
            break;
    }
}

void Level::changeLevel(Character &character, int &stage) {
    stage++;
    enemies.clear();
    itemsOnMap.clear();
    levelData.clear();
    mapData.clear();
    mapData = createLevel();
    readLevel(character, stage, mapData);
}
