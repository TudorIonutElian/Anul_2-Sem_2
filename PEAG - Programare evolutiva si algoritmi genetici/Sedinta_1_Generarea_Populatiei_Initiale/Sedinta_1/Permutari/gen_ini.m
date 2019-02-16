function [P] = gen_ini(dim,n)
P=zeros(dim,n+1);
for i=1:dim
    p=randperm(n);
    P(i,1:n)=p;
    P(i,n+1)=fitness(p,n);
end
end

