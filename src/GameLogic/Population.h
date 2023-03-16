
#include "Commodities.h"


class Population{
    
    

public:
    int num_troops; //stores the total number of troops in the population not in the battlefield
    int num_spies;  // stores the total number of spies in the population not in the battlefield
    int num_farmers; //stores the total number of farmers in the population
    int num_engineers; //stores the total number of engineers in the population
    int num_miners; //stores the total number of miners in the population
    Commodity commodity; //The population's commodity
    /*
    int num_farmers(){
        return num_farmers;
    }
    int num_engineers(){
        return num_engineers;
    }
    int num_troops(){
        return num_troops;
    }
    int num_miners(){
        return num_miners;
    }    
    int num_troops(){
        return num_troops;
    }*/


    void recruit_farmers(int n){
        num_farmers = num_farmers + n;
        commodity.food=commodity.food-n;
    } 
    void recruit_engineers(int n){
        num_engineers = num_engineers + n;
        commodity.food = commodity.food -2*n;
    }
    void recruit_troops(int n){
        num_troops = num_troops + n;
        commodity.food = commodity.food - n;
    }
    void recruit_miners(int n){
        num_miners = num_miners + n;
        commodity.food = commodity.food - n;
    }
    void recruit_spies(int n){
        num_spies = num_spies + n;
        commodity.food = commodity.food -2*n;
    }
};
