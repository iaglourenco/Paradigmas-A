#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROF 10
#define MAX_ALUNO 10
#define MAX_ALUNO_DISC 10
#define MAX_DISC 10

typedef struct {
	int ra;
	char nome[20];
	char empty; //true
}Aluno;

typedef struct {
	int rp;
	char nome[20];
	int empty; //true
}Professor;


typedef struct {
	char nome[20];
	Professor prof;
	Aluno alunos[MAX_ALUNO_DISC];
	int empty; //true
}Disciplina;




Aluno cadastraAluno(Aluno alunos[], int posAluno);
Professor cadastraProf(Professor profs[], int posProf);
int matriculaAluno(Disciplina *disc1, int posDisc1,Aluno alunos[],int posAluno);


//retorna a proxima posicao disponivel para cadastro
int attPosA(Aluno alunos[]) {
	int i;
	for (i = 0; i < MAX_ALUNO; i++) {
		if (alunos[i].empty != 0) {
			return i;
		}
	}
	return MAX_ALUNO;
}

int attPosP(Professor profs[]) {
	int i;
	for (i = 0; i < MAX_PROF; i++) {
		if (profs[i].empty != 0) {
			return i;
		}
	}
	return MAX_PROF;
}

int attPosD(Disciplina disc1[]) {
	int i;
	for (i = 0; i < MAX_DISC; i++) {
		if (disc1[i].empty != 0) {
			return i;
		}
	}
	return MAX_DISC;
}



