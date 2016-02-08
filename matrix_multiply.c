//*****************************************************************************
// SC 5260 : High Performace Computing Assignment 1
// Mohit Ganguly
// This program calculates the product of a square matrix with itself:
// The function is written in a way that it can be used for any two compliant matrices, not necessarily square
// B = A * A
//
// Please keep all code in this single file.
//
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>

void read_data(int * array, int n,char *file_name)
   	
  	{
  		
                FILE *file=fopen(file_name,"r");
   		int j;
   		int k;
   		
   		for (j=0;j<n*n;j++) 
   		{
   			fscanf(file,"%d",&array[j]);
   			//printf("%d \n",array[j]);
   		}
   		fclose(file);
   		
 
   		printf("Input Matrix:\n");
   		for (j=0;j<n;j++)
   		{
   			for (k=0;k<n;k++){
   			printf("%d ",array[n*j+k]);
   		}
   		printf("\n");
   	}
	
   	}
   	
void multiply(int * array1,int * array2, int n, int * result)

{
	
   	
   	printf("Output Matrix:\n");
   	FILE *file_out;
   	file_out=fopen("output_file.dat","w");
   	if ( file_out == NULL ) {
        	printf("output_file.txt not opened, exiting...\n");
      		exit(0);
   	}
   	
   	int i; int j; int k;
	for (i=0;i<n;i++){
		fprintf(file_out,"Row %d \n",i);
		for (j=0;j<n;j++){
		int sum =0;
			for (k=0;k<n;k++){
				sum=sum+array1[n*i+k]*array2[n*k+j];
				
			}
		result[n*i+j]=sum;
		
		printf("%d ",result[n*i+j]);
		
		fprintf(file_out,"%d ",result[n*i+j]);
		}
	printf("\n");
	
	
	fprintf(file_out,"\n");
	
	}
	fclose(file_out);
	
}


int main(int argc, char **argv)

{
	//check command line arguments
	
	if (argc!=3){
		printf("This program computes the product of n X n matrix with itself\n");
		printf("Usage: ./matrix_multiply filename n\n");
		exit(0);
	}
	
	
	//parse input arguments
	
	int i;
        for (i=0;i<argc;i++) {
        printf("i: %d argv[i]: %s\n",i,argv[i]); 
        }
        
   	// dynamically allocate space for input matrix in 1d array
   	int n=atoi(argv[2]);
   	int * array_A=malloc(n*n*sizeof(int));
   	
   	if (array_A==NULL){
   	printf("Allocation failed, exiting!\n");
   	exit(0);
   	}
   	
   	
   	//call function to read data from file and copy into matrix_A
   	char * input_file=argv[1];
   	//int matrix_A[n][n];
   	read_data(array_A,n,input_file);
   	
   	
   	// dynamically allocate space for output matrix in 1d array
   	int * array_B=malloc(n*n*sizeof(int));
   	
   	if (array_B==NULL){
   	printf("Allocation failed, exiting!\n");
   	exit(0);
   	}
   	
   	
   	//call function to perform matrix multiplication (matrix_B=matrix_A*matrix_A)
   	multiply(array_A,array_A,n,array_B);
   	
   	
   	
   	
   	
   	
   	
   	
   	
   free(array_A);
   free(array_B);
   return 0;
   
}
