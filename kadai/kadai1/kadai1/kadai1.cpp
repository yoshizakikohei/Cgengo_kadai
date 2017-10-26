#include<stdio.h>

int main(void){
	FILE *fp;
	char *fname = "data.csv";
	int ret;
	char buf[4][10];
	char name[10];
	int data[3];

	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("%sファイルが開けません\n", fname);
		
		return -1;
	}

	printf("\n");

	fscanf(fp, "%[^,], %[^,], %[^,], %s", buf[0], buf[1], buf[2], buf[3]);
	printf("%s %s %s %s\n", buf[0], buf[1], buf[2], buf[3]);

	for(int i = 0; i < 500; i++){
	    fscanf(fp, "%[^,], %d, %d, %d", name, &data[0], &data[1], &data[2]);
		printf("%s %d %d %d", name, data[0], data[1], data[2]);
	}

	fclose(fp);

	return 0;
}