//#include "Soldier.hpp"
class Sniper : public Shooter {
public:
	int player;
	int health;
    int damage;
	pair<int, int> location;
	Sniper(int x): player(x), health(100), damage(50){}
	void shoot();
};