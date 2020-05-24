class Sniper : public Shooter {
public:
	Sniper(uint x){
		player = x;
		int health = 100;
		int damage = 50;
	}
	
    void move(WarGame::Board::MoveDIR dir);
	void shoot();
};