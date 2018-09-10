"""
Problem extracted from coursera.org:

The file contains the edges of a directed graph. Vertices are labeled as positive integers from 1 to 875714. Every row indicates an edge, the vertex label in first column is the tail and the vertex label in second column is the head (recall the graph is directed, and the edges are directed from the first column vertex to the second column vertex). So for example, the 11th row looks liks : "2 47646". This just means that the vertex with label 2 has an outgoing edge to the vertex with label 47646

Your task is to code up the algorithm from the video lectures for computing strongly connected components (SCCs), and to run this algorithm on the given graph.

Output Format: You should output the sizes of the 5 largest SCCs in the given graph, in decreasing order of sizes, separated by commas (avoid any spaces). So if your algorithm computes the sizes of the five largest SCCs to be 500, 400, 300, 200 and 100, then your answer should be "500,400,300,200,100". If your algorithm finds less than 5 SCCs, then write 0 for the remaining terms. Thus, if your algorithm computes only 3 SCCs whose sizes are 400, 300, and 100, then your answer should be "400,300,100,0,0".

The idea of Kosaraju's algorithm is like this:
1. Compute the finishing time of all the vertices by doing a DFS on the reversed graph;
2. Replace the vertex index with its finishing time to get a new graph, DFS the new graph to compute each vertex's leader vertex( in a strongly connected component(SCC) if exists any);
3. Do statistical job on the leader vertices' index. If multiple vertices have same leader vertex, they are in the same SCC.

ulimit command
April 5, 2012
Recently I was running programs on very large dataset and encountered "Segmentation Fault" problems frequently. After quite a few times of proofreading without any discovery, it turns out the system stack was to "blame".  The system stack, usually with a limited size by default, was 'blowed up' by a huge amount of data. And that caused the segmentation fault.

The 'ulimit' command can be used to increase the stack size.

ulimit -a  (to list out user limit of system-wide resources)
ulimit -s (check stack size)
ulimit -s +a number (set stack size as the number specified)
"""

import sys
sys.setrecursionlimit(300000)
source='SCC.txt'
N=875714
def getG():
    G={}
    Grev={}
    for i in range(1,N+1):
        G[i]=[]
        Grev[i]=[]
    fin=open(source)
    for line in fin:
        v1=int(line.split()[0])
        v2=int(line.split()[1])
        G[v1].append(v2)
        Grev[v2].append(v1)
    fin.close()
    return G, Grev

#globals
visited={}
finish={}
leader={}

def init():
    for i in range(1,N+1):
        visited[i]=0
        finish[i]=0
        leader[i]=0

def dfs(G, i):
    global t
    visited[i]=1
    leader[i]=s
    for j in G[i]:
        if(visited[j]==0): dfs(G,j)
    t=t+1
    finish[i]=t

def dfs_loop(G):
    global t
    global s
    t=0 #number of nodes processed so far
    s=0 #current source vertex
    i=N
    while(i>0):
        if(visited[i]==0):
            s=i
            dfs(G,i)
        i=i-1

if __name__ == "__main__":
    init()
    g, grev=getG()
    dfs_loop(grev) #THE FIRST LOOP ON REVERSE GRAPH

    # construct new graph
    newGraph={}
    for i in range(1,N+1):
        temp=[]
        for x in g[i]: temp.append(finish[x])
        newGraph[finish[i]]=temp

    init()    
    dfs_loop(newGraph) #THE SECOND LOOP 

    # statistics
    lst= sorted(leader.values())
    stat=[]
    pre=0
    for i in range(0,N-1):
        if lst[i]!=lst[i+1]:
            stat.append(i+1-pre)
            pre=i+1
    stat.append(N-pre)
    L= sorted(stat)
    L.reverse()
    print(L[0:5])
