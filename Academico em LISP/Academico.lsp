;;Iago Lourenço - 15610116
;;Academico.lsp
	;;cdar BD = nome da disciplina
	;;caaaar BD = alunos da turma 1
	;;cdaaar BD = alunos da turma 2
	;;cdaar BD = professores

;;FINISHED - MATRICULAR,VINCULAR,CANCELAR-MATRICULA,REMOVER-VINCULO,ALUNOS?,PROFESSORES?,MATRICULADOS?,VINCULADOS?,CURSA?,MINISTRA?

;;Matricula cada um dos alunos na lista ALUNOS em  todas as disciplinas da lista DISCIPLINAS, na  TURMA indicada.
(defun MATRICULAR (ALUNOS DISCIPLINAS TURMA BD) 

	(if (eql TURMA 1) ;;cadastre na turma 1 FINISHED
	
		(if (and (null BD) (null DISCIPLINAS))
			nil	
			(if (find (cdar BD) DISCIPLINAS);;vejo se a disciplina do BD tem o mesmo nome de alguma e DISCIPLINAS
				(cons(cons(cons (cons (union (caaaar BD) ALUNOS) (cdaaar BD)) (cdaar BD))(cdar BD)) (MATRICULAR ALUNOS (remove (cdar BD) DISCIPLINAS) TURMA (cdr BD)));;se tiver cadastro os alunos e removo a disciplina de DISCIPLINAS
				(if (null (cdar BD));; se nao vejo se nao tem alguma disciplina e cadastro a nova e removo a discilpina de DISCIPLINAS
				(cons (cons(cons (cons (union (caaaar BD) ALUNOS) (cdaaar BD)) (cdaar BD))(car DISCIPLINAS)) (MATRICULAR ALUNOS (remove (car DISCIPLINAS) DISCIPLINAS) TURMA (cdr BD)))
				;;se tiver apenas copio
				(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (MATRICULAR ALUNOS DISCIPLINAS TURMA (cdr BD)))
				)
			)
		)	
		(if (and (null BD) (null DISCIPLINAS)) ;; cadastre na turma 2 FINISHED
			nil	
			(if (find (cdar BD) DISCIPLINAS);;vejo se a disciplina do BD tem o mesmo nome de alguma e DISCIPLINAS
				(cons(cons(cons (cons (caaaar BD) (union (cdaaar BD) ALUNOS)) (cdaar BD))(cdar BD)) (MATRICULAR ALUNOS (remove (cdar BD) DISCIPLINAS) TURMA (cdr BD)));;se tiver cadastro os alunos e removo a disciplina de DISCIPLINAS
				(if (null (cdar BD));; se nao vejo se nao tem alguma disciplina e cadastro a nova e removo a discilpina de DISCIPLINAS
				(cons (cons(cons (cons (caaaar BD) (union (cdaaar BD) ALUNOS)) (cdaar BD))(car DISCIPLINAS)) (MATRICULAR ALUNOS (remove (car DISCIPLINAS) DISCIPLINAS) TURMA (cdr BD)))
				;;se tiver apenas copio
				(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (MATRICULAR ALUNOS DISCIPLINAS TURMA (cdr BD)))
				)
			)
		)
	)
)
;;Cancelar a matrícula cada um dos alunos na lista  ALUNOS de todas as disciplinas da lista  DISCIPLINAS na TURMA indicada. 
;;Disciplinas não  vinculadas a nenhum professor e sem alunos  matriculados devem ser removidas da base
(defun CANCELAR-MATRICULA (ALUNOS DISCIPLINAS TURMA BD)
;;(remove 'NOME LISTA) retorna a LISTA sem o NOME

	(if (eql TURMA 1)

		(if (or (null BD) (null DISCIPLINAS))
			nil
			(if (null DISCIPLINAS) 
				(limpa-bd (cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS DISCIPLINAS TURMA (cdr BD))))
			
				(if (find (cdar BD) DISCIPLINAS) 
					(limpa-bd(cons(cons(cons (cons (set-difference (caaaar BD) ALUNOS)(cdaaar BD)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS (remove (cdar BD) DISCIPLINAS) TURMA (cdr BD))))
					(limpa-bd(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS DISCIPLINAS TURMA (cdr BD))))
				)
			)
		)
		;;TURMA 2
		(if (or (null BD) (null DISCIPLINAS))
			nil
			(if (null DISCIPLINAS)
				(limpa-bd (cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS DISCIPLINAS TURMA (cdr BD))))
				
				(if (find (cdar BD) DISCIPLINAS) 
					(limpa-bd (cons(cons(cons (cons (caaaar BD)(set-difference (cdaaar BD) ALUNOS)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS (remove (cdar BD) DISCIPLINAS) TURMA (cdr BD))))
					(limpa-bd (cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (CANCELAR-MATRICULA ALUNOS DISCIPLINAS TURMA (cdr BD))))
				)
			)
		)
	)
)

;;Vincular cada um dos professores na lista  PROFESSORES  a cada uma das disciplinas na lista  DISCIPLINAS
(defun VINCULAR (PROFESSORES DISCIPLINAS BD) 

	(if (and (null BD) (null DISCIPLINAS))
		nil
		(if (find (cdar BD) DISCIPLINAS);vejo se a discilpina tem o mesmo nome
			(cons(cons(cons(cons (caaaar BD) (cdaaar BD)) (union (cdaar BD) PROFESSORES))(cdar BD)) (VINCULAR PROFESSORES (remove (cdar BD) DISCIPLINAS) (cdr BD)))
			(if (null (cdar BD));; se nao vejo se nao tem alguma disciplina e cadastro a nova
			(cons(cons(cons(cons (caaaar BD) (cdaaar BD)) (union (cdaar BD) PROFESSORES))(car DISCIPLINAS)) (VINCULAR PROFESSORES (remove (car DISCIPLINAS) DISCIPLINAS) (cdr BD)))
			;;se tiver apenas copio
			(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (VINCULAR PROFESSORES DISCIPLINAS (cdr BD)))
			)
		)
	)
)

;;Remover o vínculo de cada um dos professores na  lista PROFESSORES  a cada uma das disciplinas na  lista DISCIPLINAS; 
;;Disciplinas não vinculadas a  nenhum professor e sem alunos matriculados devem  ser removidas da base.
(defun REMOVER-VINCULO (PROFESSORES DISCIPLINAS BD)


	(if (or (null BD) (null DISCIPLINAS))
			nil
			(if (or (null DISCIPLINAS) (null BD))
				(limpa-bd(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (REMOVER-VINCULO PROFESSORES DISCIPLINAS (cdr BD))))
		
				(if (find (cdar BD) DISCIPLINAS) 
					(limpa-bd(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (set-difference (cdaar BD) PROFESSORES))(cdar BD)) (REMOVER-VINCULO PROFESSORES (remove (cdar BD) DISCIPLINAS)(cdr BD))))
					(limpa-bd(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (REMOVER-VINCULO PROFESSORES DISCIPLINAS (cdr BD))))
				)
			)
	)
	
)
;;REMOVE DISCIPLINAS SEM PROFESSORES E ALUNOS
(defun limpa-bd (BD)

	(if (null BD)
		nil
		(if (and (null (cdaar BD)) (null (caaaar BD)) (null (cdaaar BD)))
			(limpa-bd (cdr BD))
			(cons(cons(cons (cons (caaaar BD)(cdaaar BD)) (cdaar BD))(cdar BD)) (limpa-bd (cdr BD)))
		)
	)
)
;;=================================================================PRINTS======================================================================================
;;Lista contendo o nome de todos os alunos  cadastrados
(defun ALUNOS? (BD)

	(if (null BD)
		nil
		(union (union (caaaar BD) (ALUNOS? (cdr BD))) (union(cdaaar BD) (ALUNOS? (cdr BD))))
	)
)


