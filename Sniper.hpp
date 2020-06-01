//#include "Soldier.hpp"
class Sniper : public Shooter {
public:
	Sniper(int x): player(x), health(100), damage(50){}
	void shoot();
};