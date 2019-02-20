
#include <stdio.h> 
#include <stdlib.h> 

int comp(const void* a, const void* b) 
{ return *(int*)a > *(int*)b ; }
  

int findNumberOfTriangles(int arr[], int n) 
{ 
    int count = 0;  

    for (int i = 0; i < n-2; ++i)
    { 
        int k = i+2;

        for (int j = i+1; j < n; ++j) 
        { 

            while (k < n && arr[i] + arr[j] > arr[k]) 
            ++k; 
  
            if( k > j )
            {
                count += k - j - 1;
            }
        } 
    } 
  
    return count; 
}

int main() 
{ 
    int n, m;

    scanf("%d %d",&m,&n);

    int n2 = n;
    int m2 = m;

    int arr[1000]{};

    int brr[1000]{};

    int par = 0;int impar = 0;

    for ( int i = m; i <= n; ++i)   
    {
        if( i%2==0 )
        {
            arr[par++] = i;
        }
        else
        {
            brr[impar++] = i;
        }
    }

    int back2frontPar = 0;
    int back2frontImpar = 0;

// Pares

    if ( par == 1 )
    {
        back2frontPar = 0;
    }
    else if ( par == 2 )
    {
        if ( arr[0]==2 && arr[1]==4)
        {
            back2frontPar +=0;
        }
        else
        {
            back2frontPar += 1;
        }
    }
    else if( par == 3 )
    {
        if( arr[0] == 2 )
        {
            back2frontPar+=1;
        }
        else if ( arr[0] == 4 )
        {
            back2frontPar+=2;
        }
        else
        {
            back2frontPar+=3;
        }
    }
    else if( par > 3 )
    {

        if (m%2==0)
        {
            while( n > 4 && m < 4)
            {
                m+=2;
            }
        }
        else
        {
            while( n > 4 && m < 4)
            {
                m++;
            }
            if (m%2==1)
            {
                m++;
            }
        }

        int restantesP = (n-m)/2;

        int iterSup = restantesP;

        if (m == 4 && n == 4)
        {

        }
        else if ( m >= 4 && n >= 6)
        {

            int displace = 0;

            if ( m==4 )
            {
                displace = 1;
            }
            else 
            {
                displace = (m/2) - 1;
            }

            for(int j = 0 ;j < restantesP; j++)
            {

                while( displace > iterSup)
                {
                    displace--;
                }

                back2frontPar+=displace;

                displace++;

                iterSup--;
            }
        }

    }
    

//impares

    if ( impar == 1 )
    {
        back2frontImpar = 0;
    }
    else if ( impar == 2 )
    {
        if ( brr[0]==1 && brr[1]==3)
        {
            back2frontImpar +=0;
        }
        else
        {
            back2frontImpar += 1;
        }
    }
    else if( impar == 3 )
    {
        if( brr[0] == 1 )
        {
            back2frontImpar+=1;
        }
        else if ( brr[0] == 3 )
        {
            back2frontImpar+=2;
        }
        else
        {
            back2frontImpar+=3;
        }
    }
    else if( impar > 3 )
    {
        if (m2%2==1)
        {
            while( n2 > 3 && m2 < 3)
            {
                m2+=2;
            }
        }
        else
        {
            while( n2 > 3 && m2 < 3)
            {
                m2++;
            }   
            if(m2%2==0)
            {
                m2++;
            }
        }

        int restantesP =  ( (n2-m2)/2 ) ;

        int iterSup = restantesP ;

        if (m2 == 3 && n2 ==3)
        {

        }
        else if ( m2 >= 3 && n2 >= 5)
        {
            int displace = 0;

            if ( m2==3 )
            {
                displace = 1;
            }
            else 
            {
                displace = (m2/2);
            }

            for(int j = 0 ; j < restantesP; ++j)
            {
                while( displace > iterSup)
                {
                    displace--;
                }
                back2frontImpar+=displace;
                displace++;
                iterSup--;
                
            }
        }
    }

    int front2backPar = ( (par * (par+1) )/2 ) - par;
    int front2backImpar = ( (impar * (impar+1) )/2 ) - impar;

    int resI = findNumberOfTriangles( brr, impar );
    int resP = findNumberOfTriangles( arr, par );

    printf("%d %d\n", 
        resI+impar+back2frontImpar+front2backImpar, resP+par+back2frontPar+front2backPar);
  
        return 0; 
}