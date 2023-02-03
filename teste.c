#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char n2[] = "julia";
    char n1[] = "julaa";

    if (strcmp(n1, n2) < 0)
    {
        printf("%s\n", n1);
    }
    else
    {
        printf("%s\n", n2);
    }
    return 0;
}
