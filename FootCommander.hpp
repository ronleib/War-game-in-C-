//#includes "FootSoldier.hpp"

class FootCommander : public FootSoldier {
public:
	FootCommander(uint x) : FootSoldier(x){
		health = 150;
		damage = 20;
	}
	~FootCommander(){
		delete FootSoldier;
	}
	void spetialAbility();
};
