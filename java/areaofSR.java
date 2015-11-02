import java.util.Scanner;

/**
 *
 * @author MILIND
 */
class square{
    int side,par,area;
    square(){
        side=0;
        par=0;
        area=0;
    }
  
   public void getsideA(){
          Scanner scanner=new Scanner(System.in);
    System.out.println("Area of square = ");
    side = scanner.nextInt();
    }
 public void cal(){
        area=side*side;
        par=side*4;
        System.out.println("Area of square = "+ area + "\n and P = " + par);
    }
}
import java.util.Scanner;
class rect extends square{
    int b,par1,area1;
    rect(){
        super();
        b=0;
        par1=0;
        area1=0;
    }
    public void getsideB(){
          Scanner scanner=new Scanner(System.in);
    System.out.println("Enter side b :");
    b = scanner.nextInt();
    }
   public void cal1(){
        area1=side*b;
        par1=(b+side)*2;
        System.out.println("Area of square = "+ area1 + "\n and P = " + par1);
    }
}

import java.util.Scanner;
class areaofSR {
    public static void main(String[] a){
        int n;
        square s=new square();
        rect r=new rect();
                  

        System.out.println("For cal area and par. of (square enter 1/rectangle enter 2)  ");
        Scanner scanner=new Scanner(System.in);
        n =scanner.nextInt();
        switch(n){
            case 1 :
                s.getsideA();
                s.cal();
                break;
            case 2 :
                r.getsideA();
                r.getsideB();
                r.cal1();
                break;
            default :
                System.out.print("enter 1 or 2");
        }
        
        
}
}