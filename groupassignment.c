#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct userInfo{
  char gamePiece; //X, Y, O
  int boardPos; //position of player
  int special; //Ignore this, this is for missing turns and shit.
}

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
void player (){
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
  struct userInfo player[3]; // player[0] is X, player[1] is Y, player [2] is O

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
    }
    printf("Rolling the dice...\n");
      printf("\n %d",a);
  c=getchar();
}
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

  //choose whether single mode or multiplayer mode
  printf("\n\nOPTION 1 : Single player\n");
  printf("OPTION 2 : Multiplayer\n");
  printf("\nPLEASE CHOOSE YOUR GAME MODE : " );
  scanf("%d",&choice);

    switch (choice){
      case 1://single mode
      printf("\nHUMAN VS COMPUTER\n" );
      printf("\nLet's Play");break;

      case 2://multiplayer mode
      printf("HUMAN VS HUMAN");
      player () ;break;

      default ://not of them
      printf("Thank you for playing this game");break;

    }//end of the switch case




}//end of the process
