class Paramedic : public Soldier {
public:
	Paramedic(uint x){
		player = x;
		int health = 100;
	
	}
	
    void move(WarGame::Board::MoveDIR dir);
	void heal();
};