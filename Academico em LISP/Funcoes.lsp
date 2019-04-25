;;Cria uma lista de numeros de a ate b
(defun enumera (a b)
	
		(if (= a b)
			(cons a nil)
		(cons a (enumera (1+ a) b))
		)
)

;;Encontra o n-esimo elemento numa lista
(defun n-esimo (n lista)

		(if (zerop n)
			(car lista)
		(n-esimo (1- n)(cdr lista))
		)
)
;;Muda o n-esimo elemento numa lista
(defun muda-n-esimo (n el lista)
	
		(if(zerop n)
			(cons el (cdr lista))
		(cons (car lista) (muda-n-esimo (1- n) el (cdr lista)))
		)
)

;;Encontra n do elemento na lista
(defun get-n (el lista)

	(if (or (null lista) (eql el (car lista)))
		(if (null lista)
			nil
			0
		)
		(1+ (get-n el (cdr lista)))
		
	)
)
;;Retorna o ultimo elemento de uma lista
(defun ultimo (l)
	
	(if (null l)
		(car l)
	(ultimo (cdr l))
	)
)
;;Retorna quantos numeros existem numa lista
(defun conta-numeros (l)
	(if (null l)
		0
		(if (numberp (car l))
			(1+ (conta-numeros (cdr l)))
			(conta-numeros (cdr l))
		)
	)
)
;;Retorna a quantidade de elementos numa lista
(defun qtd (l)
	(if (null l)
		0
	(1+ (qtd (cdr l)))
	)
)

;;Retorna t caso a l1>l2
(defun mais-longap (l1 l2)

	(if (> (qtd l1) (qtd l2))
		t
		nil
	)
)

