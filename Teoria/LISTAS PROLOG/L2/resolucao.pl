%lista 2


s(1,um).
s(f(1),dois).
s(f(f(1)),três).
s(f(f(f(X))),N):- s(X,N).



%1

%s(f(1),X). = dois
%s(f(f(1)),dois). = false
%s(f(f(f(f(f(f(1)))))),X). = um
%s(X,três). = loop infinito no ultimo predicado

%2
%sucede, X e uma variavel e f(X) um valor
