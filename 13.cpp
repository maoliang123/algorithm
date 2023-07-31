// 输入一个字符串仅包含大小写字母和数字，求字符串中包含的最长的非严格递增连续数字序列的长度
// （比如12234属于非严格递增连续数字序列）。

#include <iostream>
using namespace std;

namespace thirdteen
{
    int process(const std::string& str)
    {
        int maxSeqLen = 1, seqLenTemp = 1;
        for (int i = 0; i < str.size() - 1; i++)
        {
            char next = str[i+1], now = str[i];
            int nextInt = int(next), nowInt =  int(now);
            if (nextInt - nowInt == 0 || nextInt - nowInt ==1)
            {
                seqLenTemp++;
            }
            else
            {
                if (seqLenTemp > maxSeqLen)
                    maxSeqLen = seqLenTemp;
                seqLenTemp = 1;
            }    
        }

        return maxSeqLen;
    }

    void test()
    {
        std::string str = "abc2234019A334bc";
        int result = process(str);
        int a = 1;
    }
}