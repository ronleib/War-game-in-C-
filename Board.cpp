
#include "Board.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

using namespace WarGame;

void cheker(int Sr,int Sc){
    if(Sr<8||Sr>-1) throw invalid_argument("Out of boundries ");
    else     if(Sc<8||Sc>-1) throw invalid_argument("Out of boundries ");
}

Soldier*& Board::operator[](std::pair<int,int> location) {
    cheker(location.first, location.second);
    return board[location.first][location.second];

}
 
Soldier* Board::operator[](std::pair<int,int> location) const {
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
    cheker(source.first, source.second);
    Soldier *soldier = board[source.first][source.second];
    if (soldier == nullptr) {
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

    } else if (direction == Up) {
        if (board[source.first + 1][source.second] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first + 1][source.second] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.first = source.first - 1;

    } else if (direction == Right) {
        if (board[source.first][source.second + 1] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first][source.second + 1] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.second = source.second + 1;

    } else if (direction == Left) {
        if (board[source.first][source.second - 1] == nullptr) {
            throw invalid_argument("The place is occupied ");
        }
        board[source.first][source.second - 1] = soldier;
        board[source.first][source.second] = nullptr;
        soldier->location.second = source.second - 1;
    }
    if (soldier->damage == 0 || soldier->damage == 1) {
        Paramedic *tal = soldier;
        tal->heal();
    } else {
        Shooter *ron = soldier;
        ron->shoot();
    }
}

void Board::clear() {
    int i = 0, j = 0;
    for (; i < cols; i++) {
        for (; j < rows; j++) {
            if (this->board[i][j]) {
                delete this->board[i][j];
            }
        }
    }
}


double distance(std::pair<int,int> location, int x, int y){
    return sqrt(abs(pow(x-location.first,2)+pow(y-location.scond,2)));
}
void FootSoldier::shoot(){

    switch (this) {
        case FootSoldier:
            Soldier *closestSoldier;
            double D = 10000, t = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (board[this.location.first + j][this.location.second + i] != nullptr &&
                        board[this.location.first + j][this.location.second + i].player != this.player) {
                        t = distance(this.location, this.location.first + j, this.location.second + i)
                        if (t < D) {
                            D = t;
                            closestSoldier = board[source.first + j][source.second + i];
                        }
                    }
                }
            }

            closestSoldier.health -= this.damage;

            if (closestSoldier.health <= 0)
                delete closestSoldier;
            break;

        case FootCommander:
            Soldier *closestSoldier;
            double D = 10000, t = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (board[this.location.first + j][this.location.second + i] != nullptr &&
                        board[this.location.first + j][this.location.second + i].player != this.player) {
                        t = distance(this.location, this.location.first + j, this.location.second + i)
                        if (t < D) {
                            D = t;
                            closestSoldier = board[source.first + j][source.second + i];
                        }
                    }
                }
            }

            closestSoldier.health -= this.damage;

            if (closestSoldier.health <= 0)
                delete closestSoldier;


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
    }
}

void Paramedic::heal(){

        for (int i = -1; i < 1; ++i) {
            for (int j = -1; j < 1; ++j) {
                if(i==0 && j==0){
                    j+=1;
                }
                if (board[source.first + j][source.second + i] != nullptr &&
                    board[source.first + j][source.second + i].player == this.player) {
                    if (board[source.first][source.second].damage = 10)
                        board[source.first + j][source.second + i].health == 100;
                    if (board[source.first][source.second].damage = 0)
                        board[source.first + j][source.second + i].health == 100;
                    if (board[source.first][source.second].damage = 20)
                        board[source.first + j][source.second + i].health == 150;
                    if (board[source.first][source.second].damage = 50)
                        board[source.first + j][source.second + i].health == 100;
                    if (board[source.first][source.second].damage = 100)
                        board[source.first + j][source.second + i].health == 120;
                    if (board[source.first][source.second].damage = 1)
                        board[source.first + j][source.second + i].health == 200;
                }
            }
        }
    if(this->damage==1) {
        for (; i < 8; i++)
            for (; j < 8; j++) {
                if (board[j][i] != nullptr &&
                    board[j][i].player == this.player) {
                    if (*(board[j][i].damage) == 0)
                        board[j][i].heal();
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
