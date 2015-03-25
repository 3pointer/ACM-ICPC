#include <stdio.h>
#include <string.h>

int main()
{
    char male[30];
    char female[30];
    char fm[20];
    char ffm[20];
    while(scanf("%s %s", male, female) != EOF)
    {
        for (int i = 0; male[i] != '\0'; i ++) 
        if (male[i] == '_')
        {
            int j;
            i ++;
            for (j = 0; male[j + i] != '\0'; j ++)
                fm[j] = male[j + i];
            fm[j] = '\0';
            break;
        }
        for (int i = 0; female[i] != '\0'; i ++) 
        if (female[i] == '_')
        {
            int j;
            i ++;
            for (j = 0; female[j + i] != '\0'; j ++)
                ffm[j] = female[j + i];
            ffm[j] = '\0';
            break;
        }
        printf("%s_small_%s\n", fm, ffm);
    }
    return 0;
}
