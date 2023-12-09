#include "Player.h"

Player::Player()
{
	type = WHITE;
}

Player::Player(DiskColor type): type(type)
{
	
}

DiskColor Player::getType()
{
	return type;
}
