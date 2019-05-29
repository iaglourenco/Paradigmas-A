um_dos_pais(paula,roberto).
um_dos_pais(tomas,roberto).
um_dos_pais(tomas,atila).
um_dos_pais(tomas,luisa).

um_dos_pais(roberto,ana).
um_dos_pais(roberto,patricia).
um_dos_pais(patricia,joao).

mulher(paula).
mulher(ana).
mulher(patricia).
homem(roberto).
homem(tomas).
homem(joao).

tem_filho(X) :-um_dos_pais(X,_).

irma(X,Y) :-
    um_dos_pais(Z,X),
    um_dos_pais(Z,Y),
    mulher(X),
    X\=Y.

irmao(X,Y) :-
    um_dos_pais(Z,X),
    um_dos_pais(Z,Y),
    homem(X),
    X\=Y.

%lista 1

%1a
feliz(X) :- tem_filho(X).

%1b
tem_dois_filhos(X) :-
    um_dos_pais(X,Y),
    um_dos_pais(X,Z),
    Y\=Z.
%2
neto(X,Y) :-
    um_dos_pais(Y,Z),
    um_dos_pais(Z,X).
%3
tia(X,Y) :-
    um_dos_pais(Z,Y),
    irma(X,Z).
%4

gosta_de_comer(joao,X):-alimento(X).
alimento(maça).
alimento(ostras).
alimento(X) :- come(Z,X),vivo(Z).
come(andre,cobras).
vivo(andre).
come(sueli,X):- come(andre,X).

%5
estuda(maria).
passa_em_calculo(X):- estuda(X) ; sorte(X).
feliz(X) :- passa_em_calculo(X) ; loteria(X).
sorte(joao).
loteria(X):-sorte(X).
