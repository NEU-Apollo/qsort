#include <bits/stdc++.h>
#define N 13
using namespace std;
double arr[N] = {8, 1, 2, 5, 4, 3, 7, 6, 9, 12, 6, 4, 3};
int compare(const void *e1, const void *e2)
{
    return *(double *)e1 - *(double *)e2;
}

void QSort(void *base, size_t nitem, size_t width, int (*compare)(const void *, const void *))
{
    size_t i = 0;          // i为第一个元素编号
    size_t j = nitem - 1;  // j为最后一个函数编号
    char *temp = new char; //????
    if (nitem > 0)
    {
        for (int elementwidth = 0; elementwidth < width; elementwidth++)
        {
            *(temp + elementwidth) = *((char *)base + elementwidth);
        }
        // cout << *((int *)temp) << "    ";
        while (i < j)
        {
            while (j > i && compare((char *)base + j * width, temp) > 0)
                j--;
            if (i < j)
            {
                for (int elementwidth = 0; elementwidth < width; elementwidth++)
                {
                    *((char *)base + i * width + elementwidth) = *((char *)base + j * width + elementwidth);
                }
                ++i;
            }
            while (i < j && compare((char *)base + i * width, temp) < 0)
                i++;
            if (i < j)
            {
                for (int elementwidth = 0; elementwidth < width; elementwidth++)
                {
                    *((char *)base + j * width + elementwidth) = *((char *)base + i * width + elementwidth);
                }
                --j;
            }
        }
    }
    else
    {
        delete temp;
        return;
    }
    for (int elementwidth = 0; elementwidth < width; elementwidth++)
    {
        *((char *)base + i * width + elementwidth) = *(temp + elementwidth);
    }
    delete temp;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    QSort(base, i, width, compare);
    QSort((char *)base + (i + 1) * width, nitem - i - 1, width, compare);
}

int main()
{
    cout << "before:";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    QSort(arr, N, sizeof(double), compare);
    cout << endl
         << "after:";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}