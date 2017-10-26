#include<stdio.h>
#include<stdlib.h>
#include <malloc.h> 
#include<string.h>

#define NINZU 500
#define KAMOKU 3

typedef struct date{
	int *english;
	int *math;
	int *science;
}score;

typedef char namae[10];

int main(void){
	FILE *fp;
	char *fname = "data.csv";
	char buf[4][5];
	char n[10];
	int e, m, s;
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

	//1�s�ڂ̓ǂݍ���
	fscanf(fp, "%[^,], %[^,], %[^,], %s", buf[0], buf[1], buf[2], buf[3]);
	printf("%s     %s %s %s\n", buf[0], buf[1], buf[2], buf[3]);

	//2�s�ڈȍ~�̓ǂݍ���
	for(int i = 0; i < 500; i++){
		fscanf(fp, "%[^,], %d, %d, %d", name[i], &seiseki.english[i], &seiseki.math[i], &seiseki.science[i]);
		printf("%s %d %d %d\n", name[i], seiseki.english[i], seiseki.math[i], seiseki.science[i]);
	}
		//���w�̓_�����������Ƀ\�[�g
		/*for(int j = 0; j < 500; j++){
			if(seiseki.math[j] <= seiseki.math[j + 1]){
				//���O�̓���ւ�
				strcpy(n, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], n);
				//���w�̓_������ւ�
				m = seiseki.math[j];
				seiseki.math[j] = seiseki.math[j + 1];
				seiseki.math[j + 1] = m;
				//�p��̓_������ւ�
				e = seiseki.english[j];
				seiseki.english[j] = seiseki.english[j + 1];
				seiseki.english[j + 1] = e;
				//���Ȃ̓_������ւ�
				s = seiseki.science[j];
				seiseki.science[j] = seiseki.science[j + 1];
				seiseki.science[j + 1] = s;
			}
		}
	}

	//500�l�̐��т�\��
		for(int k = 0; k < 500; k++){
			printf("%s %d %d %d\n", name[k], seiseki.english[k], seiseki.math[k], seiseki.science[k]);
		}*/

	fclose(fp);

	free(name);
	free(seiseki.english);
	free(seiseki.math);
	free(seiseki.science);

	return 0;
}