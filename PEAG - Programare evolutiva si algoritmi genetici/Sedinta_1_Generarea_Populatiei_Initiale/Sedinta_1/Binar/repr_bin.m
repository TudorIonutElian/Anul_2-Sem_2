function [y]=repr_bin(x,m)
y = bitget(x,m:-1:1);
end