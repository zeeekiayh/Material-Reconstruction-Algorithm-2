#include <iostream>
#include "Pixel.h"
#include <vector>

#ifndef SLICE_H
#define SLICE_H


class Slice {

	public:

//		=======================
		Slice(); // Constructor
		~Slice() {} // Destructor
//      ======================

//      ===================
//      Slice Class Methods
//      =======================
		void Initialize_Rand();
		void Initialize_Noise();
		void FindClosestNeighborhood(Slice sample);
		//void VoteCloseNeighbors();
		int GetTypeAtIndex(int row, int col) const;
		//int GetTypeAtIndex(int index) { return pixels[index].GetType(); }
		int NumberSimilarPixels(int row, int col, int newRow, int newCol, const Slice & sample) const;
		int approximateNumberSimilarPixels(int row, int col, int newRow, int newCol, const Slice & sample) const;
		//float CalculateError(Pixel);
//      ============================

		friend std::ostream& operator << (std::ostream& out, Slice rhs)
		{
			for (int i = 0; i < (rhs.sz * rhs.sz); i++)
			{
				std::cout << rhs.pixels[i];
				if ((i + 1) % rhs.sz == 0)
					std::cout << std::endl;
			}
			return out;
		}

	private:
			
		//this is the size of one side of
		//  the square field
		const int sz;
		int seed;

		//Vector that holds the pixels
		std::vector<Pixel> pixels;

}; // end Slice()

#endif