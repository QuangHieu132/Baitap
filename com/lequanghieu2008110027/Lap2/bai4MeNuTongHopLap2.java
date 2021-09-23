package Lap2;
import java.util.Scanner;

public class bai4MeNuTongHopLap2 {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        int suLuaChon;
    do{    
        System.out.println("+----------------------------+");
        System.out.println("1.Giai phuong trinh bac 1");
        System.out.println("2.Giai phuong trinh bac 2");
        System.out.println("3.Tinh tien dien");
        System.out.println("4.Ket thuc");
        System.out.println("+----------------------------+");
    
        System.out.print("Chon dich vu: ");
        suLuaChon= scanner.nextInt();
        
        switch(suLuaChon)
        {   case 1:{   System.out.println("Giai phuong trinh bac 1");
        
                        System.out.print("Nhap vao 2 so a va b: ");
                        Double a= scanner.nextDouble(); 
                        Double b= scanner.nextDouble(); 
                        if(a==0)    
                        { if(b==0)
                            System.out.println("Vo so nghiem");
                        else 
                            System.out.println("Vo nghiem");
                        }      
                        else
                        {Double x=-b/a;
                        System.out.println("Nghiem x= "+x);
                        break;
                        }
        
        
                        }
            case 2:{    System.out.println("Giai phuong trinh bac 2");

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
                                break;
                            } 

                                }            

                    }
            case 3:{    System.out.print("Nhap so dien da su dung: ");
                        Double soDien= scanner.nextDouble();
                
                        if(soDien<=50)
                        {
                            Double tienDien= soDien*1000;
                            System.out.print("Tien dien can tra: "+tienDien);
                            System.out.println("Dong");
                        }
                        else if(soDien>50)
                        {
                            Double tienDienCoVuotMuc=50*1000+(soDien-50)*1200;
                            System.out.print("Tien dien can tra: "+tienDienCoVuotMuc);
                            System.out.println("Dong");
                        }
                        else 
                        System.out.println("Nhap sai vui long nhap lai so dien da su dung");
                        break;
                        

                    }
            case 4:break;        



        }




} while (suLuaChon<4 && suLuaChon>0);
}
}
    

