#include "Slice.h"
#include "perlinnoise.h"
#include <cmath>


Slice::Slice(): sz(10)
{
	std::cout << "initializing Slice" << std::endl;
	seed = round((rand() % 1000));
} // Constructor
    


void Slice::Initialize_Rand() 
{
	std::cout << "randomizing Slice" << std::endl;

	float temp;
	for (int i = 0; i < (sz * sz); i++)
	{
		temp = round((rand() % 2));
		Pixel tempPixel;

		tempPixel.SetType(temp);
		pixels.push_back(tempPixel);
	}

};//end Slice::Initialize_Rand()



void Slice::Initialize_Noise() 
{
	PerlinNoise pn(seed);
		
	std::cout << "noisifying Slice" << std::endl;
	for (int i = 0; i < (sz * sz); i++)
	{
		Pixel tempPixel;
		double n = round(pn.noise(i / sz, i % sz, .5));
		tempPixel.SetType(n);
		pixels.push_back(tempPixel);
	}
	
};//end Slice::Initialize_Noise()




int Slice::GetTypeAtIndex(int row, int col) const //starting at (0,0)
{
	if ((row > 0 && row < sz) && (col > 0 && col < sz))
		return pixels[(row * sz) + col].GetType();
	else
		return -1;
};//end Slice::GetTypeAtIndex()



int Slice::NumberSimilarPixels(int row, int col, int newRow, int newCol, const Slice & sample) const 
{
    //This function finds the number of similar pixels
    //within the neighborhood size.
    //This is a full check for each pixel. This has a high proformance cost.
    
    int number_similar=0;
    int rowPoint, colPoint, newRowPoint, newColPoint;

    //This the loop to check every point.
    for (int i = 0; i < 25; i++)
    {
        //sets the points to the right spot with respect to i.
        rowPoint = ((row - 2) + (i / 5));
        colPoint = ((col - 2) + (i % 5));
        newRowPoint = ((newRow - 2) + (i / 5));
        newColPoint = ((newCol - 2) + (i % 5));

        //This checks if the two spots are the same.
        if ((rowPoint > 0 && rowPoint < sz) && (colPoint > 0 && colPoint < sz) && (newRowPoint > 0 && newRowPoint < sz) && (newColPoint > 0 && newColPoint < sz))
        {
            if (GetTypeAtIndex(rowPoint, colPoint) == sample.GetTypeAtIndex(newRowPoint, newColPoint))
                number_similar++;
        }
    }
    return number_similar;
    
};//end Slice::NumberSimilarPixels()



int Slice::approximateNumberSimilarPixels(int row, int col, int newRow, int newCol, const Slice& sample) const
{
    //This is only going to do a cross check
    //this will decrease the number of checks from 25 to 9
    int number_similar = 0;
    int rowPoint, colPoint, newRowPoint, newColPoint;

    //This checks the corss at the same time but makes sure not to count the middle twice.
    for (int i = 0; i < 5; i++)
    {
        //This where we change the col and row points in respect to i.
        rowPoint = ((row - 2) + i);
        newRowPoint = ((newRow - 2) + i);
        colPoint = ((col - 2) + i);
        newColPoint = ((newCol - 2) + i);

        //This keeps the col the same but changes the row
        if ((rowPoint > 0 && rowPoint < sz) && (newRowPoint > 0 && newRowPoint < sz))
        {
            if (GetTypeAtIndex(rowPoint, col) == sample.GetTypeAtIndex(newRowPoint, newCol))
                number_similar++;
        }

        //This keeps the row the same but changes the col unless it is in the middle.
        if ((colPoint > 0 && colPoint < sz) && (newColPoint > 0 && newColPoint < sz) && (i != 3))
        {
            if (GetTypeAtIndex(row, colPoint) == sample.GetTypeAtIndex(newRow, newColPoint))
                number_similar++;
        }
    }
    return number_similar;

};//end Slice::approximateNumberSimilarPixels()


	
//not done
//This function is used to calculate the error
//  ==============================================================
	void Slice::FindClosestNeighborhood(Slice sample) {
		//sample is what we are comparing
		
		for (std::vector<Pixel>::iterator it = pixels.begin(); it != pixels.end(); it++)
		{
			
		}
		//variable to store index of best match:
		int idx_best_match[2]={0,0};
		
		//the number of similar pixels in the
		//  current best match
		int sim=0;
		
		//temporary variable for the
		//  number of similar pixels
		//  in the
		int num=0;
		
		//for the pixel at idx in 'random', search in the sample for the closest match
		for(int rows_samp = 0; rows_samp < sz; rows_samp++){
			for(int cols_samp = 0; cols_samp < sz; cols_samp++){
				
				
				
				//If the number of similar pixels compared to
				//  the neighborhood of this pixel is larger
				//  than the the previos best match, replace
				//  it and store the index.
				//If the number of similar pixels in the
				//  neighborhood is equal to the square of the
				//  neighborhood size, it is a perfect match,
				//  and we don't need to vote on any of the
				//  pixels in it.
				
		};};//end for()'s in sample
		
		//return the index of the best macth
		//  and store it in the pixel's variable
		//return idx_best_match;
		
	};//end Slice::FindClosestNeighborhood()
//  ========================================

/*
//not done
void Slice::VoteCloseNeighbors() {

    //We may just need to vote on any pixels in
    //  the neighboorhoods as we go through.

};//end Slice::VoteCloseNeighbors()


//not done
float Slice::CalculateError(Pixel sample) {

    //The error is basically the total
    //  number of different pixels in
    //  every best matching neighborhood
    
    //Go through all the pixels in 'random'
    //  and find the closest neighborhood.
    //Then, difference between the number of
    //  similar pixels and the total possible
    //  number of similar pixels; add it to 
    //  the total differences.

    return 0.00;
    
};//end Slice::CalculateError()

*/