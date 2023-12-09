#pragma once
#include <Disk.h>
class WhiteDisk :
    public Disk
{
public:
    WhiteDisk(int posX, int posY);
    void flip() override;
};

