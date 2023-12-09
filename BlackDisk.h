#pragma once
#include "Disk.h"

class BlackDisk :
    public Disk
{
public:
    BlackDisk(int posX, int posY);
    void flip() override;
};

