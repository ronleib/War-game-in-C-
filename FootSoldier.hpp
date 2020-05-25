//#includes "Soldier.hpp"

class FootSoldier : public Shooter {
public:
	FootSoldier(int x){
		player = x;
		int health = 100;
		int damage = 10;
	}
	void shoot();
};
