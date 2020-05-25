#include "doctest.h"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"

TEST_CASE(" first ") {
	Board board(8,8);
	board[{0,1}] = new Paramedic(1);
	board[{0,3}] = new ParamedicCommander(1);
	board[{0,5}] = new Paramedic(1);
	CHECK(board[{0,1}] != nullptr);
	CHECK(board[{0,3}] != nullptr);
	CHECK(board[{0,5}] != nullptr);
	
	board[{7,1}] = new Paramedic(2);
	board[{7,3}] = new ParamedicCommander(2);
	board[{7,5}] = new Paramedic(2);
	CHECK(board[{7,1}] != nullptr);
	CHECK(board[{7,3}] != nullptr);
	CHECK(board[{7,5}] != nullptr);
    
	board.move(1, {0,1}, Board::MoveDIR::Up); 
	CHECK(board[{0,1}] == nullptr);
	CHECK(!board.has_soldiers(2));

	board.move(2, {7,1}, Board::MoveDIR::Down);  
	CHECK(board[{7,1}] == nullptr);
	CHECK(!board.has_soldiers(1));

	board.move(1, {0,3}, Board::MoveDIR::Up);   
	CHECK(board[{0,3}] == nullptr);
	CHECK(!board.has_soldiers(2));

	board.move(2, {7,3}, Board::MoveDIR::Left);   
	CHECK(board[{7,3}] == nullptr);  
	CHECK(!board.has_soldiers(1));
	
	board.clear();
	int i = 0, j =  0;
	for(;i<8;i++){
		for(;j<8;j++){
			CHECK(board[{i,j}] == nullptr);
		}
	}
}


TEST_CASE(" second ") {
	Board board(8,8);
	board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);
	CHECK(board[{0,1}] != nullptr);
	CHECK(board[{0,3}] != nullptr);
	CHECK(board[{0,5}] != nullptr);
	
	board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);
	CHECK(board[{7,1}] != nullptr);
	CHECK(board[{7,3}] != nullptr);
	CHECK(board[{7,5}] != nullptr);
    
	board.move(1, {0,1}, Board::MoveDIR::Up); 
	CHECK(board[{0,1}] == nullptr);
	CHECK(!board.has_soldiers(2));

	board.move(2, {7,1}, Board::MoveDIR::Down);  
	CHECK(board[{7,1}] == nullptr);
	CHECK(!board.has_soldiers(1));

	board.move(1, {0,3}, Board::MoveDIR::Up);   
	CHECK(board[{0,3}] == nullptr);
	CHECK(!board.has_soldiers(2));

	board.move(2, {7,3}, Board::MoveDIR::Left);   
	CHECK(board[{7,3}] == nullptr);  
	CHECK(!board.has_soldiers(1));
	
	board.clear();
	int i = 0, j =  0;
	for(;i<8;i++){
		for(;j<8;j++){
			CHECK(board[{i,j}] == nullptr);
		}
	}
}


TEST_CASE(" second ") {
	Board board(8,8);
	board[{0,1}] = new Sniper(1);
	board[{0,2}] = new Sniper(1);
	board[{0,3}] = new SniperCommander(1);
	board[{0,4}] = new Sniper(1);
	board[{0,5}] = new Sniper(1);
	
	board[{7,1}] = new FootSoldier(2);
    
	board.move(1, {0,3}, Board::MoveDIR::Up);   
	CHECK(board.has_soldiers(2));
	
}
