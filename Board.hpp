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
    
        Board();
        

        ~Board() {}

        void post(u_int row, u_int column, Direction direction, const std::string &message);
        std::string read(u_int row, u_int column, Direction direction, u_int length);
        void show();

    private:
        void fill_with_new_message_horizon(u_int row, u_int col, const std::string &message);
        void fill_with_new_message_vert(u_int row, u_int col, const std::string &message);
        void resizeVect(u_int row, u_int column, const std::string &message);
    };

}
