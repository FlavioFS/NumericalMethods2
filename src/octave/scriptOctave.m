figure;
a = ezplot("((2*x^2 + x + 2)^2)/4",[0,1])
set(a,"linewidth",2)
set(a,"color","k")
grid on
hold on
trk2 = [0, 0.25, 0.5, 0.75, 1]
yrk2 = [1, 1.40451, 2.23073, 3.70609, 6.15178]
rk2 = plot(trk2, yrk2)
set(rk2,"linewidth",2)
set(rk2,"color","b")
hold on
trk3 = [0, 0.25, 0.5, 0.75, 1]
yrk3 = [1, 1.41043, 2.24949, 3.75094, 6.24236]
rk3 = plot(trk3, yrk3, "r-")
set(rk3,"linewidth",2)
hold on
trk4 = [0, 0.25, 0.5, 0.75, 1]
yrk4 = [1, 1.40531, 2.23428, 3.71763, 6.17979]
rk4 = plot(trk4, yrk4, "m-")
set(rk4,"linewidth",2)
hold on
tad3 = [0, 0.25, 0.5, 0.75, 1]
yad3 = [1, 1.41043, 2.24949, 3.75333, 6.24951]
ad3 = plot(tad3, yad3, "g-")
set(ad3,"linewidth",2)
hold on
tad4 = [0, 0.25, 0.5, 0.75, 1]
yad4 = [1, 1.40531, 2.23428, 3.71763, 6.2024]
ad4 = plot(tad4, yad4, "c-")
set(ad4,"linewidth",2)
legend('solucao analitica', 'RK2', 'RK3', 'RK4', 'Adams3', 'Adams4');