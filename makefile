


all:
	$(MAKE) -C src/methods/closed-newton-cotes/trapz
	$(MAKE) -C src/methods/closed-newton-cotes/simpson13
	$(MAKE) -C src/methods/closed-newton-cotes/simpson38
	$(MAKE) -C src/methods/romberg
	$(MAKE) -C src/methods/gaussian-quadrature
	$(MAKE) -C src/methods/open-newton-cotes
	$(MAKE) -C src/methods/multiple-integral
	$(MAKE) -C src/methods/derivatives/Backward-Difference
	$(MAKE) -C src/methods/derivatives/Backward-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Backward-Difference-Second
	#$(MAKE) -C src/methods/derivatives/Central-Difference
	$(MAKE) -C src/methods/derivatives/Central-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Central-Difference-Second
	$(MAKE) -C src/methods/derivatives/Forward-Difference
	$(MAKE) -C src/methods/derivatives/Forward-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Forward-Difference-Second
	$(MAKE) -C src/methods/derivatives/Lagrange-Difference

