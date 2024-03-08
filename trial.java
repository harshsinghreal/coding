import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Solution {
    
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n];
        int[] b= new int[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
            b[i]=sc.nextInt();
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                   temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
        int count=0;
        List <Integer> list = new ArrayList<>();
        list.add(b[0]);count=1;
        for(int i=1;i<n;i++){
            int min=Collections.min(list);
            if(a[i]<min){
                list.add(b[i]);count++;}
            else if(a[i]>=min){
                list.add(b[i]);
                list.remove(Integer.valueOf(min));
                Collections.sort(list);
            }                                                                                                                                                                                                                                                        
                
        }
        System.out.print(count);
        
    }
}