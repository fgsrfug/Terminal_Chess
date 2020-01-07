/********************************************************************************************* 
 * File name: chessboard.cpp
 * Author: Jesus Narvaez
 * Description: This file is in charge of creating the chessboard
 * How it works: Functions are called from Logic.cpp to assemble the board as it updates
*********************************************************************************************/ 
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//enum for piece types
enum piece_type {
    pawn,
    rook,
    knight,
    bishop,
    queen,
    king
};

//enum for team colors
enum team_color {
    black,
    white
};

/********************************************************************************************* 
 * Function name: tile_creation
 * Description: Creates a tile within the board and places correct piece in board if necessary
 * How it works: If a tile is occupied, place the correct color and piece within the tile 
 *               with switch case. Otherwise, create a blank tile
*********************************************************************************************/ 
void tile_creation(bool occupied, team_color team = white, piece_type piece = pawn){
    //cout << "Team color: " << team << "Piece type: " << piece << endl;
    if (occupied){
        cout << "-------------" << endl;
        cout << "|           |" << endl;
        
        switch (team){
            case white:   
                cout << "|  white    |" << endl;
                break;
            case black:   
                cout << "|  black    |" << endl;
                break;
            default:
                break;
        }
        
        switch (piece){
            case pawn:   
                cout << "|  pawn     |" << endl;
                break;
            case rook:   
                cout << "|  rook     |" << endl;
                break;
            case knight: 
                cout << "|  knight   |" << endl;
                break;
            case bishop: 
                cout << "|  bishop   |" << endl;
                break;
            case queen:  
                cout << "|  queen    |" << endl;
                break;
            case king:   
                cout << "|  king     |" << endl;
                break;
            default:
                break;
        }
        cout << "|           |" << endl;
        cout << "-------------" << endl;
        return;
    } 
    else {
        cout << "-------------" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "|           |" << endl;
        cout << "-------------" << endl;
        return;
    }
}

/********************************************************************************************* 
 * Function name: create_column()
 * Description: Print a row of 8 tiles with pieces in correct spots
 * How it works: If a tile is occupied, place the correct color and piece within the tile 
 *               with switch case. Otherwise, create a blank tile
*********************************************************************************************/ 
void create_column(int* piece_locations, team_color* team_array, piece_type* piece_array, int array_sizes){
   // int pieces_in_row = sizeof(piece_locations) / sizeof(piece_locations[0]);
   // cout << pieces_in_row << endl;
    //int size_of_element = sizeof(piece_locations[0]);
    //int array_size = (size_of_array / size_of_element);
    cout << "Array sizes: " << array_sizes << endl;
    cout << piece_locations[0] << piece_locations[1] << piece_locations[2] << piece_locations[3]<< endl;
    cout << "Print the color array: " << team_array[0] << team_array[1] << team_array[2] << endl;
    cout << "Print the piece array: " << piece_array[0] << piece_array[1] << piece_array[2] << endl;
    
    for (int i = 0; i < 8; i++){
        bool piece_found = false;
        for (int j = 0; j < array_sizes; j++){
            if (piece_locations[j] == i){
                piece_found = true;
                tile_creation(true, team_array[j], piece_array[j]);
            }
        } 
        if (piece_found == false)
            tile_creation(false);
    }

    return;
}
/*
//Function to create a row of tiles for the chessboard
void board_row(){
  cout << "-------------------------------------------------------------------------------------------------" << endl;
  cout << "|           |           |           |           |           |           |           |           |" << endl;
  cout << "|           |           |           |           |           |           |           |           |" << endl;
  cout << "|           |           |           |           |           |           |           |           |" << endl;
  cout << "|           |           |           |           |           |           |           |           |" << endl;
  cout << "-------------------------------------------------------------------------------------------------" << endl;
  return;
}

void make_board(){
  int i;
  for(i = 0; i < 8; i++){
    board_row();
  }
  return;
}
*/
int main(){
    //make_board();
    piece_type piece1 = pawn;
    piece_type piece2 = knight;
    team_color color1 = white;
    team_color color2 = black;
  
    tile_creation(false);
    tile_creation(false, color1, piece1);
    tile_creation(true, color2, piece1);
    tile_creation(true, color1, piece2);
    int test[] = {2, 3, 7};
    int size_of_arrays = 3;
    piece_type piece_array[] = {pawn, knight, knight};
    team_color color_array[] = {white, black, white};
    create_column(test, color_array, piece_array, size_of_arrays);
  return 0;
}
