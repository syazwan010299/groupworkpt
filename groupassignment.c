/* NAME : 1. MOHD SYAZWAN ZULFARIS BIN ZAINAL ( B04180021)
          2. LAU JUN HONG (B04180032)
          3.
          4.
          5.

  ASSIGNMENT : GROUP PROJECT ( SNAKE AND LADDER )
  SUBMISSION DATE : 1/8/2018
  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

struct userInfo
{
  char gamePiece; //X, Y, O
  int boardPos;   //position of player
  int special;    //Ignore this, this is for missing turns and shit.
};

void bot1();
void choosesymbol();
void choosesymbol();
void displayline();
void menu();
void bot();
int dice();
void buildBoard(struct userInfo currentB[], int roll, int i);
int move(struct userInfo currentB[], int i);

void main()
{
  //initializing everything
  struct userInfo player[3]; // player[0] is X, player[1] is Y, player [2] is O
  player[0].gamePiece = 'X';
  player[1].gamePiece = 'Y';
  player[2].gamePiece = 'O';

  for (int i = 0; i < 3; i++)
  {
    player[i].boardPos = 0;
  }
  ///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///
  int yourMove = 0;
  while (move(player, yourMove))
  {
    yourMove++;
    if (yourMove == 3)
      yourMove = 0;
  }
  ///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///

  printf("\n ||||||||       ||||    ||     ||    ");
  printf("\n ||             || ||   ||     ||    ");
  printf("\n ||||||||       ||  ||  ||     ||    ");
  printf("\n       ||       ||   || ||     ||    ");
  printf("\n ||||||||       ||    ||||     ||||||");

  printf("\n\n");

  int a; //declare the variable for the table
  int s;
  int id;

  int choice; //declare the variable to choose whether single mode or multiplayer mode
  int turn;   //declare the variable to choose whether player or computer play first

  //choose whether single mode or multiplayer mode
  printf("\n\nOPTION 1 : Single player\n");
  printf("OPTION 2 : Multiplayer\n");
  printf("\nPLEASE CHOOSE YOUR GAME MODE : ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1: //single mode
    printf("\nHUMAN VS COMPUTER\n");
    printf("\nLet's Play\n");
    bot(); //bot(); //??
    break; //added the function to let player to choose who's going to play first

  case 2: //multiplayer mode
    printf("HUMAN VS HUMAN");
    menu();
    break;

  default: //not of them
    printf("Thank you for playing this game");
    break;

  } //end of the switch case

} //end of the process

//function for declare who play first for 2 players
void bot1()
{
  int turn; //declare variable to let player play first or computer play first
  char d;   //char for enter button
  printf("\nPress 1 to play first\n");
  printf("Press 2 to Second Player play first\n");
  printf("\n Your Choice : ");
  scanf("%d", &turn);

  switch (turn)
  { //to choose the turn
  case 1:
    printf("First player turn: \n");
    printf("Press enter to roll the dice: \n");
    getchar(); //obtain the enter input
    if (getchar() == '\n')
    {         //if input is enter button
      dice(); //roll the dice
    }
    else
      printf("Thank you for playing this game"); //else will quit the game
    break;

  case 2:
    printf("Second player player turn: \n");
    printf("Press enter to roll the dice: \n");
    getchar(); //obtain the enter input
    if (getchar() == '\n')
    {         //if input is enter button
      dice(); //roll the dice
    }
    else
      printf("Thank you for playing this game"); //else will quit the game
    break;

  default:
    printf("Thank you for playing this game");
    break;
  } //end of the switch case
}

//function for declare who play first for 3 players
void bot2()
{
  int turn; //declare variable to let player play first or computer play first
  char d;   //char for enter button
  printf("\nPress 1 to play first\n");
  printf("Press 2 to Second Player play first\n");
  printf("Press 3 to Third Player play first\n");
  printf("\n Your Choice : ");
  scanf("%d", &turn);

  switch (turn)
  { //to choose the turn
  case 1:
    printf("First Player turn: \n");
    printf("Press enter to roll the dice: \n");
    getchar(); //obtain the enter input
    if (getchar() == '\n')
    {         //if input is enter button
      dice(); //roll the dice
    }
    else
      printf("Thank you for playing this game"); //else will quit the game
    break;

  case 2:
    printf("Second Player turn: \n");
    printf("Press enter to roll the dice: \n");
    getchar(); //obtain the enter input
    if (getchar() == '\n')
    {         //if input is enter button
      dice(); //roll the dice
    }
    else
      printf("Thank you for playing this game"); //else will quit the game
    break;

  case 3:
    printf("Third Player turn: \n");
    printf("Press enter to roll the dice: \n");
    getchar(); //obtain the enter input
    if (getchar() == '\n')
    {         //if input is enter button
      dice(); //roll the dice
    }
    else
      printf("Thank you for playing this game"); //else will quit the game
    break;

  default:
    printf("Thank you for playing this game");
    break;
  }
} //end of the switch case

//void function for 3 players
void choosesymbol2()
{
  int c;

  char n, m, b;                                  //declare variable for the character
  printf("\n\nThe Character are : + , -, *");    //declare what is the character
  printf("\n\nPlease Choose your character : "); //first character
  scanf(" %c", &n);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : "); //second character
  scanf(" %c", &m);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : "); //third character
  scanf(" %c", &b);
  if ((n == m) || (n == b) || (m == b))
  {
    printf("\nError");
  } //i still dont know how to end the games if the value is same but i just can notify them only
    //end of the if
} //end of the void choosesymbol2

//void function for 2 players
void choosesymbol()
{
  char v, x;                                     //declare variable for the character
  printf("\n\nThe Character are : + , -");       //declare the Character
  printf("\n\nPlease Choose your character : "); //first character
  scanf(" %c", &v);
  printf("\n\nNext Person");
  printf("\n\nPlease Choose your character : "); //second Character
  scanf(" %c", &x);
  if (v == x)
  { //check whether first character is same or not with second Character
    printf("\nError");
  } //i still dont know how to end the games if the value is same but i just can notify them only

} //end of the void choosesymbol

//void function to make the table

//void function for how many players in the game
void menu()
{
  int number;                               //declare the variable for how many players
  printf("\n\nHow Many PLayers(MAX 3) : "); //get the number of players from user
  scanf("%d", &number);

  switch (number)
  {
  case 1: //only have one player
    printf("\nHuman Vs Yourself");
    break;

  case 2:
    choosesymbol(); //have 2 players
    printf("\nLet's Play\n");
    bot1();
    break;

  case 3:
    choosesymbol2(); //have 3 players
    printf("\nLet's Play");
    bot2();
    break;

  default: //have more than 3 players
    printf("\nThank you for playing this game");

  } //end of the switch case
} //end of the void player

void bot()
{
  struct userInfo X, Y;
  X.boardPos = 0;
  Y.boardPos = 0;
  int turn; //declare variable to let player play first or computer play first
  printf("\nPress 1 to play first\n");
  printf("Press 2 to let computer player first\n");
  printf("\n Your Choice : ");
  scanf("%d", &turn);

  switch (turn)
  { //to choose the turn
  case 1:
    printf("Your turn: \n");
    dice(); //roll the dice
    //printf("%d",diceNumb);
    break;

  case 2:
    printf("Computer's turn: \n");
    dice();
    break;

  default:
    printf("Thank you for playing this game");
    break;
  }

} //end of the switch case

int dice()
{
  ///rolling the dice
  //declare the varibale for the dice
  int diceNumb;
  char c = '\n';
  time_t t;
  srand((unsigned)time(&t));

  //I'll improve this later
  printf("Press enter to roll the dice\n");
  c = getchar();

  //rolling the dice
  do
  {
    diceNumb = rand() % 7;
  } while (diceNumb == 0);

  printf("Rolling the dice...\n%d", diceNumb);
  return diceNumb;
}

int move(struct userInfo currentB[], int i)
{
  int roll = dice();
  int flag = 0;
  for (; roll > 0; roll--)
  {
    if (++currentB[i].boardPos > 50)
    {
      currentB[i].boardPos--;
      flag = 1;
      break;
    }
    Sleep(500);
    system("cls");
    buildBoard(currentB, roll, i);
  }
  if (flag == 1)
  {
    for (; roll > 0; roll--)
    {
      currentB[i].boardPos--;
      Sleep(500);
      system("cls");
      buildBoard(currentB, roll, i);
    }
    flag = 0;
  }
  if (currentB[i].boardPos == 50)
  {
    printf("\t\t\t%c is the Winner!", currentB[i].gamePiece);
    Sleep(7000);
    return 0;
  }
  else
    return 1;
}

void buildBoard(struct userInfo currentB[], int roll, int i)
{
  int numb = 0, flow = 0, boardNumb = 60, tile = 0;
  for (int vert = 0; vert <= 30; vert++, numb++)
  {
    if (vert % 6)
    {
      printf("|");
      for (int row = 0; row < 10; row++)
      {
        //tile knows what box/square is what number
        if (flow % 2)
          tile = boardNumb + row; //odd row starting from 0
        else
          tile = boardNumb - row; //even row starting from 0

        if (numb == 1)
        {
          if (flow % 2)
            printf("\t%8d|", tile); //odd row starting from 0
          else
            printf("\t%8d|", tile); //even row starting from 0
        }
        else if (numb == 2 && currentB[0].boardPos == tile)
          printf("\t%-8c|", currentB[0].gamePiece);
        else if (numb == 3 && currentB[1].boardPos == tile)
          printf("\t%-8c|", currentB[1].gamePiece);
        else if (numb == 4 && currentB[2].boardPos == tile)
          printf("\t%-8c|", currentB[2].gamePiece);
        else
          printf("\t\t|");
      }
      printf("\n");
    }
    else
    { //prints +-----+-----+
      for (int horz = 0; horz <= 160; horz++)
      {
        if (horz % 16)
        {
          printf("-");
        }
        else
          printf("+");
      }
      printf("\n");

      numb = 0;
      flow++;

      if (flow % 2)
        boardNumb -= 19;
      else
        boardNumb -= 1;
    }
  }
  printf("%c rolled a %d", currentB[i].gamePiece, roll);
}

//This is how i designed my board, idk how to make the game identify the special tiles and make the character move accordingly.
void myboard(){

    printf("Welcome To Snake And Ladders!");
    printf("\nPress Enter To Roll Dice And Move");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |    DT# = Go down to a tile");
    printf("\n|  37  |  38  |  39  |  40  |  41  |  42  |  43  |    GT# = Climb up to a tile");
    printf("\n|      |      |      | DT7  |      |      |      |");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |");
    printf("\n|  36  |  35  |  34  |  33  |  32  |  31  |  30  |");
    printf("\n|      |      | DT15 |      | GT39 |      |      |");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |");
    printf("\n|  23  |  24  |  25  |  26  |  27  |  28  |  29  |");
    printf("\n|      | DT20 |      |      |      | GT34 |      |");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |");
    printf("\n|  22  |  21  |  20  |  19  |  18  |  17  |  16  |");
    printf("\n|      |      |      | DT6  |      |      |      |");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |");
    printf("\n|  8   |  9   |  10  |  12  |  13  |  14  |  15  |");
    printf("\n|      | GT26 |      | DT3  |      | GT22 |      |");
    printf("\n|------|------|------|------|------|------|------|");
    printf("\n|      |      |      |      |      |      |      |");
    printf("\n|  7   |  6   |  5   |  4   |  3   |  2   |   1  |");
    printf("\n|      |      |      | GT14 |      |      |      |");
    printf("\n|------|------|------|------|------|------|------|");

}
