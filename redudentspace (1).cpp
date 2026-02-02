#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a keyword
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "main","auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef",
        "unsigned","void","printf","while"
    };

    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[50], operators[] = "+-*/%=<>";
    FILE *fp;
    char filename[100];
    int i, j = 0;

    // Ask user for file name
    printf("Enter the input file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Check for operators
        for (i = 0; i < strlen(operators); i++) {
            if (ch == operators[i]) {
                printf("%c is operator\n", ch);
                break;
            }
        }

        // Build token (identifiers, keywords, numbers)
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t' || 
                    ch == ';' || ch == '(' || ch == ')' || 
                    ch == '{' || ch == '}' || ch == ',') && j != 0) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
                printf("%s is keyword\n", buffer);
            else if (isdigit(buffer[0]))
                printf("%s is number\n", buffer);
            else
                printf("%s is identifier\n", buffer);
        }
    }

    // Check last token before EOF
    if (j != 0) {
        buffer[j] = '\0';
        if (isKeyword(buffer))
            printf("%s is keyword\n", buffer);
        else if (isdigit(buffer[0]))
            printf("%s is number\n", buffer);
        else
            printf("%s is identifier\n", buffer);
    }

    fclose(fp);
    return 0;
}

