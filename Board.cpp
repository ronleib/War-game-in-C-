
#include "Board.hpp"
#include "FootSoldier.hpp"
using namespace WarGame;
Soldier*& Board::operator[](std::pair<int,int> location) {
//    Soldier *bob = new Soldier;
//    *(this->board[location.first][location.second])=bob;
//    return *(this->board[location.first][location.second]);
    return board[location.first][location.second];

}
 
Soldier* Board::operator[](std::pair<int,int> location) const {
    //	Soldier* bob = new Soldier();
//    return *(this->board[location.first][location.second]);
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {

    Soldier *soldier = board[source.first][source.second];

    if (!soldier) {
        throw invalid_argument("Soldier don`t exist");
    }
    if (*(soldier.player) != player_number) {
        throw invalid_argument("Soldier of other player");
    }

    if (direction == Down) {
        if (board[source.first + 1][source.second] != nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first + 1][source.second] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first + 1;
        soldier->location.second = source.second;

    } else if (direction == Up) {
        if (board[source.first - 1][source.second] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first - 1][source.second] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first - 1;
        soldier->location.second = source.second;

    } else if (direction == Right) {
        if (board[source.first][source.second + 1] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first][source.second + 1] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first;
        soldier->location.second = source.second + 1;

    } else if (direction == Left) {
        if (board[source.first][source.second - 1] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first][source.second - 1] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first;
        soldier->location.second = source.second - 1;
    }
}

void Board::clear(){
	int i=0, j=0;
	for(;i<cols;i++){
		for(;j<rows;j++){
			if(this->board[i][j]){
                delete this->board[i][j];
			}
		}
	}
}

bool Board::has_soldiers(uint player_number) const {
    for (; i < cols; i++) {
        for (; j < rows; j++) {
            if (this->board[i][j] != nullptr) {
                if (board[i][j].player == player_number)
                    return true;
            }
        }
    }
    return false;
}
