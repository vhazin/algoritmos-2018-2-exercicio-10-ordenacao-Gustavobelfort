#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


void receiveNames(int number) {

    int plusCounter = 0;
    int minusCounter = 0;
    char * str[number+1][21]; 
    char t[21];
    int i, j;

    for(i=0; i<number+1; i++)
    {
        fgets(str[i], 21, stdin);
    }

    for(i=1; i<number+1; i++)
    {
        for(j=1; j<number+1; j++)
        {
            if(strcmp(str[j-1], str[j])>0)
            {
                strcpy(t, str[j-1]);
                strcpy(str[j-1], str[j]);
                strcpy(str[j], t);
            }
        }
    }
     for(i=0; i<number+1; i++)
    {
        if(str[i][0] == '+')
            plusCounter++;
        else if(str[i][0] ==  '-')
            minusCounter++;
        
        if (str[i][0] == '-' || str[i][0] == '+') 
            memmove(str[i], str[i]+2, strlen(str[i]));

        printf("%s",str[i]);
    }

        printf("\nSe comportaram: %d | Nao se comportaram: %d\n", plusCounter, minusCounter);
}



void main() {
    int iterationNumber;
    scanf("%d", &iterationNumber);
    receiveNames(iterationNumber);
}