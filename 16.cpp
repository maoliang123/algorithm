// 给出一个仅包含字母的字符串，不包含空格，统计字符串中各个字母（区分大小写）出现的次数，
// 并按照字母出现次数从大到小的顺序输出各个字母及其出现次数。如果次数相同，按照自然顺序进行排序，且小写字母在大写字母之前。
// 输入描述:
// 输入一行，为一个仅包含字母的字符串。
// 输出描述:
// 按照字母出现次数从大到小的顺序输出各个字母和字母次数，用英文分号分隔，注意末尾的分号；字母和次数间用英文冒号分隔。
#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <algorithm>

namespace sixteen
{
    bool cmp(pair<char, int> pairFirst, pair<char, int> pairSecond)
    {
        return pairFirst.second > pairSecond.second;
    }

    std::string process(const std::string& str)
    {
        std::map<char, int> mapCharFirst;
        std::map<char, int> mapCharSecond;
        std::string resultFirst = "", resultSecond = "";
        mapCharFirst.clear();
        mapCharSecond.clear();

        for (int i = 0; i < str.length(); i++)
        {
            char key = str[i];
           if (key >= 'a' && key <= 'z')
            {
                if (mapCharFirst.count(key))
                {
                    mapCharFirst[key]++;
                }
                else
                {
                    mapCharFirst[key] = 1;
                }
            }
            else if (key >= 'A' && key <= 'Z')
            {
                if (mapCharSecond.count(key))
                {
                    mapCharSecond[key]++;
                }
                else
                {
                    mapCharSecond[key] = 1;
                }
            }
        
        }
        std::vector<pair<char, int>> vecFirst, vecSecond;
        for(map<char, int>::iterator it = mapCharFirst.begin(); it != mapCharFirst.end(); it++)
        {
            vecFirst.push_back(pair<char, int>(it->first,it->second));
        }
        sort(vecFirst.begin(),vecFirst.end(),cmp);

        for(map<char, int>::iterator it = mapCharSecond.begin(); it != mapCharSecond.end(); it++)
        {
            vecSecond.push_back(pair<char, int>(it->first,it->second));
        }
        sort(vecSecond.begin(),vecSecond.end(),cmp);

        for (std::vector<pair<char, int>>::const_iterator it = vecFirst.begin(); it != vecFirst.end(); it++)
        {
            resultFirst.push_back(it->first);
            resultFirst += ':' + std::to_string(it->second) + ';';
        }

        for (std::vector<pair<char, int>>::const_iterator it = vecSecond.begin(); it != vecSecond.end(); it++)
        {
            resultSecond.push_back(it->first);
            resultSecond += ':' + std::to_string(it->second) + ';';
        }

        return resultFirst + resultSecond;
    }

    void test()
    {
        std::string str1 = "abababb";
        std::string strResult1 = process(str1);
        std::string str = "xyxyXX";
        std::string strResult = process(str);
    }
}