function [pop,fmax,poz,individ] = exemplu_generare(m,n,x,y)

%exemplu de apel: [pop,fmax,poz,individ] = exemplu_generare(12,4,-1,2);


%generarea unei matrice mxn cu numere aleatoare din distributia uniforma pe
%[x,y]
a=unifrnd(x,y,m,n);

%presupunem ca o linie din a este un individ, iar meritul sau este suma patratelor componentelor
%in vectorul fitness pastram calitatea fiecarui individ
fitness=zeros(m,1);
for i=1:m
    for k=1:n
        fitness(i)=fitness(i)+a(i,k)^2;
    end;
end;

%populatia generata este matricea indivizilor a bordata (concatenata) cu vectorul coloana
%fitness
pop=[a fitness];
disp('populatia generata si calitatea fiecarui individ');
disp(pop);
%calculul calitatii maxime din populatie si a individului cel mai bun
[fmax,poz]=max(fitness);
disp(['Calitatea maxima:' num2str(fmax)]);
disp(['Pozitia primului celui mai bun indvid din populatie:' num2str(poz)]);
individ=a(poz,:);
disp('Cel mai bun individ');
disp(individ);
end

