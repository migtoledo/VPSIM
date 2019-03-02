#pragma once

// Planck units vs. Atomic units 

/*
PLANCK UNITS <-> ATOMIC UNITS

Electron

me = 9.109e-31 kg

In atomic units: me = 1

Planck-Mass = 2.176e-8 kg

Also, calculating the Planck-mass in terms of
the electron-mass:

2.176e-8 kg = 1 Planck-mass = 2.176e-8 / 9.109e-31 me

1 Planck-mass = 2.39e22 me

ATOMIC UNITS -> PLANCK UNITS

1 me = 1 Planck-mass / 2.39e22

Proton mass = 1836 me

Electric charge

In atomic units, e=1

e = 1.6e-19C

q-Planck = e/sqrt(alfa) = 1.875e-18C

alfa=1/137 the fine-structure constant

q-Planck=11.7e

e = q-Planck/11.7

Length

Atomic-Radius = Bohr Radius = a0 =1 in atomic units

a0 = 5.29e-11 m 

Planck-Length = e-35 m

Also, a planck length is very smaller than an atom !

1 Planck-Length = 1.890359168241966e-25 a0, respect to atomic units

Equivalently the radius of Bohr can be expressed
as multiple of the Planck-Length:

1 a0 = 1 Planck-length / 1.89e-25 = 5.29e24 Planck-length

Also, respect to the Planck-scale an atom is really very very ... very big!

/// In VPSIM we will be by default using Planck scales, and with
/// a basic knowledge of Physics, and a lot of fantasy, we will
/// be representing particles (virtual-particles) they "live" in a Planck world ...
/// Virtual particles are the responsible to transmit the 
/// elements responsible of the communication between "standard" or
/// "normal" physical particles. For example, the electrostatic
/// Coulomb's force between two charged particles should be transmitted
/// thanks to "virtual-photons".
/// Note, that like other elements in Biology sciences like enzimes or catalysators,
/// the virtual-particles "disappear" after its work is done, furthermore
/// cannot be physical observable, because, formally they are no more
/// than some kind of mathematical "creatures", necessary to explain
/// the crazy equations of Physics...

Atomic time

1 t0 = 2.419e-17 s = hp/E

Planck-time

1 tP = 5.39e-44 s

Planck-time = 2.2281934683753614e-27 t0

t0 = 4.4879406307977745e+26 tP


In Planck Units the Newton's gravity
constant and the Coulomb's constant
are simply 1 ! Yuhu!

G = K = 1

"EINFACHER", GEHT NICHT ... !!!

Let's formalize that a bit...


*/

// The structure fine constant -adimensional-
double structurefineconst = 1 / 137;

// Planck-length in m:
double SI_PlanckLength = 1.62e-35;

// Planck-time in seconds
double tPlanck = 5.39e-44;

/// MASS PLANCK UNITS FROM ATOMIC UNITS OF MASS (me=1)

// Getting the Planck mass from the atomic mass (=1 electron-mass)
double getplanckmassfromatomic(double atomicmass)
{
	// Electron-mass in kg:
	double SI_me = 9.109e-31;

	// Planck-mass in kg:
	double SI_PlanckMass = 2.176e-8;
	   
	// Mass of 1-electron expressed in Planck-mass units
	double Planck_me = SI_me/SI_PlanckMass;

	double retval = atomicmass * Planck_me;

	return (retval);
}

// Getting the Planck mass for 1 electron
double getplanckmass1electron()
{
	double retval = getplanckmassfromatomic(1);

	return retval;
}

// Getting the Planck mass for 1 proton
double getplanckmass1proton()
{
	double retval = getplanckmassfromatomic(1836);

	return retval;
}

// CHARGE PLANCK UNITS FROM ATOMIC UNITS OF CHARGE (e=1)
double getplanckchargefromatomic(double atomiccharge)
{
	double retval;

	retval = atomiccharge / sqrt(structurefineconst);
	
	return retval;
}

double getplanckcharge1electron()
{
	return getplanckchargefromatomic(1);
}


// LENGTH PLANCK UNITS FROM ATOMIC UNITS OF LENGTH (a0=Bohr-Radius=1)
double getplancklengthfromatomic(double atomiclength)
{
	double retval;

	// Bohr-Radius in m:
	double a0 = 5.29e-11;

	// Planck-length in m:
	double SI_PlanckLength = 1.62e-35;

	// Bohr-Radius in Planck units:
	double a0Planck = a0 / SI_PlanckLength;

	retval = atomiclength * a0Planck;

	return retval;
}

// Getting the Bohr Radius expressed in Planck units
double getPlanckBohrRadius()
{
	return getplancklengthfromatomic(1);
}

// TIME PLANCK UNITS FROM ATOMIC UNITS OF TIME (t0)
double getplancktimefromatomic(double atomictime)
{
	double retval;

	// Planck-time in seconds
	double tPlanck = 5.39e-44;

	// Atomic-time in seconds
	double tAtomic = 2.419e-17;

	// One atomic unit time in Planck units
	double t0Planck = tAtomic / tPlanck;

	retval = atomictime * t0Planck;

	return retval;
}



/// The idea is to understand how "looks" an atom
/// respect the point of view of Planck scales
/// using virtual particles.








