    import java.io.BufferedReader;  
    import java.io.DataInputStream;  
    import java.io.FileInputStream;  
    import java.io.IOException;  
    import java.io.InputStreamReader;  
    /* 
     * n this assignment you will implement one or more algorithms for the all-pairs shortest-path problem.  
     * Here are data files describing three graphs: graph #1; graph #2; graph #3. 
    The first line indicates the number of vertices and edges, respectively. Each subsequent line describes an edge  
    (the first two numbers are its tail and head, respectively) and its length (the third number).  
    NOTE: some of the edge lengths are negative. NOTE: These graphs may or may not have negative-cost cycles. 
     
    Your task is to compute the "shortest shortest path".  
    Precisely, you must first identify which, if any, of the three graphs have no negative cycles. For each such graph, you should compute all-pairs shortest paths and remember the smallest one (i.e., compute minu,v∈Vd(u,v), where d(u,v) denotes the shortest-path distance from u to v). 
     
    If each of the three graphs has a negative-cost cycle, then enter "NULL" in the box below.  
    If exactly one graph has no negative-cost cycles, then enter the length of its shortest shortest path in the box below.  
    If two or more of the graphs have no negative-cost cycles, then enter the smallest of the lengths of their shortest  
    shortest paths in the box below. 
     
    OPTIONAL: You can use whatever algorithm you like to solve this question.  
    If you have extra time, try comparing the performance of different all-pairs shortest-path algorithms! 
     
    OPTIONAL: If you want a bigger data set to play with, try computing the shortest shortest path for this graph. 
     *  
     */  
    import java.io.FileNotFoundException;  
      
    public class PS4Q1 {  
      
        static int[][] graph;  
        static int [][][] A;  
        static int n;  
      
      
        /** 
         * @param args 
         */  
        public static void main(String[] args) {  
            int count =1;  
            while (count <= 3 ){  
                FileInputStream f;  
      
                try {  
                    f = new FileInputStream("g1.txt");  
                    if (count == 2) f = new FileInputStream("g2.txt");  
                    if (count == 3) f = new FileInputStream("g3.txt");  
                    DataInputStream d = new DataInputStream(f);  
                    BufferedReader b = new BufferedReader(new InputStreamReader(d));  
                    n = Integer.parseInt(b.readLine().split(" ")[0]);  
                    graph = new int [n][n];  
                    A = new int[n][n][2];//we dont need of size [n][n][k] because at any point we refer to k and k-1 only   
                    for (int i = 0; i < n; i++)  
                        for (int j =0; j < n; j++)  
                            if (i==j) graph[i][j] = 0;  
                            else  
                                graph[i][j] = 999999;  
                    String str;  
                    int x,y,z;;  
                    while((str=b.readLine())!= null){  
                        x = Integer.parseInt(str.split(" ")[0]);  
                        y = Integer.parseInt(str.split(" ")[1]);  
                        z = Integer.parseInt(str.split(" ")[2]);  
                        graph[x-1][y-1] = z;                          
                    }  
                    for (int i = 0; i < n; i++)  
                        for (int j = 0 ; j < n; j++)  
                            if (i==j) A[i][j][0] = 0;  
                            else A[i][j][0] = graph[i][j];  
      
                    for (int k = 0; k < n; k++){  
                        for (int i = 0; i < n; i++)  
                            for (int j = 0; j < n; j++){  
                                A[i][j][1] = Math.min(A[i][j][0],A[i][k][0]+A[k][j][0]);                              
                            }  
                        //copy A[][][1] to A[][][0]  
                        for (int i = 0; i < n; i++)  
                            for (int j = 0; j<n;j++){  
                                A[i][j][0] = A[i][j][1];  
                            }  
                    }  
                    int i = 0;  
                    for (; i <n;i++){  
                        if(A[i][i][0] < 0){  
                            System.out.println(" A[i][i][0] = " + i + " " + A[i][i][0]);  
                            System.out.println("graph " + count + " has a -ve cycle");  
                            break;  
                        }  
                    }  
                    if (i == n){  
                        System.out.println("graph " + count + " has NO -ve cycle");  
                        int min = 0;  
                        for (int ix = 0; ix < n; ix++)  
                            for (int j =0;j<n;j++){  
                                min = Math.min(min,A[ix][j][0]);  
                            }  
                        System.out.println("min cost "+ min);                     
                    }  
      
                } catch (FileNotFoundException e) {  
                    // TODO Auto-generated catch block  
                    e.printStackTrace();  
                } catch (NumberFormatException e) {  
                    // TODO Auto-generated catch block  
                    e.printStackTrace();  
                } catch (IOException e) {  
                    // TODO Auto-generated catch block  
                    e.printStackTrace();  
                }  
                count++;  
            }  
        }  
    }  
