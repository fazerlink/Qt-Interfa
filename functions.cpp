#include "functions.h"

std::mutex mt1, mt2;
void f1(int* M1, int* M2, size_t arraySize)
{

    for(size_t i = 0;i<arraySize;i++)
    {
        mt1.lock();
        M1[i] += rand() %10;
        mt1.unlock();
    }



    for(size_t j = 0; j< arraySize; j++)
    {
        mt2.lock();
        M2[j] %= 10;
        M2[j] += 5;
        mt2.unlock();
    }


}
void f2(int* M1, int* M2, size_t arraySize)
{


    for(size_t i= 0; i<arraySize;i++)
    {
        mt1.lock();
        M1[i] -= rand() %10;
        mt1.unlock();
    }

    for(size_t j = 0; j< arraySize; j++)
    {
        mt2.lock();
        M2[j] *= 10;
        mt2.unlock();
    }


}

void f3(int* M1, int* M2, size_t arraySize)
{

    f1( M1, M2, arraySize);

}

void f4(int* M1, int* M2, size_t arraySize)
{

    f2( M1, M2, arraySize);

}
void f5(int* M1, int* M2, size_t arraySize)
{

    f2( M1, M2, arraySize);

}
void f6(int* M1, int* M2, size_t arraySize)
{

    f3( M1, M2, arraySize);
    f4( M1, M2, arraySize);

}
void f7(int* M1, int* M2, size_t arraySize)
{

    f3( M1, M2, arraySize);
    f4( M1, M2, arraySize);

}
void f8(int* M1, int* M2, size_t arraySize)
{


    f5( M1, M2, arraySize);
    f6( M1, M2, arraySize);
    f7( M1, M2, arraySize);

}

QString toString(int* M, size_t arraySize)
{
    QString string;
    for(size_t i = 0;i<arraySize; i++)
    {

        string.push_back(QString::number(M[i]));
    }
    return string;
}
