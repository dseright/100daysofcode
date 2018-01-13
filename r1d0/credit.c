#include <stdio.h>
#include <cs50.h>

long long card;
int checksum = 0;

int main(void)
{
    do
    {
        // prompt for long long
        card = get_long_long("Card Number: ");
    }
    while (card <= 0);

    long long position = 1;
    // for loop to multiply every second digit starting from second to last by 2 and add the digits of the product to checksum
    // and to add each other single digit in there.
    for (int i = 1; i < 17; i++, position *= 10)
    {
        // check to see if very first iteration, probably ended up not needing this due to loop changes
        if (i == 1)
        {
            // simple equation to add that value since it's the first digit
            checksum = card % 10;
        }
        // check to see if it's one of the every other digits
        else if (i % 2 == 0)
        {
            // the basic math to add double that digit's value
            int working = ((card % (position * 10)) / position) * 2;
            // the check to account for extra rollover digits
            if (working > 9)
            {
                checksum = checksum + 1 + (working % 10);
            }
            else
            {
                checksum += working;
            }
        }
        else
        {
            // the basic equation to add that value to the checksum
            checksum = checksum + ((card % (position * 10)) / position);
        }
    }
    // first test to see if the checksum is valid
    if (checksum % 10 == 0)
    {
        // test if the card is 13 or 16 digits and starts with a 4
        if (card / 1000000000000000 == 4 || card / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        // test to see if the card starts with 51, 52, 53, 54 or 55
        else if (card / 100000000000000 < 56 && card / 100000000000000 > 50)
        {
            printf("MASTERCARD\n");
        }
        // check to see if 15 digits and starts with 34 or 37
        else if (card / 10000000000000 == 34 || card / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        // otherwise it passes the checksum but does not fit into one of the 3 given card categories so still invalid
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }


    return 0;
}

