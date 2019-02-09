function [pop] = gen_ini(dim)
%Problema 1
%a.Scrieti o functie MATLAB pentru generarea aleatoare a unei populatii, pop, cu dimensiunea dim;

pop=zeros(dim,4);
i=1;
x=zeros(1,3);
while i<=dim 
    %f:[-1,1]×[0,0.2]×[-2,1]
    x(1) = unifrnd (-1, 1);
    x(2) = unifrnd (0, 0.2);
    x(3) = unifrnd (-2, 1);
    pop(i,1:3) = x;
    pop(i,4)= f_obiectiv(x);
    i=i+1;
    disp(x);
end

