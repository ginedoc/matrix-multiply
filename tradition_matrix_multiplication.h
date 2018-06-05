#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Matrix{
	int column;
	int row;
	int *array;
};
void MatricInfo(struct Matrix* M, FILE* fptr){
	int c;
	int cnt=0;
	
	fscanf(fptr, "%d%d", &M->column, &M->row);
	M->array = malloc(sizeof(int)*M->column*M->row);

	while(cnt < M->column*M->row){
		c = getc(fptr)-'0';
		if(c>0) {
			M->array[cnt++] = c;
		}
	}
}

void getMatrixData(struct Matrix* A, struct Matrix* B, char* input){
	FILE *fptr = fopen(input, "r");
		
	MatricInfo(A, fptr);
	MatricInfo(B, fptr);

	fclose(fptr);
}

int* get_col(struct Matrix M, int col){
	int* arr = malloc(sizeof(int)*M.row);
	for(int i=0;i<M.row;i++){
		*(arr+i) = M.array[col+i*M.row];
	}
	return arr;
}
int* get_row(struct Matrix M, int row){
	int* arr = malloc(sizeof(int)*M.column);
	for(int i=0; i<M.column; i++)
		*(arr+i) = M.array[row+i];
	return arr;
}

int inner_product(int* col, int* row){
	int result = 0;
	for(int i=0;i<sizeof(col)/sizeof(int); i++){
		result += col[i]*row[i];
	}
	return result;
}

struct Matrix tradition_multiply(struct Matrix A, struct Matrix B){
	struct Matrix result;
	if(A.row != B.column){
		printf("[error] dimension not equal. cannot multiply\n");
		result.column = result.row = 0;
	}
	
	result.column = A.column;
	result.row = B.row;
	result.array = malloc(sizeof(int) * result.column * result.row);

	
	int* A_row, *B_col;
	for(int i=0; i<result.column; i++){
		for(int j=0;j<result.row; j++){
				A_row = get_row(A, i);
				B_col = get_col(B, j);
				result.array[j*result.row+i] = inner_product(A_row, B_col);
				printf("%d\n", inner_product(A_row, B_col));
		}
	}

	return result;
}
