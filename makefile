


all:
	
####### Part I #######

	$(MAKE) -C src/methods/closed-newton-cotes/trapz
	$(MAKE) -C src/methods/closed-newton-cotes/simpson13
	$(MAKE) -C src/methods/closed-newton-cotes/simpson38
	$(MAKE) -C src/methods/romberg
	$(MAKE) -C src/methods/gaussian-quadrature
	$(MAKE) -C src/methods/open-newton-cotes
	$(MAKE) -C src/methods/multiple-integral


####### Part II #######

	# Derivatives
	$(MAKE) -C src/methods/derivatives/Backward-Difference
	$(MAKE) -C src/methods/derivatives/Backward-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Backward-Difference-Second
	$(MAKE) -C src/methods/derivatives/Central-Difference
	$(MAKE) -C src/methods/derivatives/Central-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Central-Difference-Second
	$(MAKE) -C src/methods/derivatives/Forward-Difference
	$(MAKE) -C src/methods/derivatives/Forward-Difference-Richardson
	$(MAKE) -C src/methods/derivatives/Forward-Difference-Second
	$(MAKE) -C src/methods/derivatives/Lagrange-Difference


####### Part III #######

	# Power
	$(MAKE) -C src/methods/power/regular-power
	$(MAKE) -C src/methods/power/inverse-power
	$(MAKE) -C src/methods/power/shifted-power

	#Jacobi
	$(MAKE) -C src/methods/jacobi

	#Qr
	$(MAKE) -C src/methods/qr/simple
	#$(MAKE) -C src/methods/qr/householder


####### Part IV #######

	# TODO