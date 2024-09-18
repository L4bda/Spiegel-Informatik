#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Zu viele/wenige Zahlen\n");
        return 1;
    }
    int zahl = atoi(argv[1]);
    int le = (int) log10(zahl) + 1;
    int digit[(int) log10(zahl) + 1];
    for (int i = (int) log10(zahl); i >= 0; i--)
    {
        digit[i] = zahl % 10;
        if(digit[i] != 0 && digit[i] != 1)
        {
            printf("Nicht Binaer\n");
            return 1;
        }
        zahl = zahl / 10;
    }
    int total = 0;
    for (int i = 0; i < le; i++)
    {
        int d = digit[i] * pow(2, le - 1 - i);
        total += d;
    }
    printf("%i\n", total);
}
// zu deutsch: nimmt jegliche binaer zahl und multipliziert sie mit 2 hoch ihrer position als zahl
// von rechts nach links (ausgehend von 0) um sie dann zu addieren bsp.: 1010
//  0 * 2^0 = 0
//  1 * 2^1 = 2
//  0 * 2^2 = 0
//  1 * 2^3 = 8
//  0 + 2 + 0 + 8 = 10
//fuer transparenz: beide logarithmus-funktionen habe ich mir nicht ausgedacht
