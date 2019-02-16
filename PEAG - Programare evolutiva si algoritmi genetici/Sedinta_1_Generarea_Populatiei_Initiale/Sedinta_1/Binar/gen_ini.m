function [P] = gen_ini(dim)
P=zeros(dim,6);
for i=1:dim
    x = unidrnd(32)-1;
    P(i,1:5)=repr_bin(x,5);
    P(i,6)=f_obiectiv(x);
end
end

