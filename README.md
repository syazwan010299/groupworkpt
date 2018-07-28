Yo, waddup  
[PLEASE CREATE YOUR OWN COMPILABLE RUNNABLE FUNCTION in SEPERATE .c FILES]  
Think of it as bot(); is in its own .c file so you might have an empty main but you have ONLY your function there.  
Then do things to make it work  
Example: inside jun.c
```
#include <stdio.h>

int main(void){
    ///Something
}

void bot(){
///your code
}
```

Use the struct to integrate everyone's work.  
we have player[i].gamePiece //which player we changing values for  
we have player[i].boardPos //which position on the board do we want to move the player to.

Guys to use the dice function for your own functions:

int variable = dice();

Now variable will randomly be 1 - 6
