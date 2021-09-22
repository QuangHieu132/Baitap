package Lap2;
import java.util.Scanner;

import javax.lang.model.util.ElementScanner6;

public class bai2GiaiPTBac2 {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Giai phuong trinh bac 2");

        System.out.print("Nhap vao he so a: ");
        Double a= scanner.nextDouble();

        System.out.print("Nhap vao he so b: ");
        Double b= scanner.nextDouble();

        System.out.print("Nhap vao he so c: ");
        Double c= scanner.nextDouble();
        if(a==0){
            if(b==0)    
            {   
                if(c==0)
                System.out.println("Vo so nghiem");    
                else 
                System.out.println("Vo nghiem");
            }     
            else
            {   
                Double x=-c/b;
                System.out.println("Nghiem x= "+x);
            }
        }   
        else 
        { Double delta= Math.pow(b, 2) -4*a*c;
            if(delta<0)
            System.out.println("Phuong trinh vo nghiem");
            else if(delta==0)
            {   double x= -b/(2*a);
                System.out.println("Phuong trinh co nghiem kep: "+x);

            }
            else
            {
                double canDelta= Math.sqrt(delta);
                double x1 = (-b + canDelta) / (2*a);
                double x2 = (-b - canDelta) / (2*a);
                System.out.println("Phuong trinh co hai nghiem phan biet");
                System.out.printf("Nghiem x1: %.2f\n",x1);
                System.out.printf("Nghiem x2: %.2f\n",x2);
            } 


        }
       


    
        }

    
    

}
