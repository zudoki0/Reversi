
#include "Game.h"

void Game::flip(int targetX, int targetY, int source) {
	if (!isWithinGame(targetX, targetY)) {
		return;
	}
	flipWithinRow(targetX, targetY, source);
	flipWithinColumn(targetX, targetY, source);
	flipWithinDiagonal(targetX, targetY, source);
}

void Game::flipWithinRow(int x, int y, int source)
{
	for (int i = y - 1; i >= 0; i--) {
		if (map[x][i] == 0) {
			break;
		}
		if (map[x][i] == source) {
			for (int j = i; j < y; j++) {
				map[x][j] = source;
			}
			break;
		}
	}
	for (int i = y + 1; i < height; i++) {
		if (map[x][i] == 0) {
			break;
		}
		if (map[x][i] == source) {
			for (int j = i; j > y; j--) {
				map[x][j] = source;
			}
			break;
		}
	}
}

void Game::flipWithinColumn(int x, int y, int source)
{
	for (int i = x - 1; i >= 0; i--) {
		if (map[i][y] == 0) {
			break;
		}
		if (map[i][y] == source) {
			for (int j = i; j < x; j++) {
				map[j][y] = source;
			}
			break;
		}
	}
	for (int i = x + 1; i < width; i++) {
		if (map[i][y] == 0) {
			break;
		}
		if (map[i][y] == source) {
			for (int j = i; j > x; j--) {
				map[j][y] = source;
			}
			break;
		}
	}
}

void Game::flipWithinDiagonal(int x, int y, int source)
{
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			for (int k = i, l = j; k < x && l < y; k++, l++) {
				map[k][l] = source;
			}
			break;
		}
	}
	for (int i = x + 1, j = y + 1; i < width && j < height; i++, j++) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			for (int k = i, l = j; k > x && l > y; k--, l--) {
				map[k][l] = source;
			}
			break;
		}
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < height; i--, j++) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			for (int k = i, l = j; k < x && l > y; k++, l--) {
				map[k][l] = source;
			}
			break;
		}
	}
	for (int i = x + 1, j = y - 1; i < width && j >= 0; i++, j--) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			for (int k = i, l = j; k > x && l < y; k--, l++) {
				map[k][l] = source;
			}
			break;
		}
	}
}

bool Game::hasWithinDiagonal(int x, int y, int source)
{
	bool sourceFound = false;
	std::vector<int> amount;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			sourceFound = true;
			for (int k = i + 1, l = j + 1; k < x && l < y; k++, l++) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();

	for (int i = x + 1, j = y + 1; i < width && j < height; i++, j++) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			sourceFound = true;
			for (int k = i - 1, l = j - 1; k > x && l > y; k--, l--) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();
	
	for (int i = x - 1, j = y + 1; i >= 0 && j < height; i--, j++) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			sourceFound = true;
			for (int k = i + 1, l = j - 1; k < x && l > y; k++, l--) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();
	
	for (int i = x + 1, j = y - 1; i < width && j >= 0; i++, j--) {
		if (map[i][j] == 0) {
			break;
		}
		if (map[i][j] == source) {
			sourceFound = true;
			for (int k = i - 1, l = j + 1; k > x && l < y; k--, l++) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();
	
	return false;
}

bool Game::hasWithinRow(int x, int y, int source)
{
	bool sourceFound = false;
	std::vector<int> amount;
	for (int i = y - 1; i >= 0; i--) {
		if (map[x][i] == 0) {
			break;
		}
		if (map[x][i] == source) {
			sourceFound = true;
			for (int j = i + 1; j < y; j++) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();

	for (int i = y + 1; i < height; i++) {
		if (map[x][i] == 0) {
			break;
		}
		if (map[x][i] == source) {
			sourceFound = true;
			for (int j = i - 1; j > y; j--) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();

	return false;
}

bool Game::hasWithinColumn(int x, int y, int source)
{
	bool sourceFound = false;
	std::vector<int> amount;
	for (int i = x - 1; i >= 0; i--) {
		if (map[i][y] == 0) {
			break;
		}
		if (map[i][y] == source) {
			sourceFound = true;
			for (int j = i + 1; j < x; j++) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();

	for (int i = x + 1; i < width; i++) {
		if (map[i][y] == 0) {
			break;
		}
		if (map[i][y] == source) {
			sourceFound = true;
			for (int j = i - 1; j > x; j--) {
				amount.push_back(1);
			}
			break;
		}
	}

	if (sourceFound && amount.size() > 0) {
		return true;
	}

	sourceFound = false;
	amount.clear();

	return false;
}

bool Game::isAdjacentToExisting(int x, int y, int source)
{
	int target = 0;
	if (source == BLACK_DISK) target = WHITE_DISK;
	else if (source == WHITE_DISK) target = BLACK_DISK;

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) {
				continue;
			}
			int new_x = x + dx;
			int new_y = y + dy;

			if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height && map[new_x][new_y] == target) {
				return true;
			}
		}
	}
	return false;
}

bool Game::isFull()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

bool Game::isOnlyWhiteDisk()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == BLACK_DISK) return false;
		}
	}
	return true;
}

