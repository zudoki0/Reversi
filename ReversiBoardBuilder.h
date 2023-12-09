#pragma once
#include "BoardBuilder.h"
class ReversiBoardBuilder :
    public BoardBuilder
{
private:
    const int numOfRows = 8;
    const int numOfCols = 8;
public:
    Board build() override;
};

