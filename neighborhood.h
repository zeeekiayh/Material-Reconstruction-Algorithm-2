#include <iostream>
#include <vector>
#include "Pixel.h"
#include "Slice.h"

#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

class NeighborHood
{
private:
	int row;
	int col;
	std::vector<Pixel> pixels;

public:
	NeighborHood(int row, int col, Slice sample)
	{
		this->row = row;
		this->col = col;
		for(int i = row - 2; )
	}

};

#endif // !NEIGHBORHOOD_H
