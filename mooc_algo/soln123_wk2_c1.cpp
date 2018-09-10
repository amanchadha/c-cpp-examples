#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swap(vector<int> &vec,int a,int b);
void QuickSort(vector<int> &,int);
int Qsort(vector<int> &vec,int left,int right);
int ChosePivot1(vector<int> &vec,int left,int right);//use the first number
int ChosePivot2(vector<int> &vec,int left,int right);//use the final number
int ChosePivot3(vector<int> &vec,int left,int right);//use Median of three Partion

int main()
{
	ifstream fin("QuickSort.txt");
	vector<int> init;
	int temp;
	
	while(fin>>temp)
	{
		init.push_back(temp);
	}
	
	int DataSize = init.size();
	cout<<"DataSize: "<<DataSize<<endl;
	
	QuickSort(init,DataSize);	
	
	return 0;
}



void QuickSort(vector<int> &vec,int size)
{
	int num;
	num = Qsort(vec,0,size-1);
	cout<<"the total number of comparisons: "<<num<<endl;
}

int Qsort(vector<int> &vec,int left,int right)
{
	int i,j;
	int result,c1,c2,c3;
	
	if((right - left) == 1)
	{
		if(vec[right] < vec[left])
			swap(vec,left,right);
		return 1;
	}
	else if(right - left < 1)
	{
		return 0;
	}
	else{
		
	int pivot = ChosePivot1(vec,left,right);
	//int pivot = ChosePivot2(vec,left,right);
	//int pivot = ChosePivot3(vec,left,right);

	i = left + 1;
	for(j = left + 1;j <= right; j++)
	{
		if(vec[j] < pivot)
		{
			swap(vec,i,j);
			i++;
		}
	}
	swap(vec[left],vec[i-1]);
	}
	
	c2 = Qsort(vec,left,i-2);
	c3 = Qsort(vec,i,right);
	
	c1 = right - left;
	
	result = c1 + c2 + c3;
	
	return result;
	
}

int ChosePivot1(vector<int> & vec,int left,int right)
{
	return vec[left];
}

int ChosePivot2(vector<int> & vec,int left,int right)
{
	swap(vec,left,right);
	return vec[left];
}

int ChosePivot3(vector<int> & vec,int left,int right)
{
	int mid = (right + left) / 2;
	int midnum;
	if(vec[left] > vec[right] && vec[right] > vec[mid]||vec[left] < vec[right] && vec[right] < vec[mid])
		midnum = right;
	if(vec[right] > vec[mid] && vec[mid] > vec[left]||vec[right] < vec[mid] && vec[mid] < vec[left])
		midnum = mid;
	if(vec[mid] > vec[left] && vec[left] > vec[right]||vec[mid] < vec[left] && vec[left] < vec[right])
		midnum = left;
	
	swap(vec,left,midnum);
		
	return vec[left];
}



void swap(vector<int> &vec,int a,int b)
{
	int temp;
	temp = vec[a];
	vec[a] = vec[b];
	vec[b] = temp;
} 
