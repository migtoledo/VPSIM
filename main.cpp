/*
Project: Virtual Particles Simulator (VPS)
Update: 17-Okt.-2018 dC
By: Miguel Toledo González
Version: v 1.0
Code Serie: n7
Programming Language: C++
External Libraries: Allegro 5.2.4 for graphical output.
License: GPL v3 - Free Software Foundation -
Redistribution: Allowed under the terms of the license GPL v3.
Platforms: Microsoft Windows 10.
Project Compilation: Microsoft Visual Studio 2017.
Description: This program is a simulator for systems of interacting
                    virtual particles evolving at real-time.
Audience: Testers, researchers, or students of physical sciences.
*/
/*
	IMPROVEMENTS / ISSUES
			
	Memory optimization for big matrices of interacting particles.
	Added Multi-Thread Support.

*/

#pragma warning(disable:4996)

// Standard C++ Headers

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <iostream>
#include <sstream>
#include <random>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <complex>
#include <vector>

// Allegro 5.2.4 Headers

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

// Project Headers A

#include "hA0planckunits.h"
#include "hA1rgbcolors.h"
#include "hA2structures1.h"
#include "hA3timestring.h"
#include "hA4filefunctions.h"
#include "hA5mathglobals.h"
#include "hA6systemglobals.h"
#include "hA7buttonglobals.h"
#include "hA8resolution.h"
#include "hA9initcolors.h"
#include "hA10initsystem.h"
#include "hA11graphicsmode.h"
#include "hA12welcome.h"
#include "hA13defbuffers.h"
#include "hA14loadhelp.h"
#include "hA15loadgraphics.h"

// Class "Boundary" B

#include "hB1defclassBoundary.h"
#include "hB2classBoundary1.h"
#include "hB3classBoundary2.h"
#include "hB4classBoundary3.h"

// User Numerical Input C

#include "hC1usernumericalinput.h"

// Structures for Initial Configuration D

#include "hD1initstate.h"

#include "hD2sumistates.h"

// Geometries of matrices of initial states E

#include "hE1getpixstate.h"

#include "hE2initstategeometrysegm.h"

#include "hE3initstategeometrycirc.h"

#include "hE4initstategeometrydisc.h"

#include "hE5initstategeometryrect.h"


// Dynamical Elements of the Animation F

// Class "Pix" F 

#include "hF1defclassPix.h"
#include "hF2classPix1init.h"
#include "hF3classPix2exy.h"
#include "hF4classPix3boundary.h"

// Class "procPix" G 

#include "hG1defclassprocPix.h"

// Class "pixM" - Global Pix Matrix - H

#include "hH1defclasspixM.h"
#include "hH2classpixM1init.h"
#include "hH3classpixM2loadpixm.h"
#include "hH4classpixM3setcolorscale.h"
#include "hH5classpixM4compute.h"
#include "hH6classpixM5run.h"
#include "hH7classpixM6getmass.h"
#include "hH8classpixM7draw.h"

// Class "Animation" I

#include "hI1defclassAnimation.h"
#include "hI2classAnimation1init.h"
#include "hI3classAnimation2xx.h"
#include "hI4classAnimation3exy.h"
#include "hI5classAnimation4op.h"
#include "hI6classAnimation5wa.h"
#include "hI7classAnimation6ip.h"
#include "hI8classAnimation7save.h"

// MAIN J

#include "hJ1drawingop.h"
#include "hJ2drawingip.h"
#include "hJ3drawingwa.h"
#include "hJ4redrawing.h"
#include "hJ5buttonactions.h"

// K

#include "hK1cleaning.h"
#include "hK2mainflow.h"
#include "hK3threads.h"

// PROGRAM

int main(int argc, char **argv)
{
	loadgraphics();
			
	// Initiating Boundary
	Armadillo = _Armadillo->init();

	// Initiating Animation
	_Anim->initinterface();
	
	// Main loop

	while (running)
	{
		gettimeinfo();

		// Fetch events doing actions according to events

		scrframeevents();

		mouseevents();
			   
		keyboardevents();
		
		timerevents();		
	} 
	
	cleanup();
	
	return 0;
}

