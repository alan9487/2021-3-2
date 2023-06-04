#include"Tetris.h"

Tetris::Tetris() {
    srand(static_cast<unsigned>(time(0))); // 初始化隨機種子
    currentX = WIDTH / 2;
    currentY = 0;
    currentShape = generateRandomShape();
}

ShapeType Tetris::generateRandomShape() {
    // 根據需要，你可以自訂每個形狀的表示方式
    // 這裡只提供一個簡單的範例
    ShapeType shapes[] = {
        SHAPE_I, SHAPE_J, SHAPE_L, SHAPE_O, SHAPE_S, SHAPE_T, SHAPE_Z
    };
    int index = rand() % 7;
    return shapes[index];
}

void Tetris::clearBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = SHAPE_EMPTY;
        }
    }
}

void Tetris::drawBoard() {
    system("cls"); // 清除螢幕
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == SHAPE_EMPTY) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
}

void Tetris::moveDown() {
    if (isValidMove(currentShape, currentX, currentY + 1)) {
        currentY++;
    } else {
        // 將目前的方塊固定在板上
        placeShape(currentShape, currentX, currentY);
        clearLines();
        currentX = WIDTH / 2;
        currentY = 0;
        currentShape = generateRandomShape();
        if (!isValidMove(currentShape, currentX, currentY)) {
            // 遊戲結束
            cout << "Game Over!" << endl;
            exit(0);
        }
    }
}

void Tetris::moveLeft() {
    if (isValidMove(currentShape, currentX - 1, currentY)) {
        currentX--;
    }
}

void Tetris::moveRight() {
    if (isValidMove(currentShape, currentX + 1, currentY)) {
        currentX++;
    }
}

void Tetris::rotate() {
    ShapeType newShape = rotateShape(currentShape);
    if (isValidMove(newShape, currentX, currentY)) {
        currentShape = newShape;
    }
}

bool Tetris::isValidMove(ShapeType shape, int x, int y) {
    // 檢查是否超出邊界
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return false;
    }

    // 檢查是否和已固定的方塊重疊
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (getShapeBlock(shape, i, j) != SHAPE_EMPTY) {
                int boardX = x + j;
                int boardY = y + i;
                if (boardY >= 0 && board[boardY][boardX] != SHAPE_EMPTY) {
                    return false;
                }
            }
        }
    }

    return true;
}

void Tetris::placeShape(ShapeType shape, int x, int y) {
    // 在板上固定方塊
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (getShapeBlock(shape, i, j) != SHAPE_EMPTY) {
                int boardX = x + j;
                int boardY = y + i;
                if (boardY >= 0) {
                    board[boardY][boardX] = shape;
                }
            }
        }
    }
}

void Tetris::clearLines() {
    for (int i = HEIGHT - 1; i >= 0; i--) {
        bool lineFull = true;
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == SHAPE_EMPTY) {
                lineFull = false;
                break;
            }
        }

        if (lineFull) {
            // 將該行上方所有方塊下移一格
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < WIDTH; j++) {
                    board[k][j] = board[k - 1][j];
                }
            }

            // 最上面的一行清空
            for (int j = 0; j < WIDTH; j++) {
                board[0][j] = SHAPE_EMPTY;
            }
        }
    }
}

ShapeType Tetris::rotateShape(ShapeType shape) {
    // 簡單的旋轉，不考慮碰撞偵測
    return static_cast<ShapeType>((static_cast<int>(shape) + 1) % 7);
}

ShapeType Tetris::getShapeBlock(ShapeType shape, int x, int y) {
    // 根據需要，你可以自訂每個形狀的表示方式
    // 這裡只提供一個簡單的範例
    switch (shape) {
        case SHAPE_I:
            return (y == 1) ? SHAPE_I : SHAPE_EMPTY;
        case SHAPE_J:
            return (x == 1 && y != 0) ? SHAPE_J : SHAPE_EMPTY;
        case SHAPE_L:
            return (x == 2 && y != 0) ? SHAPE_L : SHAPE_EMPTY;
        case SHAPE_O:
            return (x == 1 && y != 0) ? SHAPE_O : SHAPE_EMPTY;
        case SHAPE_S:
            return ((x == 1 && y == 1) || (x == 2 && y == 0)) ? SHAPE_S : SHAPE_EMPTY;
        case SHAPE_T:
            return (x == 1 && y != 0) ? SHAPE_T : SHAPE_EMPTY;
        case SHAPE_Z:
            return ((x == 1 && y == 0) || (x == 2 && y == 1)) ? SHAPE_Z : SHAPE_EMPTY;
        default:
            return SHAPE_EMPTY;
    }
}

void Tetris::run() {
    clearBoard();
    while (true) {
        drawBoard();
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'a':
                    moveLeft();
                    break;
                case 'd':
                    moveRight();
                    break;
                case 's':
                    moveDown();
                    break;
                case 'w':
                    rotate();
                    break;
                case 'q':
                    exit(0);
                    break;
            }
        }
        moveDown();
    }
}
