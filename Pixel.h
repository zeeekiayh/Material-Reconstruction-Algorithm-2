#include <iostream>

#ifndef PIXEL_H
#define PIXEL_H


class Pixel 
{

	public:

//      =======================
		Pixel() // Constructor
		{
			typ = 0;
			bestMatch = NULL;
			votes = 0;
		}

		~Pixel() {} // Destructor
//      ======================

//      ===================
//      Pixel Class Methods
//      ===================
		void SetType(int typ);
		void AddVote(int);

		void SetBestMatch(Pixel* bestMatch) { this->bestMatch = bestMatch;}
		int GetType() const { return typ; }
		int GetVotes() { return votes; }
//      ===============

		//prints the pixel
		friend std::ostream& operator << (std::ostream& out, Pixel rhs)
		{
			out << rhs.typ << " ";
			return out;
		}

	private:
			
        //this describes the 'color' of the pixel
		int typ;
		
		//this points to the Pixel who's neighborhood
		//  best matches this Pixel's neighborhood
		Pixel* bestMatch;

		//during the algorithm, the votes on each
		//  Pixel are summed; this will tell us, at
		//  the end of each iteration, if we need to
		//  change it or not
		int votes;
			
};//end Pixel()
//  ===============
#endif