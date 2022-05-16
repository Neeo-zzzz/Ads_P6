#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <time.h>
using namespace std;
vector<pair<int, int>> readlist(string i)
{
    vector<pair<int, int>> m;
    ifstream infile;
    int a, b;
    string file1 = i + ".txt";
    infile.open(file1);
    while (infile >> a && infile >> b)
        m.emplace_back(make_pair(b, a));
    infile.close();
    sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });
    return m;
}
pair<int, vector<pair<int, int>>> readlist1(string i)
{
    vector<pair<int, int>> m;
    ifstream infile;
    int a, b, width, num, index;
    string file1 = i + ".txt";
    infile.open(file1);
    infile >> num;
    infile >> width;
    while (infile >> index && infile >> a && infile >> b)
        m.emplace_back(make_pair(b, a));
    infile.close();
    sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });
    cout << "num" << num;
    return make_pair(width, m);
}
double NFDH_1(vector<pair<int, int>> m, int width)
{
    int height = 0;
    int OPT_H = 200;
    int tmp_W = 0;
    for (auto p : m)
    {
        if (tmp_W == 0)
        {
            height += p.first;
            tmp_W = p.second;
            continue;
        }
        if (p.second + tmp_W <= width)
            tmp_W += p.second;
        else
        {
            tmp_W = p.second;
            height += p.first;
        }
    }
    double ans = 1.0 * height / OPT_H;
    return ans;
}

int main()
{
    clock_t start, end;
    vector<pair<int, int>> m;
    vector<string> s1 = {"17_1", "17_2", "17_3", "17_4", "17_5"};
    vector<string> s2 = {"25_1", "25_2", "25_3", "25_4", "25_5"};
    vector<string> s3 = {"29_1", "29_2", "29_3", "29_4", "29_5"};
    vector<string> s4 = {"49_1", "49_2", "49_3", "49_4", "49_5"};
    vector<string> s5 = {"73_1", "73_2", "73_3", "73_4", "73_5"};
    vector<string> s6 = {"97_1", "97_2", "97_3", "97_4", "97_5"};
    vector<string> s7 = {"197_1", "197_2", "197_3", "197_4", "197_5"};
    // time and performance for NFDH
    vector<vector<string>> s = {s1, s2, s3, s4, s5, s6, s7};
    double ans = 0.0, t = 0.0;

    for (auto tmp : s)
    {
        ans = 0.0, t = 0.0;
        for (auto a : tmp)
        {
            m = readlist(a);
            start = clock();
            ans += NFDH_1(m, 200);
            end = clock();
            // t += double(end - start) / CLOCKS_PER_SEC;
            t += double(end - start);
        }
        ans = ans / 5;
        t = t / 5.0;
        cout << "ans:" << ans << " time:" << t << endl;
    }

    cout << "time test" << endl;
    vector<string> time_test = {"zdf1", "zdf2", "zdf3", "zdf4", "zdf5", "zdf6", "zdf7", "zdf8", "zdf9", "zdf10", "zdf11", "zdf12", "zdf13", "zdf14", "zdf15", "zdf16"};
    int width = 0;
    for (auto a : time_test)
    {
        t = 0.0;
        width = readlist1(a).first;
        m = readlist1(a).second;
        start = clock();
        NFDH_1(m, width);
        NFDH_1(m, width);
        NFDH_1(m, width);
        NFDH_1(m, width);
        NFDH_1(m, width);
        end = clock();
        // t += double(end - start) / CLOCKS_PER_SEC;
        t = double(end - start);
        cout << " time:" << t << endl;
    }
}