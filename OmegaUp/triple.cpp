
#include <cstdio>
#include <iostream>
#include <string>

int main()
{
  int n, t, index = 0;
  
  scanf("%d",&n);

  std::string res = "";
  
  int arr[n+1] = {};
  
  for(int i = 1; i <= n; ++i)
  {
      scanf("%d",&t);
      if (t%3==0)
      {
        index++;
        res+= std::to_string(i)+' ';
      }
  }
  
  if ( index > 0)
  {
     printf("%d\n",index);
     std::cout << res <<'\n';
  }else
  {
      printf("No hay triples.");
  }
  return 0;
}