#include <iomanip>
#include<bits/stdc++.h>
#include <cmath>
using namespace std;
int pr[1766667],no[10000];
using namespace std ;

int main ()
{
    int us,us1, prime,pos=2 ;
    int i,j;
    bool flag1 = false,flag2 = false;
    pr[0]=2;
    pr[1]=3;
    for(i=1;i<1666666;i++)
    {
        flag1=false;
        flag2=false;
        us=(6*i)+1;
        us1=us-2;

        for( j = 2; j < static_cast<int>(sqrt(us) + 1) ; j++)
    {
        if (us % j == 0)
            {
                flag1 = true;

            }
        if (us1 % j == 0)
            {
                flag2 = true;

            }


    }

    if(flag2==false)
    {
        pr[pos++]=us1;
    }

    if(flag1==false)
    {
        pr[pos++]=us;
    }

    }
    pos=0;
   /* for(i=2;i<1000;i++)
    {
    flag1=false;

        for( j = 2; j < static_cast<int>(sqrt(i) + 1); j++)
    {
        if (i % j == 0)
            {
                flag1 = true;
                break;
            }

    }
    if(flag1==false)
    {
        no[pos++]=i;
    }

    }*/



return 0;
}

