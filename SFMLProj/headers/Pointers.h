#pragma once
#include "Grid.h"

class Pointers
{
    static Grid* grid_p; 
public:
    static void setGridPointer(Grid* p)
    {
        grid_p = p; 
    }
    static Grid* getGridPointer()
    {
        return grid_p;
    }
};

