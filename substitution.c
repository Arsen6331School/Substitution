#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ask_for_plaintext(char input[]);

const int ERR_NOT_ENOUGH_ARGS = 1;
const int ERR_KEY_INVALID = 2;

const int LEN_INPUT = 1000;

int main(int argc, char *argv[]) 
{
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return ERR_NOT_ENOUGH_ARGS;
    }

    int keyLen = strlen(argv[1]);
    if (keyLen != 26)
    {
        printf("Key must contain 26 characters.\n");
        return ERR_KEY_INVALID;
    }

    char src[LEN_INPUT];
    ask_for_plaintext(src);

    int srcLen = strlen(src);

    char output[LEN_INPUT];

    for (int i = 0; i < srcLen; i++) {
        char replace = 0;
        if (isupper(src[i])) {
            replace = argv[1][src[i]-65];
        } else if (islower(src[i])) {
            replace = tolower(argv[1][src[i]-97]);
        } else {
            replace = src[i];
        }
        strncat(output, &replace, 1);
    }
    printf("ciphertext: %s", output);
}


void ask_for_plaintext(char input[])
{
  printf("plaintext: ");
  fgets(input, LEN_INPUT, stdin);
}