;;Lista contendo o nome de todos os professores  cadastrados.
(defun PROFESSORES? (BD)
	
	(if (null BD)
		nil
		(union (cdaar BD) (PROFESSORES? (cdr BD)))
	)
)

;;Lista contendo o nome de todos os alunos  matriculados na disciplina DISCIPLINA em uma  determinada TURMA.
(defun MATRICULADOS? (DISCIPLINA TURMA BD)

	(if (null BD)
		nil
		(if (eql TURMA 1)
			(if (eql (car DISCIPLINA) (cdar BD))
				(caaaar BD)
				(MATRICULADOS? DISCIPLINA TURMA (cdr BD))
			)
			;;TURMA 2
			(if (eql (car DISCIPLINA) (cdar BD))
				(cdaaar BD) 		
				(MATRICULADOS? DISCIPLINA TURMA (cdr BD))
			)
		)
	)
)

;;Lista contendo o nome de todos os professores  vinculados à disciplina DISCIPLINA. 
(defun VINCULADOS? (DISCIPLINA BD)

	(if (null BD)
	nil
		(if (eql (car DISCIPLINA) (cdar BD))
			(cdaar BD)
			(VINCULADOS? DISCIPLINA (cdr BD))
		)
		
	)
)


;;Lista contendo o nome de todas as disciplinas  cursadas pelo aluno ALUNO.
(defun CURSA? (ALUNO BD)

	(if (null BD)
		nil
		(if (or(eql (find ALUNO (caaaar BD)) ALUNO) (eql (find ALUNO (cdaaar BD)) ALUNO) )
			(cons (cdar BD) (CURSA? ALUNO (cdr BD)))
			(CURSA? ALUNO (cdr BD))
		)
	)
)

;;Lista contendo o nome de todas as disciplinas  ministradas pelo professor PROFESSOR. 
(defun MINISTRA? (PROFESSOR BD)

	(if (null BD)
		nil
		(if (eql (find PROFESSOR (cdaar BD)) PROFESSOR) 
			(cons (cdar BD) (MINISTRA? PROFESSOR (cdr BD)))
			(MINISTRA? PROFESSOR (cdr BD))
		)
	)


)

