/**
 * 用户邮箱地址验证
 * 1、判断邮箱有效性 是否包含 @ 和 . 且 . 在 @ 后面
 * 2、判断用户输入的用户名中是否包含除了小写字母之外字符(ASCII范围97~122)
 * 3、判断用户输入的邮箱地址是否正确(chdlyx@qq.com)
 */

#include <iostream>
#include <string>
using namespace std;

// 1、判断邮箱有效性，是否包含@和.且.在@后面
bool Check_Valid(string &email)
{
    int pos1 = email.find("@");
    int pos2 = email.find(".");
    // 判断@和.是否存在
    if (pos1 == -1 || pos2 == -1)
    {
        return false;
    }
    // 判断.是否在@后面
    if (pos1 > pos2)
    {
        return false;
    }
    return true;
}

// 2、判断用户输入的用户名中是否包含除了小写字母之外字符(ASCII范围97~122)
bool Check_Username(string &email)
{
    int pos = email.find("@");
    string username = email.substr(0, pos - 1); // 截取用户名 0~pos-1 个字符
    for (string::iterator it = username.begin(); it != username.end(); it++)
    {
        if (*it < 97 || *it > 122)
        {
            return false;
        }
    }
    return true;
}

// 3、判断用户输入的邮箱地址是否正确
bool Check_EqualTo(string &email)
{
    string ans = "chdlyx@qq.com";
    if (email.compare(ans) == 0)
    {
        return true;
    }
    return false;
}

void testEmail()
{
    string email;
    cout << "请输入您的邮箱:" << endl;
    cin >> email;

    bool flag = Check_Valid(email);
    if (!flag)
    {
        cout << "Email格式不正确" << endl;
        return;
    }
    flag = Check_Username(email);
    if (!flag)
    {
        cout << "用户名中包含非小写字母字符" << endl;
        return;
    }
    flag = Check_EqualTo(email);
    if (!flag)
    {
        cout << "邮箱地址不正确" << endl;
        return;
    }
    cout << "邮箱地址正确" << endl;
}

int main()
{
    testEmail();
    return 0;
}