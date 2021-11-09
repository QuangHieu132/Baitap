package Lab1;

import java.util.Scanner;

public class bai4TinhDeltaVaXuat {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);

        System.out.print("Nhap he so a: ");
        Double a= scanner.nextDouble(); 

        System.out.print("Nhap he so b: ");
        Double b= scanner.nextDouble(); 

        System.out.print("Nhap he so c: ");
        Double c= scanner.nextDouble(); 

        Double Delta = Math.pow(b, 2) -4*a*c;

        Float canDelta=(float) Math.sqrt(Delta);
        System.out.printf("Can Delta: %.2f",canDelta);

    }
    
}
