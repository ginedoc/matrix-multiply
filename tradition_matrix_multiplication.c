#include "tradition_matrix_multiplication.h"

void getMatrixData(struct Matrix*, struct Matrix*, char*);
struct Matrix tradition_multiply(struct Matrix, struct Matrix);

int main(){
	struct Matrix A, B, result;

	getMatrixData(&A, &B, "input.txt");
	result = tradition_multiply(A, B);
}
