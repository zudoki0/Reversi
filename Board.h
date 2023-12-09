#pragma once
#include <Disk.h>
#include <WhiteDisk.h>
#include <BlackDisk.h>

class Board
{
private:
	int numOfRows, numOfCols;
	Disk*** map;
public:
	Board(int numOfRows, int numOfCols);
	virtual void insertWhiteDisk(int x, int y);
	virtual void insertBlackDisk(int x, int y);
	virtual void flipDisk(int x, int y);
	Disk*** getMap();
	int getNumOfRows();
	int getNumOfCols();
	int countWhiteDisks();
	int countBlackDisks();
	bool isOnlyWhiteDisks();
	bool isOnlyBlackDisks();
	bool isFull();
	bool isWithinMap(int x, int y);
	bool isEmptyCell(int x, int y);
	~Board();
};