int main() {

	int opcao = 0, i,j;
	char more;
	int op2;

	int posAluno = 0; //indica a proxima posicao disponivel para cadastro
	int posProf = 0;
	int posDisc1 = 0;
	int posDisc2 = 0;


	Aluno alunos[MAX_ALUNO];
	Professor profs[MAX_PROF];
	Disciplina disc1[MAX_DISC];
	Disciplina disc2[MAX_DISC];



	do {
		system("cls");
		printf("\t<PROJETO EM C [SISTEMA ACADEMICO]>");
		printf("\n\n1 - <Cadastrar Aluno>");//ok
		printf("\n2 - <Cadastrar Disciplina>");//ok
		printf("\n3 - <Cadastrar Professor>");//ok
		printf("\n4 - <Realizar Matricula>");//ok
		printf("\n5 - <Cancelar Matricula>");
		printf("\n6 - <Vincular professores a disciplinas>");
		printf("\n7 - <Remover vinculo de professores a disciplinas>");
		printf("\n8 - <Imprimir a lista de alunos>");//ok
		printf("\n9 - <Imprimir a lista de disciplinas>");//ok
		printf("\n10 - <Imprimir a lista de professores>");//ok
		printf("\n11 - <Imprimir a lista de disciplinas de um aluno>");//ok
		printf("\n12 - <Imprimir a lista de alunos em uma disciplina e turma>");//em partes
		printf("\n13 - <Imprimir a lista de alunos em uma disciplina, independente da turma>");
		printf("\n14 - <Imprimir a lista de todas as disciplinas ministradas por um professor (independente de turma)>");
		printf("\n15 - <Imprimir a lista de todos os professores vinculados a uma disciplina (independente de turma)>");
		printf("\n0 - <Sair>\n>>>");
		fflush(stdin);
		scanf("%i", &opcao);
		system("cls");
		switch (opcao) {


		case 1://cadastro alunos
			do {
				alunos[posAluno] = cadastraAluno(alunos, posAluno);
				posAluno = attPosA(alunos);
				printf("Cadastrar mais alunos? (s \\ n) \n");
				getchar();
				scanf("%c", &more);
			} while (more == 's');

			break;

		case 2://cadastrar disciplina

			do {
				printf("Digite o nome da disciplina:\n>>");
				getchar();
				scanf("%s", &disc1[posDisc1].nome);
				disc1[posDisc1].empty = 0;
				disc2[posDisc2].empty = 0;
				strcpy(disc2[posDisc2].nome, disc1[posDisc1].nome);
				posDisc1 = attPosD(disc1);
				posDisc2 = attPosD(disc2);
				getchar();
				printf("Cadastrar mais disciplinas? (s \\ n)\n");
				scanf("%c", &more);
			} while (more == 's');

			break;

		case 3://cadastro professores
			do {
				profs[posProf] = cadastraProf(profs, posProf);
				posProf = attPosP(profs);
				printf("Cadastrar mais professores? (s \\ n) \n");
				getchar();
				scanf("%c", &more);
			} while (more == 's');

			break;


		case 4://realizar matricula

			printf("Em qual turma voce deseja realizar a matricula?\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &opcao);
			switch (opcao) {
			case 1:
				matriculaAluno(disc1, posDisc1,alunos,posAluno);
				posDisc1 = attPosD(disc1);
				break;
			case 2:
				matriculaAluno(disc2, posDisc2,alunos,posAluno);
				posDisc2 = attPosD(disc2);
				break;
			default:
				printf("Opcao Invalida\n");
				break;

			}


			break;

		case 5://cancelar matricula
			break;


		case 6://vincular profs
			break;
	
		case 7://remover vinculo
			break;

		case 8://imprimir todos alunos
			printf("Nome          RA\n");
			for (i = 0; i < MAX_ALUNO; i++) {

				if (alunos[i].empty == 0) {//false
					
					printf("%s        %i\n", alunos[i].nome, alunos[i].ra);
				}
			}
			printf("\n");
			system("pause");

			break;
		case 9://imprimir todas as disciplinas
			printf("Nome\n");
			for (i = 0; i < MAX_DISC; i++) {

				if (disc1[i].empty == 0) {//false
					printf("%s\n", disc1[i].nome);
				}
			}
			printf("\n");
			system("pause");

			break;
		case 10://imprimir todos professores
			printf("Nome          RP\n");
			for (i = 0; i < MAX_PROF; i++) {

				if (profs[i].empty == 0) {//false
					
					printf("%s        %i\n", profs[i].nome, profs[i].rp);
				}
			}
			printf("\n");
			system("pause");
			break;
		case 11://Imprimir a lista de disciplinas de um aluno


			printf("Digite o RA do aluno:\n>>");
			scanf("%i", &opcao);

			printf("Nome da disciplina\n\n");
			for (i = 0; i < MAX_DISC; i++) {
				
				if (disc1[i].empty == 0) {
					for (j = 0; j < MAX_ALUNO_DISC; j++) {

						if (disc1[i].alunos[j].empty == 0) {
							if (disc1[i].alunos[j].ra == opcao) {
								printf("%s\n", disc1[i].nome);
								
							}
						}
					}

				}
			}
			printf("\n");
			system("pause");
			break;
		case 12://Imprimir a lista de alunos em uma disciplina e turma

			if (disc1[0].empty != 0) {
				printf("Sem disciplinas cadastradas\n");
				system("pause");
				break;
			}

		
			printf("#		Nome\n\n");
			for (i = 0; i < MAX_DISC; i++) {
				if (disc1[i].empty == 0) {
					printf("%i	-	%s\n", i, disc1[i].nome);
				}
			}
			printf("\nEscolha a disciplina:\n>>");
			scanf("%i", &op2);
			if (op2 > i) {
				printf("Opcao invalida\n");
				break;
			}
				printf("Nome		RA\n\n");
				for (j = 0; j < MAX_ALUNO_DISC; j++) {
					if (disc1[op2].alunos[j].empty == 0) {
						
						printf("%s		%i\n", disc1[op2].alunos[j].nome);

					}
				}
				printf("\n");
				system("pause");

			break;
		case 13://Imprimir a lista de alunos em uma disciplina, independente da turma>");
			break;
		case 14://Imprimir a lista de todas as disciplinas ministradas por um professor (independente de turma)
			break;
		case 15://Imprimir a lista de todos os professores vinculados a uma disciplina (independente de turma)
			break;

		default:
			printf("Opcao invalida\n");
			break;
		}

	} while (opcao != 0);

	return 0;
}



Aluno cadastraAluno(Aluno alunos[], int posAluno) {

	Aluno entryAluno;
	int i;
	printf("\nDigite o RA do aluno:\n>>");
	getchar();
	scanf("%i", &entryAluno.ra);

	for (i = 0; i < MAX_ALUNO; i++) {

		if (alunos[i].ra == entryAluno.ra) {
			//RA CADASTRADO
			printf("RA ja cadastrado no sistema\n");
			return alunos[posAluno];
		}

	}
	//RA NAO CADASTRADO
	printf("\nDigite o nome do aluno:\n>>");
	getchar();
	scanf("%s", &entryAluno.nome);

	entryAluno.empty = 0;
	return entryAluno;

}

Professor cadastraProf(Professor profs[], int posProf) {

	Professor entryProf;
	int i;
	printf("\nDigite o RP do professor:\n>>");
	getchar();
	scanf("%i", &entryProf.rp);

	for (i = 0; i < MAX_PROF; i++) {

		if (profs[i].rp == entryProf.rp) {
			//RA CADASTRADO
			printf("RP ja cadastrado no sistema\n");
			return profs[posProf];
		}

	}
	//RA NAO CADASTRADO
	printf("\nDigite o nome do professor:\n>>");
	getchar();
	scanf("%s", &entryProf.nome);

	entryProf.empty = 0;//false
	return entryProf;

}

int matriculaAluno(Disciplina *disc, int posDisc,Aluno alunos[],int posAluno){

	int i,opcao,contaAlunos=0,contaDisc=0,j;
	char mais;
	Aluno alunosMatricula[MAX_ALUNO];
	Disciplina discMatricula[MAX_ALUNO];

	if (posAluno == 0) {
		printf("Cadastre alunos primeiro\n");
		system("pause");
		return -1;
	}
	if (posDisc == 0) {
		printf("Cadastre disciplinas primeiro\n");
		system("pause");
		return -1;
	}


	do {
		system("cls");
		printf("Escolha os alunos a matricular:\tqtd de alunos selecionados = %i\n\n",contaAlunos);
		printf("#		Nome	RA\n");
		for (i = 0; i < MAX_ALUNO; i++) {
			if (alunos[i].empty == 0) {//false

				for (j = 0; j < contaAlunos; j++) {
					if (alunosMatricula[j].ra == alunos[i].ra) {
						i++;
					}
				}
				printf("%i	-	%s	%i\n", i, alunos[i].nome, alunos[i].ra);

			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);

		if(alunos[opcao].empty == 0){
			strcpy(alunosMatricula[contaAlunos].nome, alunos[opcao].nome);
			alunosMatricula[contaAlunos].ra = alunos[opcao].ra;
			contaAlunos++;
		}
		else {
			printf("Opcao invalida\n");
			mais = 's';
		}
	
		printf("Deseja selecionar mais alunos? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');
	
	do {
		system("cls");
		printf("Escolha as disciplinas a matricular os alunos:\tqtd de disciplinas selecionadas = %i\n\n", contaDisc);
		printf("#		Nome\n");
		for (i = 0; i < MAX_DISC; i++) {
			if (disc[i].empty == 0) {//false

				for (j = 0; j < contaDisc; j++) {
					if (strcmp(discMatricula[j].nome, disc[i].nome) == 0) {
						i++;
					}
				}
				printf("%i	-	%s\n", i, disc[i].nome);

			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);
		if (disc[opcao].empty == 0) {
			strcpy(discMatricula[contaDisc].nome, disc[opcao].nome);
			contaDisc++;
			printf("Deseja selecionar mais disciplinas? (s \\ n)\n>>");
			getchar();
			scanf("%c", &mais);
		}
		else {
			printf("Opcao invalida");
			mais = 's';
		}
		

	} while (mais == 's');

	system("cls");
	printf("Sera efetuada a matricula deste(s) aluno(s):\n\n");
	for (i = 0; i < contaAlunos; i++) {
		printf("%s		%i\n",alunosMatricula[i].nome,alunosMatricula[i].ra);
	}
	printf("\nNessa(s) disciplinas(s)\n\n");
	for (i = 0; i < contaDisc; i++) {
		printf("%s\n", discMatricula[i].nome);
	}
	printf("\nConfirma? (s \\ n)\n>>");
	getchar();
	scanf("%c", &mais);
	if (mais != 's') {
		printf("CANCELADO\n");
		return 0;
	}

	for (i = 0; i < contaDisc; i++) {
		for (j = 0; j < contaAlunos; j++) {

			disc[i].alunos[j].ra = alunosMatricula[j].ra;
			strcpy(disc[i].alunos[j].nome, alunosMatricula[j].nome);
			disc[i].alunos[j].empty = 0;//nao vazio
		}
	}
	return 1;
}






