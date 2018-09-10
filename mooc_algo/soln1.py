"""
Programming assignment: The file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated. Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith entry of an array.

Question 1 Download the text file here. (Right click and save link as)

This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith entry of an array. Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures. The numeric answer for the given input file should be typed in the space below. So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas / any other punctuation marks. You can make up to 5 attempts, and we'll use the best one for grading. (We do not require you to submit your code, so feel free to use any programming language you want --- just type the final numeric answer in the following space.)
"""

# load contents of text file into a list
# numList
NUMLIST_FILENAME = "IntegerArray.txt"
inFile = open(NUMLIST_FILENAME, 'r')

with inFile as f:
    numList = [int(integers.strip()) for integers in f.readlines()]
    
count = 0

def inversionsCount(x):
    global count
    midsection = len(x) / 2
    leftArray = x[:midsection]
    rightArray = x[midsection:]
    if len(x) > 1:
        # Divid and conquer with recursive calls
        # to left and right arrays similar to
        # merge sort algorithm
        inversionsCount(leftArray)
        inversionsCount(rightArray)
        
        # Merge sorted sub-arrays and keep
        # count of split inversions
        i, j = 0, 0
        a = leftArray; b = rightArray
        for k in range(len(a) + len(b) + 1):
            if a[i] <= b[j]:
                x[k] = a[i]
                i += 1
                if i == len(a) and j != len(b):
                    while j != len(b):
                        k +=1
                        x[k] = b[j]
                        j += 1
                    break
            elif a[i] > b[j]:
                x[k] = b[j]
                count += (len(a) - i)
                j += 1
                if j == len(b) and i != len(a):
                    while i != len(a):
                        k+= 1
                        x[k] = a[i]
                        i += 1                    
                    break   
    return x
# call function and output number of inversions
inversionsCount(numList)
print count 
