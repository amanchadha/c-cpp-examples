#include <stdio.h> 
#include <sys/time.h>

#define KB 1024 // 1 KB = 1024 bytes
#define MB 1024 * KB // 1 MB = 1024 KB
#define SIZE 256 * KB // size of data array
#define REPS 1 * MB // times to access/modify memory (MB/KB just used as millions/thousands multiplier)
#define TIMES 1 // times to repeat experiment to get "average"

long long wall_clock_time();

int main() {
	long long start, end;
	float totalTime;
  int p = 0;

  // possible cache address multiples to test for -- to determine associativity
  //256 --> 8-way SA
	int multiples[] = {4*KB, 8*KB, 16*KB, 32*KB, 64*KB, 128*KB, 256*KB, 512*KB, 1024*KB, 2048*KB};
	//int multiples[] = {16, 32, 64, 128, 256, 512, 1024, 2048};

  // init data 
	int *data = new int[SIZE/sizeof(int)];
	
  // for each possible cache size to test for
	for (int i = 0; i < sizeof(multiples)/sizeof(int); i++) {
		// repeatedly read data
		totalTime = 0;
		for (int j = 0; j < REPS; j++) {
			start = wall_clock_time();
      {
        data[p % (SIZE/sizeof(int))]++;
        p += multiples[i]/sizeof(int);
      }
      end = wall_clock_time();
			totalTime += ((float)(end - start))/1000000000;
		}
		// where theres a spike in time --> new level of cache
		printf("%d, %1.2f \n", multiples[i], totalTime / REPS);
	}

	// cleanup
	delete[] data;
}

/*******************************************************
 * Helpers
 ******************************************************/
long long wall_clock_time() {
	#ifdef __linux__
		struct timespec tp;
		clock_gettime(CLOCK_REALTIME, &tp);
		return (long long)(tp.tv_nsec + (long long)tp.tv_sec * 1000000000ll);
	#else 
	#warning "Your timer resolution may be too low. Compile on linux"
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return (long long)(tv.tv_usec * 1000 + (long long)tv.tv_sec * 1000000000ll);
	#endif
}
