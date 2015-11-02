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
public class Area {
    public static void main(String a[]){ 
 
        constructor obj1=new constructor();
         constructor obj2=new constructor(10, 20);
           constructor obj3=new constructor(obj2);
        obj1.showresult(obj1.cal());
          obj2.showresult(obj2.cal());
            obj3.showresult(obj3.cal());
        System.out.println("OBJ1= " + obj1.cal());
}
}