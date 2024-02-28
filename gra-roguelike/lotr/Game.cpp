#include "Game.h"

Game::Game(){
    character = Character(1,1,1,1,1,3);
    vector<vector<Tile>> createdMap = level.createLevel();
    level.readLevel(character, level.stage, createdMap);
    //level.printLevel();

}

void Game::playGame() {
    startScreen();
    bool isDone = true;
    while (isDone) {
        if (character._chances != 0) {
            characterMove();
            enemiesMove();
            level.printLevel();

        } else {
            if (BattleSystem::prince.isWonOver) {
                endScreen();
            } else {
                badEndScreen();
            }
            break;
        }
    }
}

void Game::characterMove(){
    char input;
    cin>>input;
    level.moveCharacter(input, character);

}

void Game::enemiesMove() {
    for(int i=0; i<level.enemies.size(); i++){
        level.enemies[i].makeAMove(level.mapData, level.levelData, character);
    }
}

void Game::initDialogue() {
    Dialogue::addStartingAdmirerLine("Happiness in marriage is entirely a matter of chance.", Entity::CHARISMA);
    Dialogue::addStartingAdmirerLine("There is no charm equal to tenderness of heart.", Entity::CHARM);
    Dialogue::addStartingAdmirerLine("The world is a stage, but the play is badly cast.", Entity::INTELLIGENCE);
    Dialogue::addStartingAdmirerLine("The person, be it gentleman or lady, who has not pleasure in a good novel, must be intolerably stupid.", Entity::INTELLIGENCE);
    Dialogue::addStartingAdmirerLine("Life seems but a quick succession of busy nothings.", Entity::INTELLIGENCE);
    Dialogue::addStartingAdmirerLine("Ah! There is nothing like staying at home, for real comfort.", Entity::CHARM);
    Dialogue::addStartingAdmirerLine("There is nothing I would not do for those who are really my friends. I have no notion of loving people by halves, it is not my nature. ", Entity::MANIPULATION);
    Dialogue::addStartingAdmirerLine("I have been a selfish being all my life, in practice, though not in principle. ", Entity::CHARISMA);


    Dialogue::addCharacterLine("It isn't what we say or think that defines us, but what we do. ",Entity::CHARISMA);
    Dialogue::addCharacterLine("I declare after all there is no enjoyment like reading! How much sooner one tires of anything than of a book!",Entity::INTELLIGENCE);
    Dialogue::addCharacterLine("There are as many forms of love as there are moments in time.", Entity::CHARM);
    Dialogue::addCharacterLine("To love is to burn, to be on fire.", Entity::CHARM);
    Dialogue::addCharacterLine("Selfishness must always be forgiven, you know, because there is no hope of a cure.", Entity::MANIPULATION);
    Dialogue::addCharacterLine("It is a truth universally acknowledged, that a single man in possession of a good fortune, must be in want of a wife.", Entity::MANIPULATION);
    Dialogue::addCharacterLine("For what do we live, but to make sport for our neighbours and laugh at them in our turn?",Entity::CHARISMA);
    Dialogue::addCharacterLine("To be fond of dancing is a certain step towards falling in love. ", Entity::CHARM);
    Dialogue::addCharacterLine("Every moment had its pleasure and its hope.",Entity::INTELLIGENCE);
    Dialogue::addCharacterLine("Angry people are not always wise.", Entity::MANIPULATION);
    Dialogue::addCharacterLine("There is safety in reserve, but no attraction. One cannot love a reserved person.", Entity::CHARM);
    Dialogue::addCharacterLine("Nothing ever fatigues me but doing what I do not like.", Entity::CHARISMA);


    Dialogue::addNegativeAdmirerResponse("My lady, your company is as refreshing as a summer breeze, yet I find myself yearning for the shelter of solitude.", Entity::NOTRAIT);
    Dialogue::addNegativeAdmirerResponse("Madam, your grace is as undeniable as the dance of a butterfly. Alas, my affections flutter elsewhere.", Entity::NOTRAIT);
    Dialogue::addNegativeAdmirerResponse("My lady, like a rose with too many thorns, your company, though visually captivating, leaves me cautious of drawing too near.", Entity::NOTRAIT);

    Dialogue::addPositiveAdmirerResponse("My heart is filled with joy whenever I am in your presence, my lady. Your charm and grace are unparalleled.", Entity::NOTRAIT);
    Dialogue::addPositiveAdmirerResponse("I don't think I could bear to say goodbye after I let you into my heart.", Entity::NOTRAIT);
    Dialogue::addPositiveAdmirerResponse("In dancing, you exceed many-and in loveliness, I have known no equal. ", Entity::NOTRAIT);
    Dialogue::addPositiveAdmirerResponse("I've never met anyone as kind as you are, except my Mum, of course. ", Entity::NOTRAIT);
    Dialogue::addPositiveAdmirerResponse("I may have lost my heart, but not my self-control.", Entity::NOTRAIT);
    Dialogue::addPositiveAdmirerResponse("You pierce my soul. I am half agony, half hope... I have loved none but you.", Entity::NOTRAIT);
}


