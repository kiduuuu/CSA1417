#include <stdio.h>

int main() {
    char input[] =
        "int main() {\n"
        "    int x = 10;\n"
        "    x = x + 5;\n"
        "}\n";

    int whitespace = 0, newlines = 0;
    char ch;
    int i = 0;

    while ((ch = input[i++]) != '\0') {
        if (ch == ' ' || ch == '\t') {
            whitespace++;
        }
        if (ch == '\n') {
            newlines++;
        }
    }

    printf("Number of whitespace characters (space or tab): %d\n", whitespace);
    printf("Number of newline characters: %d\n", newlines);

    return 0;
}

