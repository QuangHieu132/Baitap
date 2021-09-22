package Lap3;

import java.util.Scanner;

public class bai1KiemTraSoNguyenTo {
    public static void main(String[] args) {
        
        Scanner scanner= new Scanner(System.in);

        System.out.print("Nhap vao mot so nguyen: ");
        int n = scanner.nextInt();

        int souoc = 0;
        for (int i = 1;i <= n;i++){
            if (n % i == 0){
                souoc++;
            }
        }if (souoc == 2){
            System.out.print(""+n);
            System.out.println(" la so nguyen to");
        }
        else{
            System.out.print(""+n);
            System.out.println(" khong phai la so nguyen to");
             }
        } 
            
    
}
