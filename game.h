#ifndef GAME_H
#define GAME_H


void moveDown(int* board, int size, int* flag, int* score);
void moveUp(int* board, int size, int* flag, int* score);
void moveRight(int* board, int size, int* flag, int* score);
void moveLeft(int* board, int size, int* flag, int* score);
void printBoard(int* board, int size, int* score, int* best);
void chooseRandomBoardSpot(int* board, int size, int* numRow, int* numCol);
int chooseRandomNum();
void playGame(int* board, int size, int scoreToWin);
void clearboard(int* board, int size);
void printMenu();
void startBoard(int* board, int size);
void startBoard_1(int* board, int size, int flag);
void checkBiggestTile(int* board, int* biggestTile, int size);
int isGameOver(int* board, int size);
int checkEmptyBoard(int* board, int size);

#endif




