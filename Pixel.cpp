#include "Pixel.h"


void Pixel::SetType(int typ) 
{

    if (typ != 1) 
        std::cout << "Setting type to 0..." << std::endl;
    else 
        std::cout << "Setting type to 1..." << std::endl;
    
    this->typ = typ;

} //end SetType()


void Pixel::AddVote(int vote)
{
    
    if ((vote != 1) && (vote != -1)) {
        std::cout << "Can only vote +-1, not " << vote << ". Setting vote to 0..." << std::endl;
    } else {
        votes+=vote;
    }

} //end AddVote()


