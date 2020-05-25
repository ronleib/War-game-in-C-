
#include "Board.hpp"
#include "FootSoldier.hpp"
using namespace WarGame;
Soldier*& Board::operator[](std::pair<int,int> location){
	return new FootSoldier(1);
}
 
Soldier* Board::operator[](std::pair<int,int> location) const {
	return new FootSoldier(1);
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

}

bool Board::has_soldiers(uint player_number) const {
	return true;
}
