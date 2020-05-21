
#include <iostream>
#ifndef B_H
#define B_H
#include "Board.hpp"
#endif
using namespace WarGame;
using namespace std;
#pragma once
namespace Soldiers {
	
	class Human {
    public:
        int player;
		int health;
		
		Human(int p)
			: player(p), health(100)
		{}
    };

    class Soldier {
    public:
        pair<int, int> location;
        virtual void move(WarGame::Board::MoveDIR dir);
    };
	 
	class Shooter : public Human, public Soldier {
    public:
        int damage;
		Shooter(int x) : Human(x), damage(10) {}
		void shoot();
    };

    class Commander {
        virtual void spetialAbility();
    };

    class FootSoldier : public Shooter {
	public:
        FootSoldier(int x) : Shooter(x) {}

        void move(MoveDIR dir);
    };

    class FootCommander : public FootSoldier, public Commander {
	public:
		FootCommander(int x) : FootSoldier(x){
            health = 150;
        }

        void spetialAbility();
    };

    class Sniper : public Shooter {
	public:
        Sniper (int x) : Shooter(x) {  
			damage = 50;
        }

        void move(MoveDIR dir);
    };

    class SniperCommander : public Sniper, public Commander {
	public:
        SniperCommander (int x) : Sniper(x){
            health = 120;
            damage = 100;
        }

        void spetialAbility();
    };
	
    class Paramedic : public Soldier, public Human {
	public:
        Paramedic (int x) : Human(x) {}
		
        void move(MoveDIR dir);
    };
	
    class ParamedicCommander : public Paramedic, public Commander {
	public:
        ParamedicCommander (int x) : Paramedic (x) {
           health = 200;
		}
        void spetialAbility();
    };
 }
//#endif