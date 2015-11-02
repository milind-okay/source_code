/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Milind
 */
import java.util.*;
import java.util.Scanner
interface bank{
    void addaccount(int i,String str[],String str1[],int ar[]);
    void viewaccount(int i,String str[],String str1[],int ar[]);
}

class customer implements bank{

    Scanner myscan=new Scanner(System.in);
    public void addaccount(int i,String str[],String str1[],int ar[])
    {
        System.out.println("1. Select an username for your account");
    str[i]=myscan.nextLine();
    System.out.println("2. Select a password for your account");
    str1[i]=myscan.nextLine();
    System.out.println("3. Select an account no. for your account");
    ar[i]=myscan.nextInt();
    System.out.println("thanks, ur account has been created");
    }
    public void viewaccount(int i,String str[],String str1[],int ar[])
    {
          String test,test1;
          System.out.println("enter your username");
          test=myscan.nextLine();
          System.out.println("enter your password");
          test1=myscan.nextLine();
          for(int j=0;j<i;j++)
          {
          if(str[j].equalsIgnoreCase(test))
          {
              if(str1[j].equalsIgnoreCase(test1))
              {
              System.out.println("your account no. is "+ar[j]);
              }
          }
          }
    }
}

class clerk implements bank{

    Scanner myscan=new Scanner(System.in);
    public void addaccount(int i,String str[],String str1[],int ar[]){}
    public void viewaccount(int i,String str[],String str1[],int ar[])
    {
          int num;
          num=myscan.nextInt();
          for(int j=0;j<i;j++)
          {
            if(ar[j]==num)
            {
            System.out.println("person name is "+str[j]);
            }
          }
    }
}

public class BankAndCustomer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println(" ");
         String str[]=new String[100];
    String str1[]=new String[100];
    int ar[]=new int[100];
    int num1=0;
    while(true)
    {
        System.out.println("1. customer 2. banker 3. enter any other to terminate the program");
        Scanner mysc=new Scanner(System.in);
        int k=mysc.nextInt();
        if(k==1)
        {
             customer ob=new customer();
            System.out.println("1. add account 2. view your account");
            int u=mysc.nextInt();
            if(u==1)
            {
                ob.addaccount(num1, str, str1, ar);
                num1++;
            }
            else
            {
               ob.viewaccount(num1, str, str1, ar);
            }
        }
        else if(k==2)
        {
            System.out.println("enter the ac. no. to view person details");
            clerk ob1=new clerk();
            ob1.viewaccount(num1, str, str1, ar);
        }
        else
        {
            break;
        }

    }
        // TODO code application logic here
    }

}
