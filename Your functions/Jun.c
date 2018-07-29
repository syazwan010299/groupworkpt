#include <stdio.h>
#include <stdlib.h>

struct playerInfo{
    int Pos;
};

int main()
{
    int turn, diceRoll = 5;
    struct playerInfo X,Y;
    char c;
    X.Pos = 0;
    Y.Pos = 0;
    printf("Please choose who to play first: \n");
    printf("Press 1 to play first\n");
    printf("Press 2 to let computer play first\n");
    scanf("%d",&turn);

    switch(turn){
    case 1:
            do{
                printf("your turn : \n");
                printf("Press enter to roll dice: \n");
                c = getch();
                if (c ='\n'){
                printf("%d\n",diceRoll);}
                X.Pos += diceRoll;
                printf("Your position: %d\n",X.Pos);
                if(X.Pos>=100){
                printf("YOU WIN!!!");
                break;
                }
            else{
                printf("Computer's turn:\n");
                printf("Rolling dice...\n");
                printf("%d\n",diceRoll);
                Y.Pos += diceRoll;
                printf("Computer's position: %d\n",Y.Pos);
            }
                if (Y.Pos>=100){
                    printf("YOU LOSE!!!");
                    break;
                }else
                continue;
            }while ((X.Pos<100)||(Y.Pos<100));

    case 2:
        do{
                printf("Computer's turn:\n");
                printf("Rolling dice...\n");
                printf("%d\n",diceRoll);
                Y.Pos += diceRoll;
                printf("Computer's position: %d\n",Y.Pos);
                if (Y.Pos>=100){
                    printf("YOU LOSE!!!");
                    break;
                }
                else {
                printf("your turn : \n");
                printf("Press enter to roll dice: \n");
                c = getch();
                if (c ='\n'){
                printf("%d\n",diceRoll);}
                X.Pos += diceRoll;
                printf("Your position: %d\n",X.Pos);
                }
                if(X.Pos>=100){
                printf("YOU WIN!!!");
                break;
                 }else
                continue;
            }while ((X.Pos<100)||(Y.Pos<100));
    }
}

