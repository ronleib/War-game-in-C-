class Paramedic : public Soldier {
public:
	int player;
	int health;
	pair<int, int> location;
	Paramedic(int x) : player(x), health(100){}
	void heal();
};