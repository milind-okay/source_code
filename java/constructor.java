/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package milind;

/**
 *
 * @author MILIND
 */
public class constructor {
    int len,w,c;
   public constructor(){
    len=0;
    w=0;
}
   public constructor(int x,int y){
       len=x;
       w=y;
   }
   public constructor( constructor b){
       len=b.len;
       w=b.w;
   }
   public int cal(){
       c = len*w;
       return c;
   }
   public void showresult(int result){
       System.out.printf(" area of %d ",result);
   }
}