#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct userInfo
{
    char gamePiece; //X, Y, O
    int boardPos;   //position of player
    int special;    //Ignore this, this is for missing turns and shit.
};

int dice();
void buildBoard(struct userInfo currentB[], int roll, int i);
int move(struct userInfo currentB[], int i);
int specialtiles(int x);

int main()
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
    int yourMove = 0; //Who's turn is it?
    while (move(player, yourMove))
    {                      //pass all players user info
        yourMove++;        //next person's turn
        if (yourMove == 3) //after the 3rd guy, i want it back to the 1st guy
            yourMove = 0;
    }
    ///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///DEMO///
}

int dice()
{
    ///rolling the dice
    int diceNumb; //this is a LOCAL variable
    char c;
    time_t t;
    srand((unsigned)time(&t));

    //Only allow enter button
    printf("Press enter to roll the dice\n");
    c = getchar();
    while (c != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Press enter to roll the dice\n");
        c = getchar();
    }

    //rolling the dice
    do
    {
        diceNumb = rand() % 7;
    } while (diceNumb == 0);

    printf("Rolling the dice...\n%d", diceNumb);
    return diceNumb; //number is then returned to whoever called the function
}

int move(struct userInfo currentB[], int i)
{
    int roll, die;
    roll = die = dice(); //roll and die now have the dice number stored
    int flag = 0;        //this is to check if they are over tile 50 (max tile, so i want to bring them backwards)
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
        buildBoard(currentB, die, i);
    }
    if (flag == 1)
    { // Have to go back if you don't perfectly land on 50
        for (; roll > 0; roll--)
        {
            currentB[i].boardPos--;
            Sleep(500);
            system("cls");
            buildBoard(currentB, roll, i);
        }
        flag = 0;
    }
    
    if (specialtiles(currentB[i].boardPos))
    {
        system("cls");
        currentB[i].boardPos = specialtiles(currentB[i].boardPos);
        buildBoard(currentB, 0, i);
    }
    
    if (currentB[i].boardPos == 50)
    { //If the guy is on 50 Winner!
        printf("\t\t\tWinner!");
        sleep(7000);
        return 0;
    }
    else
        return 1;
}

void buildBoard(struct userInfo currentB[], int roll, int i)
{
    int numb = 0, flow = 0, boardNumb = 60, tile = 0, tempChange = 0;
    //variable tile is the most important, it knows each of the tiles number
    for (int vert = 0; vert <= 30; vert++, numb++)
    { //draws the vertical lines
        if (vert % 6)
        {
            printf("|");
            
            for (int row = 0; row < 10; row++)
            {
                ///Tile number
                if (flow % 2) //finds the right tile number through an algorithm
                    tile = boardNumb + row;
                else
                    tile = boardNumb - row;
                if (numb == 1)
                { //printf the tile number
                ///end of Tile number
                
                    if (flow % 2)
                        printf("\t%8d|", tile);
                    else
                        printf("\t%8d|", tile);
                }
                else if (numb == 2 && currentB[0].boardPos == tile)
                    printf("\t%-8c|", currentB[0].gamePiece);
                else if (numb == 3 && currentB[1].boardPos == tile)
                    printf("\t%-8c|", currentB[1].gamePiece);
                else if (numb == 4 && currentB[2].boardPos == tile)
                    printf("\t%-8c|", currentB[2].gamePiece);
                else if (numb == 5 && (tempChange = specialtiles(tile)) != 0)
                    printf("%13s%2d|", "Go to ", tempChange);
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

            numb = 0; //needs to reset for next rows after +-----+-----+
            flow++;

            //DA ALGORITHM! MUAHAHAHAAHAH!
            if (flow % 2)
                boardNumb -= 19;
            else
                boardNumb -= 1;
        }
    }
    printf("%c rolled a %d\n", currentB[i].gamePiece, roll); //prints the dice roll and the guy who rolled it
}

int specialtiles(int x)
{
    switch (x)
    {
    case 4:
        return 14;
        break;
    case 9:
        return 26;
        break;
    case 12:
        return 3;
        break;
    case 45:
        return 22;
        break;
    case 19:
        return 6;
        break;
    case 24:
        return 20;
        break;
    case 28:
        return 34;
        break;
    case 47:
        return 39;
        break;
    case 49:
        return 15;
        break;
    case 40:
        return 7;
        break;
    default:
        return 0;
    }
}