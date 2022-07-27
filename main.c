#include "chessboard.h"

int main() {

    chessboard new_board;

    //initializeChessboard(new_board);
    accommodatePieces(new_board);
    drawChessboard(new_board);

    system("pause");

    return 0;
}