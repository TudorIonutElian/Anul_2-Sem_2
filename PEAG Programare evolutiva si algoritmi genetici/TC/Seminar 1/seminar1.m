function [v,a1,rez1,a2,x,y,m_aleat]=seminar1(vector,matrice,p,m,n)
%[v,a1,r1,a2,x,y,ma]=seminar1('vector.txt','matrice.txt',3,5,7)

%incarcarea unei matrice patratice dintr-un fisier text
a1=load(matrice);
disp('Matricea citita');
disp(a1);
[l,~]=size(a1);
%incarcarea unui vector dintr-un fisier text
v=load(vector);
%produsul matrice * vector
rez1=a1*v;
disp('Matricea*vector');
disp(rez1);
%ridicarea matricei patratice la o putere p

a2=a1^p;
% matricea rezultat
disp(['Matricea la puterea' num2str(p)]);
disp(a2);
%copierea ultimei linii/coloane in cate un vector
x=a1(l,:);
disp('Ultimul vector linie');
disp(x);
y=a1(:,l);
disp('Ultimul vector coloana:');
disp(y);

%generarea une matrice aleatoare cu m linii s n coloane, fiecare element
%fiind generat din distributia uniforma pe [0,1]
m_aleat=unifrnd(0,1,m,n);
disp('Matricea generata aleator');
disp(m_aleat);
end
