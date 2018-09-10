#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

typedef long long int64;

const char* filename = "algo1-programming_prob-2sum.txt";
const int NUM_ELEMENTS = 1000000;
const int MIN = -10000;
const int MAX = 10000;

int64 data[NUM_ELEMENTS];

int main()
{
    ifstream fin;
    fin.open(filename);

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        fin >> data[i];
    }

    sort(data, data + NUM_ELEMENTS);

    int start = 0;
    int end = NUM_ELEMENTS - 1;
    bool found[MAX - MIN + 1];
    for (int i = MIN; i <= MAX; i++)
    {
        found[i - MIN] = false;
    }
    while (start < end)
    {
        int64 probe_sum = data[start] + data[end];
        if (probe_sum < MIN)
        {
            // the value is too small, there is just no hope for success, let go the small side
            start++;
        }
        else if (probe_sum > MAX)
        {
            // the value is too large, there is just no hope for success, let go the small side
            end--;
        }
        else
        {
            if (data[start] != data[end])
            {
                found[probe_sum - MIN] = true;
            }
            int current_start = start;
            int current_end = end;
            while (true)
            {
                // let see if there are any more solution starting with the same end
                start++;
                int64 probe_sum = data[start] + data[end];
                if (probe_sum < MIN)
                {
                    // This is impossible
                    break;
                }
                else if (probe_sum > MAX)
                {
                    break;
                }
                else
                {
                    if (data[start] != data[end])
                    {
                        found[probe_sum - MIN] = true;
                    }
                }
            }
            start = current_start;

            while (true)
            {
                // let see if there are any more solution starting with the same start
                end--;
                int64 probe_sum = data[start] + data[end];
                if (probe_sum < MIN)
                {
                    break;
                }
                else if (probe_sum > MAX)
                {
                    // This is impossible
                    break;
                }
                else
                {
                    if (data[start] != data[end])
                    {
                        found[probe_sum - MIN] = true;
                    }
                }
            }
            end = current_end;
            // We have exhausted all solution with start and end, so skip them both
            start++;
            end--;
        }
    }

    int count = 0;
    for (int i = MIN; i <= MAX; i++)
    {
        if (found[i - MIN])
        {
            count++;
        }
    }
    cout << count << endl;

    fin.close();
    return 0;
}
