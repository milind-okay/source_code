#include <iostream>
#include <map>
#include<string>
int main ()
{
  std::map<std::string,int> mymap;
  std::map<char,int>::iterator it;

  mymap["aa"]=-1;
  mymap["ab"]=-1;
 // mymap['c']=-1;
 // mymap['d']=-1;

if(mymap["aab"] != -1){
   std:: cout<<"okay";
}
  /*it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';
*/
  return 0;
}
