
#include "Board.hpp"
#include "FootSoldier.hpp"
using namespace WarGame;
Soldier*& Board::operator[](std::pair<int,int> location){
	Soldier* bob = new FootSoldier(1);
	return bob;
}
 
Soldier* Board::operator[](std::pair<int,int> location) const {
	Soldier* bob = new FootSoldier(1);
	return bob;
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

}

bool Board::has_soldiers(uint player_number) const {
	return true;
}
