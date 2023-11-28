
#include "board.h"

Board::Board(sf::Color l_col, sf::Color d_col){
    load(l_col,d_col);
}

void Board::load(sf::Color l_col, sf::Color d_col) {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            sf::RectangleShape& escaque = matriz_tabla[j + (i * 8)];
            escaque.setPosition(sf::Vector2f(j * 64.f, i * 64.f));
            escaque.setSize(sf::Vector2f(64.f, 64.f));
            escaque.setFillColor(((i + j) % 2 == 0) ? l_col : d_col);
        }
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0;i<64;i++){
        target.draw(matriz_tabla[i]);
    }
}