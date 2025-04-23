#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int player , computer = rand() % 3;
/*
    0-->STONE
    1-->PAPER
    2-->SCISSOR
*/
    printf("Disclaimer\n");
    printf("Choose \n0 for STONE\n1 for PAPER\n2 for SCISSOR\n");
    scanf("%d" , &player);
    printf("Computer: %d\n" , computer);
    
    if(player==0 && computer ==0)
    {
        printf("Draw!! :0");
    }
    else if(player ==0 &&computer == 1)
    {
        printf("You Lose :(");        
    }
    else if(player ==0 &&computer == 2)
    {
        printf("Congo!! You WIN!! :)");
    }

    else if(player ==1 &&computer == 0)
    {
        printf("Congo!! You WIN!! :)");
    }
    else if(player ==1 &&computer == 1)
    {
        printf("Draw!! :0");
    }
    else if(player ==1 &&computer == 2)
    {
        printf("You Lose :(");
    }

    else if(player ==2 &&computer == 0)
    {
        printf("You Lose :(");
    }
    else if(player ==2 &&computer == 1)
    {
        printf("Congo!! You WIN!! :)");
    }
    else if(player ==2 &&computer == 2)
    {
        printf("Draw!! :0");
    }
    else{
        printf("Please Enter the number according the rule...now rerun :|");
    }


   
    return 0;
}