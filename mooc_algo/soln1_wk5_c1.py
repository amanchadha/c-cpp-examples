f=open('dijkstraData.txt','r')  
vertices=dict()  
for line in f.readlines():  
    tmp=line.split()  
    try:  
        vertices[int(tmp[0])]={int(x.split(',')[0]):int(x.split(',')[1]) for x in tmp[1:]}  
    except:  
        print('error'+tmp)  
f.close  
  
length=200  
exped=[1]  
noexped=list(range(2,length+1))  
distance={x:0 for x in range(1,length+1)}  
  
while len(exped)<length:  
    maxlimit=1000000  
    tmpdist=maxlimit  
    lenvw=tmpdist  
    for v in exped:  
        for w in noexped:  
            if w in vertices[v].keys():  
                lenvw=distance[v]+vertices[v][w]  
                if lenvw<tmpdist:  
                    tmpdist=lenvw  
                    tmpv=v  
                    tmpw=w  
    if tmpdist==maxlimit:break  
    exped.append(tmpw)  
    noexped.remove(tmpw)  
    distance[tmpw]=tmpdist  
  
print('distance is')  
print(distance)  
print('max distance is: '+str(max(distance.values())))  
for ind in [7,37,59,82,99,115,133,165,188,197]:  
    print(str(ind)+' is : '+str(distance[ind]))  
