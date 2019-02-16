function [P] = gen_ini(dim)
P=zeros(dim,4);
i=1;
x=zeros(1,3);
while i<=dim
    x(1)=unifrnd(0,1);
    x(2)=unifrnd(-2,3);
    x(3)=unifrnd(0,5);
    if este_fezabil(x)
        P(i,1:3)=x;
        P(i,4)=f_obiectiv(x);
        i=i+1;
    end
end
    
end

