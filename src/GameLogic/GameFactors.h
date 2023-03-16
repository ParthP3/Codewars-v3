// To be written in a multithreaded manner

// Game class would have the constructor function as the one main thread, and the others would mere

// Threading!
// select() -> polling method :
#pragma once
#include "Commodities.h"
#include "Map.h"
#include "Population.h"

struct Kingdom
{

    int defence_rating; // measure of how good the defense of a kingdom is
    int offence_rating; // measure of how good the attack/offense of a kingdom is
    Population population; //The kingdom's population
    Location location; //The kingdom's map parameters


    void initDefenseOffense(int x)
    {
        population.commodity.raw_materials -= x;
        defence_rating = x;
        offence_rating = 100 - x;
    }
    void initializeMilitary(int x){
        static bool called  = false;
        if(called) return;
        called = true;
        initDefenseOffense(x);
    }

    void improve_attack(int num_engineers, int raw_materials, float fraction)
    {
        while (true)
        {
            offence_rating = offence_rating + num_engineers * raw_materials * fraction;
            sleep(1);
        }
    } // increases attack capabilities per second
    void improve_defense(int num_engineers, int raw_materials, float fraction)
    {
        while (true)
        {
            defence_rating = defence_rating + num_engineers * raw_materials * (1 - fraction);
            sleep(1);
        }
    } // increases defense capabilities per second
    void square_assign(int x, int y, char a)
    { // function to make a square at a particular location either red or yellow
        location.attack_square[x][y] = a;
        if (a == 'r')
        {
            defence_rating = defence_rating - 2;
        }
        else if (a == 'y')
        {
            defence_rating = defence_rating - 1;
        }
    }
};

struct Game
{
    void spy_capture(Kingdom k, int n)
    {
        int initSpies = k.location.spies;
        k.location.spies = k.location.spies - n;
        if (k.location.spies < 0)
        {
            n = initSpies;
        }
        k.defence_rating = k.defence_rating - 5 * n;
    }
    void troops_for_attack(int n, Kingdom k)
    {
        k.population.num_troops = k.population.num_troops - n;
        for (int i = 0; i < k.location.land_width - 1; i++)
        {
            for (int j = 0; j < k.location.land_length - 1; j++)
            {
                int nTroops = k.location.troops[i][j];
                n = n - nTroops;
            }
        }
    }
    bool attack;
    void troop_killed(int n)
    {
        n = n - 1;
    } // n troops sent to the war

    bool attack(bool attack, Kingdom k, int n)
    { // a boolean function that one has to decide upon every second to decide if he wants to attack or not
        while (true)
        {
            if (attack == 1)
            {
                return true;
            }
            else
            {
                k.population.num_troops = k.population.num_troops + n;
                return false;
            }
            sleep(1);
        }
    }

    void deployArmy(bool attack, int n, Kingdom k)
    { // here n is the number of troops you want to send to the war
        if (attack == true)
        {
            troops_for_attack(n, k);
        }
        else
        {
            NULL;
        }
    }

    void deploySpy(int n, Kingdom k)
    { // n is the number of spies to be deployed at the battlefield
        int num_spies_war = n;
        for (int i = 0; i < k.location.land_width - 1; i++)
        {
            for (int j = 0; j < k.location.land_length - 1; j++)
            {
                int nSpies = k.location.troops[i][j];
                n = n - nSpies;
            }
        }
    }
};
