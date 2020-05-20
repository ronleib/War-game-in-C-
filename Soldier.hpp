
using namespace std;

class Soldier {
private:
	uint8_t helth;
	virtual final uint8_t  demage;
public:
    //enum SoldierType {};
	std::pair<int,int> location;
	virtual void move( MoveDIR dir );
}

class Commander {
	virtual void spetialAbility();
}

class FootSoldier : public Soldier {
	void move( MoveDIR dir);
}

class FootCommander : public FootSoldier, public Commander {
	void spetialAbility();
}

class Sniper : public Soldier {
	void move( MoveDIR dir);
}

class SniperCommander : public Sniper, public Commander {
	void spetialAbility();
}

class Paramedic : public Soldier {
	void move( MoveDIR dir);
}

class ParamedicCommander : public Paramedic, public Commander {
	void spetialAbility();
}