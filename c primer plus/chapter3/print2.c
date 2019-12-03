#include <stdio.h>

int main()
{
    unsigned int un = 300000000;
    short end = 200;
    long big = 65537;
    long long verybig = 1245115862358785;

    printf("un = %u not %d\n", un, un);
     printf("end = %hd not %d\n", end, end);
      printf("bigun = %ld not %hd\n", big, big);
       printf("verybig = %lld not %ld\n", verybig, verybig);
    return 0;
}