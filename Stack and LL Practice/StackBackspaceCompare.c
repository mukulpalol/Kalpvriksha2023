/* 
PuneetTanwar Question:
Stack Question: Determine if two strings, s and t, are equivalent after simulating the typing of each string in an empty text editor, accounting for the effect of backspace characters. 
A backspace character removes the character preceding it, and if there are no characters to remove, the text remains empty. If the final result of the two simulations is the same, the function should return true.
'#' means a backspace character. 
*/

#include <stdio.h>
#include <ctype.h>

char stackS[100];
char stackT[100];
int topS=-1;
int topT=-1;

void pushS(char x)
{
    stackS[++topS]=x;
}
char popS()
{
    if(topS==-1)
        return -1;
    else
        return stackS[topS--];
}

void pushT(char x)
{
    stackT[++topT]=x;
}
char popT()
{
    if(topT==-1)
        return -1;
    else
        return stackT[topT--];
}

int main()
{
    char stringS[100], stringT[100];
    char inputChar, x;
    printf("Enter String S:\n");
    scanf("%[^\n]%*c",stringS);
    
    printf("Enter String T:\n");
    scanf("%[^\n]%*c",stringT);
    
    for(int i=0;stringS[i]!='\0';i++)
    {
        inputChar=stringS[i];
        if(inputChar=='#'){
            popS();
        }
        else{
            pushS(inputChar);
        }
    }
    for(int i=0;stringT[i]!='\0';i++)
    {
        inputChar = stringT[i];
        if(inputChar=='#'){
            popT();
        }
        else{
            pushT(inputChar);
        }
    }
    
    if(topT!=topS){
        printf("false");
        return 0;
    }
    else{
        for(int i=0;i<=topS;i++){
            if(stackS[i]!=stackT[i]){
                printf("false");
                return 0;
            }
        }
    }
    printf("true");
    return 0;
}
