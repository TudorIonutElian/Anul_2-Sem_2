%problema 14

%function [outputArg1,outputArg2] = untitled2(inputArg1,inputArg2)
%creez functia gen_ini care are ca parametru de intrare dimensiunea
%populatiei dim
%dimensiunea o introducem de la tastatura cand apelam din command window
%gen_ini(10) - de exemplu

function [P] = gen_ini(dim)
%pas 1 creez matricea si o initializez cu 0
% functia zeros creaza o matrice cu dimensiunile specificate si care are
% toate valorile egale cu 0

%matricea va avea numarul de coloane indicate de la tastatura si 4 coloane
P=zeros(dim,4);
i=1;
%creez vector in care salvez valoarea pentru x1, x2 si x3
x=zeros(1,3); %o linie si trei coloane
%creez un while loop care parcurge linie cu linie matricea P
while i<=dim
    %intai adaug pentru x1 sa genereze aleator (unifrnd) o valoare de la -1 la 1
    %unifrnd genereaza numere aleatoare cuprinse intre valorile indicate
    %intre paranteze
    %f:[-1,1]×[0,0.2]×[-2,1]f:[-1,1]×[0,0.2]×[-2,1]
    x(1) = unifrnd(-1,1);
    x(2) = unifrnd(0,0.2);
    x(3) = unifrnd(-2,1);
    %copiez in P valorile generate mai sus
    P(i,1:3)=x;
    P(i,4)=f_obiectiv(x);
    i=i+1;
end

