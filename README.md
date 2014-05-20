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
* Romberg
* Multiple Integrals
* Finite Differences for First Derivative and Equally Spaced Intervals
* Finite Differences for First Derivative and Non Equally Spaced Intervals
* Lagrange Difference
* Richardson
* Regular Power
* Inverse Power
* Shifted Power
* Jacobi
* Qr
* Qr with Householder

## How does it work?
ISample interface describes what the read-from-file classes need to implement.
Function class allows you to choose one between 5 continuous pre-defined functions,
or to pass your customized function as argument.
Any method needs at least an ISample and a Function argument.
Closed Newton-Cotes formulae use SampleClosed class, and Open Newton-Cotes formulae
use SampleOpen class as argument to read from file.

## How to run

We use **MAKE** to build our executables.

All you have to do is dive into the **NumericalMethods2/** directory and run

```
$> make
```

After that, the executables are all created on this folder (our root). 
You choose one of the executables and a text file to run:

Trapezoidal:

```
$> ./trapz samples.txt
```

1/3 Simpson:

```
$> ./simp13 samples.txt
```

3/8 Simpson:

```
$> ./simp38 samples.txt
```

Open Newton-Cotes:

```
$> ./open_nc samples.txt
```

Gaussian quadrature:

```
$> ./quad_gauss samples.txt
```

Romberg:

```
$> ./romberg samples.txt
```

Multiple Integrals:

```
$> ./int_dup samples.txt
```

Forward Difference:

```
$> ./forwarddiff samples.txt
```

Forward Difference for Second Derivative:

```
$> ./forwarddiff2 samples.txt
```

Backward Difference:

```
$> ./backdiff samples.txt
```

Backward Difference for Second Derivative:

```
$> ./backdiff2 samples.txt
```
Central Difference:

```
$> ./centraldiff samples.txt
```

Central Difference for Second Derivative:

```
$> ./centraldiff2 samples.txt
```

Richardson (Forward):

```
$> ./richardson_forward samples.txt
```

Richardson (Backward):

```
$> ./richardson_back samples.txt
```

Richardson (Central):

```
$> ./richardson_central samples.txt
```

Lagrange Difference:

```
$> ./gendiff samples.txt
```

Regular Power:

```
$> ./regpot samples.txt
```

Inverse Power:

```
$> ./invpot samples.txt
```

Shifted Power:

```
$> ./despot samples.txt
```

Jacobi:

```
$> ./jacobi samples.txt
```

Qr:

```
$> ./qr samples.txt
```

Qr with Householder:

```
$> ./qrHouseholder samples.txt
```

