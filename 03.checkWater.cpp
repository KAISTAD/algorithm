/*
Don't delete this comment!
이 주석을 지우지 마십시오.
------------------------------
이름 : 03.checkWater.cpp
설명 : 물 옮기기
*/

#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int global_k;

int val_cmp(int *p1, int *p2, int cnt)
{
        int i;

        for (i = 0; i < cnt; i++)
        {
                if (p1[i] != p2[i])        return 0;
        }

        return 1;
}

void playTube(int *narray, int n, int *ngoal, int *earray[2], int e, int *way[3])
{
    int i;
    int k = 0;
    int elen = e;
    int nlen = n;
    int *nminus = (int *) malloc (nlen);
    
        way[0] = (int *) malloc (2 * n * n);
    way[1] = (int *) malloc (2 * n * n);
    way[2] = (int *) malloc (2 * n * n);

    for(i = 0; i < nlen; i++)
        {
        nminus[i] = narray[i] - ngoal[i];
    }
    
    int *lowtubecnt = (int *) malloc (nlen);
    int low = 0;
    
        for(i = 0; i < nlen; i++) lowtubecnt[i] = 0;

        for(i = 0; i < elen; i++)
        {
        lowtubecnt[earray[0][i] - 1]++;
        lowtubecnt[earray[1][i] - 1]++;
    }
    
        for(i = 1; i < nlen; i++)
        {
        if(lowtubecnt[low] > lowtubecnt[i]) low = i;
    }
    
    while(true)
        {
        int goin = 0xff;
        int golow = 0;
        for(i = 0; i < elen; i++)
                {
            if(earray[0][i] - 1 == low)
                        {
                if(goin > nminus[earray[1][i] - 1])
                                {
                    golow = earray[1][i] - 1;
                    goin = nminus[golow];
                }
            }
        }

        int minus;

                minus = abs(nminus[low]) < abs(nminus[golow]) ? nminus[golow] : nminus[low];

                way[0][k] = nminus[low] > nminus[golow] ? low : golow;
        way[1][k] = nminus[low] > nminus[golow] ? golow : low;
        way[2][k] = abs(minus);

                narray[way[0][k]] -= way[2][k];
                narray[way[1][k]] += way[2][k];

        k++;

                if (val_cmp(narray, ngoal, nlen)) break;

                low = golow;
    }
    
    free(lowtubecnt);
    free(nminus);
    
    global_k = k;
}

int main()
{
        int i, n, v, e, *narray = NULL, *ngoal = NULL, *earray[2] = { NULL, NULL };

        scanf("%d %d %d", &n, &v, &e);
    
    narray = (int *)malloc(n);
    ngoal  = (int *)malloc(n);
    
    if (e > 0)
    {
         earray[0] = (int *)malloc(e);
         earray[1] = (int *)malloc(e);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &narray[i]);
    }
    
    for (i = 0; i < n; i++)
        {
        scanf("%d", &ngoal[i]);
    }
    
    for(i = 0; i < e; i++)
        {
        scanf("%d %d", &earray[0][i], &earray[1][i]);
    }
    
        
        int *callback[3] = { NULL, NULL, NULL };
                
        playTube(narray, n, ngoal, earray, e, callback);
    
    printf("%d\n", global_k);
    
    for(i = 0; i < global_k; i++){
        printf("%d %d %d", callback[0][i] + 1, callback[1][i] + 1, callback[2][i]);
    }
    
        for (i = 0; i < 3; i++)
        {
                if (callback[i])
                        free(callback[i]);
        }

        if (narray)
                free(narray);

    if(ngoal)
            free(ngoal);

    
        for (i = 0; i < 2; i++)
        {
                if(earray[i])
                        free(earray[i]);
        }

    system("pause >nul");

    return 0;
}
