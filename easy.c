#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters until a space or the start of string is encountered
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char str[104];
    scanf("%[^\n]%*c",str);
    printf("%d\n",lengthOfLastWord(str));

    return 0;
}
