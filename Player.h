#pragma once
#include <Disk.h>
class Player
{
private:
	DiskColor type;
public:
	Player();
	Player(DiskColor type);
	DiskColor getType();
};

