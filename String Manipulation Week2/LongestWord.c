/******************************************************************************
C program to find the longest word in a sentence
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char sentence[100];
    int sentence_length;
    printf("Enter a sentence: ");
    scanf("%[^\n]%*c", sentence);
    sentence_length = strlen(sentence);
    char *word_start = sentence;
    char *longest_word_start = sentence;
    int longest_word_length = 0;
    for(int i = 0; i <= sentence_length; i++){
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\0'){
            int word_length = i - (word_start - sentence);
            if(word_length > longest_word_length){
                longest_word_length = word_length;
                longest_word_start = word_start;
            }
            word_start = sentence + i + 1;
        }
    }
    char longest_word[MAX_LENGTH];
    strncpy(longest_word, longest_word_start, longest_word_length);
    longest_word[longest_word_length] = '\0';
    printf("The longest word is: %s\n", longest_word);
    return 0;
}