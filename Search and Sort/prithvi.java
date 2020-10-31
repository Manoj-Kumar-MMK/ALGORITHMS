import java.util.*;

import java.lang.*;
public class reverseArray { 
  
    /* function that reverses array and stores it  
       in another array*/
    static void reverse(int a[], int n) 
    { 
        int[] b = new int[n]; 
        int j = n; 
        for (int i = 0; i < n; i++) { 
            b[j - 1] = a[i]; 
            j = j - 1; 
        } 
  
        /*printing the reversed array*/
        System.out.print("{"); 
        for (int k = 0; k < n; k++) { 
            System.out.print(b[k]); 
        } 
        System.out.print("}"); 
    } 
  
    public static void main(String[] args) 
    { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System/./in)); // remove ‘/’s



String str[] = br.readLine().split(" ");

int N = str.length-1; //N stores number of values

int vals[] = new int[N];

for(int i=0; i<N; i++)

vals[i] = Integer.parseInt(str[i]);

//prints integer values
reverse(arr, arr.length);     
}