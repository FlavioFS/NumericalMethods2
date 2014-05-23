figure;
a = ezplot("(2*x^2 - 2*x + 3*e^(-2*x) + 1)/4",[0,2])
set(a,"linewidth",2)
set(a,"color","k")
grid on
hold on
teuler = [0, 0.5, 1, 1.5, 2]
yeuler = [1, 0, 0.125, 0.5, 1.125]
euler = plot(teuler, yeuler, "b--")
set(euler,"linewidth",2)
hold on
trk2 = [0, 0.5, 1, 1.5, 2]
yrk2 = [1, 0.5625, 0.53125, 0.828125, 1.41406]
rk2 = plot(trk2, yrk2, "b-")
set(rk2,"linewidth",2)
hold on
trk3 = [0, 0.5, 1, 1.5, 2]
yrk3 = [1, 0.364583, 0.319444, 0.637731, 1.24383]
rk3 = plot(trk3, yrk3, "r-")
set(rk3,"linewidth",2)
hold on
trk4 = [0, 0.5, 1, 1.5, 2]
yrk4 = [1, 0.465856, 0.414697, 0.713851, 1.3062]
rk4 = plot(trk4, yrk4, "m-")
set(rk4,"linewidth",2)
hold on
tad3 = [0, 0.5, 1, 1.5, 2]
yad3 = [1, 0.364583, 0.319444, 0.691744, 1.30654]
ad3 = plot(tad3, yad3, "g-")
set(ad3,"linewidth",2)
hold on
tad4 = [0, 0.5, 1, 1.5, 2]
yad4 = [1, 0.465856, 0.414697, 0.713851, 1.27142]
ad4 = plot(tad4, yad4, "c-")
set(ad4,"linewidth",2)
legend('solucao analitica', 'Euler', 'RK2', 'RK3', 'RK4', 'Adams3', 'Adams4');