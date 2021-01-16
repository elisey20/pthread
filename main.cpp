#include <iostream>
#include <sysinfoapi.h>
#include "methods.h"

using namespace std;

int main()
{
    unsigned int time_begin = GetTickCount();
    cout << "Сумма высчитанная в одном потоке: " << one_pth() << endl;
    unsigned int time_end = GetTickCount();
    cout << "Один поток посчитал сумму чисел во всех файлах за: " << (time_end - time_begin) << "ms" << endl << endl;

    time_begin = GetTickCount();
    cout << "Сумма высчитанная в " << N << " потоках: " << some_pth() << endl;
    time_end = GetTickCount();
    cout << N << " потоков посчитали сумму чисел во всех файлах за: " << (time_end - time_begin) << "ms" << endl;

    return 0;
}
