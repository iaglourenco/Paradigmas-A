%Sao_Paulo
voo(sao_paulo,mexico,sp1,19:30,(seguinte,23:30),0,gol,[qua]).
voo(sao_paulo,nova_york,sp2,17:15,(seguinte,1:30),0,tam,[seg,ter,sab]).
voo(sao_paulo,lisboa,sp3,21:30,(seguinte,3:30),1,passaredo,[sex,sab]).
voo(sao_paulo,madrid,sp4,8:15,(mesmo,12:30),0,passaredo,[qua,sex]).
voo(sao_paulo,londres,sp5,16:30,(mesmo,23:30),2,tam,[dom,qui,sex,sab]).
voo(sao_paulo,paris,sp6,21:45,(seguinte,4:50),0,tam,[seg,sab]).

%Mexico
voo(mexico,nova_york,me1,14:00,(mesmo,19:30),0,gol,[dom,qua,sex]).
voo(mexico,paris,me2,12:00,(mesmo,23:30),0,tam,[ter,sab,dom]).

%Nova_York
voo(nova_york,londres,ny1,20:15,(seguinte,00:30),1,passaredo,[dom,seg,ter,sex,sab]).

%Londres
voo(londres,lisboa,lon1,5:10,(mesmo,8:30),0,gol,[qui,sex]).
voo(londres,paris,lon2,15:00,(mesmo,17:50),0,tam,[dom,seg,sex,sab]).
voo(londres,estocolmo,lon3,14:30,(mesmo,16:00),2,tam,[seg,sex]).

%Madrid
voo(madrid,paris,ma1,15:35,(mesmo,18:30),0,passaredo,[qui,sex]).
voo(madrid,roma,ma2,15:00,(mesmo,15:50),0,tam,[seg,sex,sab]).
voo(madrid,frankfurt,ma3,17:30,(seguinte,23:10),0,gol,[dom,sex,sab]).

%Frankfurt
voo(frankfurt,estocolmo,frank1,10:35,(mesmo,16:30),0,tam,[qui,sex,sab]).
voo(frankfurt,roma,frank2,22:00,(seguinte,2:50),0,passaredo,[seg,sex,sab]).


pertence(X,[X|Cauda]).
pertence(X,[Cabeça|Cauda]) :-
	pertence(X,Cauda).

acrescentarFim(X,[],[X]).
acrescentarFim(X,[Y|L1],[Y|L2]):-
    acrescentarFim(X,L1,L2).

minToTempo(Min,(H:M)):-
	H is Min//60,
	M is Min-(H*60).

tempoToMin((H:M),Min):- Min is (H*60)+M.

menor(X,[X]).
menor(Menor,[X,Y|Cauda]):-
	X > Y,menor(Menor,[Y|Cauda]);
	X =< Y ,menor(Menor,[X|Cauda]).


%1
voo_direto(Origem,Destino,Companhia,Dia,Hora):-
    voo(Origem,Destino,_,Hora,(_,_),0,Companhia,Dia).

%2
filtra_voo_dia_semana(Origem,Destino,Dia,HoraS,HoraC,Companhia):-
    voo(Origem,Destino,_,HoraS,(_,HoraC),0,Companhia,Lista),pertence(Dia,Lista).


%3
roteiro(Origem,Destino,Listavoo) :- voo(Origem,Destino,Cod,_,(_,_),0,_,_),
	                            acrescentarFim(Cod,[],Listavoo).
roteiro(Origem,Destino,Lista) :- voo(Novaorigem,Destino,Cod,_,(_,_),0,_,_),
	                            roteiro(Origem,Novaorigem,Listavoo),
				    acrescentarFim(Cod,Listavoo,Lista).



%calcula o tempo num voo sem escalas
tempoVooDireto(Origem,Destino,Tempo):-
	voo(Origem,Destino,_,HoraS:MinS,(mesmo,HoraC:MinC),0,_,_),
	tempoToMin((HoraS:MinS),MinSai),
	tempoToMin((HoraC:MinC),MinChega),
	Tempo is MinChega - MinSai.

tempoVooDireto(Origem,Destino,Tempo):-
	voo(Origem,Destino,_,HoraS:MinS,(seguinte,HoraC:MinC),0,_,_),
	tempoToMin((HoraS:MinS),MinSai),
	tempoToMin((HoraC:MinC),MinChega),
	Tempo is (MinChega - MinSai) + (24 * 60).


%Cria lista de tempos
listaTempo(A,B,ListaTempo) :-
	findall(Tempo,tempoVooDireto(A,B,Tempo),ListaTempo).



%4
menorDuracao(Origem,Destino,Dia,HorarioSaida,HorarioChegada,Companhia):-
	filtra_voo_dia_semana(Origem,Destino,Dia,HorarioSaida,HorarioChegada,Companhia),
	listaTempo(Origem,Destino,Lista),
	menor(Menor,Lista),tempoVooDireto(Origem,Destino,Menor).


