#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "Piece_hijas.h"
using namespace std;

class ChessGame: public sf::Drawable{
private:
    Board board;

    std::array<Piece*, 16> whitePieces;
    std::array<Piece*, 16> blackPieces;

    sf::RectangleShape selectionBorder;

    vector<sf::RectangleShape> possibleMovesSquares;
    
    Piece* piezaseleccionada; //seguira la pieza seleccionada y la usaremos en todo el codigo sin necesidad de copiar toda la info de la pieza

    sf::RectangleShape infoRestart;
    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    
    bool seleccionado;
    bool playerTurn;
 
    void createSelectSquare();
    void createMovesSquares();
    
    void calcPossibleMoves();

    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    ChessGame(sf::Color bordL_col, sf::Color bordD_col);

    ~ChessGame(){
        for (int i = 0; i < 16; i++) {
            delete blackPieces[i];
            delete whitePieces[i];
        }
    }

    bool getSelected(){return seleccionado;}
    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();

    void getPosicionesWhitePieces();
    void getPosicionesBlackPieces();


};


#endif