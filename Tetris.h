#include"ShapeType.h"
#ifndef t_h
#define t_h

const int WIDTH = 10;
const int HEIGHT = 20;

class Tetris {
private:
    ShapeType board[HEIGHT][WIDTH];
    int currentX, currentY;
    ShapeType currentShape;

public:
    Tetris();

    ShapeType generateRandomShape();

    void clearBoard();

    void drawBoard();

    void moveDown();

    void moveLeft();

    void moveRight();

    void rotate();

    bool isValidMove(ShapeType shape, int x, int y);

    void placeShape(ShapeType shape, int x, int y);

    void clearLines();

    ShapeType rotateShape(ShapeType shape);

    ShapeType getShapeBlock(ShapeType shape, int x, int y);

    void run();
};

#endif
