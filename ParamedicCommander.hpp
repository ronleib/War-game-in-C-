//#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic {
public:
	//int player;
	//int health;
	//pair<int, int> location;
	ParamedicCommander(int x): player(x),damage(1),health(200){}
	
	void spetialAbility();
};