void strC(string &a,long long int n){
    long long int r;
    if(n==0)
        a.push_back(48);
        string aa;
        int i=0;
    while(n > 0){
        r = n%10;
        n/=10;
        aa.push_back(r + 48);
        i++;
    }
    reverse(aa.begin(),aa.end());
    a.append(aa);
}
string Solution::fractionToDecimal(int numerato, int denominato) {
   int mk[10000];
   memset(mk,0,10000);
   string ss;

  long long int r = 0,q;
   if((numerato<0 && denominato>=0)|| (numerato>=0 && denominato<0)){
    if(numerato!=0)
    ss.push_back('-');
   }
   long long int   denominator = denominato;
     long long int  numerator = numerato;
   if(denominato<0)
         denominator = (long long int )(-1)*denominato;

 if(numerato<0)
  numerator = (long long int )(-1)*(numerato);


   if(denominator == 1){
       strC(ss,numerator);
   }
   else{

   if(numerator >= denominator){

           r = numerator%denominator;
           numerator/= denominator;
           strC(ss,numerator);
           numerator = r;

       }
       if(numerator != 0){
           if(ss.length() == 0 || (ss.length()==1 && ss[0]== '-'))
                ss.push_back('0');
       ss.push_back('.');
       string dec="";
       numerator*=10;
       while(numerator<denominator){
            numerator*=10;
            dec.push_back(48);
       }
       while(1){

        r = numerator%denominator;
        q = numerator/denominator;
        if(mk[q]==1)
            break;
        else
            mk[q]++;

        strC(dec,q);

        if(r == 0)
        break;
        numerator = r;
        numerator*=10;

         while(numerator<denominator){
       numerator*=10;
       dec.push_back(48);
       }
       }
       if(r!=0){
       ss.push_back('(');
       ss+=dec;
       ss.push_back(')');
       }
       else
       ss+=dec;
   }
   }
       return ss;

}
