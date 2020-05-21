//#ifndef Soldier_s
//#define Soldier_s
//#include "Board.hpp"
using namespace std;
//using namespace WarGame;
namespace Soldiers {
	
	class Human {
    public:
        int player;
		int health;
		
		Human(int p)
			: player(p), health(100)
		{}
    };

    class Soldier {
    public:
        std::pair<int, int> location;
        virtual void move(std::pair<int,int> dir);
    };
	 
	class Shooter : public Human, public Soldier {
    public:
        int damage;
		Shooter(int x) : Human(x), damage(10) {}
		void shoot();
    };

    class Commander {
        virtual void spetialAbility();
    };

    class FootSoldier : public Shooter {
	public:
        FootSoldier(int x) : Shooter(x) {}

        void move(std::pair<int,int> dir);
    };

    class FootCommander : public FootSoldier, public Commander {
	public:
		FootCommander(int x) : FootSoldier(x){
            health = 150;
        }

        void spetialAbility();
    };

    class Sniper : public Shooter {
	public:
        Sniper (int x) : Shooter(x) {  
			damage = 50;
        }

        void move(std::pair<int,int> dir);
    };

    class SniperCommander : public Sniper, public Commander {
	public:
        SniperCommander (int x) : Sniper(x){
            health = 120;
            damage = 100;
        }

        void spetialAbility();
    };
	
    class Paramedic : public Human {
	public:
        Paramedic (int x) : Human(x) {}
		
        void move(std::pair<int,int> dir);
    };
	
    class ParamedicCommander : public Paramedic, public Commander {
	public:
        ParamedicCommander (int x) : Paramedic (x) {
           health = 200;
		}
        void spetialAbility();
    };
 }
//#endif