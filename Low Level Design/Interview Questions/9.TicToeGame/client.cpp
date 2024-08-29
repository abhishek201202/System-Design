#include<bits/stdc++.h>
using namespace std;

enum PieceType {
    BLANK, X, O
};

class TicTacToe {
    Board *board;
    vector<Player*> players;
    TicTacToeDao *playerMoves;
    int turn;
    TicTacToe(int totalPlayers, int n, int m) {
        board = new Board(n, m);
        playerMoves = new TicTacToePlayerTurns();
        for(int i = 0; i < totalPlayers; i++) {
            // this is following observer pattern
            players.push_back(new Player(str(i), PieceType[i + 1] ))
        }
    }
};

class TicTacToeDao {

};
// by creating this we have solved open / closed principle here
class TicTacToePlayerTurns: public TicTacToeDao {
public:
    bool turn(Player *player, int x, int y) {
        return player -> moves -> turn(x, y);
    }
}

class Board {
    vector<vector<Cells>> cells;
    Board(int n, int m) {
        cells = vector<vector<Cells>>(n, vector<Cells>(m));
    }
};

class Cells {
    Piece piece;
    Cells() {
        piece = Piece(BLANK);
    }
};

class Piece {
    PieceType pieceType;
    Piece(PieceType type) {
        pieceType = type;
    }
};

class Player {
    string name;
    PieceType pieceType;
    PlayerDao *moves;
    Player(string name, PieceType pieceType) {
        this -> name = name;
        this -> pieceType = pieceType;
        dao = new PlayerMoves();
    }
};


class PlayerDao {

};
// we have solved for open / closed principle
class PlayerMoves: public PlayerDao {
    bool isValid(int x, int y) {

    }

    bool isWon() {

    }

    bool turn(int x, int y) {
        if(isValid(x, y)) {
            // turn
        }
        if(isWon()) {
            return true;
        }
        return false;
    }
};

