#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int v[10] = { 3, 2, 7, 4, 2, -999, -21, 99, 0, 9 };

void print()
{

        for (int i = 0; i < 10; i++)

               cout << v[i] << " ";

        cout << endl;

}

void quickSort(int left, int right)//快排
{
        if (left < right)
        {
               int l = left;
               int r = right;
               int pvoid = v[l];
               while (l < r)
               {
                       while (l<r&&v[r]>=pvoid)
                              r--;
                       v[l] = v[r];
                       while (l < r&&v[l] <= pvoid)
                              l++;
                       v[r] = v[l];
               }
               v[l] = pvoid;
               quickSort(left, r - 1);
               quickSort(l + 1, right);

        }
}

void insertSort(int n)//直接插入排序
{
        for (int i = 1; i < n; i++)
        {
               if (v[i] < v[i - 1])
               {
                       int j = i - 1;
                       int temp = v[i];
                       while (j >= 0 && temp < v[j])
                       {
                              v[j + 1] = v[j];
                              j--;
                       }
                       v[j + 1] = temp;
               }
        }
}

void shellSort(int n)//希尔排序
{
        int gap = n / 2;
        while (gap > 0)
        {
               for (int i = gap; i < n; i++)
               {
                       if (v[i] < v[i - gap])
                       {
                              int j = i - gap;
                              int temp = v[i];
                              while (j >= 0 && v[j] > temp)
                              {
                                      v[j + gap] = v[j];
                                      j = j - gap;
                              }
                              v[j + gap] = temp;
                       }
               }
               gap = gap / 2;
        }
}

void adjust_heap(int* a, int node, int size)//堆排序中的调整堆
{
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int max = node;
        if (left < size && a[left] > a[max])
               max = left;
        if (right < size && a[right] > a[max])
               max = right;
        if (max != node)
        {
               swap(a[max], a[node]);
               adjust_heap(a, max, size);
        }
}

void heap_sort(int* a, int len)//堆排序
{
        for (int i = len / 2 - 1; i >= 0; --i)
               adjust_heap(a, i, len);
        for (int i = len - 1; i >= 0; i--)
        {
               swap(a[0], a[i]);           // 将当前最大的放置到数组末尾
               adjust_heap(a, 0, i);              // 将未完成排序的部分继续进行堆排序
        }
}

void merge(int* a, int l, int mid, int r, int n) { // 两个数组合并，如果是链表得用两个链表的合并，思想一样
    int tmp[n];
    int i = l, j = mid + 1, k = l;
    while(i != mid + 1 && j != r + 1) {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i < mid + 1)
        tmp[k++] = a[i++];
    while(j < r + 1)
        tmp[k++] = a[j++];
    for(int t = l; t <= r; t++)
        a[t] = tmp[t];
}

void merge_sort(int* a, int l, int r, int n) { // 归并排序可以用于链表的排序
    if(l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    merge_sort(a, l, mid, n);
    merge_sort(a, mid + 1, r, n);
    merge(a, l, mid, r, n);
}

int main()
{
        //quickSort(0, 9);
        //insertSort(10);
        //shellSort(10);
        
        int a[10] = { 3, 2, 7, 4, 2, -999, -21, 99, 0, 9 };
        
        int len = sizeof(a) / sizeof(int);
        //merge_sort(a, 0, len - 1, len);
        for (int i = 0; i < len; ++i)
               cout << a[i] << ' ';
        cout << endl;

        heap_sort(a, len);
        for (int i = 0; i < len; ++i)
               cout << a[i] << ' ';
        cout << endl;
        print();
        return 0;

}

