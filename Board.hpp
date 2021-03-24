#include <string>
#include "Direction.hpp"
#include <vector> 
#include <limits>

const int ROW = 200;
const int COL = 200;

namespace ariel {

    class Board {
        
    public:
        std::vector<std::vector<char>> vect;
        
        //range of the strings in the board
        unsigned int  low_limit_row = std::numeric_limits<int>::infinity();
        unsigned int  high_limit_row = 0;
        unsigned int  low_limit_col = std::numeric_limits<int>::infinity();
        unsigned int  high_limit_col = 0;

        Board() {
            this->vect.resize(ROW);//, std::vector<char>(COL));
            for (unsigned int i = 0; i < ROW; i++)
            {
                this->vect.at(i).resize(COL);
            }

            // for (size_t i = 0; i < vect.size(); i++){
            //     for (size_t j = 0; i < vect.at(0).size(); j++){
            //         this->vect.at(i).at(j) = '_';
            //     }
            // }
            
        }

        ~Board() {}

        void post(unsigned int row, unsigned int column, Direction direction, std::string message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();

    private:
        void fill_with_new_message_horizon(unsigned int row, unsigned int intcol, std::string message);
        void fill_with_new_message_vert(unsigned int row, unsigned int col, std::string message);
        void resizeVect(unsigned int row, unsigned int column, std::string message);
    };

}
