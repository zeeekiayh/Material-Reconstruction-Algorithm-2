//  ==================
    #include "Pixel.h"
    #include "Slice.h"
    #include "GlobalVariables.h"
//  ============================

//  ====================
    using namespace std;
//  ====================

//  ============
    int main() {
            
        //testing pixel
        Pixel somePixel;
        //testing the SetType() function
        somePixel.SetType(0);

        //The random Slice object
        Slice rndm;
        rndm.Initialize_Rand();
        cout << rndm;

        //The sample Slice object
        Slice sample;
        cout << "Initialize_Noise()" << endl;
        sample.Initialize_Noise();
        cout << sample;

        return 0;

    } // int main()
//  ===============