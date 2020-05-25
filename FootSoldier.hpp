//#includes "Soldier.hpp"

class FootSoldier : public Shooter {
public:
	int player;
	int health;
    int damage;
	pair<int, int> location;
	FootSoldier(int x){
		player = x;
		health = 100;
		damage = 10;
	}
	void shoot();
};
