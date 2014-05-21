figure;
a = ezplot("e^(0.25*x^4-1.5*x)",[0,2])
set(a,"linewidth",2)
set(a,"color","k")
grid on
hold on
trk2 = [0,0.5,1,1.5,2]
yrk2 = [-1.5,0.539062,0.332703,0.408081,1.88418]
rk2 = plot(trk2, yrk2)
set(rk2,"linewidth",2)
set(rk2,"color","b")
hold on
trk3 = [0,0.5,1,1.5,2]
yrk3 = [-1.5,0.471537,0.287046,0.386868,2.37924]
rk3 = plot(trk3, yrk3, "r-")
set(rk3,"linewidth",2)
hold on
tad3 = [0,0.5,1.5,2]
yad3 = [-1.5,0.471537,0.210727,-2.49212]
ad3 = plot(tad3, yad3, "g-")
set(ad3,"linewidth",2)
legend('solucao analitica','Forward Euler', 'RK2', 'RK3');