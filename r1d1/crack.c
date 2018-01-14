#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int passwordfound = 0;
string foundpassword;
void lettercycle(int passsize);
char passarray[5];
char saltarray[2];
string hash;

int main(int argc, string argv[])
{
    // arguments check
    if (argc != 2)
    {
        printf("One single hashed password please.");
        return 1;
    }
    hash = argv[1];
    // Create a string with the first 2 characters of hash.
    saltarray[0] = hash[0];
    saltarray[1] = hash[1];
    // loop that builds a password to test against the given hash
    for (int j = 2; j < 7; j++)
    {
        passarray[j - 1] = '\0';
        lettercycle(j);
        if(passwordfound == 1)
        {
            printf("%s\n", foundpassword);
            return 0;
        }
    }
}

// function that loops through each alphabetical character
void lettercycle(int passsize)
{
    for (int i = 0; i < 52; i++)
    {
        if (passwordfound == 1)
        {
            return;
        }
        int ascii;
        // set ascii variable to character to check
        if (i < 26)
        {
            ascii = i + 65;
        }
        else
        {
            ascii = i + 71;
        }
        passarray[passsize - 2] = ascii;
        string testhash = crypt(passarray, saltarray);
        if (strcmp(hash, testhash) == 0)
        {
            foundpassword = passarray;
            passwordfound = 1;
            return;
        }
        if (passsize > 2)
        {
            lettercycle(passsize - 1);
        }
    }
}