package bankSystem;

public interface BankSystem {
	void addacc(int i,String str[],String str1[],int ar[]);
    void viewacc(int i,String str[],String str1[],int ar[]);
}

package bankSystem;
import java.util.*;
public  class Customer implements BankSystem{
	 Scanner myscan=new Scanner(System.in);
	    public void addacc(int i,String str[],String str1[],int ar[])
	    {
	        System.out.println("Enter  username of customer");
	    str[i]=myscan.nextLine();
	    System.out.println("Enter password customer");
	    str1[i]=myscan.nextLine();
	    System.out.println("Enter account no. customer ");
	    ar[i]=myscan.nextInt();
	    System.out.println("customer account has been created");
	    }
	    public void viewacc(int i,String str[],String str1[],int ar[])
	    {
	          String test,test1;
	          System.out.println("Username :");
	          test=myscan.nextLine();
	          System.out.println("Password :");
	          test1=myscan.nextLine();
	          for(int j=0;j<i;j++)
	          {
	          if(str[j].equalsIgnoreCase(test))
	          {
	              if(str1[j].equalsIgnoreCase(test1))
	              {
	              System.out.println("Your account no. is "+ar[j]);
	              }
	          }
	          }
	    }
}
package bankSystem;
import java.util.*;
public class banker implements BankSystem{
	 Scanner myscan=new Scanner(System.in);
	    public void addacc(int i,String str[],String str1[],int ar[]){}
	    public void viewacc(int i,String str[],String str1[],int ar[])
	    {
	          int num;
	          num=myscan.nextInt();
	          for(int j=0;j<i;j++)
	          {
	            if(ar[j]==num)
	            {
	            System.out.println("Welcome ! : "+str[j] +" to java bank");
	            }
	          }
	    }
}
package bankSystem;
import java.util.*;
public class Main {

	private static Scanner mysc;

	public static void main(String[] args) {
		System.out.println(" ");
        String str[]=new String[100];
   String str1[]=new String[100];
   int ar[]=new int[100];
   int num1=0;
   while(true)
   {
       System.out.println("ENTER : 1. for  banker ,2. for customer");
       mysc = new Scanner(System.in);
       int k=mysc.nextInt();
       if(k==1)
       {
            Customer ob=new Customer();
           System.out.println("1. Add account 2. View  account");
           int u=mysc.nextInt();
           if(u==1)
           {
               ob.addacc(num1, str, str1, ar);
               num1++;
           }
           else
           {
              ob.viewacc(num1, str, str1, ar);
           }
       }
       else if(k==2)
       {
           System.out.println("Enter acc. no. to view person details");
           banker ob1=new banker();
           ob1.viewacc(num1, str, str1, ar);
       }
       else
       {
           break;
       }

   }


	}

}
