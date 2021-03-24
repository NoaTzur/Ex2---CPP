#include "Board.hpp"
#include <stdexcept>
#include <vector> 
#include <math.h>    
#include <iostream> 
#include <cctype>


namespace ariel {
    

    void Board::post(unsigned int  row, unsigned int  column, Direction direction, std::string message) {

        //checks if the row or col is out of bounds (should be > 0)
        /*
        if (row < 0 || column < 0){
            throw std::out_of_range ("out of range, row and col should be greater then zero");
        }

        //resize if the range we have recieved is greater then the current range of the 2d vector
        if (this->vect.size()-row < message.size() || this->vect.at(0).size()-column < message.size())
        {
            Board::resizeVect(row, column, message);
        }
        
        if(direction == Direction::Vertical){

            fill_with_new_message_vert(row, column, message);
        }
        else{ //direction == Direction::Horizontal

            fill_with_new_message_horizon(row, column, message);

        } 

        //update the new area (range) of strings in the borad
        if(row < this->low_limit_row){
            this->low_limit_row = row;
        }
        else if (row+message.size() > this->high_limit_row){
            this->high_limit_row = row+message.size();
        }

        if (column < this->low_limit_col)
        {
            this->low_limit_col = column;
        }
        else if (column+message.size() > this->high_limit_col)
        {
            this->high_limit_col = column+message.size();
        }
        */
          
    }
    void Board::resizeVect(unsigned int row, unsigned int column, std::string message){

        unsigned int prevRow = this->vect.size();
        unsigned int prevCol = this->vect.at(0).size();

        unsigned int newRow = prevRow+(message.size()*2);
        unsigned int newCol = prevCol+(message.size()*2);
/*
        this->vect.resize(newRow);//, std::vector<char>(COL));
        for (size_t i = 0; i < newRow; i++)
        {
            this->vect.at(i).resize(newCol);
        }


        // for (size_t i = prevRow; i < newRow ; i++){
        //     for (size_t j = prevCol; j < newCol; j++){
        //         this->vect.at(i).at(j) = '_';
        //     }
        // }
        */
    }

    std::string Board::read(unsigned int  row, unsigned int  column, Direction direction, unsigned int  length) {
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
        
/*
        std::string ans;
        if (direction == Direction::Vertical)
        {
            for (size_t i = 0; i < length; i++)
            {
                ans = ans + this->vect.at(row+i).at(column);
            }
            
        }
        else{ // direction == Direction::Horizontal
            for (size_t i = 0; i < length; i++)
            {
                ans = ans + this->vect.at(row).at(column+i);
            }
        }
        */
        
        return "";
    }
    void Board::show() {
      

        //more clever way to print
        
        for (unsigned int i = this->low_limit_row; i < this->high_limit_row; i++)
        {
            for (unsigned int  j = this->low_limit_col; j < this->high_limit_col; j++)
            {
                if (int(this->vect.at(i).at(j)) == 0)
                {
                    std::cout << '_';
                }
                else{
                    std::cout << this->vect.at(i).at(j);
                    
                }
                
            }
            std::cout << "" << std::endl;
            
        }
         
    }



    void Board::fill_with_new_message_vert(unsigned int  row, unsigned int  col, std::string message){
        unsigned int  j = 0;
        for (unsigned int  i = row; i < row + message.size(); i++)
        { 
            this->vect.at(i).at(col) = message[j++];
        }

    }

    void Board::fill_with_new_message_horizon(unsigned int  row, unsigned int  col, std::string message){
        
        unsigned int  j = 0;
        for (unsigned int  i = col; i < col + message.size(); i++)
        {
            
            this->vect.at(row).at(i) = message[j++];
        }
        
    }
}

