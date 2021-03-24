/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Noa Tzur>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;


//Post function
TEST_CASE("Good messages tests - should return TRUE for all - valid inputs") {
    Board board;
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(board.post(0,5,Direction::Vertical,"Noa"));
    CHECK_NOTHROW(board.post(0,8,Direction::Horizontal,"Tzur"));
    CHECK_NOTHROW(board.post(0,8,Direction::Horizontal,"CPP course"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"2342"));
    CHECK_NOTHROW(board.post(0,5,Direction::Vertical,"@#$"));
    CHECK_NOTHROW(board.post(0,8,Direction::Horizontal,"Tzu4r"));
    CHECK_NOTHROW(board.post(0,8,Direction::Horizontal,"%$aa"));
      
}


//Read function
TEST_CASE("Invalid input and outputs") {
    Board board;

    //fill a board
    board.post(100,200,Direction::Horizontal,"abcd");
    board.post(0,5,Direction::Vertical,"Noa");
    board.post(0,8,Direction::Horizontal,"Tzur");
   


    

    //Invalid output - didnt return the newer messages
    CHECK_FALSE(board.read(100,200,Direction::Horizontal,6).compare("abcd") != 0);
    CHECK_FALSE(board.read(0,5,Direction::Vertical,3).compare("Noa") != 0);
    CHECK_FALSE(board.read(0,8,Direction::Horizontal,6).compare("Tzur") != 0);
    CHECK_FALSE(board.read(0,40,Direction::Horizontal,6).compare("") != 0);
    
    CHECK_FALSE(board.read(100,200,Direction::Horizontal,6).compare("abcd") != 0);
    CHECK_FALSE(board.read(0,5,Direction::Vertical,3).compare("Noa") != 0);
    CHECK_FALSE(board.read(0,8,Direction::Horizontal,6).compare("Tzur") != 0);
    CHECK_FALSE(board.read(0,40,Direction::Horizontal,6).compare("") != 0);
    
    CHECK_FALSE(board.read(100,200,Direction::Horizontal,6).compare("abcd") != 0);
    CHECK_FALSE(board.read(0,5,Direction::Vertical,3).compare("Noa") != 0);
    CHECK_FALSE(board.read(0,8,Direction::Horizontal,6).compare("Tzur") != 0);
    CHECK_FALSE(board.read(0,40,Direction::Horizontal,6).compare("") != 0);
    
}


