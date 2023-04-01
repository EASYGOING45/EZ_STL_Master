/**
 * deque实际案例
 * 评委打分案例（sort算法排序）
 * 创建5个选手(姓名，得分)，10个评委对5个选手进行打分
 * 得分规则：去除最高分，去除最低分，取出平均分
 * 按得分对5名选手进行排名
 */

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 选手类
class Player
{
public:
    string name;
    int score;
};

// 创建选手
void Create_Player(vector<Player> &plist)
{

    string randseed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        Player player;
        player.name = "选手";
        player.name += randseed[i];
        player.score = 0;

        plist.push_back(player);
    }
}

bool myconpare(int v1, int v2)
{
    return v1 < v2;
}

// 对选手进行打分
// 打分规则：去除最高分，去除最低分，取出平均分
void Set_Player_Score(vector<Player> &plist)
{
    for (vector<Player>::iterator it = plist.begin(); it != plist.end(); it++)
    {
        deque<int> dscore; // 保存评委的十次打分
        for (int i = 0; i < 10; i++)
        {
            int score = 50 + rand() % 50;
            dscore.push_back(score);
        }
        // 排序
        sort(dscore.begin(), dscore.end(), myconpare);
        // 去除最高分和最低分
        dscore.pop_back();
        dscore.pop_front();

        // 求平均分
        int totalScore = 0;
        for (deque<int>::iterator dit = dscore.begin(); dit != dscore.end(); dit++)
        {
            totalScore += *dit;
        }
        int scoreavg = totalScore / dscore.size();
        (*it).score = scoreavg;
    }
}

bool conparePlayer(Player player1, Player player2)
{
    return player1.score > player2.score;
}
// 按照得分排名
void Show_Player_List(vector<Player> &plist)
{

    sort(plist.begin(), plist.end(), conparePlayer);
    cout << "选手得分排名:" << endl;
    for (vector<Player>::iterator it = plist.begin(); it != plist.end(); it++)
    {
        cout << "姓名:" << it->name << " 得分:" << it->score << endl;
    }
}

void test()
{

    vector<Player> plist;
    // 创建5名选手
    Create_Player(plist);
    // 对5名选手进行打分
    Set_Player_Score(plist);
    // 按照得分排名
    Show_Player_List(plist);
}
int main()
{

    test();

    return EXIT_SUCCESS;
}
