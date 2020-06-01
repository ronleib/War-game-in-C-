
#include "Board.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

//#include "Soldier.hpp"
using namespace WarGame;

void cheker(int Sr,int Sc){
    if(Sr<8||Sr>-1) throw invalid_argument("Out of boundries ");
    else     if(Sc<8||Sc>-1) throw invalid_argument("Out of boundries ");
}

Soldier*& Board::operator[](std::pair<int,int> location) {
//    Soldier *bob = new Soldier;
//    *(this->board[location.first][location.second])=bob;
//    return *(this->board[location.first][location.second]);
    cheker(location.first,location.second);
return board[location.first][location.second];

}
 
Soldier* Board::operator[](std::pair<int,int> location) const {
    //	Soldier* bob = new Soldier();
//    return *(this->board[location.first][location.second]);
//    cheker(location.first,location.second);
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
    cheker(source.first,source.second);
    Soldier *soldier = board[source.first][source.second];
    if (!soldier) {
        throw invalid_argument("Soldier don`t exist");
    }
    if (*(soldier.player) != player_number) {
        throw invalid_argument("Soldier of other player");
    }

    if (direction == Down) {
        if (board[source.first - 1][source.second] != nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first - 1][source.second] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first + 1;
        soldier->location.second = source.second;

    } else if (direction == Up) {
        if (board[source.first + 1][source.second] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first + 1][source.second] = soldier;
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

void Shooter::shoot(){

    switch (this) {
        case FootSoldier:
            for (int i = -1; i < 1; ++i) {
                for (int j = -1; j < 1; ++j) {
                    if (board[this.location.first + j][this.location.second + i] != nullptr &&
                        board[this.location.first + j][this.location.second + i].player !=
                        board[this.location.first][this.location.second].player) {

                        board[this.location.first + j][this.location.second + i].health -= board[this.location.first][this.location.second].damage;
                        i=2;j=2;
                        if (board[this.location.first + j][this.location.second + i].health >= 0)
                            delete board[this.location.first + j][this.location.second + i];
                    }
                }
            }
            break;

        case FootCommander:
            for (int i = -1; i < 1; ++i) {
                for (int j = -1; j < 1; ++j) {
                    if (board[source.first + j][source.second + i] != nullptr &&
                        board[source.first + j][source.second + i].player !=
                        board[source.first][source.second].player) {
                        i=2;j=2;
                        board[source.first + j][source.second + i].health -= board[source.first][source.second].damage;
                        if (board[source.first + j][source.second + i].health >= 0)
                            delete board[source.first + j][source.second + i];
                    }
                }
            }

            for (; i < 8; i++)
                for (; j < 8; j++) {
                    if (board[j][i] != nullptr &&
                        board[j][i].player == this.player) {
                        if (*(board[j][i].damage) == 10)
                            board[j][i].shoot();
                    }
                }
            break;


        case Sniper:
            Soldier *soldierStrong;
            for (; i < 8; i++)
                for (; j < 8; j++) {
                    if (board[j][i] != nullptr &&
                        board[j][i].player != this.player) {
                        if (*(board[source.first + j][source.second + i].health) > *(soldierStrong.health))
                            soldierStrong = board[source.first + j][source.second + i];
                    }
                }
            *(soldierStrong).health -= this.damage;
            if (*(soldierStrong).health >= 0)
                delete soldierStrong;
            break;

        case SniperCommander

            for (; i < 8; i++)
                for (; j < 8; j++) {
                    if (board[j][i] != nullptr &&
                        board[j][i].player != this.player) {
                        if (*(board[source.first + j][source.second + i].health) > *(soldierStrong.health))
                            soldierStrong = board[source.first + j][source.second + i];
                    }
                }
            *(soldierStrong).health -= this.damage;
            if (*(soldierStrong).health >= 0)
                delete soldierStrong;

            for (; i < 8; i++)
                for (; j < 8; j++) {
                    if (board[j][i] != nullptr &&
                        board[j][i].player == this.player) {
                        if (*(board[j][i].damage) == 50)
                            board[j][i].shoot();
                    }
                }
            break;

        case
//        default: // code to be executed if n doesn't match any cases
    }
}

void Paramedic::heal(){
    for (int i = -1; i < 1; ++i) {
        for (int j = -1; j < 1; ++j) {
            if (board[source.first + j][source.second + i] != nullptr &&
                board[source.first + j][source.second + i].player ==
                board[source.first][source.second].player) {
                if(board[source.first][source.second].damage=10)
                board[source.first + j][source.second + i].health == 100;
            }
        }
    }
};

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
