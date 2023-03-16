// structs for different type of population
// The classes for the derived commodities (which include raw material, population's engineering, )
#ifndef COMMODITY
#define COMMODITY
#define INIT_FOOD 100
#define INIT_RAW 100
#include "Map.h"
#include <unistd.h>
class Commodity
{

public:
    unsigned int raw_materials = 100; // amount of gold in the inventory which is initially 1000
    unsigned int food = 100;          // amount of food in the inventory
    
    /*
        unsigned int food()
        {
            return food;
        }
        unsigned int raw_materials()
        {
            return raw_materials;
        }*/
    void produce_food(int land_area, int num_farmers)
    {
        while (true)
        {
            food = food + land_area * num_farmers;
            sleep(1);
        }
    } // frequency of production of food is one second

    void produce_material(int land_area, int num_miners)
    {
        while (true)
        {
            raw_materials = raw_materials + land_area * num_miners;
            sleep(1);
        }
    }
};
#endif