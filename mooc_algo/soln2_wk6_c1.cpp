#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const char* filename = "median.txt";
const int NUM_ELEMENTS = 10000;

class heap
{
public:
    heap();
    int get_min();
    void delete_min();
    void insert(int x);
    void fixup(int index);
    void fixdown(int index);
private:
    int data[NUM_ELEMENTS];
    int size;
};

heap::heap()
{
    size = 0;
}

void heap::delete_min()
{
    if (size == 0)
    {
        throw 0;
    }
    else
    {
        data[1] = data[size];
        size--;
        fixdown(1);
    }
}

int heap::get_min()
{
    if (size == 0)
    {
        throw 0;
    }
    else
    {
        return data[1];
    }
}

void heap::insert(int x)
{
    size++;
    data[size] = x;
    fixup(size);
}

void heap::fixup(int index)
{
    if (index == 1)
    {
        return;
    }
    else
    {
        int parent = index / 2;
        if (data[parent] > data[index])
        {
            swap(data[parent], data[index]);
            fixup(parent);
        }
    }
}

void heap::fixdown(int index)
{
    int left_child = index * 2;
    int right_child = left_child + 1;
    if (right_child <= size)
    {
        if (data[left_child] < data[right_child])
        {
            if (data[index] < data[left_child])
            {
                // we are good, index < left < right
            }
            else
            {
                swap(data[index], data[left_child]);
                fixdown(left_child);
            }
        }
        else
        {
            if (data[index] < data[right_child])
            {
                // we are good, index < right < left 
            }
            else
            {
                swap(data[index], data[right_child]);
                fixdown(right_child);
            }
        }
    }
    else if (left_child <= size)
    {
        if (data[index] < data[left_child])
        {
            // we are good, index < left < right
        }
        else
        {
            swap(data[index], data[left_child]);
            fixdown(left_child);
        }
    }
}

int main()
{
    int median = 0;
    heap low;
    heap high;
    fstream fin;
    fin.open(filename);

    int median_sum = 0;

    for (int i = 1; i <= NUM_ELEMENTS; i++)
    {
        int data;
        fin >> data;
        if (i == 1)
        {
            median = data;
        }
        else if (i == 2)
        {
            if (data < median)
            {
                low.insert(-data);
                high.insert(median);
            }
            else
            {
                low.insert(-median);
                high.insert(data);
            }
        }
        else if (i % 2 == 1)
        {
            int low_max = -low.get_min();
            int high_min = high.get_min();

            if (data < low_max)
            {
                low.delete_min();
                low.insert(-data);
                median = low_max;
            }
            else if (data > high_min)
            {
                high.delete_min();
                high.insert(data);
                median = high_min;
            }
            else
            {
                median = data;
            }
        }
        else if (i % 2 == 0)
        {
            int low_max = -low.get_min();
            int high_min = high.get_min();

            if (data < low_max)
            {
                low.insert(-data);
                high.insert(median);
            }
            else if (data > high_min)
            {
                high.insert(data);
                low.insert(-median);
            }
            else
            {
                if (data > median)
                {
                    high.insert(data);
                    low.insert(-median);
                }
                else
                {
                    high.insert(median);
                    low.insert(-data);
                }
            }
        }

        if (i % 2 == 0)
        {
            median = -low.get_min();
        }

        median_sum = (median_sum + median) % 10000;
    }
    cout << median_sum << endl;
    fin.close();
    return 0;
}
