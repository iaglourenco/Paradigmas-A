%lista 2


s(1,um).
s(f(1),dois).
s(f(f(1)),três).
s(f(f(f(X))),N):- s(X,N).

%1

%s(f(1),X). = dois
%s(f(f(1)),dois). = false
%s(f(f(f(f(f(f(1)))))),X). = um
%s(X,três). = tres, loop infinito no ultimo predicado

%2
%sucede, X e uma variavel e f(X) um valor

conc([],L,L).
conc([X|L1],L2,[X|L]) :-
    conc(L1,L2,L).
%3





%6a
ultimo(X,[X]).




%6b
ultimo(X,[X]).
ultimo(X,[_|Cauda]) :-
    ultimo(X,Cauda).

