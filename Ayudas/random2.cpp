#include<iostream>
#define nV 5
#define INF 9999
using namespace std;
int i,j,k;
void printMatrix(int matrix[][nV]){
	for(int i=0;i<nV;i++){
		for(int j=0;j<nV;j++){
			if(matrix[i][j]==INF)
			cout<<"\n INF";
			else
			cout<<"\t "<<matrix[i][j];
		}
		cout<<endl;
	}
}

void FloyWarsall(int graph [][nV]){
	int matrix[nV][nV],i,j,k;
	for(i=0;i<nV;i++)
	for(j=0;j<nV;j++)
	matrix[i][j]=graph[i][j];
	
	//generar el recorrido de la suma de las matrices
	for(k=0;k<nV;k++){
		for(i=0;i<nV;i++){
			for(j=0;j<nV;j++){
				if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
					matrix[i][j] = matrix[i][k]+matrix[k][j];
				}
			}
		}
	}
	printMatrix(matrix);
}

int main(){
	 cout<<"       Punta   Cerro   Huacho  Mancora  Ilo\n";
	 cout<<"        Sal     Azul\n";
 int graph[nV][nV]=  {{ 0 , 50,INF, 30,INF},
	                  {INF, 0 , 15, 25,INF},
					  {INF,INF, 0 ,INF,15 },
					  {20 ,INF, 10, 0 ,INF},
					  {INF, 5 ,INF, 25, 0 }};			  
				  
	FloyWarsall(graph); 
}