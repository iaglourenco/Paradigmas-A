#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROF 15
#define MAX_ALUNO 15
#define MAX_ALUNO_DISC 15
#define MAX_DISC 15

typedef struct {
	int ra;
	char nome[20];
	int empty; //flag, 0 tem algo, 1 nao tem nada
}Aluno;

typedef struct {
	int rp;
	char nome[20];
	int empty; //flag, 0 tem algo, 1 nao tem nada
}Professor;

typedef struct {
	char nome[20];
	Professor prof;
	Aluno alunos[MAX_ALUNO_DISC];
	int empty; //flag, 0 tem algo, 1 nao tem nada
}Disciplina;

typedef struct {
	int qAlunos;
	int qProfs;
	int qDisc;
}Contador;

Aluno cadastraAluno(Aluno alunos[], int posAluno, Contador *contador);//ok
Professor cadastraProf(Professor profs[], int posProf, Contador *contador);//ok
int hasLetter(char s[]);
int matriculaAluno(Disciplina *disc, Aluno alunos[], Contador *contador, int turma);//ok
int cancelaMatricula(Disciplina *disc, Aluno alunos[], Contador *contador, int turma);//ok
int vinculaProf(Disciplina *disc, Professor profs[], Contador *contador);//falta testar
int cancelaVinculo(Disciplina *disc, Professor profs[], Contador *contador);//copia do vincula


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

	int opcao = 0, i, j;
	char more;
	int op2, op3;

	int posAluno = 0; //indica a proxima posicao disponivel para cadastro
	int posProf = 0;
	int posDisc1 = 0;
	int posDisc2 = 0;

	Aluno alunos[MAX_ALUNO];
	Professor profs[MAX_PROF];
	Disciplina disc1[MAX_DISC];
	Disciplina disc2[MAX_DISC];
	Contador contador;
	contador.qAlunos = 0;
	contador.qProfs = 0;
	contador.qDisc = 0;

	for (i = 0; i < MAX_ALUNO; i++) {
		alunos[i].empty = 1;
		alunos[i].ra = -99;
	}
	for (i = 0; i < MAX_PROF; i++) {
		profs[i].empty = 1;
		profs[i].rp = -99;
	}

	for (i = 0; i < MAX_ALUNO; i++) {
		disc1[i].empty = 1;
		disc2[i].empty = 1;
		disc1[i].prof.empty = 1;
		disc2[i].prof.empty = 1;
		for (j = 0; j < MAX_ALUNO; j++) {
			disc1[i].alunos[j].ra = -99;
			disc2[i].alunos[j].ra = -99;
		}
	}

	do {
		system("cls");
		printf("\t<PROJETO EM C [SISTEMA ACADEMICO]>\n");
		printf("\n1  - <Cadastrar Aluno>");//ok
		printf("\n2  - <Cadastrar Disciplina>");//ok
		printf("\n3  - <Cadastrar Professor>");//ok
		printf("\n4  - <Realizar Matricula>");//ok
		printf("\n5  - <Cancelar Matricula>");
		printf("\n6  - <Vincular professores a disciplinas>");
		printf("\n7  - <Remover vinculo de professores a disciplinas>");
		printf("\n8  - <Imprimir a lista de alunos>");//ok
		printf("\n9  - <Imprimir a lista de disciplinas>");//ok
		printf("\n10 - <Imprimir a lista de professores>");//ok
		printf("\n11 - <Imprimir a lista de disciplinas de um aluno>");//ok
		printf("\n12 - <Imprimir a lista de alunos em uma disciplina e turma>");//ok
		printf("\n13 - <Imprimir a lista de alunos em uma disciplina, independente da turma>");
		printf("\n14 - <Imprimir a lista de todas as disciplinas ministradas por um professor (independente de turma)>");
		printf("\n15 - <Imprimir a lista de todos os professores vinculados a uma disciplina (independente de turma)>");
		printf("\n0  - <Sair>\n>>>");
		fflush(stdin);
		scanf("%i", &opcao);
		system("cls");
		switch (opcao) {


		case 1://cadastro alunos
			printf("\t\tCadastrar alunos\n\n");
			if (contador.qAlunos == MAX_ALUNO) {
				printf("MAXIMO DE ALUNOS ATINGIDO!\n");
				system("pause");
				break;
			}

			do {
				alunos[posAluno] = cadastraAluno(alunos, posAluno, &contador);
				posAluno = attPosA(alunos);
				printf("Cadastrar mais alunos? (s \\ n) \n");
				getchar();
				scanf("%c", &more);
				if (contador.qAlunos == MAX_ALUNO) {
					printf("MAXIMO DE ALUNOS ATINGIDO!\n");
					system("pause");
					break;
				}
			} while (more == 's');

			break;

		case 2://cadastrar disciplina
			printf("\t\tCadastrar disciplinas\n\n");
			if (contador.qDisc == MAX_DISC) {
				printf("MAXIMO DE DISCIPLINAS ATINGIDO!\n");
				system("pause");
				break;
			}

			do {
				printf("Digite o nome da disciplina:\n>>");
				getchar();
				scanf("%s", &disc1[posDisc1].nome);
				disc1[posDisc1].empty = 0;
				disc2[posDisc2].empty = 0;
				strcpy(disc2[posDisc2].nome, disc1[posDisc1].nome);
				posDisc1 = attPosD(disc1);
				posDisc2 = attPosD(disc2);
				contador.qDisc++;
				getchar();
				printf("Cadastrar mais disciplinas? (s \\ n)\n");
				scanf("%c", &more);
				if (contador.qDisc == MAX_DISC) {
					printf("MAXIMO DE DISCIPLINAS ATINGIDO!\n");
					system("pause");
					break;
				}
			} while (more == 's');

			break;

		case 3://cadastro professores
			printf("\t\tCadastrar professores\n\n");

			if (contador.qProfs == MAX_PROF) {
				printf("MAXIMO DE PROFESSORES ATINGIDO!\n");
				system("pause");
				break;
			}


			do {
				profs[posProf] = cadastraProf(profs, posProf, &contador);
				posProf = attPosP(profs);
				printf("Cadastrar mais professores? (s \\ n) \n");
				getchar();
				scanf("%c", &more);
				if (contador.qProfs == MAX_PROF) {
					printf("MAXIMO DE PROFESSORES ATINGIDO!\n");
					system("pause");
					break;
				}
			} while (more == 's');

			break;


		case 4://realizar matricula

			printf("Em qual turma voce deseja realizar a matricula?\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &opcao);
			switch (opcao) {
			case 1:
				matriculaAluno(disc1, alunos, &contador, 1);
				posDisc1 = attPosD(disc1);
				break;
			case 2:
				matriculaAluno(disc2, alunos, &contador, 2);
				posDisc2 = attPosD(disc2);
				break;
			default:
				printf("Opcao Invalida\n");
				break;

			}

			break;

		case 5://cancelar matricula
			printf("Em qual turma deseja cancelar a matricula?\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &opcao);
			switch (opcao) {
			case 1:
				cancelaMatricula(disc1, alunos, &contador, 1);
				break;
			case 2:
				cancelaMatricula(disc2, alunos, &contador, 2);
				break;

			default:
				printf("Opcao Invalida\n");
				break;

			}

			break;


		case 6://vincular profs
			printf("Em qual turma deseja vincular professor?\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &opcao);
			switch (opcao) {
			case 1:
				vinculaProf(disc1, profs, &contador);
				break;
			case 2:
				vinculaProf(disc2, profs, &contador);
				break;

			default:
				printf("Opcao Invalida\n");
				break;

			}

			break;

		case 7://remover vinculo
			printf("Em qual turma deseja desvincular professores?\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &opcao);
			switch (opcao) {
			case 1:
				cancelaVinculo(disc1, profs, &contador);
				break;
			case 2:
				cancelaVinculo(disc2, profs, &contador);
				break;

			default:
				printf("Opcao Invalida\n");
				break;

			}
			break;

		case 8://imprimir todos alunos
			printf("\t\tImprimir todos os alunos\n\nNome	RA\tAlunos cadastrados=%i\n", contador.qAlunos);
			for (i = 0; i < MAX_ALUNO; i++) {

				if (alunos[i].empty == 0) {//false

					printf("%-s	%-i\n", alunos[i].nome, alunos[i].ra);
				}
			}
			printf("\n");
			system("pause");

			break;
		case 9://imprimir todas as disciplinas
			printf("\t\tImprimir todas as disciplinas\n\n\tDisciplinas cadastradas=%i\nNome\n", contador.qDisc);
			for (i = 0; i < MAX_DISC; i++) {

				if (disc1[i].empty == 0) {//false
					printf("%-s\n", disc1[i].nome);
				}
			}
			printf("\n");
			system("pause");

			break;
		case 10://imprimir todos professores
			printf("\t\tImprimir todos os professores\n\n");
			printf("Todos os professores\n\tProfessores cadastrados=%i\nNome	RP\n", contador.qProfs);
			for (i = 0; i < MAX_PROF; i++) {

				if (profs[i].empty == 0) {//false

					printf("%-s	%-i\n", profs[i].nome, profs[i].rp);
				}
			}
			printf("\n");
			system("pause");
			break;
		case 11://Imprimir a lista de disciplinas de um aluno

			printf("\t\tImprimir a lista de disciplinas de um aluno\n\n");
			printf("Digite o RA do aluno:\n>>");
			scanf("%i", &opcao);

			printf("Nome		Turma\n\n");
			for (i = 0; i < MAX_DISC; i++) {

				if (disc1[i].empty == 0) {
					for (j = 0; j < MAX_ALUNO_DISC; j++) {

						if (disc1[i].alunos[j].empty == 0) {
							if (disc1[i].alunos[j].ra == opcao) {
								printf("%-s		%-s\n", disc1[i].nome, "T1");

							}
						}
					}

				}
			}
			for (i = 0; i < MAX_DISC; i++) {

				if (disc2[i].empty == 0) {
					for (j = 0; j < MAX_ALUNO_DISC; j++) {

						if (disc2[i].alunos[j].empty == 0) {
							if (disc2[i].alunos[j].ra == opcao) {
								printf("%-s		%-s\n", disc2[i].nome, "T2");

							}
						}
					}

				}
			}
			printf("\n");
			system("pause");
			break;
		case 12://Imprimir a lista de alunos em uma disciplina e turma
			printf("\t\tImprimir a lista de alunos em uma disciplina e turma\n\n");
			if (disc1[0].empty != 0) {
				printf("Sem disciplinas cadastradas\n");
				system("pause");
				break;
			}

			printf("#		Nome\n\n");
			for (i = 0; i < MAX_DISC; i++) {
				if (disc1[i].empty == 0) {
					printf("%-i	-	%-s\n", i, disc1[i].nome);
				}
			}
			printf("\nEscolha a disciplina:\n>>");
			scanf("%i", &op2);

			if (op2 > i) {
				printf("Opcao invalida\n");
				break;
			}

			printf("Qual turma?\n\n");
			printf("1 - TURMA 1\n");
			printf("2 - TURMA 2\n>>");
			scanf("%i", &op3);
			switch (op3) {

			case 1:
				printf("\n\nTurma 1\n\n");
				printf("Nome		RA\n\n");
				for (j = 0; j < MAX_ALUNO_DISC; j++) {
					if (disc1[op2].alunos[j].empty == 0) {

						printf("%-s		%-i\n", disc1[op2].alunos[j].nome, disc1[op2].alunos[j].ra);

					}
				}
				break;
			case 2:
				printf("\n\nTurma 2\n\n");
				printf("Nome		RA\n\n");
				for (j = 0; j < MAX_ALUNO_DISC; j++) {
					if (disc2[op2].alunos[j].empty == 0) {

						printf("%-s		%-i\n", disc2[op2].alunos[j].nome, disc2[op2].alunos[j].ra);

					}
				}
				break;
			default:
				printf("Opcao invalida!\n");
				break;

			}

			printf("\n");
			system("pause");

			break;
		case 13://Imprimir a lista de alunos em uma disciplina, independente da turma>");
			printf("\t\tImprimir a lista de alunos em uma disciplina, independente da turma>\n\n");
			if (disc1[0].empty != 0) {
				printf("Sem disciplinas cadastradas\n");
				system("pause");
				break;
			}

			printf("#		Nome\n\n");
			for (i = 0; i < MAX_DISC; i++) {
				if (disc1[i].empty == 0) {
					printf("%-i	-	%-s\n", i, disc1[i].nome);
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

					printf("%-s		%-i	\n", disc1[op2].alunos[j].nome, disc1[op2].alunos[j].ra);

				}
				if (disc2[op2].alunos[j].empty == 0) {

					printf("%-s		%-i	\n", disc2[op2].alunos[j].nome, disc2[op2].alunos[j].ra);

				}
			}


			printf("\n");
			system("pause");

			break;
		case 14://Imprimir a lista de todas as disciplinas ministradas por um professor, independente de turma
			printf("\t\tImprimir a lista de todas as disciplinas ministradas por um professor, independente de turma\n\n");
			printf("Nome disciplina		Nome professor\n\n");
			for (j = 0; j < MAX_DISC; j++) {
				if (disc1[j].prof.empty == 0) {

					printf("%-s             	%-s	\n", disc1[j].nome, disc1[j].prof.nome);

				}
				if (disc2[j].prof.empty == 0) {

					printf("%-s             	%-s	\n", disc2[j].nome, disc2[j].prof.nome);

				}
			}

			printf("\n");
			system("pause");


			break;
		case 15://Imprimir a lista de todos os professores vinculados a uma disciplina, independente de turma)
			printf("\t\tImprimir a lista de todos os professores vinculados a uma disciplina, independente de turma\n\n");
			printf("Nome		RP		Nome disciplina		Turma\n\n");
			for (j = 0; j < MAX_DISC; j++) {
				if (disc1[j].prof.empty == 0) {

					printf("%-s		%-i		%-s                      %-s\n", disc1[j].prof.nome, disc1[j].prof.rp, disc1[j].nome, "T1");

				}
				if (disc2[j].prof.empty == 0) {

					printf("%-s		%-i		%-s                      %-s\n", disc2[j].prof.nome, disc1[j].prof.rp, disc2[j].nome, "T2");

				}
			}

			printf("\n");
			system("pause");


			break;

		case 0:
			printf("Feito por: Iago Lourenco --> github\\@iaglourenco\n\nPressione qualquer teclar para sair...");
			system("pause>nul");

			break;

		default:
			printf("Opcao invalida\n");
			break;
		}

	} while (opcao != 0);

	return 0;
}


Aluno cadastraAluno(Aluno alunos[], int posAluno, Contador *contador) {

	Aluno entryAluno;
	int i;
	char buff[20];


	do {
		printf("\nDigite o RA do aluno: (SOMENTE NUMEROS)\n>>");
		getchar();
		scanf("%s", &buff);

		if (hasLetter(buff) > 0) {
			printf("\nSOMENTE NUMEROS!\n");
			printf("Pressione qualquer tecla para digitar novamente...\n");
			system("pause>nul");
			system("cls");
		}
		else {
			entryAluno.ra = atoi(buff);
			break;
		}

	} while (1);

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
	contador->qAlunos++;
	return entryAluno;

}

Professor cadastraProf(Professor profs[], int posProf, Contador *contador) {

	Professor entryProf;
	int i;
	char buff[20];

	do {
		printf("\nDigite o RP do professor: (SOMENTE NUMEROS)\n>>");
		getchar();
		scanf("%s", &buff);

		if (hasLetter(buff) > 0) {
			printf("\nSOMENTE NUMEROS!\n");
			printf("Pressione qualquer tecla para digitar novamente...\n");
			system("pause>nul");
			system("cls");
		}
		else {
			entryProf.rp = atoi(buff);
			break;
		}



	} while (1);




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
	contador->qProfs++;
	return entryProf;

}

int hasLetter(char s[])
{
	int counter = 0;
	int i;
	int tam = strlen(s);
	for (i = 0; i < tam; i++) {
		if (!isdigit(s[i]))//if it's not a number  
			counter++;
	}

	return counter;//return how many non-digits have
}

int matriculaAluno(Disciplina *disc, Aluno alunos[], Contador *contador, int turma) {

	int i, opcao, contaAlunos = 0, contaDisc = 0, j, k, l, m, jaCadastrado = 0;
	char mais;
	int err = 0;//sinaliza erros
	Aluno alunosMatricula[MAX_ALUNO];
	Disciplina discMatricula[MAX_DISC];

	if (contador->qAlunos == 0) {
		printf("Cadastre alunos primeiro\n");
		system("pause");
		return -1;
	}
	if (contador->qDisc == 0) {
		printf("Cadastre disciplinas primeiro\n");
		system("pause");
		return -1;
	}


	do {
		system("cls");
		printf("Escolha os alunos a matricular:\tqtd de alunos selecionados = %i\n\n", contaAlunos);
		printf("Nome	RA\n");
		for (i = 0; i < MAX_ALUNO; i++) {
			if (alunos[i].empty == 0) {//false

				for (j = 0; j < contaAlunos; j++) {

					if (alunosMatricula[j].ra == alunos[i].ra) {
						jaCadastrado = 1;
						break;
					}
				}

				if (alunos[i].empty == 0 && jaCadastrado != 1)
					printf("%-s	%-i\n", alunos[i].nome, alunos[i].ra);
				jaCadastrado = 0;


			}
		}
		printf("\nDigite RA>>>");
		scanf("%i", &opcao);
		err = 1;
		for (i = 0; i < MAX_ALUNO; i++) {

			if (alunos[i].ra == opcao) {
				strcpy(alunosMatricula[contaAlunos].nome, alunos[i].nome);
				alunosMatricula[contaAlunos].ra = alunos[i].ra;
				contaAlunos++;
				err = 0;
				break;
			}
		}

		if (err == 1) {
			printf("Opcao invalida\n");
			mais = 's';
			err = 0;
		}

		if (contaAlunos == contador->qAlunos) {
			break;
		}
		printf("Deseja selecionar mais alunos? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	do {
		jaCadastrado = 0;
		system("cls");
		printf("Escolha as disciplinas a matricular os alunos:\tqtd de disciplinas selecionadas = %i\n\n", contaDisc);
		printf("#        Nome\n");
		for (i = 0; i < MAX_DISC; i++) {
			if (disc[i].empty == 0) {//false

				for (j = 0; j < contaDisc; j++) {
					if (strcmp(discMatricula[j].nome, disc[i].nome) == 0) {
						jaCadastrado = 1;
						break;
					}
				}
				if (disc[i].empty == 0 && jaCadastrado != 1)
					printf("%-i-------- %-s\n", i + 1, disc[i].nome);
				jaCadastrado = 0;
			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);
		opcao--;
		for (j = 0; j < contaDisc; j++) {
			if (strcmp(discMatricula[j].nome, disc[opcao].nome) == 0) {
				err = 1;
				break;
			}
		}


		if (disc[opcao].empty == 0 && err == 0) {
			strcpy(discMatricula[contaDisc].nome, disc[opcao].nome);
			contaDisc++;
		}
		else {
			printf("Opcao invalida");
			mais = 's';
			err = 0;
		}


		if (contador->qDisc == contaDisc) {
			break;
		}

		printf("Deseja selecionar mais disciplinas? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	system("cls");
	printf("Sera efetuada a matricula deste(s) aluno(s):\n\n");
	for (i = 0; i < contaAlunos; i++) {
		printf("%-s----%-i\n", alunosMatricula[i].nome, alunosMatricula[i].ra);
	}
	printf("\nNessa(s) disciplinas(s)\n\n");
	for (i = 0; i < contaDisc; i++) {
		printf("%-s %-i\n", discMatricula[i].nome, turma);
	}
	printf("\nConfirma? (s \\ n)\n>>");
	getchar();
	scanf("%c", &mais);
	if (mais != 's') {
		printf("CANCELADO\n");
		return 0;
	}

	for (i = 0; i < MAX_DISC; i++) {//percorro todas as disciplinas

		for (j = 0; j < contaDisc; j++) {//vejo qual tem o mesmo nome da disciplina requerida na matricula

			if (strcmp(disc[i].nome, discMatricula[j].nome) == 0) {//se sim

				for (k = 0; k < contaAlunos; k++) {//cadastro todos os alunos nessa disciplina,
					jaCadastrado = 0;
					for (l = 0; l < MAX_ALUNO_DISC; l++) {//vejo qual a proxima posicao livre e guardo em 'l'
						if (disc[i].alunos[l].empty != 0)
							break;
					}
					if (l == MAX_ALUNO_DISC) {//vejo se chegou ao maximo de alunos
						break;
					}
					for (m = 0; m < MAX_ALUNO_DISC; m++) {//vejo se o aluno ja esta matriculado nessa disciplina
						if (disc[i].alunos[m].ra == alunosMatricula[k].ra) {
							jaCadastrado = 1;
							break;
						}
					}
					if (jaCadastrado == 0) {//cadastro
						disc[i].alunos[l].ra = alunosMatricula[k].ra;
						strcpy(disc[i].alunos[l].nome, alunosMatricula[k].nome);
						disc[i].alunos[l].empty = 0;//sinaliza o nao vazio, 0 tem algo, 1 nao tem nada
					}

				}

			}
		}

	}
	return 1;
}

int cancelaMatricula(Disciplina * disc, Aluno alunos[], Contador *contador, int turma)
{

	int i, opcao, contaAlunos = 0, contaDisc = 0, j, k, l, jaCadastrado = 0;
	char mais;
	int err = 0;//sinaliza erros
	Aluno alunosCancela[MAX_ALUNO];
	Disciplina discCancela[MAX_DISC];


	if (contador->qDisc == 0) {
		printf("Cadastre disciplinas primeiro\n");
		system("pause");
		return -1;
	}
	if (contador->qAlunos == 0) {
		printf("Cadastre alunos primeiro\n");
		system("pause");
		return -1;
	}

	do {
		system("cls");
		printf("Escolha os alunos que terao matriculas canceladas:\tqtd de alunos selecionados = %i\n\n", contaAlunos);
		printf("Nome	RA\n");

		for (i = 0; i < MAX_ALUNO; i++) {
			if (alunos[i].empty == 0) {//false

				for (j = 0; j < contaAlunos; j++) {

					if (alunosCancela[j].ra == alunos[i].ra) {
						jaCadastrado = 1;
						break;
					}
				}

				if (alunos[i].empty == 0 && jaCadastrado != 1)
					printf("%-s	%-i\n", i, alunos[i].nome, alunos[i].ra);

				jaCadastrado = 0;
			}
		}

		printf("\nDigite RA>>>");
		scanf("%i", &opcao);
		err = 1;
		for (i = 0; i < MAX_ALUNO; i++) {

			if (alunos[i].ra == opcao) {
				strcpy(alunosCancela[contaAlunos].nome, alunos[i].nome);
				alunosCancela[contaAlunos].ra = alunos[i].ra;
				contaAlunos++;
				err = 0;
				break;
			}
		}

		if (err == 1) {
			printf("Opcao invalida\n");
			mais = 's';
			err = 0;
		}

		if (contaAlunos == contador->qAlunos) {
			break;
		}
		printf("Deseja selecionar mais alunos? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	do {
		jaCadastrado = 0;
		system("cls");
		printf("Escolha as disciplinas a desmatricular os alunos:\tqtd de disciplinas selecionadas = %i\n\n", contaDisc);
		printf("#        Nome\n");
		for (i = 0; i < MAX_DISC; i++) {

			if (disc[i].empty == 0) {

				for (j = 0; j < contaDisc; j++) {
					if (strcmp(discCancela[j].nome, disc[i].nome) == 0) {
						jaCadastrado = 1;
						break;
					}
				}
				if (disc[i].empty == 0 && jaCadastrado != 1)
					printf("%-i-------- %-s\n", i + 1, disc[i].nome);
				jaCadastrado = 0;
			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);
		opcao--;
		for (j = 0; j < contaDisc; j++) {
			if (strcmp(discCancela[j].nome, disc[opcao].nome) == 0) {
				err = 1;
				break;
			}
		}


		if (disc[opcao].empty == 0 && err == 0) {
			strcpy(discCancela[contaDisc].nome, disc[opcao].nome);
			contaDisc++;
		}
		else {
			printf("Opcao invalida");
			mais = 's';
			err = 0;
		}


		if (contador->qDisc == contaDisc) {
			break;
		}

		printf("Deseja selecionar mais disciplinas? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	system("cls");
	printf("Sera efetuada o cancelamento da matricula deste(s) aluno(s):\n\n");
	for (i = 0; i < contaAlunos; i++) {
		printf("%-s		%-i\n", alunosCancela[i].nome, alunosCancela[i].ra);
	}
	printf("\nNessa(s) disciplinas(s)\n\n");
	for (i = 0; i < contaDisc; i++) {
		printf("%-s %-i\n", discCancela[i].nome, turma);
	}
	printf("\nConfirma? (s \\ n)\n>>");
	getchar();
	scanf("%c", &mais);
	if (mais != 's') {
		printf("CANCELADO\n");
		return 0;
	}

	for (i = 0; i < MAX_DISC; i++) {//percorro todas as disciplinas

		for (j = 0; j < contaDisc; j++) {//vejo qual tem o mesmo nome da disciplina requerida no cancelamento

			if (strcmp(disc[i].nome, discCancela[j].nome) == 0) {//se sim

				for (k = 0; k < MAX_ALUNO_DISC; k++) {//procuro cada aluno no BD de alunos de cada disciplinas 

					for (l = 0; l < contaAlunos; l++) {

						if (disc[i].alunos[k].ra == alunosCancela[l].ra) {
							//ao encontrar removo-o
							disc[i].alunos[k].ra = -99;
							disc[i].alunos[k].empty = 1;

						}
					}
				}
			}
		}
	}
	return 1;
}

int vinculaProf(Disciplina * disc, Professor profs[], Contador *contador) {
	int i, opcao, contaProfs = 0, contaDisc = 0, j, jaCadastrado = 0;
	char mais;
	int err = 0;//sinaliza erros
	Professor profMatricula;
	Disciplina discMatricula[MAX_DISC];

	if (contador->qProfs == 0) {
		printf("Cadastre professores primeiro\n");
		system("pause");
		return -1;
	}
	if (contador->qDisc == 0) {
		printf("Cadastre disciplinas primeiro\n");
		system("pause");
		return -1;
	}


	do {
		system("cls");
		printf("Escolha o professor a vincular:\n\n");
		printf("#        Nome	RP\n");
		for (i = 0; i < MAX_PROF; i++) {
			if (profs[i].empty == 0) {//false


				printf("%-i-------- %-s	%-i\n", i, profs[i].nome, profs[i].rp);

			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);

		if (profs[opcao].empty == 0) {
			strcpy(profMatricula.nome, profs[opcao].nome);
			profMatricula.rp = profs[opcao].rp;
			mais = 'n';
			break;
		}
		else {
			printf("Opcao invalida\n");
			mais = 's';
			err = 0;
		}

	} while (mais == 's');

	do {
		jaCadastrado = 0;
		system("cls");
		printf("Escolha as disciplinas a vincular o professor:\tqtd de disciplinas selecionadas = %i\n\n", contaDisc);
		printf("#		 Nome\n");
		for (i = 0; i < MAX_DISC; i++) {
			if (disc[i].empty == 0) {//false

				for (j = 0; j < contaDisc; j++) {
					if (strcmp(discMatricula[j].nome, disc[i].nome) == 0) {
						jaCadastrado = 1;
						break;
					}
				}
				if (disc[i].empty == 0 && jaCadastrado != 1)
					printf("%-i-------- %-s\n", i + 1, disc[i].nome);
				jaCadastrado = 0;
			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);
		opcao--;
		for (j = 0; j < contaDisc; j++) {
			if (strcmp(discMatricula[j].nome, disc[opcao].nome) == 0) {
				err = 1;
				break;
			}
		}


		if (disc[opcao].empty == 0 && err == 0) {
			strcpy(discMatricula[contaDisc].nome, disc[opcao].nome);
			contaDisc++;
		}
		else {
			printf("Opcao invalida");
			mais = 's';
			err = 0;
		}


		if (contador->qDisc == contaDisc) {
			break;
		}

		printf("Deseja selecionar mais disciplinas? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	system("cls");
	printf("Sera efetuado o vinculo deste professor:\n\n");
	printf("%-s----%-i\n", profMatricula.nome, profMatricula.rp);

	printf("\nNessa(s) disciplina(s)\n\n");
	for (i = 0; i < contaDisc; i++) {
		printf("%-s\n", discMatricula[i].nome);
	}
	printf("\nConfirma? (s \\ n)\n>>");
	getchar();
	scanf("%c", &mais);
	if (mais != 's') {
		printf("CANCELADO\n");
		return 0;
	}

	for (i = 0; i < MAX_DISC; i++) {//percorro todas as disciplinas

		for (j = 0; j < contaDisc; j++) {//vejo qual tem o mesmo nome da disciplina requerida na matricula

			if (strcmp(disc[i].nome, discMatricula[j].nome) == 0) {//se sim

				//cadastro o professor nessa disciplina,ignorando se ja tiver algum prof vinculado nessa disciplina
				disc[i].prof.rp = profMatricula.rp;
				strcpy(disc[i].prof.nome, profMatricula.nome);
				disc[i].prof.empty = 0;//sinaliza o nao vazio, 0 tem algo, 1 nao tem nada

			}
		}

	}
	return 1;
}

int cancelaVinculo(Disciplina * disc, Professor profs[], Contador *contador)
{
	int i, opcao, contaProfs = 0, contaDisc = 0, j, l, jaCadastrado = 0;
	char mais;
	int err = 0;//sinaliza erros
	Professor profsCancela[MAX_PROF];
	Disciplina discCancela[MAX_DISC];

	if (contador->qProfs == 0) {
		printf("Cadastre professores primeiro\n");
		system("pause");
		return -1;
	}
	if (contador->qDisc == 0) {
		printf("Cadastre disciplinas primeiro\n");
		system("pause");
		return -1;
	}


	do {
		system("cls");
		printf("Escolha os professores a desvincular:\tProfs selecionandos=%i\n\n", contaProfs);
		printf("#		 Nome	RP\n");
		for (i = 0; i < MAX_PROF; i++) {
			if (profs[i].empty == 0) {//false


				for (j = 0; j < contaProfs; j++) {

					if (profsCancela[j].rp == profs[i].rp) {
						jaCadastrado = 1;
						break;
					}
				}

				if (profs[i].empty == 0 && jaCadastrado != 1)
					printf("%-i-------- %-s	%-i\n", i, profs[i].nome, profs[i].rp);
				jaCadastrado = 0;

			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);

		for (i = 0; i < contaProfs; i++) {
			if (profsCancela[i].rp == profs[opcao].rp) {
				err = 1;//prof ja selecionado anteriormente
				break;
			}
		}

		if (profs[opcao].empty == 0) {
			strcpy(profsCancela[contaProfs].nome, profs[opcao].nome);
			profsCancela[contaProfs].rp = profs[opcao].rp;
			contaProfs++;
		}
		else {
			printf("Opcao invalida\n");
			mais = 's';
			err = 0;
		}

		if (contaProfs == contador->qProfs) {
			break;
		}
		printf("Deseja selecionar mais professores? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	do {
		jaCadastrado = 0;
		system("cls");
		printf("Escolha as disciplinas a vincular o professor:\tqtd de disciplinas selecionadas = %i\n\n", contaDisc);
		printf("#		 Nome\n");
		for (i = 0; i < MAX_DISC; i++) {
			if (disc[i].empty == 0) {//false

				for (j = 0; j < contaDisc; j++) {
					if (strcmp(discCancela[j].nome, disc[i].nome) == 0) {
						jaCadastrado = 1;
						break;
					}
				}
				if (disc[i].empty == 0 && jaCadastrado != 1)
					printf("%-i-------- %-s\n", i + 1, disc[i].nome);
				jaCadastrado = 0;
			}
		}
		printf("\n>>>");
		scanf("%i", &opcao);
		opcao--;
		for (j = 0; j < contaDisc; j++) {
			if (strcmp(discCancela[j].nome, disc[opcao].nome) == 0) {
				err = 1;
				break;
			}
		}


		if (disc[opcao].empty == 0 && err == 0) {
			strcpy(discCancela[contaDisc].nome, disc[opcao].nome);
			contaDisc++;
		}
		else {
			printf("Opcao invalida");
			mais = 's';
			err = 0;
		}


		if (contador->qDisc == contaDisc) {
			break;
		}

		printf("Deseja selecionar mais disciplinas? (s \\ n)\n>>");
		getchar();
		scanf("%c", &mais);

	} while (mais == 's');

	system("cls");
	printf("Sera cancelado o vinculo deste(s) professor(s):\n\n");
	for (i = 0; i < contaProfs; i++) {
		printf("%-s----%-i\n", profsCancela[i].nome, profsCancela[i].rp);
	}
	printf("\nNessa(s) disciplina(s)\n\n");
	for (i = 0; i < contaDisc; i++) {
		printf("%-s\n", discCancela[i].nome);
	}
	printf("\nConfirma? (s \\ n)\n>>");
	getchar();
	scanf("%c", &mais);
	if (mais != 's') {
		printf("CANCELADO\n");
		return 0;
	}

	for (i = 0; i < MAX_DISC; i++) {//percorro todas as disciplinas

		for (j = 0; j < contaDisc; j++) {//vejo qual tem o mesmo nome da disciplina requerida

			if (strcmp(disc[i].nome, discCancela[j].nome) == 0) {//se sim

				for (l = 0; l < contaProfs; l++) {

					if (disc[i].prof.rp == profsCancela[l].rp) {//acho o professor 
						//removo o professor nessa disciplina
						disc[i].prof.empty = 1;//sinaliza o nao vazio, 0 tem algo, 1 nao tem nada
						break;
					}

				}

			}
		}

	}
	return 1;
}








