// 现有一字符串仅由 '('，')'，'{'，'}'，'['，']'六种括号组成。
// 若字符串满足以下条件之一，则为无效字符串：
//   ①任一类型的左右括号数量不相等；
//   ②存在未按正确顺序（先左后右）闭合的括号。
// 输出括号的最大嵌套深度，若字符串无效则输出0。
// 0≤字符串长度≤100000

#include <stack>
#include <map>
using namespace std;
namespace fourteen
{
    std::map<char, char> g_mapBrackets;

    void initMapBrackets()
    {
        g_mapBrackets.clear();
        g_mapBrackets.insert(std::pair<char, char>('(', ')'));
        g_mapBrackets.insert(std::pair<char, char>('{', '}'));
        g_mapBrackets.insert(std::pair<char, char>('[', ']'));
    }

    int process(const std::string& str)
    {
        std::stack<char> stackBrackets;
        int maxStackLen = 0;
        initMapBrackets();
        for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
        {
            if (stackBrackets.size() == 0 || g_mapBrackets[stackBrackets.top()] != *it)
            {
                stackBrackets.push(*it);
            }
            else
            {
                stackBrackets.pop();
                if (stackBrackets.size() + 1 > maxStackLen)
                    maxStackLen = stackBrackets.size() + 1;
            }
        }
        if (stackBrackets.size() > 0)
            return 0;
        return stackBrackets.size() > 0 ? 0 : maxStackLen;
    }

    void test()
    {
        std::string str_1 = "([]{()})";
        int res_1 = process(str_1);
        std::string str_2 = "([)]";
        int res_2 = process(str_2);
    }
}