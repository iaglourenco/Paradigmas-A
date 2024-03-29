%Sao_Paulo
voo(sao_paulo,mexico,sp1,19:30,(mesmo,23:30),0,gol,[qua]).
voo(sao_paulo,nova_york,sp2,17:15,(seguinte,1:30),0,tam,[seg,ter,sab]).
voo(sao_paulo,lisboa,sp3,21:30,(seguinte,3:30),0,passaredo,[sex,sab]).
voo(sao_paulo,madrid,sp4,8:15,(mesmo,12:30),0,passaredo,[qua,sex]).
voo(sao_paulo,londres,sp5,16:30,(mesmo,23:30),0,tam,[dom,qui,sex,sab]).
voo(sao_paulo,paris,sp6,21:45,(seguinte,4:50),0,tam,[seg,sab]).

%Mexico
voo(mexico,nova_york,me1,14:00,(mesmo,19:30),0,gol,[dom,qua,sex]).
voo(mexico,paris,me2,12:00,(mesmo,23:30),0,tam,[ter,sab,dom]).

%Nova_York
voo(nova_york,londres,ny1,20:15,(seguinte,00:30),0,passaredo,[dom,seg,ter,sex,sab]).

%Londres
voo(londres,lisboa,lon1,5:10,(mesmo,8:30),0,gol,[qui,sex]).
voo(londres,paris,lon2,15:00,(mesmo,17:50),0,tam,[dom,seg,sex,sab]).
voo(londres,estocolmo,lon3,14:30,(mesmo,16:00),0,tam,[seg,sex]).

%Madrid
voo(madrid,paris,ma1,15:35,(mesmo,18:30),0,passaredo,[qui,sex]).
voo(madrid,roma,ma2,15:00,(mesmo,14:50),0,tam,[seg,sex,sab]).
voo(madrid,frankfurt,ma3,17:30,(seguinte,23:10),0,gol,[dom,sex,sab]).

%Frankfurt
voo(frankfurt,estocolmo,frank1,10:35,(mesmo,16:30),0,tam,[qui,sex,sab]).
voo(frankfurt,roma,frank2,22:00,(seguinte,2:50),0,passaredo,[seg,sex,sab]).

%funcoes_auxiliares
pertence(X,[X|Cauda]).
pertence(X,[Cabeca|Cauda]) :- pertence(X,Cauda).

acrescentarFim(X,[],[X]).
acrescentarFim(X,[Y|L1],[Y|L2]):- acrescentarFim(X,L1,L2).


%exercicio1
voo_direto(Origem,Destino,Companhia,Dia,Horario) :- voo(Origem,Destino,_,Horario,(_,_),0,Companhia,Lista), pertence(Dia,Lista).

%exercicio2
roteiro(Origem,Destino,Listavoo) :- voo(Origem,Destino,Cod,_,(_,_),0,_,_),
	                            acrescentarFim(Cod,[],Listavoo).
roteiro(Origem,Destino,Lista) :- voo(Novaorigem,Destino,Cod,_,(_,_),0,_,_),
	                            roteiro(Origem,Novaorigem,Listavoo),
				    acrescentarFim(Cod,Listavoo,Lista).

%exercicio3
filtra_voo_dia_semana(Origem,Destino,DiaSemana,HorarioSaida,HorarioChegada,Companhia):-
voo(Origem,Destino,_,HorarioSaida,(_,HorarioChegada),0,Companhia,DiaSemana), pertence(Dia,Lista),!.
