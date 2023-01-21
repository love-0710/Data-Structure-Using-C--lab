#include<stdio.h>
void mat(int m[20][20], int , int);
void printarr(int m[20][20], int , int);

int main(){
	int rows,col;
	printf("Enter the number of rows and columns\n");
	scanf("%d%d", &rows, &col);
	int m[rows][col];
	mat(m,rows,col);
	return 0;
}

void mat(int m[20][20], int row, int col){
	printf("Enter the elements of the compact matrix\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			scanf("%d", &m[i][j]);
		}
	}

	printarr(m, row, col);

	int x = m[0][0], y= m[0][1], z = m[0][2];
	int com[row][col],k=1;
	com[0][0] = y, com[0][1] = x, com[0][2] = z;

	if(z>0){
		for(int j=0; j<y; j++){
			for(int i=1; i<=z; i++){
				if(m[i][1] == j){
					com[k][0] = m[i][1];
					com[k][1] = m[i][0];
					com[k][2] = m[i][2];
					k++;
				}
			}
		}
	}
	printf("Transpose of Compact Matrix\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d\t",com[i][j]);
		}
		printf("\n");
	}
//	printarr(com,row,col);

}

void printarr(int m[20][20], int row, int col){
	printf("Matrix: \n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
}