bool Game::isOnlyBlackDisk()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == WHITE_DISK) return false;
		}
	}
	return true;
}

Game::Game(int width, int height) : width(width), height(height), move(1)
{
	map = new int* [width];
	for (int i = 0; i < width; i++) {
		map[i] = new int[height];
		for (int j = 0; j < height; j++) {
			map[i][j] = 0;
		}
	}
	map[width / 2 - 1][height / 2 - 1] = 1;
	map[width / 2][height / 2] = 1;
	map[width / 2 - 1][height / 2] = 2;
	map[width / 2][height / 2 - 1] = 2;
}

Game::~Game()
{
	for (int i = 0; i < height; i++) {
		delete map[i];
	}
	delete map;
}

bool Game::isWithinGame(int x, int y) {
	return x >= 0 && y >= 0 && x < width && y < height;
}

bool Game::isValidMove(int x, int y, int player) {
	if (!isWithinGame(x,y)) return false;
	return (hasWithinColumn(x, y, player) || hasWithinDiagonal(x, y, player) || hasWithinRow(x, y, player)) && isAdjacentToExisting(x, y, player);
}

int** Game::getMap() {
	return map;
}

bool Game::isWonByBlack()
{
	int white = 0, black = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == BLACK_DISK) {
				black++;
			}
			if (map[i][j] == WHITE_DISK) {
				white++;
			}
		}
	}
	return black > white;
}

bool Game::insertDisk(int x, int y, int player) {
	if(!isValidMove(x, y, player)) return false;
	if (map[x][y] != 0) return false;
	map[x][y] = player;
	flip(x, y, player);
	if (move == BLACK_DISK) {
		move = WHITE_DISK;
	}
	else if (move == WHITE_DISK) {
		move = BLACK_DISK;
	}
	if (!hasValidMove(move) && move == BLACK_DISK) {
		move = WHITE_DISK;
	}
	else if (!hasValidMove(move) && move == WHITE_DISK) {
		move = BLACK_DISK;
	}
	return true;
}

int Game::getCurrentMove() {
	return move;
}

bool Game::hasValidMove(int player)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (map[i][j] == 0 && isValidMove(i, j, player)) {
				return true;
			}
		}
	}
	return false;
}

int Game::isWonBy()
{

	if (isOnlyBlackDisk()) {
		return BLACK_DISK;
	}
	if (isOnlyWhiteDisk()) {
		return WHITE_DISK;
	}
	if (isFull()) {
		if (isWonByBlack()) {
			return BLACK_DISK;
		}
		else {
			return WHITE_DISK;
		}
	}
	return 0;
}

bool** Game::getValidMoves(int player)
{
	bool** tempMap;
	tempMap = new bool* [width];
	for (int i = 0; i < width; i++) {
		tempMap[i] = new bool[height];
		for (int j = 0; j < height; j++) {
			if (map[i][j] == 0 && isValidMove(i,j,player)) {
				tempMap[i][j] = true;
			} else {
				tempMap[i][j] = false;
			}
		}
	}
	return tempMap;
}

void Game::renderMapOnConsole()
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout << map[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
