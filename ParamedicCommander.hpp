//#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic {
public:
	//int player;
	//int health;
	//pair<int, int> location;
	ParamedicCommander(int x): Paramedic(x){
		health = 200;
	}
	
	void spetialAbility();
};