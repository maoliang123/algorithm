// 给出一个仅包含字母的字符串，不包含空格，统计字符串中各个字母（区分大小写）出现的次数，
// 并按照字母出现次数从大到小的顺序输出各个字母及其出现次数。如果次数相同，按照自然顺序进行排序，且小写字母在大写字母之前。
// 输入描述:
// 输入一行，为一个仅包含字母的字符串。
// 输出描述:
// 按照字母出现次数从大到小的顺序输出各个字母和字母次数，用英文分号分隔，注意末尾的分号；字母和次数间用英文冒号分隔。
#include <iostream>
using namespace std;
#include <map>

namespace sixteen
{
    std::map<char, int> g_mapChar;

    std::string process(const std::string& str)
    {
        std::string resultFirst = "", resultSecond = "";
        g_mapChar.clear();
        for (int i = 0; i < str.length(); i++)
        {
            char key = str[i];
            if (g_mapChar.count(key))
            {
                g_mapChar[key]++;
            }
            else
            {
                g_mapChar[key] = 1;
            }
        }
        for (std::map<char, int>::const_iterator it = g_mapChar.begin(); it != g_mapChar.end(); ++it)
        {
            if (it->first >= 'a')
            {
                resultFirst.push_back(it->first);
                resultFirst += ':' + std::to_string(it->second) + ';';
            }
            else
            {
                resultSecond.push_back(it->first);
                resultSecond += ':' + std::to_string(it->second) + ';';
            }
        }

        return resultFirst + resultSecond;
    }

    void test()
    {
        std::string str = "xyxyXX";
        std::string strResult = process(str);
    }
}