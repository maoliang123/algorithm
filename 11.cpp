//为了充分发挥GPU算力，需要尽可能多的将任务交给GPU执行，现在有一个任务数组
//，数组元素表示在这1秒内新增的任务个数且每秒都有新增任务，假设GPU最多一次执行n个任务，
//一次执行耗时1秒，在保证GPU不空闲情况下，最少需要多长时间执行完成
#include <iostream>
using namespace std;

// template <class T>
// int getlength(T& array)
// {
//  	return (sizeof(array) / sizeof(array[0]));
// }
namespace eleven
{
    static int process(int jobMaxLen,int jobArrayLen,int jobArray[])
    {
        int num = 0, extraTime = 0;
        for (int i = 0; i < jobArrayLen; i++)
        {
            if (jobArray[i] + num > jobMaxLen)
                num = jobArray[i] + num - jobMaxLen;
            else
                num = 0;     
        }

        extraTime = num % jobMaxLen > 0 ? num/jobMaxLen + 1 : num/jobMaxLen;

        return num > 0 ? jobArrayLen + extraTime : jobArrayLen;
    }

    int test1()
    {
        int jobNum = 3, jobMaxLen = 5;
        int jobArray[] = {1, 2, 3, 4, 5};
        int result = process(jobNum, jobMaxLen, jobArray);
        return 0; 
    }

    int test2()
    {
        int jobNum1 = 4, jobMaxLen1 = 5;
        int jobArray1[] = {5, 4, 1, 1, 1};
        int result2 = process(jobNum1, jobMaxLen1, jobArray1);
    }

    int test()
    {
        test1();
        test2();
        return 0; 
    }
}
