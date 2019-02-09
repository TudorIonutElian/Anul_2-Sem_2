%problema 14 sub b
%dar se iau doar 2 valori x1 si y1 in loc de toata coloana

%alpha este ponderea

%recombinarea aritmetica totala
%x2(i)=alpha*x1(i)+(1-alpha)*y1(i);
%y2(i)=alpha*y1(i)+(1-alpha)*x1(i);
function [x2,y2] = r_aritmetica_totala(x1,y1,pc,alpha)
x2=x1;
y2=y1;

d=length(x1);

for i=1:d
    %generam o valoare aleatoare intre 0 si 1
    r=unifrnd(0,1);
    disp('Valoarea selectata intre 0 si 1');
    disp(r);%doar ca sa afisez ce valoare a creat.
    if r<pc
        %progeniturile x2 si y2 sunt obtinute astfel:
        x2(i) = alpha*x1(i)+ (1-alpha)* y1(i);
        y2(i) = alpha*y1(i) + (1-alpha)* x1(i);
    end %pt if
end %pt for
end %pt functie

