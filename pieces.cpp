#include <iostream>
using namespace std;

class Piece {
  public:
    //General piece attributes
    string piece_class;
    //string piece_name;
    string team;
    
    //Piece movement rules
    bool move_forward; 
    bool move_backward; 
    bool move_sideways; 
    bool move_diagonally;
    
    //Number of spaces the piece can move
    int max_forward_spaces;
    int max_backward_spaces;
    int max_sideways_spaces;
    int max_diagonal_spaces;
    
    //Function to toggle bool value
    bool toggle_bool(bool toggle){
      bool inverted_bool = !toggle;
      return inverted_bool;
    }
    
    //Function that changes the number of spaces a piece can move in direction
    //pointed in by toggle
    void adjust_spaces(bool movement_bool, int space_adjustment, string movement_type){
      if (movement_bool == false){
        return;  
      }
      else{
        if (movement_type == "forward")
            max_forward_spaces = space_adjustment;
        else if (movement_type == "backward")
            max_backward_spaces = space_adjustment;
        else if (movement_type == "sideways")
            max_sideways_spaces = space_adjustment;
        else if (movement_type == "diagonal")
            max_diagonal_spaces = space_adjustment;
      }
    }
};

class Pawn : public Piece {
  public:
    Pawn(){
      piece_class = "pawn";
      move_forward = true;
      move_backward = false;
      move_sideways = false;
      //Remember to change whenever eating opportunity arises!
      move_diagonally = false;
      max_forward_spaces = 2;
      max_backward_spaces = 0;
      max_sideways_spaces = 0;
      max_diagonal_spaces = 0;
      cout << "Constructer completed" << endl;
    }
};

//int main(){
//  cout << "In main my nibbas" << endl;
//  Pawn pawn1;
//  return 0;
//}
