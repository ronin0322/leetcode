

// https://www.nowcoder.com/practice/de538edd6f7e4bc3a5689723a7435682?tpId=37&tqId=21241&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=undefined&judgeStatus=undefined&tags=&title=
#include <bits/stdc++.h>
using namespace std;

bool Check(string ip, string mask)
{
    bool is_mask = true;
    bool is_ip;
    istringstream sip(ip);
    string ip_num;
    while (getline(sip, ip_num, '.'))
    {

        if (ip_num.size() == 0)
            return false;
        auto num = atoi(ip_num.c_str());
        if (num < 0 || num > 255)
            return false;
    }
    istringstream smask(mask);
    string mask_num;
    long long all_mask = 0;
    while (getline(smask, mask_num, '.'))
    {

        if (mask_num.size() == 0)
            return false;
        auto num = atoi(mask_num.c_str());
        // cout<<num<<endl;
        all_mask = (all_mask << 8) + num;
        if (num < 0 || num > 255)
            return false;
    }
    // cout<<all_mask<<endl;
    if (all_mask % 2 == 1)
        return false;
    while (all_mask % 2 == 0)
    {
        // cout<<all_mask<<endl;
        // printf("%x\n",all_mask);
        all_mask = all_mask >> 1;
    }
    if (all_mask == 0)
        return false;
    while (all_mask % 2 == 1)
    {
        // printf("%x\n",all_mask);
        all_mask = all_mask >> 1;
    }
    if (all_mask > 0)
        return false;
    return true;
}

vector<int> GetIp(string s)
{
    vector<int> res;
    istringstream sip(s);
    string ip_num;
    while (getline(sip, ip_num, '.'))
    {
        res.push_back(atoi(ip_num.c_str()));
    }
    return res;
}

int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, pri = 0;
    string s;
    while (cin >> s)
    {
        istringstream sin(s);
        string ip;
        string mask;
        getline(sin, ip, '~');
        getline(sin, mask, '~');
        // cout<<ip <<" "<<mask<<endl;
        auto arr_ip = GetIp(ip);
        // for (auto x : arr_ip)
        //     cout << x << " ";
        // cout << endl;
        if (arr_ip[0] == 0 || arr_ip[0] == 127)
            continue;
        if (!Check(ip, mask))
        {
            err++;
            continue;
        }
        if (arr_ip[0] >= 1 && arr_ip[0] <= 126)
            a++;
        if (arr_ip[0] >= 128 && arr_ip[0] <= 191)
            b++;
        if (arr_ip[0] >= 192 && arr_ip[0] <= 223)
            c++;
        if (arr_ip[0] >= 224 && arr_ip[0] <= 239)
            d++;
        if (arr_ip[0] >= 240 && arr_ip[0] <= 255)
            e++;
        if (arr_ip[0] == 10)
            pri++;
        if (arr_ip[0] == 172 && arr_ip[1] >= 16 && arr_ip[1] <= 31)
            pri++;
        if (arr_ip[0] == 192 && arr_ip[1] == 168)
            pri++;
    }
    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, err, pri);
}
// 64 位输出请用 printf("%lld")