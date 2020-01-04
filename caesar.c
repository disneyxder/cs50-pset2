#include <cs50.h>
#include <stdio.h>

void invalid(void);

int main(void)
{
    long input, cc1, cc2, cc3;
    input = get_long("Number: ");
    cc1 = input;
    cc2 = input;
    cc3 = input;

    int count = 0;
    while (cc1 > 0)
    {
        count++;
        cc1 /= 10;
    }

    if (count != 13 && count != 15 && count != 16)
    {
        invalid();
    }
    else
    {
        int countsecond = count / 2, countnonsecond = count - count / 2, sum1, sum2;
        int seconddigit[countsecond], nonseconddigit[countnonsecond], doubleseconddigit[countsecond], multipliedsum[countsecond],
            nonmultipliedsum[countnonsecond];
        for (int i = 0; i < countsecond; i++)
        {
            seconddigit[i] = (cc2 % 100) / 10;
            cc2 /= 100;
            doubleseconddigit[i] = seconddigit[i] * 2;
            if (i != 0)
            {
                multipliedsum[0] = doubleseconddigit[0] / 10 + doubleseconddigit[0] % 10;
                multipliedsum[i] = multipliedsum[i - 1] + doubleseconddigit[i] / 10 + doubleseconddigit[i] % 10;
                sum1 = multipliedsum[i];
            }
        }
        for (int j = 0; j < countnonsecond; j++)
        {
            nonseconddigit[j] = (cc3 % 10);
            cc3 /= 100;
            if (j != 0)
            {
                nonmultipliedsum[0] = nonseconddigit[0];
                nonmultipliedsum[j] = nonseconddigit[j] + nonmultipliedsum[j - 1];
                sum2 = nonmultipliedsum[j];
            }
        }
        if ((sum1 + sum2) % 10 != 0)
        {
            invalid();
        }
        else
        {
            if (count == 13)
            {
                if (nonseconddigit[6] == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    invalid();
                }
            }
            if (count == 15)
            {
                if (nonseconddigit[7] == 3)
                {
                    if (seconddigit[6] == 4 || seconddigit[6] == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        invalid();
                    }
                }
            }
            if (count == 16)
            {
                if (seconddigit[7] == 4)
                {
                    printf("VISA\n");
                }
                else if (seconddigit[7] == 5)
                {
                    if (nonseconddigit[7] == 1 || nonseconddigit[7] == 2 || nonseconddigit[7] == 3 || nonseconddigit[7] == 4 ||
                        nonseconddigit[7] == 5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        invalid();
                    }
                }
                else
                {
                    invalid();
                }
            }
        }
    }
}

void invalid(void)
{
    printf("INVALID\n");
}
