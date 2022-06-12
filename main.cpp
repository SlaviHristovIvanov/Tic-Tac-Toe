#include <iostream>
using namespace std;

class Game{
public:
char board [3] [3] {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

  char current_marker;
  int current_player;

  void drawBoard(){
    cout << " " << board[0] [0] << " | " << board[0] [1] << " | " << board[0] [2] << endl;
    cout << "___________\n";
    cout << " " << board[1] [0] << " | " << board[1] [1] << " | " << board[1] [2] << endl;
    cout << "___________\n";
    cout << " " << board[2] [0] << " | " << board[2] [1] << " | " << board[2] [2] << endl;
   
  }
  bool placeMarker(int slot){
     int row = slot / 3;
     int col;
     if(slot % 3 == 0){
       row = row - 1;
       col = 2;
     }
     else col = (slot % 3) - 1;

     if(board[row] [col] != 'x' && board[row] [col] != 'o') {
       board[row] [col] = current_marker;
       return true;
     }
     else return false;
   }


   int winner(){
     for(int i =0; i< 3; i++){
       //redove
       if(board[i] [0] == board[i] [1] && board[i] [1] == board[i] [2]) return current_player;
       //coloni
       if(board[0] [i] == board[1] [i] && board[1] [i] == board[2] [i]) return current_player;
     }
     if(board[0] [0] == board[1] [1] && board[1] [1] == board [2] [2]) return current_player;
     if(board[0] [2] == board[1] [1] && board[1] [1] == board [2] [0]) return current_player;

     return 0;
   }

    void swap_player_and_marker(){
      if(current_marker == 'x') current_marker = 'o';
      else current_marker = 'x';

      if(current_player == 1) current_player = 2;
      else current_player = 1;
    }


    void game(){
      cout << "Palyer 1, choose your marker : ";
      char marker_p1;
      cin>> marker_p1;

      current_player = 1;
      current_marker = marker_p1;
      
      drawBoard();
      
      int player_won;

      //for cikal za 9-te hoda
      for(int i =0; i < 9; i++){
         cout << "It's player " << current_player << "'s turn. Enter your slot : ";
         int slot;
         cin >> slot;
        
        //tuka e ako napishat po golqmo chislo ot 9
        if(slot < 1 || slot > 9){
          
         cout << "This move is invalid! Try another numer! "; 
         i--;
         continue;
        }
        //tuka kogato iskat da napishat varho edno i zashto miasto da im izpishe che e zaeto
        //s i-- davame oshte edin shans na tozi igrach da si izigrae hoda
         if(!placeMarker(slot))
         {
         (cout << "That slot is occuped! Try another slot! "); i--; continue;
         }
         drawBoard();
        

        player_won = winner();
        //player 1 ili 2 pecheli
        if(player_won == 1) 
        {cout << "Player one won! "; break;

        }
        if(player_won == 2){
          cout << "Player two won! "; break;
        }
         swap_player_and_marker();
         
      }
      //kogato ne pecheli nikoi ot dvamata igrachi
      if(player_won == 0) cout << "Game draw! ";
    }

  
};
int main(){
 Game g;
 Game * game1 = & g;


game1 -> drawBoard();
game1 -> winner();
game1 -> swap_player_and_marker();
game1 -> game();

  return 0;
}