#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bot (int);//function prototype for bot

struct userInfo{
  char gamePiece; //X, Y, O
  int boardPos; //position of player
  int special; //Ignore this, this is for missing turns and shit.
};

//void function for 3 players
void choosesymbol2 (){
  int c;

  char n,m,b;//declare variable for the character
  printf("\n\nThe Character are : + , -, *");//declare what is the character
  printf("\n\nPlease Choose your character : ");//first character
  scanf(" %c",&n);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : ");//second character
  scanf(" %c",&m);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : ");//third character
  scanf(" %c",&b);
  if ( (n == m) || (n == b) || (m == b) ){
    printf("\nError");}//i still dont know how to end the games if the value is same but i just can notify them only
    //end of the if
} //end of the void choosesymbol2

//void function for 2 players
void choosesymbol (){
  char v, x;//declare variable for the character
  printf("\n\nThe Character are : + , -");//declare the Character
  printf("\n\nPlease Choose your character : ");//first character
  scanf(" %c",&v);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : ");//second Character
  scanf(" %c",&x);
  if ( v == x ){//check whether first character is same or not with second Character
    printf("\nError");}//i still dont know how to end the games if the value is same but i just can notify them only

} //end of the void choosesymbol

//void function to make the table
void displayline(){
    printf("\n___________________________________________________________________________________\t\n" );
}
//void function for how many players in the game
void menu(){
  int number;//declare the variable for how many players
  printf("\n\nHow Many PLayers(MAX 3) : ");//get the number of players from user
  scanf("%d",&number);

  switch (number){
    case 1 ://only have one player
    printf("\nHuman Vs Yourself");break;

    case 2:
    choosesymbol();//have 2 players
    printf("\nLet's Play");break;

    case 3:
    choosesymbol2 ();//have 3 players
    printf("\nLet's Play");break;

    default://have more than 3 players
    printf("\nThank you for playing this game");

  }//end of the switch case
}//end of the void player

void main (){


  printf("\n ||||||||       ||||    ||     ||    ");
  printf("\n ||             || ||   ||     ||    ");
  printf("\n ||||||||       ||  ||  ||     ||    ");
  printf("\n       ||       ||   || ||     ||    ");
  printf("\n ||||||||       ||    ||||     ||||||");

  printf("\n");
  printf("\n");
  struct userInfo player[3]; // player[0] is X, player[1] is Y, player [2] is O


  printf("\n");
  printf("\n");
  int a;  //declare the variable for the table
  int s;
  int id;
  /// to make the table
  for ( id =0;id < 5;id++){
    displayline();
    for( a =0;a<2;a++){
      printf("\n");
      for( s =0;s<11;s++){
        printf("|\t");
      }//end of the second loop
    }//end of the first loop
  }//end of the last loop
  displayline();

  int choice;//declare the variable to choose whether single mode or multiplayer mode
  int turn;//declare the variable to choose whether player or computer play first

  //choose whether single mode or multiplayer mode
  printf("\n\nOPTION 1 : Single player\n");
  printf("OPTION 2 : Multiplayer\n");
  printf("\nPLEASE CHOOSE YOUR GAME MODE : " );
  scanf("%d",&choice);

    switch (choice){
      case 1://single mode
      printf("\nHUMAN VS COMPUTER\n" );
      printf("\nLet's Play\n");
      bot();break;//added the function to let player to choose who's going to play first

      case 2://multiplayer mode
      printf("HUMAN VS HUMAN");
      menu() ;break;

      default ://not of them
      printf("Thank you for playing this game");break;

    }//end of the switch case



}//end of the process

void bot(int){
    int turn;//declare variable to let player play first or computer play first
    char d;//char for enter button
    printf("Press 1 to play first\n");
    printf("Press 2 to let computer player first\n");
    printf("\n Your Choice : ");
    scanf("%d",&turn);

      switch (turn){//to choose the turn
      case 1:
        printf("Your turn: \n");
        printf("Press enter to roll the dice: \n");
        getchar();//obtain the enter input
        if (getchar()=='\n'){//if input is enter button
        dice();//roll the dice
        }else printf("Thank you for playing this game");//else will quit the game
        break;

      case 2:
        printf("Computer's turn: \n");
        dice();
        break;

      default:
      printf("Thank you for playing this game");
      break;

      }

    }//end of the switch case

void dice(){
      ///rolling the dice
      int b;  //declare the varibale for the dice
  char c = '\n';
  time_t t;
  srand  ( (unsigned) time(&t));

  //rolling the dice
  while(c=='\n'){
    int a=rand() % 7;
    if(a == 0){
      continue;
    }else{
    printf("Rolling the dice...\n");
      printf("\n%d",a);
  c=getchar();
  break;
    }
  }
}
