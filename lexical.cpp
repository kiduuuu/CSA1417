#include <stdio.h>
#include <ctype.h>

int main() {
    char str[500];
    int i, characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter the text (end input with ~):\n\n");
    scanf("%[^~]", str);  // Read input until '~' character

    for (i = 0; str[i] != '\0'; i++) {
        characters++;

        if (str[i] == '\n') {
            lines++;
        }

        if (isspace(str[i]) || str[i] == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    // If input is not empty, count last line
    if (characters > 0)
        lines++;

    printf("\n===== Lexical Analysis Result =====\n");
    printf("Total Characters : %d\n", characters);
    printf("Total Words      : %d\n", words);
    printf("Total Lines      : %d\n", lines);

    return 0;
}

