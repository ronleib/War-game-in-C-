//#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic {
public:
	int player;
	int health;
	pair<int, int> location;
	Sniper(int x){
		player = x;
		int health = 200;
	
	}
	
void heal();
void spetialAbility();
};