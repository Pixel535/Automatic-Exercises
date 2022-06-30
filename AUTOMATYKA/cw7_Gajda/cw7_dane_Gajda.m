% Mateusz Gajda WCY20IY2S1 01.06.2022 r.
% Dane do æwiczenia 7
% Wariant 11

C1 = 10;
C2 = 5;
R1 = 0.5;
R2 = 2;

U = 2;
x10 = 2.5;
x20 = 2;
q0 = 1;
p0 = x20;
eps = 0.1 * p0;

a0 = 1/(R1*C1);
a1 = 1/C1;
b0 = 1/(R1*C2);
b1 = 1/(R2*C2);

A = [-a0 a0; b0 (-b0-b1)];
B = [a1; 0];
C = [0 1];
D = [0];
