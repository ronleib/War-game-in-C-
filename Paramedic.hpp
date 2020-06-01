class Paramedic : public Soldier {
public:

	Paramedic(int x) : player(x),damage(0),health(100){}
	void heal();
};