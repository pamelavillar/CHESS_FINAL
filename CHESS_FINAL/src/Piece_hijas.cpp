#include "piece_hijas.h"
#include "pieceTextures.h"
#include "chessGame.h"


//?KING
    
    // Override setTexture
    void PKing::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteKing : PieceTextures::blackKing);
        Piece::setTexture();

    }
    void PKing::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();

         // Calcula para arriba
        if ((piecePos / 8 - 1) >= 0) {
            int newPos = piecePos - 8;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);
            }
        }
        //Calcula para abajo
        if((piecePos / 8 + 1) <= 7) {
            int newPos = piecePos + 8;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);
            } 
        }

        // Calcula para los costados
        for (int dir = -1; dir <= 1; dir += 2) {
            if((piecePos % 8 + dir) >= 0 && (piecePos % 8 + dir) <= 7) {
                int newPos = piecePos + dir;
                
                int eraseResult = addMoves(newPos);

                if (eraseResult == 3 || eraseResult == 2) {
                    getPossibleMoves().push_back(newPos);

                } 
            }
        }

    }


//?QUEEN

    // Override setTexture
    void PQueen::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteQueen : PieceTextures::blackQueen);
        Piece::setTexture();
    }

    void PQueen::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();
         // Calcula para caminos de arriba
        for (int i = 1; (piecePos / 8 - i) >= 0; ++i) {
            int newPos = piecePos - 8 * i;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        
        // Calcula para caminos diagonales hacia arriba a la izquierda
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos - 9 * i;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        
        }
        // Calcula para caminos diagonales hacia arriba a la derecha
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos - 7 * i;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
            

           
        }

        // Calcula para caminos de abajo
        for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
            int newPos = piecePos + 8 * i;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
            
        }
        // Calcula para caminos diagonales hacia abajo a la izquierda
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos + 7 * i;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }

        
        }
        // Calcula para caminos diagonales hacia abajo a la derecha
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos + 9 * i;
           
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }

        
        }

        // Calcula para los costados
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
                int newPos = piecePos + dir * i;
                
                int eraseResult = addMoves(newPos);

                if (eraseResult == 3 || eraseResult == 2) {
                    getPossibleMoves().push_back(newPos);

                    if (eraseResult == 2) {
                        break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                    }
                } else if (eraseResult == 1) {
                    break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
                }
            }
        }

    }
    

    

//?Rook
  

    // Override setTexture
    void PRook::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteRook : PieceTextures::blackRook);
        Piece::setTexture();
    }

    void PRook::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();
        // Calcula para caminos de arriba
        for (int i = 1;(piecePos / 8 - i) >= 0; ++i) {
            int newPos = piecePos - 8 * i;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           
        }
        // Calcula para caminos de abajo
        for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
            int newPos = piecePos + 8 * i;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        // Calcula para los costados
        for (int dir = -1; dir <= 1; dir += 2) {
            for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
                int newPos = piecePos + dir * i;
                
                int eraseResult = addMoves(newPos);

                if (eraseResult == 3 || eraseResult == 2) {
                    getPossibleMoves().push_back(newPos);

                    if (eraseResult == 2) {
                        break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                    }
                } else if (eraseResult == 1) {
                    break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
                }

            }
        }

    }

//?BISHOP

    // Override setTexture
    void PBishop::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteBishop : PieceTextures::blackBishop);
        Piece::setTexture();
    // Resto de la implementación...
    }
    void PBishop::calcPiecePossibleMoves(){
        int piecePos{getPosition()};
        getPossibleMoves().clear();

       
        
        
        // Calcula para caminos diagonales hacia arriba a la derecha
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos - 7 * i;
            
            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           
        }
        // Calcula para caminos diagonales hacia arriba a la izquierda
        for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos - 9 * i;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        }
        // Calcula para caminos diagonales hacia abajo a la izquierda
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
            int newPos = piecePos + 7 * i;
            //evalua si se debe añadir como movimiento valido

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
           

        
        }
        // Calcula para caminos diagonales hacia abajo a la derecha
        for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
            int newPos = piecePos + 9 * i;

            int eraseResult = addMoves(newPos);

            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);

                if (eraseResult == 2) {
                    break; // Se encontró una pieza del equipo contrario, no es necesario seguir buscando
                }
            } else if (eraseResult == 1) {
                break; // Se encontró una pieza del mismo equipo, no es necesario seguir buscando
            }
        
        }

    }

