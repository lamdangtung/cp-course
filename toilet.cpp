/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    string ss;
    cin >> ss;

    for (int s = 1; s <= 3; s++)
    {
        char end;
        char prev = ss[0];
        if (s == 1)
        {
            end = 'U';
        }
        else if (s == 2)
        {
            end = 'D';
        }
        int count = 0;
        for (int i = 1; i < ss.size(); i++)
        {
            if (s == 3)
            {
                end = ss[i];
            }
            int space = abs(prev - ss[i]) + abs(ss[i] - end);
            count += space / ('U' - 'D');

            prev = end;
        }
        cout << count << endl;
    }
    return 0;
}
