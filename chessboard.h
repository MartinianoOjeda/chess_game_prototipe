#include "piece.h"

#define BOARD_LENGTH 10

typedef char enumeration[8];

typedef piece chessboard[BOARD_LENGTH][BOARD_LENGTH];


void initializeChessboard(chessboard);
void drawChessboard(chessboard);
void accommodatePieces(chessboard);
int isBlackOrWhite(int);
char * colorPrint(int, int, chessboard);
int whatPieceType(int, int);


void drawChessboard(chessboard new_board) {
    int i, j;
    
    for (i = 0; i < BOARD_LENGTH; i++) {

        for (j = 0; j < BOARD_LENGTH; j ++) {
            if (new_board[i][j].type == 0) {
                //system(new_board[i][j].color_print);
                printf("%d ", new_board[i][j].type);
            }
            else {
                printf("%c ", new_board[i][j].type);
            }
        }
        printf("\n");
    }
}

/*void initializeChessboard(chessboard new_board) {
    int i = 0;
    int j = 0;

    for (i = 0; i < BOARD_LENGTH; i++) {
        
        for (j = 0; j < BOARD_LENGTH; j++) {

            if(i == 0 || i == BOARD_LENGTH - 1) {
                new_board[i][j] = createPiece(i, j, BOARD_EDGE, BOARD_EDGE); //create edges
            }

            if((j == 0 || j == BOARD_LENGTH -1) && (i > 0 && i < BOARD_LENGTH - 1)) {
                new_board[i][j] = createPiece(i, j, BOARD_EDGE, BOARD_EDGE); //create edges
            }

            if((j > 0 && j < BOARD_LENGTH - 1) && (i > 0 && i < BOARD_LENGTH - 1)) {
                new_board[i][j] = createPiece(i, j, EMPTY_SQUARE, EMPTY_SQUARE); //create empty square
            }
        }
    }
}*/

int isBlackOrWhite(int i) {
    if (i == 1 || i == 2) {
        return BLACK;
    }
    if (i == 7 || i == 8){
        return WHITE;
    }
}

char * colorPrint(int i, int j, chessboard new_board) {
    if ((i == 1 || i == 2) && (j > 0 && j < BOARD_LENGTH -1)) {
        return PIECE_BALCK_PRINT;
    }
    else {
        if ((i == 7 || i == 8) && (j > 0 && j < BOARD_LENGTH -1)) {
            return PIECE_WHITE_PRINT;
        }
        else {
            if (new_board[i][j].type == BOARD_EDGE) {
                return BOARD_COLOR_PRINT;
            } 
            else {
                return EMPTY_SQUARE_COLOR_PRINT;
            }
        }
    }
}

int whatPieceType(int i, int j) {

    if ((i == 1 || i == 8) && (j == 1 || j == 8)) {
        return ROOK;
    }
    else {
        if ((i == 1 || i == 8) && (j == 2 || j == 7)) {
            return KNIGHT;
        }
        else{
            if ((i == 1 || i == 8) && (j == 3 || j == 6)) {
                return BISHOP;
            }
            else {
                if ((i == 1 || i == 8) && (j == 4)) {
                    return QUEEN;
                }
                else {
                    if ((i == 1 || i == 8) && (j == 5)) {
                        return KING;
                    }
                    else {
                        if ((i == 2 || i == 7) && (j > 0 && j < BOARD_LENGTH - 1)) {
                            return PAWN;
                        }
                        else {
                            if (((i >= 0 && i < BOARD_LENGTH) && (j == 0 || j == BOARD_LENGTH - 1)) ||
                            ((i == 0 || i == BOARD_LENGTH - 1) && (j >= 0 && j < BOARD_LENGTH))) {
                                return BOARD_EDGE;
                            }
                            else {
                                return EMPTY_SQUARE;
                            }
                        }
                    }
                }
            }
        }
    }   
}

void accommodatePieces(chessboard new_board){
    int i, j;

    for(i = 0; i < BOARD_LENGTH; i++) {

        for(j = 0; j < BOARD_LENGTH; j++) {

            new_board[i][j] = createPiece(i, j, whatPieceType(i, j), isBlackOrWhite(i), colorPrint(i, j, new_board));
        }
    }
}


