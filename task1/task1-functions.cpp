#include "task1-functions.h"
#include <iostream>
#include <math.h>
using namespace std;

#define KM_PER_MILE 1.609344

// setEngineMode - outputs the engine mode based on speed S (mph) and battery level B (%)
// Returns 0 for battery mode and 1 for petrol
int setEngineMode(int S, int B)
{

	// ************************
	// WRITE YOUR SOLUTION HERE
	// ************************

	int speed_kph = round(S * KM_PER_MILE);

	std::cout<<"Speed in kilometers per hour: " << speed_kph << " km/h" << endl;


    if (0 <= S <10) {
        if (B>25) {
            std:cout << 0 << std::endl;
            return 0;
        }
        else {
            std:cout << 1 << std::endl;
            return 1;
        }
    }
    else if (10<=S<30) {
        std:cout << 1 << std::endl;
        return 1;
    }
    else {
        if (B>=45) {
            std:cout << 1 << std::endl;
            return 1;
        }
        else {
            std:cout << 0 << std::endl;
            return 0;
        }
    }
}