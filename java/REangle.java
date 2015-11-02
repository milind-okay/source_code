 import java.lang.Math;
 abstract class tringle{  

   abstract void cal();  
   
 }  
  
 class rangle extends tringle{ 
 	float h,b,area,par,hi;
 rangle(float x,float y ){
 	h=x;
 	b=y;
 	area=0;
 	par=0;
 } 
 void cal(){
 	area=0.5*h*b;
 	hi=Math.sqrt(h*h + b*b);
 	par=hi + h + b;
 	System.out.println("Area of Right angle tringle is :"+arae+"\n and parameter is: "+par);
 }  
 }  
 class eangle extends tringle{ 
 	float side,area,par,height;
 rangle(float x){
 	side=x;
 	area=0;
 	par=0;
 } 
 void cal(){
 	
 	par=3*side;
 	height=Math.sqrt(side*side - (side/2)*(side/2));
 	area=0.5*side*height;

 	System.out.println("\nArea of E tringle is :"+arae+"\n and parameter is: "+par);
 }  
 }  

 class REtriangle{  
 public static void main(String args[]){  
  tringle obj1 = new rangle(2,5);
  tringle obj2 = new eangle(3);  
  obj1.cal();  
  obj2.cal();  
 }  
}  