//#includes "Soldier.hpp"

class FootSoldier : public Shooter {
public:
	FootSoldier(int x): player(x), health(100), damage(10){}
	void shoot();
};
