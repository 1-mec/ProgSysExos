#include <stdio.h>
#include <stdlib.h>

/* 
	Ecrire un programme permettant de multiplier des matrices.
	m de cette structure va contenir les nombres de la matrice. C’est un pointeur vers des
	pointeurs vers des entiers.
	a/ écrire la fonction Matrice alloue_matrice(int nb_ligne, int nb_col);
*/
typedef struct{
	int nb_ligne;
	int nb_col;
	int **m;
}Matrice;

// a

Matrice alloue(int nb_ligne, int nb_col){
	Matrice m1;
	m1.nb_ligne = nb_ligne;
	m1.nb_col = nb_col;
	m1.m = malloc(sizeof(int *) * nb_ligne);
	for (int i = 0; i < nb_col ; i ++){
			m1.m[i] = malloc(sizeof(int) * nb_col );
			printf("c'est bon pour nb_ligne %d\n",i+1);
	}
	return m1;
}

// b

void aff_mat( Matrice mat){
	int i = 0;
	int y = 0;
	printf("mat.nb_col %d\n",mat.nb_col);
	printf("mat.nb_ligne %d\n",mat.nb_ligne);
	while(i < mat.nb_ligne ){
		while(y < mat.nb_col){
			printf ("[%d][%d]\n",mat.m[i][y]);
			y++;
		}
		i++;
	}
}

Matrice calc(Matrice m1 , Matrice m2){
	Matrice m3 = alloue(m1.nb_ligne, m1.nb_col);
	int x = 0;
	int j = 0;
	int i = 0;
	for ( ;i< m1.nb_col;i++){
		x = m2.m[i][j]* m1.m[i][j];
		for (; j < m1.nb_ligne ; j++){
			m3.m[i][j] = x ;
		}
	}
	return m3;
}

int main(){
	Matrice mat1 = alloue(2,2);
	mat1.m[0][0] = 1;
	mat1.m[0][1] = 2;
	mat1.m[1][0] = 4;
	mat1.m[1][1] = 3;
	printf("=================================\n");
	Matrice mat2 = alloue(2,2);
	mat1.m[0][0] = 1;
	mat1.m[0][1] = 2;
	mat1.m[1][0] = 4;
	mat1.m[1][1] = 3;
	printf("=================================\nMat1 :\n");
	aff_mat(mat1);
	printf("=================================\nMat2 :\n");
	aff_mat(mat2);
	printf("=================================\n");
	Matrice mat3 = calc(mat1,mat2);
	printf("=================================\n");
	aff_mat(mat3);
	
	return 0;
}
