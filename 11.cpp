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

static unsigned int process(unsigned int jobMaxLen,unsigned int jobArrayLen,unsigned int jobArray[])
{
    unsigned int num = 0, extraTime = 0;
    for (unsigned int i = 0; i < jobArrayLen; i++)
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
    unsigned int jobNum = 3, jobMaxLen = 5;
    unsigned int jobArray[] = {1, 2, 3, 4, 5};
    unsigned int result = process(jobNum, jobMaxLen, jobArray);
    return 0; 
}

int test2()
{
    unsigned int jobNum1 = 4, jobMaxLen1 = 5;
    unsigned int jobArray1[] = {5, 4, 1, 1, 1};
    unsigned int result2 = process(jobNum1, jobMaxLen1, jobArray1);
}

int test()
{
    test1();
    test2();
    return 0; 
}