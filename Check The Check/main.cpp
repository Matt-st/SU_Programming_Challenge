#include <iostream>
#include <fstream>
using namespace std;

const char EMPTY = '.';
const char WKING = 'K';
const char BKING = 'k';
const char WQUEEN = 'Q';
const char BQUEEN = 'q';
const char WROOK = 'R';
const char BROOK = 'r';
const char WBISHOP = 'B';
const char BBISHOP = 'b';
const char WKNIGHT = 'N';
const char BKNIGHT = 'n';
const char WPAWN = 'P';
const char BPAWN = 'p';

char board[8][8];

struct point {
	int x;
	int y;
};

char charatpoint(point p) {
	return board[p.y][p.x];
}

bool isblack(char c) {
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}

bool iswhite(char c) {
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}

point bking, wking;

//done
bool check_king(point king, point oking) {
	//one off
	int xdiff = abs(king.x - oking.x);
	int ydiff = abs(king.y - oking.y);

	if (abs(xdiff) <= 1 && abs(ydiff) <= 1)
		return true;

	return false;
}

//done
bool check_bishop(point king, point bishop) {
	//not diagonal
	int xdiff = abs(king.x - bishop.x);
	int ydiff = abs(king.y - bishop.y);
	if (xdiff != ydiff && xdiff != 0)
		return false;

	//direction of travel from bishop to king on x
	int xinc = (bishop.x < king.x) ? 1 : -1;
	//direction of travel from bishop to king on y
	int yinc = (bishop.y < king.y) ? 1 : -1;

	int x, y;
	for (x = bishop.x + xinc, y = bishop.y + yinc; x != king.x && y != king.y; x += xinc, y+= yinc) {
		if (board[y][x] != EMPTY)
			return false;
	}

	return true;
}

//done
bool check_rook(point king, point rook) {
	//not same row/column
	if (king.x != rook.x && king.y != rook.y)
		return false;

	//same x
	if (king.x == rook.x) {
		int starty = min(king.y, rook.y) + 1;
		int endy = max(king.y, rook.y) - 1;
		for (int i = starty; i <= endy; i++) {
			if (board[i][rook.x] != EMPTY)
				return false;
		}
	}
	//same y
	else if (king.y == rook.y) {
		int startx = min(king.x, rook.x) + 1;
		int endx = max(king.x, rook.x) - 1;
		for (int i = startx; i <= endx; i++) {
			if (board[rook.y][i] != EMPTY)
				return false;
		}
	}

	return true;
}

//done
bool check_knight(point king, point knight) {
	int xdiff = abs(king.x - knight.x);
	int ydiff = abs(king.y - knight.y);
	if ((xdiff == 1 && ydiff == 2) || (ydiff == 1 && xdiff == 2))
		return true;

	return false;
}

//done
bool check_queen(point king, point queen) {
	return (check_rook(king, queen) || check_bishop(king, queen));
}

//done
bool check_pawn(point king, point pawn) {
	bool is_king_white = (king.x == wking.x && king.y == wking.y);

	int xdiff = abs(pawn.x - king.x);
	if (xdiff != 1)
		return false;

	//pawn can only attack down (y+1)
	if (is_king_white) {
		if (pawn.y != king.y - 1)
			return false;
	}
	//pawn can only attack up
	else {
		if (pawn.y != king.y + 1)
			return false;
	}

	return true;
}

bool check(point king, point piece) {
	char piecetype = charatpoint(piece);
	switch (tolower(piecetype)) {
	case 'b':
		return check_bishop(king, piece);
		break;
	case 'q':
		return check_queen(king, piece);
		break;
	case 'k':
		return check_king(king, piece);
		break;
	case 'n':
		return check_knight(king, piece);
		break;
	case 'p':
		return check_pawn(king, piece);
		break;
	case 'r':
		return check_rook(king, piece);
		break;
	};
	return true;
}

int main(int argc, char* argv[]) {
	ifstream in;
	if (argc < 2)
			in.open("..\\board4.txt", ios_base::in);
	else
			in.open(argv[1], ios_base::in);
	int x, y;

	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			in >> board[y][x];
			if (board[y][x] == BKING) {
				bking.x = x;
				bking.y = y;
			}
			else if (board[y][x] == WKING) {
				wking.x = x;
				wking.y = y;
			}
		}
	}

	//output board
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			cout << board[y][x];
		}
		cout << endl;
	}
	cout << endl;
	
	//loop through every white piece
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			if (iswhite(board[y][x])) {
				point piece = { x, y };
				if (check(bking, piece)) {
					cout << "Black king is in check from " << board[y][x] << " at (x,y)=(" << x << "," << y << ")" << endl;
				}
			}
		}
	}

	//loop through every black piece
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			if (isblack(board[y][x])) {
				point piece = { x, y };
				if (check(wking, piece)) {
					cout << "White king is in check from " << board[y][x] << " at (x,y)=(" << x << "," << y << ")" << endl;
				}
			}
		}
	}

	return 0;
}