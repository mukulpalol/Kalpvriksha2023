/******************************************************************************
C program to arrange words in lexicographical order
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50

int main(){
    int num_words = 0;
    int max_word;
    printf("Enter number of words: ");
    scanf("%d", &max_word);
    char words[max_word][MAX_WORD_LENGTH];
    printf("Enter %d words:\n", max_word);
    while(num_words < max_word && scanf("%s", words[num_words]) == 1){
        num_words++;
    }
    for(int i = 0; i < num_words - 1; i++){
        for(int j = 0; j < num_words - i - 1; j++){
            if(strcmp(words[j], words[j+1]) > 0){
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
    }
    printf("\nLexicographical Order:\n");
    for(int i = 0; i < num_words; i++){
        printf("%s\n", words[i]);
    }
    return 0;
}