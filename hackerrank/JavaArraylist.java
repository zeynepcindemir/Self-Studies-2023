import java.io.*;
import java.util.*;

public class JavaArraylist {

    public static void main(String[] args) {
        
      Scanner sc = new Scanner(System.in);
      ArrayList<ArrayList< Integer >> arr = new ArrayList<ArrayList< Integer >>(); 
        
        int N = sc.nextInt();
        for (int n=0 ; n<N ; ++n) {
            
            int D = sc.nextInt();
            ArrayList<Integer> a = new ArrayList<Integer>();
            
            for (int d=0 ; d<D ; ++d) {
                a.add(sc.nextInt());   
            }
            
            arr.add(a);            
        }
        
        int Q = sc.nextInt();
        for (int q=0 ; q<Q ; ++q) {
            
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            try {
                System.out.println(arr.get(x-1).get(y-1));
            } catch (Exception e) {
                System.out.println("ERROR!");
            }
        }
    }
   
   
    
}
