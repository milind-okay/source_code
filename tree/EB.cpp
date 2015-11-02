#include<stdio.h>
#define mod 1000000007
char str[1000001],pat[1000001];

int main(){
   int t;
   scanf("%d",&t);
   while(t--){
   int i,j,npat[27],text[27];
   unsigned long long int n =1;
   scanf("%s",str);
   scanf("%s",pat);
   for(i=0;i<26;i++){
    npat[i] =0;
    text[i] = 0;
   }
   i=0;
   while(pat[i] != '\0'){
    npat[pat[i] - 'a']++;
    i++;
   }
   i =0;
   while(str[i] != '\0'){
    text[str[i] - 'a']++;
    i++;
   }
   for(i=0;i<26;i++){

    text[i] -=(npat[i] - 1) ;
   }

   for(i=0;i<26;i++){
    if(npat[i] != 0){
        n = (n*(text[i])%mod)%mod;
    }
   }
   printf("%llu\n",n);
   }

return 0;
}

