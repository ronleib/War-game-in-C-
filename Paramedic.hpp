class Paramedic : public Soldier {
public:
	int player;
	int health;
	pair<int, int> location;
	Paramedic(int x){
		player = x;
		int health = 100;
	
	}
	
    void move(WarGame::Board::MoveDIR dir);
	void heal();
};