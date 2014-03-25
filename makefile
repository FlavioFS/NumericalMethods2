


all:
	$(MAKE) -C src/methods/closed-newton-cotes/trapz
	$(MAKE) -C src/methods/closed-newton-cotes/simpson13
	$(MAKE) -C src/methods/closed-newton-cotes/simpson38
	$(MAKE) -C src/methods/romberg
	$(MAKE) -C src/methods/gaussian-quadrature
	$(MAKE) -C src/methods/open-newton-cotes
	$(MAKE) -C src/methods/multiple-integral

