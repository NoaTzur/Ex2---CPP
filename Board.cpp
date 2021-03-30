#include "Board.hpp"
#include <stdexcept>
#include <vector> 
#include <math.h>    
#include <iostream> 
#include <cctype>
#include <string>



namespace ariel {
    
    Board::Board(){
        this->vect.resize(ROW, std::vector<char>(COL));

        for (u_int i = 0; i < this->vect.size(); i++){
            for (u_int j = 0; j < this->vect.at(0).size(); j++){
                this->vect.at(i).at(j) = '_';
            }
        }
    }

    void Board::post(u_int row, u_int column, Direction direction, const std::string &message) {


        if (this->vect.size() < row || this->vect.at(0).size()< column)
        {
            Board::resizeVect(row, column, message);
        }
      
        
        if(direction == Direction::Vertical){

            fill_with_new_message_vert(row, column, message);
        }
        else{ //direction == Direction::Horizontal

            fill_with_new_message_horizon(row, column, message);

        } 

          
    }
    void Board::resizeVect(u_int row, u_int column, const std::string &message){

        u_int prevRow = this->vect.size();
        u_int prevCol = this->vect.at(0).size();
        if (row < column)
        {
            row = column;
        }
   
        u_int newSize = row+(message.size()*4);
       
        this->vect.resize(newSize);
        for (u_int i = 0; i < newSize; i++)
        {
            this->vect.at(i).resize(newSize);
        }
       
              
    }

    std::string Board::read(u_int row, u_int column, Direction direction, u_int length) {
        //checks if the row or col is out of bounds (should be > 0)
        if (row < 0 || column < 0)
        {
            throw std::out_of_range ("out of range, row and col should be greater then zero");
        }
        if(direction == Direction::Vertical && this->vect.size() - row < length){

            throw std::out_of_range ("out of range, cant read a word in this length");
        }
        if(direction == Direction::Horizontal && this->vect.size() - column < length){

            throw std::out_of_range ("out of range, cant read a word in this length");
        }
        //checks if the length the user has entered is negative or decimal 
        if (length < 0 || int(length) != length)
        {
            throw std::invalid_argument( "message length need to be greater then zero" );
        }

        std::string ans;
        if (direction == Direction::Vertical)
        {
            for (size_t i = 0; i < length; i++)
            {
            	if(this->vect.at(row+i).at(column) == 0){
            		ans += '_';
            	}
            	else {
            		ans += this->vect.at(row+i).at(column);
            	}

            }
            
        }
        else{ // direction == Direction::Horizontal
            for (size_t i = 0; i < length; i++)
            {
            
            if(this->vect.at(row).at(column+i) == 0){
            		ans += '_';
            	}
            	else {
			ans += this->vect.at(row).at(column+i);
            	}
                
            }
        }
        
        return ans;
    }
    void Board::show() {
        
        
            std::cout << "" << std::endl;
         
    }

    void Board::fill_with_new_message_vert(u_int row, u_int col, const std::string &message){
        unsigned long j = 0;
        for (size_t i = row; i < row + message.size(); i++)
        { 
            this->vect.at(i).at(col) = message[j++];
        }

    }

    void Board::fill_with_new_message_horizon(u_int row, u_int col, const std::string &message){
        
        unsigned long j = 0;
        for (size_t i = col; i < col + message.size(); i++)
        {
            
            this->vect.at(row).at(i) = message[j++];
        }
        
    }
}

