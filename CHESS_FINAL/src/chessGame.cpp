#include <iostream>
#include "chessGame.h"
using namespace std;



ChessGame::ChessGame(sf::Color bordL_col = sf::Color::Blue, sf::Color bordD_col = sf::Color::Black)
: board(bordL_col,bordD_col)
{   
    font.loadFromFile("Texturesa/arial.ttf");
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color(44,91,93));
    infoRestart.setPosition(sf::Vector2f(512.f,0.f));
    infoRestart.setSize(sf::Vector2f(256.f, 50.f));

    textRestart.setFont(font);
    textRestart.setString("RESTART");
    textRestart.setCharacterSize(24);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setFillColor(sf::Color(44,91,93));
    textRestart.setPosition(infoRestart.getPosition().x + 75.f, infoRestart.getPosition().y + 10.f);

    textTurn.setFont(font);
    textTurn.setCharacterSize(24);
    textTurn.setStyle(sf::Text::Bold);
    textTurn.setFillColor(sf::Color::White);
    textTurn.setPosition(530.f, 70.f);

    textSituation.setFont(font);
    textSituation.setCharacterSize(24);
    textSituation.setStyle(sf::Text::Bold);
    textSituation.setFillColor(sf::Color::White);
    textSituation.setPosition(530.f, 110.f);

    restart();
}


void ChessGame::restart(){

    seleccionado = false;
    playerTurn = true;

    blackPieces[0] = new PRook(false, 7);
    blackPieces[1] = new PKnight(false, 6);
    blackPieces[2] = new PBishop(false, 5);
    blackPieces[3] = new PKing(false, 4);
    blackPieces[4] = new PQueen(false, 3);
    blackPieces[5] = new PBishop(false, 2);
    blackPieces[6] = new PKnight(false, 1);
    blackPieces[7] = new PRook(false, 0);

    whitePieces[0] = new PRook(true, 56);
    whitePieces[1] = new PKnight(true, 57);
    whitePieces[2] = new PBishop(true, 58);
    whitePieces[3] = new PKing(true, 59);
    whitePieces[4] = new PQueen(true, 60);
    whitePieces[5] = new PBishop(true, 61);
    whitePieces[6] = new PKnight(true, 62);
    whitePieces[7] = new PRook(true, 63);
    
    
    for(int i=8;i<16;i++){
        whitePieces[i] = new PPawn(true, 48 + (i - 8));
        blackPieces[i] = new PPawn(false, 15 - (i - 8));
    }
    calcPossibleMoves();
    updateInfo();

}

void ChessGame::updateInfo(){
  
    if(playerTurn)
            textSituation.setString("White's Turn");
        else
            textSituation.setString("Blacks's Turn");
}

void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color(44,91,93));

    target.draw(board); //funcion draw de board
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(textTurn);
    target.draw(textSituation);


    
    if((piezaseleccionada != NULL) && (seleccionado)){
        for(int i=0; i<possibleMovesSquares.size();i++){
            target.draw(possibleMovesSquares.at(i));
        }
    }

    if (piezaseleccionada != NULL && seleccionado) {
        target.draw(selectionBorder);
    }

    for(int i=0;i<16;i++){
        target.draw(*whitePieces[i]);
        target.draw(*blackPieces[i]);
    }

    
}

void ChessGame::createSelectSquare(){
    sf::RectangleShape tmp;
   
        selectionBorder.setSize(sf::Vector2f(64, 64)); // Tamaño del cuadro
        selectionBorder.setFillColor(sf::Color::Transparent); // Sin relleno
        selectionBorder.setOutlineColor(sf::Color(155,80,98)); // Contorno amarillo
        selectionBorder.setOutlineThickness(-3.f); // Grosor del contorno
        int x = (piezaseleccionada->getPosition() % 8) * 64;
        int y = (piezaseleccionada->getPosition() / 8) * 64;
        selectionBorder.setPosition(x,y);
    

}
void ChessGame::createMovesSquares(){

    if(piezaseleccionada == NULL)
        return;

    possibleMovesSquares.clear();

    for(int i=0; i<piezaseleccionada->getPossibleMoves().size();i++){
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((piezaseleccionada->getPossibleMoves().at(i) % 8) * 64.f , (piezaseleccionada->getPossibleMoves().at(i) / 8) * 64.f));
        tmp.setSize(sf::Vector2f(64.f, 64.f));
        tmp.setFillColor(sf::Color(0xFFE46666));
        possibleMovesSquares.push_back(tmp);
    }
    createSelectSquare();

    return;

}


bool ChessGame::selectPiece(int pos){
    // Reiniciar selección anterior
    piezaseleccionada = NULL;
    seleccionado = false;


    for (int i=0;i<16;i++){
        if(playerTurn){
            if (whitePieces[i]->getPosition()==pos){
            piezaseleccionada = whitePieces[i]; 
            seleccionado = true;
            break;
            }
        }
        else{
            if (blackPieces[i]->getPosition()==pos){
            piezaseleccionada = blackPieces[i];
            seleccionado=true;
            break;
            }
        }
             
        seleccionado=false;
    }

    if (!seleccionado){
        piezaseleccionada=NULL;
        possibleMovesSquares.clear();
        return seleccionado;
    }

    createMovesSquares();
    return seleccionado;
}




void ChessGame::moveSelected(int pos){
    
    bool validMove{false};

    if((piezaseleccionada == NULL) || !seleccionado ) 
        return;
    
    for(int i=0;i<piezaseleccionada->getPossibleMoves().size();i++){
        if(pos == piezaseleccionada->getPossibleMoves().at(i)){
            validMove = true;
            break;
        }
    }
    
    if(validMove){
        piezaseleccionada->setPosition(pos);

        for(int i=0; i<16; i++){
                if(piezaseleccionada->getPlayer()){ 
                    if(blackPieces[i]->getPosition() == pos){
                        blackPieces[i]->setPosition(-1);
                        break;
                    }
                
                    
                }
                else{ 
                    if(whitePieces[i]->getPosition() == pos){
                        whitePieces[i]->setPosition(-1);
                        break;
                    }
                }
        }

        playerTurn = !playerTurn; 
        calcPossibleMoves();
    }
    

    piezaseleccionada = NULL;
    seleccionado = false;

}

void ChessGame::calcPossibleMoves(){
    Piece* tmp;
   
    for (int i=0;i<32;i++){
        if (i<16)
            tmp = whitePieces[i];
        else
            tmp = blackPieces[i-16];

        tmp->getPossibleMoves().clear();

        if (tmp->getPosition() == -1){
            continue;
        }

        getPosicionesWhitePieces();
        getPosicionesBlackPieces();


        tmp->calcPiecePossibleMoves();

        
    }

    updateInfo();
    
}



void ChessGame::getPosicionesWhitePieces()  {
        
    std::array<int, 16> posiciones;

    for (int i = 0; i < 16; ++i) {
        posiciones[i] = whitePieces[i]->getPosition();
    }

    Piece::setPosiciones(posiciones);


}

void ChessGame::getPosicionesBlackPieces()  {
        
    std::array<int, 16> bposiciones;

    for (int i = 0; i < 16; ++i) {
        bposiciones[i] = blackPieces[i]->getPosition();
    }

    Piece::setPosicionesB(bposiciones);

}