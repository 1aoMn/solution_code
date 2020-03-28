#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int length[25], nextTimeAnya[90000], nextTimeArup[90000], whoTime[90000];
int days;
int main()
{
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        memset(whoTime, 0, sizeof(whoTime));
        memset(nextTimeArup, 0, sizeof(nextTimeArup));
        memset(nextTimeAnya, 0, sizeof(nextTimeAnya));
        cout << "CD #" << kase << ":\n";
        int n, likePos, preLength = 0, sumLength = 0;
        cin >> n >> likePos;
        for (int i = 1; i <= n; i++)
        {
            cin >> length[i];
            if (i < likePos)
                preLength += length[i];
            sumLength += length[i];
        }
        //0是Arup 1是Anya
        for (int i = preLength + 1; i <= preLength + length[likePos]; i++)
            whoTime[i] = 1;
        for (int i = 1; i <= sumLength; i++)
            nextTimeArup[i] = i % sumLength + 1;
        for (int i = preLength + 1; i < preLength + length[likePos]; i++)
            nextTimeAnya[i] = (i + 1);
        nextTimeAnya[preLength + length[likePos]] = preLength + 1;
        cin >> days;
        for (int i = 1; i <= days; i++)
        {
            int num, evyLength, nowTime = preLength + 1, ans = 0;
            cin >> num;
            for (int j = 1; j <= num; j++)
            {
                cin >> evyLength;
                for (int k = 1; k < evyLength; k++)
                {
                    ans += whoTime[nowTime];
                    nowTime = (j % 2 == 1 ? nextTimeAnya[nowTime] : nextTimeArup[nowTime]);
                }
                //最后一秒的情况，如果以Arup结束，下一次从Anya喜欢的歌开始
                ans += whoTime[nowTime];
                nowTime = (j % 2 == 1 ? nextTimeArup[nowTime] : preLength + 1);
            }
            cout << ans << endl;
        }
        cout << endl;
    }
    return 0;
}