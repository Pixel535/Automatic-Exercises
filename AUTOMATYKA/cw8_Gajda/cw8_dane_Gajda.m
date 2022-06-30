% Mateusz Gajda WCY20IY2S1 07.06.2022 r.
% Dane do æwiczenia 8
% Wariant 7

x3 = 2;
C1 = 10;
C2 = 5;
C3 = 2;
R1 = 0.5;
R2 = 2;
R3 = 2;

P0 = 1;

kg = 40.7;
kP = 0.5 * kg;
kPI = 0.45 * kg;
kPID = 0.6 * kg;

Tg = 11.3;
TiPI = Tg/1.2;
TiPID = Tg/2;
TdPID = Tg/8;

a0 = 1/(R1*C1);
a1 = 1/C1;
b0 = 1/(R1*C2);
b1 = 1/(R2*C2);
c0 = 1/(R2*C3);
c1 = 1/(R3*C3);

A = [-a0 a0 0 ; b0 -b0-b1 b1 ; 0 c0 -c0-c1];
B = [a1 ; 0 ; 0];
C = [0 0 1];
D = [0];
