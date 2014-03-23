


all:
	$(MAKE) -C src/methods/closed-newton-cotes/trapz
	$(MAKE) -C src/methods/closed-newton-cotes/simpson13
	$(MAKE) -C src/methods/closed-newton-cotes/simpson38
	