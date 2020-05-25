
#include <iostream>
using namespace std;
#ifndef SOLDIER_H
#define SOLDIER_H
namespace Soldiers {
	
    class Soldier {
    public:
		int player;
		int health;
        std::pair<int, int> location;
    };

	class Shooter : public Soldier {
    public:
        int damage;
		void shoot();
    };
//    class Commander : public Shooter {
//    public:
//
//        virtual void spetialAbility();
//    };
}
//#pragma once
#endif
