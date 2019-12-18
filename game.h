#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include <SFML/Audio.hpp>
using namespace std;


class game
{
public:
    //Constructor
    //----------------------------------------------------------
    // Constructor:
    // * set up randonmizer for color and shape
    // * set up window size, frame limit
    // * upload text font, backgound music, and use interface
    //----------------------------------------------------------
    game();

    //-------------------------------------
    // Background: music, interface, image
    //-------------------------------------
    void Music();
    void Logo();
    void TextInit();
    void Drop();
    void UserInter();

    //----------------------------
    // check start and end
    //----------------------------
    bool Start=true;
    bool gameOver=false;

    //---------------------------
    //Initialize the game at main
    //---------------------------
    void Run();

    //---------------------------
    // Game running procedure
    //---------------------------
    //---------------------------------------------------------------------------------
    // ProcessEvent:
    // * looking for input commands from the keyboard to manipulate one tetris piece
    // * rotate, move left, move right, and drop down
    // * clear the shape after each command
    //----------------------------------------------------------------------------------
    void ProcessEvents(); // Process keyboard commans
    //----------------------------------------------------------------------------------
    // CheckStart:
    //  * display the starting image and text at start
    //  * or alreaddy startedd then, check for update
    //----------------------------------------------------------------------------------

    void CheckStart();
   //----------------------------------------------------------------------------------------
    // Update:
    // * if the game did not end, the move the piece downward
    // * when the peice is falling always ask if the piece hits the bottom or collide with
    //   other pieces
    // * and then draw this new piece at its new position
    // * check the timer
    // * when pieces piled up, one should chekc for game over by check if the piece hits the
    //   upper boundry which is when height =0;
    // * once the game is over display the "game over" text
    //----------------------------------------------------------------------------------------

    void Update();

    void CheckEnd();
    void Move();
    void UpdateScore();
    void CheckCollision();
    void Draw();
    void CheckTick();
    void CheckTop();
    void Render();
    void SelfPlayer();


    //--------------------------
    // SFML variables
    //--------------------------

    /*sound track*/
    sf::Music theme;

    /*logo*/
    sf::Texture logoText;
    sf::Sprite logo;

    /*User Interfaec*/
    sf::Texture UIText;
    sf::Sprite UI;

    /*text variables*/
    sf::Font gameFont;
    sf::Text startText;
    sf::Text score;
    sf::Text END;
    sf::Text info;

    /*accelatere*/
    sf::Time t;
    sf::Clock c;


private:
    Shape fig;
    Shape newFig;
    Grid map;
    int tick;
    sf::RenderWindow window;
};

string int2str(int source);

#endif // GAME_H
