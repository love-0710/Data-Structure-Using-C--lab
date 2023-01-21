#include<stdio.h>

int main(){

	int r,c;


	//Taking sparse matrix as input from user

	printf("Enter number of rows: ");
	scanf("%d",&r);

	printf("\nEnter number of columns: ");
	scanf("%d", &c);

	int n[r][c];

	for(int i=0; i<r; i++){
	printf("\nEnter row %d elements:\n",i+1);
		for(int j=0; j<c; j++){
			scanf("%d",&n[i][j]);
		}
	}


	//Displaying sparse matrix

	printf("Matrix in sparse form:\n");

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("%d", n[i][j]);
		}
		printf("\n");
	}



	//Compact Matrix

	int m[100][3];

	m[0][0]=r;
	m[0][1]=c;

	int count=0;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(n[i][j]!=0){
				m[i+1][0]=i;
				m[i+1][1]=j;
				m[i+1][2]=n[i][j];
				count++;
			}
		}
	}

	m[0][2]=count;


	//Displaying compact matric

	printf("\nMatrix in compact form: \n");

	int row=count+1;

	for(int i=0; i<row; i++){
		for(int j=0; j<3; j++){
			printf("%d", m[i][j]);
		}
		printf("\n");
	}

	return 0;

}
