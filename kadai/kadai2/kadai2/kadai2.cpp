#include<stdio.h>
#include<stdlib.h>
#include <malloc.h> 
#include<string.h>

#define NINZU 500

typedef char namae[10];

//�\���̂̐錾
typedef	struct date{
		int *english;
		int *math;
		int *science;
	}score;

int main(void){
	
	FILE *fp;
	char *fname = "data.csv";
	char maxname[10];
	int maxenglish, maxmath, maxscience;
	char buf[4][5];
	namae *name;
	score seiseki;

	name = (namae *)malloc(sizeof(namae) * 500);
	if(name == NULL) exit(0);
	seiseki.english = (int *)malloc(sizeof(int) * 500);
	if(seiseki.english == NULL) exit(0);
	seiseki.math = (int *)malloc(sizeof(int) * 500);
	if(seiseki.math == NULL) exit(0);
	seiseki.science = (int *)malloc(sizeof(int) * 500);
	if(seiseki.science == NULL) exit(0);
	
	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("%s�t�@�C�����J���܂���\n", fname);
		
		return -1;
	}

	printf("\n");

	//1�s�ړǂݍ���
	fscanf(fp, "%[^,], %[^,], %[^,], %s", buf[0], buf[1], buf[2], buf[3]);
	printf("%s %s %s %s\n", buf[0], buf[1], buf[2], buf[3]);
	
	
	//2�s�ڈȍ~��ǂݍ���
	for(int i = 0; i < NINZU; i++){
		fscanf(fp, "%[^,], %d, %d, %d", name[i], &seiseki.english[i], &seiseki.math[i], &seiseki.science[i]); 
		printf("%s %d %d %d\n", name[i], seiseki.english[i], seiseki.math[i], seiseki.science[i]);
	}
	
	//�_�������ւ���

	/*maxenglish = 0;
	for(i = 0; i <= NINZU; i++){
		if(seiseki.english[i] < seiseki.english[i +1]){
			strcpy(maxname, name[i + 1]);
			maxenglish = seiseki.english[i + 1];
			maxmath = seiseki.math[i + 1];
			maxscience = seiseki.science[i + 1];
		}
	}
	
	//�ō��_���̕\��
	printf("%s %d %d %d", maxname, maxenglish, maxmath, maxscience);
	*/

	fclose(fp);
	
	free(name);
	free(seiseki.english);
	free(seiseki.math);
	free(seiseki.science);
	
	return 0;
}