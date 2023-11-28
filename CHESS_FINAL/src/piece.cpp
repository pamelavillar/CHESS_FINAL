#include "piece.h"
#include <iostream>


std::array<int, 16> Piece::posiciones;
std::array<int, 16> Piece::bposiciones;


void Piece::setPiece(char type, bool player, int pos, bool moved){
    setType(type);
    setPlayer(player);
    setPosition(pos); //m_moved true
    setMoved(moved); // m_moved false

}

void Piece::move(){
    if(m_position<=-1 || 64<=m_position){
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000));//transparente
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f)); //con el resto obtenemos el indice de columna, con la div el indice de fila
        //possibleMoves.clear();
        m_moved = true;
    }
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;
    }
    return;
}



void Piece::setTexture(){    
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 , m_sprite.getTexture()->getSize().y/2));//definimos el centro de la textura, el origen donde se realizaran transformaciones
    m_sprite.setScale(sf::Vector2f(0.150f,0.150)); //la sprite se escala a 0.150 veces su tamaño original, se hace mas pequeña
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
}

void Piece::setPosiciones(const std::array<int, 16>& new_posiciones) {
        posiciones = new_posiciones;
    }
void Piece::setPosicionesB(const std::array<int, 16>& new_posiciones) {
        bposiciones = new_posiciones;
    }


int Piece::addMoves(int pos){
    for (int j = 0; j < 16; j++) {
        if ((getPlayer() && posiciones[j] == pos) || (!getPlayer() && bposiciones[j] == pos)) {
            return 1; // Se encontró una pieza del mismo equipo
        } else if ((getPlayer() && bposiciones[j] == pos) || (!getPlayer() && posiciones[j] == pos)) {
            return 2; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
        }
        }

        return 3; // Ninguna pieza en el camino
}

void Piece::calcPiecePossibleMoves(){ 
}
