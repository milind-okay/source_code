import java.util.*;
class Roo
{
    float length;
    float bre;
    void getdata(float a,float b)
    {
        length = a;
        bre = b;
    }
}
class RoomArea
{
 public static void main(String args[])
 {
    float area;
    Roo r=new Roo();
     Scanner myscan=new Scanner(System.in);
     a=myscan.nextLine();
    r.getdata(a,a);
    area=r.length*r.bre;
    System.out.println("Area="+area);
 }
}