void Game::endScreen() {
cout << "________00000000000___________000000000000_________\n"
        "______00000000_____00000___000000_____0000000______\n"
        "____0000000_____________000______________00000_____\n"
        "___0000000_______________0_________________0000____\n"
        "__000000____________________________________0000___\n"
        "__00000_____________________________________ 0000__\n"
        "_00000______________________________________00000__\n"
        "_00000_____________________________________000000__\n"
        "__000000_________________________________0000000___\n"
        "___0000000______________________________0000000____\n"
        "_____000000____________________________000000______\n"
        "_______000000________________________000000________\n"
        "__________00000_____________________0000___________\n"
        "_____________0000_________________0000_____________\n"
        "_______________0000_____________000________________\n"
        "_________________000_________000___________________\n"
        "_________________ __000_____00_____________________\n"
        "______________________00__00_______________________\n"
        "________________________00_________________________" << endl;
cout << "                      THE END                       " << endl;
cout << "                      YOU WON                       " << endl;
cout << endl;
cout << "Congratulations Emma! You have won prince's heart!" << endl;
cout << "You can dispose of the other gentlemen that are in love with you and live your life in a palace!" << endl;
}


void Game::startScreen() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout << "   __                               __   _     ______ _            , __                      \n"
        "  /  \\                             /\\_\\/| |   (_) |  | |          /|/  \\                     \n"
        " | __ |          _   _   _  _     |    || |       |  | |     _     |___/ __,   ,_  _|_       \n"
        " |/  \\|  |   |  |/  |/  / |/ |    |    ||/      _ |  |/ \\   |/     |    /  |  /  |  |  |   | \n"
        "  \\__/\\_/ \\_/|_/|__/|__/  |  |_/   \\__/ |__/   (_/   |   |_/|__/   |    \\_/|_/   |_/|_/ \\_/|/\n"
        "                                        |\\                                                /| \n"
        "                                        |/                                                \\| " << endl;
cout << "Behold, the journey of a queen begins not with the crown, but with the mastery of allure, wit, and " << endl;
cout << "the art of seduction in the grand theater of courtly intrigue." << endl;
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout  << endl;

cout << "++++++++++++++++++++++++++++++++++++++GAME CONTROLS+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
cout << "w/a/s/d - moving around" << endl;
cout << "e - inventory" << endl;
cout << "r - abilities" << endl;
cout << "f - statistics" << endl;
cout  << endl;

cout << "++++++++++++++++++++++++++++++++++++++++++RULES+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
cout << "Your goal in this game is to seduct the richest, most handsome, most powerful GENTLEMAN on this party" << endl;
cout << "                                                                           ->(the prince)<-";
    cout  << endl;
cout << "But before you get to him, you have to seize some small fish to make your EGO stronger." << endl;
    cout  << endl;
cout << "When you strengthen your EGO you can add EGO POINTS to your personality TRAITS." << endl;
    cout  << endl;
cout << "Every gentleman has his WEAKNESS, it's on you to find out their weak points and use them!" << endl;
    cout  << endl;
cout << "Collect items that look like this 'X' and move between palace rooms through doors '/'." << endl;
    cout  << endl;
cout << "You can figure out the rest. GOOD LUCK!" << endl;
    cout  << endl;
cout << "TRY TO MOVE TO START PLAYING..." << endl;
}

void Game::badEndScreen() {
    for (int i = 0; i < 40; ++i) {
        cout << endl;
    }
    cout << "  _            _                   \n"
            " | |       o  | |                  \n"
            " | |  __,     | |         ,_    _  \n"
            " |/  /  |  |  |/  |   |  /  |  |/  \n"
            " |__/\\_/|_/|_/|__/ \\_/|_/   |_/|__/\n"
            " |\\                                \n"
            " |/    " << endl;
    cout << endl;
    cout << "My lady, Your chances have ran out. This party was a failure and the Prince is out of your reach..." << endl;

}

