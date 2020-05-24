#include "Sniper.hpp"
class SniperCommander : public Sniper {
public:
	Sniper(uint x){
		player = x;
		int health = 120;
		int damage = 100;
	}

	void spetialAbility();
};

