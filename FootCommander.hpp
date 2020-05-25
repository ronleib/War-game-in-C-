//#includes "FootSoldier.hpp"

class FootCommander : public FootSoldier {
public:
	//int player;
	//int health;
    //int damage;
	//pair<int, int> location;
	FootCommander(int x) : FootSoldier(x){
		health = 150;
		damage = 20;
	}
	void spetialAbility();
};
