% Mateusz Gajda WCY20IY2S1 26.05.2022 r.
% Dane do æwiczenia 6
% Wariant 11

C1 = 10;
C2 = 5;
R1 = 0.5;
R2 = 2;


a0 = 1/(R1*C1);
a1 = 1/C1;
b0 = 1/(R1*C2);
b1 = 1/(R2*C2);

A = [-a0 a0; b0 (-b0-b1)];
B = [a1; 0];
C = [0 1];
D = [0];

