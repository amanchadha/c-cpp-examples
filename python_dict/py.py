def dic(words):
    a = {}
    for i in words:
        try:
            a[i] += 1
        except:
            a[i] = 1
    return a

def dic2(words):
    a = {}
    for i in words:
        if i in a:
            a[i] += 1
        else:
            a[i] = 1
    return a
    
if __name__ == "__main__":
    a = dic([1,2,2,3,3,3]);
    print a
    a = dic2([1,2,2,3,3,3]);
    print a
