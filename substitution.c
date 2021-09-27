#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ask_for_plaintext(char input[]);

const int ERR_INVALID_ARGS = 1;
const int ERR_KEY_INVALID = 2;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return ERR_INVALID_ARGS;
    }

    int keyLen = strlen(argv[1]);
    if (keyLen != 26)
    {
        printf("Key must contain only 26 characters.\n");
        return ERR_KEY_INVALID;
    }
    char encountered[27] = "";
    for (int i = 0; i < 26; i++)
    {
        if (strchr(encountered, argv[1][i]) != NULL || !isalpha(argv[1][i]))
        {
            printf("Key must contain each character only once.\n");
            return ERR_KEY_INVALID;
        }
        strncat(encountered, &argv[1][i], 1);
    }


    char src[1000];
    ask_for_plaintext(src);

    int srcLen = strlen(src);

    char output[1000] = "";

    for (int i = 0; i < srcLen; i++)
    {
        char replace = 0;
        if (isupper(src[i]))
        {
            replace = toupper(argv[1][src[i] % 65]);
        }
        else if (islower(src[i]))
        {
            replace = tolower(argv[1][src[i] % 97]);
        }
        else
        {
            replace = src[i];
        }
        strncat(output, &replace, 1);
    }
    printf("ciphertext: %s", output);
}


void ask_for_plaintext(char input[])
{
    printf("plaintext: ");
    fgets(input, 1000, stdin);
}