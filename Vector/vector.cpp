#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int *p = NULL;
    int count = 0; // 统计vector容量增长几次？
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            count++;
        }
    }
    cout << "count:" << count << endl; // 打印出30
}