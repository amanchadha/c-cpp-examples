//'''This problem also asks you to solve a knapsack instance, but a much bigger one.'''

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
 
/*
 * Question 1
In this programming problem and the next you'll code up the knapsack algorithm from lecture. Let's start with a warm-up. Download the text file here. This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 659", indicating that the second item has value 50074 and size 659, respectively.
You can assume that all numbers are positive. You should assume that item weights and the knapsack capacity are integers.
 
In the box below, type in the value of the optimal solution.
 
ADVICE: If youre not getting the correct answer, try debugging your algorithm using some small test cases. And then post them to the discussion forum!
 */

public class PS3Q2 {
    static int numItems;
	static int W;//size of knapsack
 
	static class Item{
		int v; //value
		int w; //weight
		public Item(int v, int w){
			this.v= v;
			this.w = w;
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int A[][];
 
		Path p = Paths.get("knapsack_big.txt");
		ArrayList<Item> items = new ArrayList<Item>();
		try {
			BufferedReader br = Files.newBufferedReader(p,StandardCharsets.UTF_8);
			String line = br.readLine();
			numItems = Integer.parseInt(line.split(" ")[1]);
			W = Integer.parseInt(line.split(" ")[0]);
			while ((line = br.readLine())!=null){
				int v = Integer.parseInt(line.split(" ")[0]);
				int w = Integer.parseInt(line.split(" ")[1]);
				items.add(new Item(v,w));
			}
			A = new int[2][W+1];
			for(int x =0;x<W+1;x++){
				A[0][x] = 0;				
			}
			for (int i =0;i<numItems;i++){
				for(int x =0;x<W+1;x++){
					int j = 0;
					if (x<items.get(i).w){						
						A[1][x] = A[j][x];	
					}else{
						A[1][x] = Math.max(A[j][x], A[j][x-items.get(i).w]+items.get(i).v);
					}
				}
				//copy A[1] to A[0]
				for(int k = 0; k<W+1;k++)
					A[0][k] = A[1][k];
			}
 
 
			System.out.println("Answer :: "+A[1][W]);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 
	}
 
}
