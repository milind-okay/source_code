#include<iostream>
using namespace std;
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

int main()
{
    float x = 2;
    int y = -2;
    cout<<power(x, y);

    return 0;
}
