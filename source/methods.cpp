#include <pthread.h>
#include <sstream>
#include <fstream>
#include "methods.h"

using namespace std;

struct thr_data {
    int numberFile;
    long long sum;
};

long one_pth()
{
    stringstream ss;
    long sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        ss << "..\\files\\" << i << ".txt";
        ifstream in(ss.str());
        ss.str(string());
        if (in.is_open())
        {
            while (!in.eof())
            {
                int num;
                in >> num;
                sum += num;
            }
        }
        in.close();
    }
    return sum;
}

void* thr(void *thread_data)
{
    stringstream ss;
    thr_data *data = (thr_data*) thread_data;

    ss << "..\\files\\" << data->numberFile << ".txt";
    ifstream in(ss.str());
    ss.str(string());
    if (in.is_open())
    {
        while (!in.eof())
        {
            int num;
            in >> num;
            data->sum += num;
        }
    }
    in.close();

    pthread_exit(NULL);
}


long some_pth()
{
    pthread_t threads[N];
    thr_data* threadData = new thr_data[N];
    long sum = 0;

    for(int i = 0; i < N; i++)
    {
        threadData[i].numberFile = i;
        threadData[i].sum = 0;
        pthread_create(&(threads[i]), NULL, thr, &threadData[i]);
    }

    for(int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
        sum += threadData[i].sum;
    }

    delete[] threadData;
    return sum;
}

