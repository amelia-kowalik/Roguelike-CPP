#include "Game.h"

Game::Game(string levelFile){

    character = Character(1,1,1,1,1,3);


    //level.loadLevel(levelFile, character, 1)

    level.createLevel();

    level.printLevel();



}

void Game::playGame(){
    bool isDone = false;
    while (isDone == false){
        characterMove();
        level.printLevel();
    }

}

void Game::characterMove(){
    char input='d';
    cin>>input;
    level.moveCharacter(input, character);
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

void Game::initItems() {

}