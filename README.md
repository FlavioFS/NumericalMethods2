Numerical Methods II
=================

## Info
Course from Federal University of Ceara


## Team

* Henrique Araújo
* Inaciane Monteiro
* Flávio Freitas
* Pedro Rocha

## Implemented Methods

* Trapezoidal
* 1/3 Simpson
* 3/8 Simpson
* Newton-Cotes
* Gaussian Quadrature

## How does it work?
ISample interface describes what the read-from-file classes need to implement.
Function class allows you to choose one between 5 continuous pre-defined functions,
or to pass your customized function as argument.
Any method needs at least an ISample and a Function argument.
Closed Newton-Cotes formulae use SampleClosed class, and Open Newton-Cotes formulae
use SampleOpen class as argument to read from file.
