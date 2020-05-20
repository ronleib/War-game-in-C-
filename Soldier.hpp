//#ifndef Soldier_s
//#define Soldier_s
//#include "Board.hpp"
using namespace std;
//using namespace WarGame;
namespace Soldiers {

     class Soldier {
     private:
         uint8_t helth;
         uint8_t demage;
     public:
         //enum SoldierType {};
         std::pair<int, int> location;

         virtual void move(std::pair<int,int> dir);
     };

     class Commander {
         virtual void spetialAbility();
     };

     class FootSoldier : public Soldier {
         void move(std::pair<int,int> dir);
     };

     class FootCommander : public FootSoldier, public Commander {
         void spetialAbility();
     };

     class Sniper : public Soldier {
         void move(std::pair<int,int> dir);
     };

     class SniperCommander : public Sniper, public Commander {
         void spetialAbility();
     };

     class Paramedic : public Soldier {
         void move(std::pair<int,int> dir);
     };

     class ParamedicCommander : public Paramedic, public Commander {
         void spetialAbility();
     };
 }
//#endif