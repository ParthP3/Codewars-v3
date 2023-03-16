// 2D Array of struct location
// Maps which donote what's there at every location

// struct cluster, and a map of it. This denotes the presence of a resource, at the location where it is.
// So these pop out randomly over time.

// One of three types

// Either its a base of a particular team
// Or its hosts some particular resource
// Or its war ground

#include "Population.h"
struct Location 
{
    char loc[1000][1000]; //defining location as 2d array (1000*1000 canvas)
    // The territory of each kingdom is supposed to be in square shape, thus the boundaries having their length and width have been defined below

    int land_width;
    int land_length;
    int land_area = land_length * land_width;

    char attack_square[1000][1000]; //can take values 'r', 'y' and by default its 'g'
    int troops[1000][1000]; //a 2d array that takes in x-y coordinates as input and outputs the number of troops deployed at that location
    int troops;
    int spies;
    int spies[1000][1000];
};



