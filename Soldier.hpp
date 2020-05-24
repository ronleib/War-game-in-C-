
#include <iostream>
using namespace std;

namespace Soldiers {
	
    class Soldier {
    public:
		uint player;
		int health;
        pair<int, int> location;
    };

	class Shooter : public Soldier {
    public:
        int damage;
		virtual void shoot();
    };
}
//#pragma once
//#endif