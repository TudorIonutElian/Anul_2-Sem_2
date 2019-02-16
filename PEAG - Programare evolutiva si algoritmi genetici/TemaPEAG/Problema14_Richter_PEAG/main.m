function [x2,y2] = main(dim)
pop=gen_ini(dim);
disp('Populatie initiala: ');
disp(pop);
x1=pop(1);
y1=pop(2);
%apelam pe r_aritmetica_totala
[x2,y2] = r_aritmetica_totala(x1,y1,0.7,0.5);
disp ('X2: ');
disp(x2);
disp ('Y2: ');
disp(y2);
end
