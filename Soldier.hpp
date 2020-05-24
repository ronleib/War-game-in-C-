
#include <iostream>
#ifndef B_H
#define B_H
#include "Board.hpp"
#endif
using namespace WarGame;
using namespace std;
#pragma once
namespace Soldiers {
	
    class Soldier {
    public:
		uint player;
		int health;
        pair<int, int> location;
        virtual void move(WarGame::Board::MoveDIR dir);
    };

	class Shooter : public Soldier {
    public:
        int damage;
		virtual void shoot();
    };
}
//#endif