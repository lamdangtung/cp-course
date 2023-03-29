#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    string board[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    vector<pair<int, int>> pos;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == '*')
            {
                pos.push_back(make_pair(i, j));
            }
        }
    }
    sort(pos.begin(), pos.end());
    bool res = true;
    for (int i = 1; i < 8; i++)
    {
        if (pos[i].first == pos[i - 1].first)
        {
            res = false;
            break;
        }
    }
    sort(pos.begin(), pos.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right)
         { return left.second < right.second; });
    for (int i = 1; i < 8; i++)
    {
        if (pos[i].second == pos[i - 1].second)
        {
            res = false;
            break;
        }
    }
    vector<int> minus;
    vector<int> sum;
    for (int i = 0; i < 8; i++)
    {
        int mi = pos[i].first - pos[i].second;
        int su = pos[i].first + pos[i].second;
        minus.push_back(mi);
        sum.push_back(su);
    }
    sort(minus.begin(), minus.end());
    sort(sum.begin(), sum.end());
    for (int i = 1; i < 8; i++)
    {
        if (minus[i - 1] == minus[i])
        {
            res = false;
            break;
        }
        if (sum[i - 1] == sum[i])
        {
            res = false;
            break;
        }
    }
    if (res)
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }

    return 0;
}