#include <iostream>
using namespace std;
int game[100000], point[100000];
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> game[i] >> point[i];
    }
    for (int j = 0; j < t; j++)
    {
        cout<<"Team #"<<j+1<<endl;
        cout<<"Games: "<<game[j]<<endl;
        cout<<"Points: "<<point[j]<<endl;
        cout<<"Possible records:\n";
        for (int i = game[j]; i >= 0; i--)
        {
            int x = (point[j] - game[j] + i) / 2;
            int y = (3 * game[j] - point[j] - 3 * i) / 2;
            //cout<<x<<" "<<y<<" "<<i<<endl;
            if (x + y + i == game[j] && 3 * x + y == point[j]&&x>=0&&y>=0)
                cout << x << "-" << y << "-" << i << endl;
        }
        cout<<endl;
    }
    //getchar();
    //getchar();
    return 0;
}

