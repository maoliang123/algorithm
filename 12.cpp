// 输入一个由n个大小写字母组成的字符串，按照Ascii码值从小到大的排序规则，查找字符串中第k个最小ascii码值的字母（k>=1），
// 输出该字母所在字符串的位置索引(字符串的第一个字符位置索引为0）。
// k如果大于字符串长度，则输出最大ascii值的字母所在字符串的位置索引，如果有重复的字母，则输出字母的最小位置索引。
#include <iostream>
using namespace std;

namespace twelve
{
    void quickSort(std::string& str, int low, int high)
    {
        if (low >= high)
            return;
        int low_t = low, high_t = high;
        char char_t = str[low];
        while(low_t < high_t)
        {
            while (str[high_t] >= char_t && low_t < high_t)
                high_t--;
            if (low_t < high_t)
                str[low_t++] = str[high_t];
            while (str[low_t] < char_t && low_t < high_t)
                low_t++;
            if (low_t < high_t)
                str[high_t--] = str[low_t];
        }
        str[low_t] = char_t;
        quickSort(str, low, low_t - 1);
        quickSort(str, low_t + 1, high);
    }

    int process(const std::string& str, int k)
    {
        std::string str_tmp = str;
        int high = str_tmp.size() - 1;
        quickSort(str_tmp, 1, high);
        if (k > str.size())
            return str.find(str_tmp[-1]);
        return str.find(str_tmp[k - 1]);
    }

    int test()
    {
        bool a = 'A' < 'B';
        bool b = 'a' < 'A';
        bool c = 'c' < 'C';
        std::string str = "AbCdeFG";
        int strLen = str.length();
        int index = process(str, 3);
        std::string str_2 = "fAdDAkBbBq";
        int index_2 = process(str_2, 4);
        int ab = 0;
    }

}