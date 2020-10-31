
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
        System.out.println("Reversed array is: \n"); 
        for (int k = 0; k < n; k++) { 
            System.out.println(b[k]); 
        } 
    } 
  
    public static void main(String[] args) 
    { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System/./in)); // remove ‘/’s



String str[] = br.readLine().split(" ");

int N = str.length; //N stores number of values

System.out.println("Size of array is "+ N);

/*

Test Input

1 9 5 8 4 2 1 2 3 5 2 22 56 94

Output

Size of array is 14

*/

//Further you can convert this array to integer array as shown below

int vals[] = new int[N];

for(int i=0; i<N; i++)

vals[i] = Integer.parseInt(str[i]);

//prints integer values

for(int i=0; i<N; i++)

System.out.println("["+i+"] = "+vals[i]);
        reverse(arr, arr.length); 
    } 
}