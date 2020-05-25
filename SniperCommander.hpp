//#include "Sniper.hpp"
class SniperCommander : public Sniper {
public:
	int player;
	int health;
    int damage;
	pair<int, int> location;
	Sniper(int x){
		player = x;
		health = 120;
		damage = 100;
	}

	void spetialAbility();
};

