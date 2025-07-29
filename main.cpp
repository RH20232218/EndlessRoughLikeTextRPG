#include <iostream>
#include <string>
#include <vector>


enum Chessboard {
    empty,
    Black_pawn,
    Black_knight,
    Black_bishop,
    Black_rook,
    Black_queen,
    Black_king,
    White_pawn,
    White_knight,
    White_bishop,
    White_rook,
    White_queen,
    White_king
    
}


class chessGame {
    Chessboard chessboard[8][8];
    std::vector<std::string> moveHistory;
    
    chessGame(){
        for(int i = 0; i < 8; i++){
            chessboard[1][i] = White_pawn;
            chessboard[2][i] = empty;
            chessboard[3][i] = empty;
            chessboard[4][i] = empty;
            chessboard[5][i] = empty;
            chessboard[6][i] = Black_pawn;
        }
        chessboard[0][0] = White_rook;
        chessboard[0][1] = White_knight;
        chessboard[0][2] = White_bishop;
        chessboard[0][3] = White_queen;
        chessboard[0][4] = White_king;
        chessboard[0][5] = White_bishop;
        chessboard[0][6] = White_knight;
        chessboard[0][7] = White_rook;
        chessboard[7][0] = Black_rook;
        chessboard[7][1] = Black_knight;
        chessboard[7][2] = Black_bishop;
        chessboard[7][3] = Black_queen;
        chessboard[7][4] = Black_king;
        chessboard[7][5] = Black_bishop;
        chessboard[7][6] = Black_knight;
        chessboard[7][7] = Black_rook;
    }

    public:


    void renderChessBoard(){
        std::cout << "------------------------------------------------\n";
        for(int x = 0; x < 8; x++){
            std::cout << "                                                \n";
            for(int y = 0; y < 8; y++){
                switch(chessboard[x][y]){
                    case empty:         std::cout << "   "; break;
                    case Black_pawn:    std::cout << "B P"; break;
                    case Black_knight:  std::cout << "B K"; break;
                    case Black_bishop:  std::cout << "B B"; break;
                    case Black_rook:    std::cout << "B R"; break;
                    case Black_queen:   std::cout << "B Q"; break;
                    case Black_king:    std::cout << "B K"; break;
                    case White_pawn:    std::cout << "W P"; break;
                    case White_knight:  std::cout << "W K"; break;
                    case White_bishop:  std::cout << "W B"; break;
                    case White_rook:    std::cout << "W R"; break;
                    case White_queen:   std::cout << "W Q"; break;
                    case White_king:    std::cout << "W K"; break;
                }
                std::cout << " | ";
            }
            std::cout << "\n";
        }
        std::cout << "------------------------------------------------\n";
    }
};

int main() {
    chessGame game;
    game.renderChessBoard();
    return 0;
}
