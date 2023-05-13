#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ship {
    int row, col;
public:
    Ship(int r, int c) {
        row = r;
        col = c;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    void setRow(int r) {
        row = r;
    }
    void setCol(int c) {
        col = c;
    }
};

class Board {
    char grid[16][16];
    int size = 16;
    vector<Ship> ships;
    bool gameover = false;
public:
    Board() {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                grid[i][j] = '-';
            }
        }
        srand(time(0));
        for(int i = 0; i < 5; i++) {
            int row = rand() % size;
            int col = rand() % size;
            Ship newShip(row, col);
            ships.push_back(newShip);
        }
    }
    void display() {
        cout << "  ";
        for(int i = 0; i < size; i++) {
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < size; i++) {
            cout << i << " ";
            for(int j = 0; j < size; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    void placeShips() {
        for(int i = 0; i < ships.size(); i++) {
            int row = ships[i].getRow();
            int col = ships[i].getCol();
            grid[row][col] = 'S';
        }
    }
    bool isShip(int row, int col) {
        for(int i = 0; i < ships.size(); i++) {
            if(ships[i].getRow() == row && ships[i].getCol() == col) {
                ships.erase(ships.begin() + i);
                return true;
            }
        }
        return false;
    }
    bool isGameOver() {
        if(ships.size() == 0) {
            gameover = true;
        }
        return gameover;
    }
    vector<Ship> getShips() {
        return ships;
    }
};

int main() {
    Board board;
    int row, col;
    while (!board.isGameOver()) {
        board.display();
        cout << "Enter row and column: ";
        cin >> row >> col;
        if(board.isShip(row, col)) {
            cout << "You sank my battleship!" << endl;
        } else {
            cout << "Missed!" << endl;
        }
    }
    cout << "Game over." << endl;
    return 0;
}