//?KNIGHT
    // Override setTexture
    void PKnight::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whiteKnight : PieceTextures::blackKnight);
        Piece::setTexture();
    // Resto de la implementación...
    }

    void PKnight::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    if((piecePos / 8) != 0 ){
        if((piecePos % 8) >= 2 ){
            if(addMoves(piecePos -10)==3||addMoves(piecePos -10)==2) {
                getPossibleMoves().push_back(piecePos - 10);
            }
        }
        if( (piecePos % 8) <= 5 ){
            if(addMoves(piecePos -6)==3||addMoves(piecePos -6)==2){
                getPossibleMoves().push_back(piecePos - 6);
            }
        }
        if((piecePos / 8) != 1){
            if((piecePos % 8) >= 1 ){
                if (addMoves(piecePos- 17)==3||addMoves(piecePos -17)==2) {
                    getPossibleMoves().push_back(piecePos - 17);
                }
            }
            if  ((piecePos % 8) <= 6 ){
                if (addMoves(piecePos- 15)==3||addMoves(piecePos -15)==2){
                    getPossibleMoves().push_back(piecePos - 15);
                }
            }
        }
    }
    if((piecePos / 8) != 7){
        if((piecePos % 8) >= 2 ){
            if (addMoves(piecePos + 6)==3||addMoves(piecePos + 6)==2) {
                getPossibleMoves().push_back(piecePos + 6);
            }
        }
        if( (piecePos % 8) <= 5 ){
            if (addMoves(piecePos + 10)==3||addMoves(piecePos + 10)==2) {
                getPossibleMoves().push_back(piecePos + 10);
            }
        }
        if((piecePos / 8) != 6){
            if((piecePos % 8) >= 1 ){
                if (addMoves(piecePos + 15)==3||addMoves(piecePos + 15)==2) {
                    getPossibleMoves().push_back(piecePos + 15);
                }
            }
            if((piecePos % 8) <= 6 ){
                if (addMoves(piecePos + 17)==3||addMoves(piecePos + 17)==2) {
                    getPossibleMoves().push_back(piecePos + 17);
                }
            }
        }
    }
}

//?PAWN

    // Implementación de setTexture
    void PPawn::setTexture() {
        m_sprite.setTexture(m_player ? PieceTextures::whitePawn : PieceTextures::blackPawn);
        Piece::setTexture();
        // Resto de la implementación...
    
    }

    void PPawn::calcPiecePossibleMoves() {
       getPossibleMoves().clear();
    int piecePos{getPosition()};
    if (piecePos>=48 && piecePos<=55){
        for (int i=1;i<=2;++i){
            getPossibleMoves().push_back(piecePos - 8 * i);}
    }
    if(piecePos>=8 && piecePos<=15){
        for (int i=1;i<=2;++i){
            getPossibleMoves().push_back(piecePos + 8 * i);}
    }

    else {//Si no es su primer movimiento

        //int newPos = piecePos - 8;
        int eraseResult = addMoves(piecePos-8);

        if (m_player){ //blanco
            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(piecePos-8);
            }
            if(addMoves(piecePos-7)==2)    {
            getPossibleMoves().push_back(piecePos-7);
            }
            if(addMoves(piecePos-9)==2)    {
                getPossibleMoves().push_back(piecePos-9);
            }
        }

        else { //negro
            eraseResult=addMoves(piecePos+8);
            if(eraseResult==3) {
                getPossibleMoves().push_back(piecePos + 8);
            }

            if(addMoves(piecePos+7)==2)    {
                getPossibleMoves().push_back(piecePos+7);
            }
            if(addMoves(piecePos+9)==2)    {
                getPossibleMoves().push_back(piecePos+9);
            }

        }
    }
}