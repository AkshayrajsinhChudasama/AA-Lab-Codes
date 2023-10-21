#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool compare(string a, string b, int p, int r)
{
    if (a.size() < b.size())
    {
        return false;
    }
    else
    {
        int k = 0;
        for (int i = p; i <= r; i++)
        {
            if (a[i] != b[k++])
            {
                return false;
            }
        }
        return true;
    }
}

vector<int> findmatching(string text, string pattern)
{
    if (pattern.size() > text.size())
    {
        return {};
    }
    else if (text == pattern)
    {
        return {0};
    }
    else
    {
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();
        unordered_map<char, int> lastoccur;
        int count = 0;
        for (int i = 0; i < m - 1; i++)
        {
            lastoccur[pattern[i]] = m - i - 1;
        }
        int j = m - 1, i = 0;
        while (j < n)
        {
            count++;
            if (compare(text, pattern, i, j))
            {
                ans.push_back(i);
            }
            if (lastoccur[text[j]] != 0)
            {
                i += lastoccur[text[j]];
                j += lastoccur[text[j]];
            }
            else
            {
                i += m;
                j += m;
            }
        }
        ans.push_back(count);
        return ans;
    }
}

vector<int> naivefindmatching(string text, string pattern)
{
    if (pattern.size() > text.size())
    {
        return {};
    }
    else if (text == pattern)
    {
        return {0};
    }
    else
    {
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();
        int j = m - 1, i = 0, count = 0;
        while (j < n)
        {
            count++;
            if (compare(text, pattern, i, j))
            {
                ans.push_back(i);
            }
            ++j;
            ++i;
        }
        ans.push_back(count);
        return ans;
    }
}

int main()
{
    string a = "the name is gohil the kapil the";
    string b = "the";
    vector<int> ans = naivefindmatching(a, b);
    cout << "Indices (last is the count of comparision) using the naive method are :";
    for (auto r : ans)
    {
        cout << r << " ";
    }
    cout << endl;
    vector<int> ans2 = findmatching(a, b);
    cout << "Indices (last is the count of comparision) using the horsepool are :";
    for (auto r : ans2)
    {
        cout << r << " ";
    }
    return 0;
}


