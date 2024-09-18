#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    int zahl = atoi(argv[1]);
    int laenge = (int)log2(zahl) + 1;
    int rck[laenge];
    int i = 0;
    while (zahl != 0)
    {
        rck[i]= zahl % 2;
        i++;
        zahl = zahl / 2;
    }
    for(i = laenge - 1; i >= 0; i--)
    {
        printf("%i", rck[i]); //zu faul für eine vernünftgige stack function
    }
    printf("\n");
}
//zu deutsch: sollte eine zahl / 2 keinen rest haben nimmt man für ihre stelle in der binrzahl eine 0 sonst eine 1 (den rest der dividierung)
//nun ersetzt man die zahl durch das ergebnis der vorherigen dividierung und wiederholt solange bis man bei 0 als zahl ankommt.
//dann liest man einfach die aufgeschriebenen Zahlen rückwaerts
//bsp.: 10
//10 / 2 = 5 (rest 0) 0
//5 / 2 = 2  (rest 1) 1
//2 / 2 = 1  (rest 0) 0
//1 / 2 = 0  (rest 1) 1
//rückwaerts: 1010
