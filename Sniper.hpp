//#include "Soldier.hpp"
class Sniper : public Shooter {
public:
	int player;
	int health;
    int damage;
	pair<int, int> location;
	Sniper(uint x){
		player = x;
		int health = 100;
		int damage = 50;
	}

	void shoot();
};