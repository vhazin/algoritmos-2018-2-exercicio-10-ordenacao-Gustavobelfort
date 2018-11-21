#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


void receiveNames(int number) {

    int plusCounter = 0;
    int minusCounter = 0;
    char * str[number][24], temp; 
    char t[21];
    int i, j;

    for(i=0; i<number; i++)
    {
        scanf(" %c%s", &temp, &str[i]);
        if(temp == '+')
          plusCounter++;
        else
          minusCounter++;
    }

    for(i=1; i<number; i++)
    {
        for(j=1; j<number; j++)
        {
            if(strcmp(str[j-1], str[j])>0)
            {
                strcpy(t, str[j-1]);
                strcpy(str[j-1], str[j]);
                strcpy(str[j], t);
            }
        }
    }

    for(i=0; i<number; i++)
    {
        if(str[i][0] == '+')
            plusCounter++;
        else if(str[i][0] ==  '-')
            minusCounter++;
            
        printf("%s\n",str[i]);
    }
        printf("Se comportaram: %d | Nao se comportaram: %d\n", plusCounter, minusCounter);
}


int main() {
    int iterationNumber;
    scanf("%d", &iterationNumber);
    receiveNames(iterationNumber);
   return 0;
}