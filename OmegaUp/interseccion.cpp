#include <cstdio>
#include <iostream>     
#include <algorithm>    
#include <vector>

int main () {

  int n;

  scanf("%d",&n);

  int first[n];
  int second[n];

  for (int i = 0; i < n; ++i)
  {
    scanf("%d",&first[i]);
  }

  for (int i = 0; i < n; ++i)
  { 
    scanf("%d",&second[i]);
  }

  std::unique( second, second+n );

  int *last;
  for (int i = 0; i < sizeof(second)/sizeof(int); ++i )
  {
    last = std::remove( first, first+n, second[i]);
  }

  printf("last:%d\n",*last);

  for (int i = 0; i < 3; ++i)
  {
    printf("%d ",first[i] );
  }

  return 0;
}