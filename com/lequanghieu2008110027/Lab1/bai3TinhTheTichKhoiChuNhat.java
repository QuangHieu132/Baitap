package Lab1;
import java.util.Scanner;

public class bai3TinhTheTichKhoiChuNhat {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);

        System.out.print("Nhap vao kich thuoc canh cua khoi lap phuong: ");
        double canh = scanner.nextDouble();

        double theTich=Math.pow(canh,3);
        System.out.print("The tich khoi lap phuong la: "+theTich);

        
    }

    
}
