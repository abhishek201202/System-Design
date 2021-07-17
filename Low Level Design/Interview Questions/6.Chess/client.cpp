#include<bits/stdc++.h>
using namespace std;


class Chess {
	ChessBoard chessBoard;
	vector<Player> player;
	Player currentPlayer;
	vector<Move> movesList;
	GameStatus gameStatus;

public: 
	bool playerMove(CellPosition fromPosition, CellPosition toPosition, Piece piece);
	bool endGame();
private:
	void changeTurn();
};


class Player {
public:
	Account account;
	Color color;
	Time timeLeft;
};


class Account {
	string username;
	string password;
	string name;
	string email;
	string phone;
};


enum Color {
	BLACK, WHITE
};

class Time {
	int mins, secs;
};


enum GameStatus {
	ACTIVE, PAUSED, FORTFEIGHT, BLACK_WIN, WHITE_WIN
};

class ChessBoard {
	vector<vector<Cell>> board;
public:
	void resetBoard();
	void updateBoard(Move move);
};



class Cell {
public:
	Color color;
	Piece piece;
	CellPosition position;
};


class CellPosition {
	char ch;
	int i;
};

class Move {
public:
	Player turn;
	Piece piece;
	Piece killedPiece;
	CellPosition startPosition;
	CellPosition endPosition;
};


class Piece {
	Color color;
public:
	virtual bool move(CellPosition from, CellPosition to);
	virtual vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	virtual bool validate(CellPosition from, CellPosition to);
};



class Knight: public Piece {
public:
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};

class Bishop: public Piece {
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};

class rook: public Piece {
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};


class King: public Piece {
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};

class Queen: public Piece {
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};


class Pawn: public Piece {
	bool move(CellPosition from, CellPosition to);
	vector<CellPosition> possibleMoves(CellPosition from, CellPosition to);
	bool validate(CellPosition from, CellPosition to);
};














int32_t main(){

}