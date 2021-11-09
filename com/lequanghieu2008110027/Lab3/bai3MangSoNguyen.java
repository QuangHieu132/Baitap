package com.lequanghieu2008110027.Lab3;
import java.util.Scanner;


public class bai3MangSoNguyen {
    public static void main(String[] args) {
            int n, sum = 0, tempSort;
            Scanner scanner = new Scanner(System.in);
            
        do {
            System.out.print("Nhập vào số phần tử của mảng: ");
            n = scanner.nextInt();
        } while (n < 0);
            
        // khởi tạo và cấp phát bộ nhớ cho mảng
        int array[] = new int[n];
            
        System.out.println("Nhập các phần tử cho mảng: ");
        for (int i = 0; i < n; i++) {
            System.out.print("Nhập phần tử thứ " + i + ": ");
            array[i] = scanner.nextInt();
        }
            
        // Hiển thị mảng vừa nhập
        System.out.println("\nMảng ban đầu: ");
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + "\t");
        }

        // sắp xếp theo thứ tự giảm dần
         for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (array[i] < array[j]) {
                tempSort = array[i];
                array[i] = array[j];
                array[j] = tempSort;
            }
        }
        }

        System.out.println("\nMảng sau khi sắp xếp theo thứ tự giảm dần là: ");
        for (int i = 0; i < n; i++) {
        System.out.print(array[i] + "\t");       
    }

          // sắp xếp theo thứ tự tăng dần
          for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (array[i] > array[j]) {
                    tempSort = array[i];
                    array[i] = array[j];
                    array[j] = tempSort;
                }
            }
            }
            

            System.out.println("\nMảng sau khi sắp xếp theo thứ tự tăng dần là: ");
            for (int i = 0; i < n; i++) {
            System.out.print(array[i] + "\t"); 
            
             }

             //tim so nho nhat
             timMin(array,n);

             //tinh trung binh cong cac so nguyen chia het cho 3
             trungBinhCong(array, n);
            

      
}
// ham tim so nho nhat
static void timMin(int a[], int n){
    int min = a[0];
    for(int m = 1; m < n; m++){
        if(min > a[m]){
            min = a[m];
        }
    }
    System.out.println("\nPhần tử có giá trị nhỏ nhất trong mảng là: " + min);
}

// ham tinh trung binh cong cac phan tu chia het cho 3
static void trungBinhCong(int a[], int n){
    int tong = 0;
    int dem=0;
    for(int k = 0; k < n; k++){
        if(a[k] % 3 == 0){
            tong += a[k];
            dem++;
        }
    }
    double tongTB = tong/dem;
    System.out.printf("Trung bình cộng các phần tử chia hết cho 3 là: %.2f", tongTB);
}
}
