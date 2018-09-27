/*
Project: Virtual Particles Simulator (VPS)
Update: 26-Sept.-2018 dC
By: Miguel Toledo González
Version: v 1.0
Code Serie: m9
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

// Project Headers

#include "rgbcolors.h"
#include "structures1.h"
#include "timestring.h"
#include "filefunctions.h"
#include "mathglobals.h"
#include "systemglobals.h"
#include "buttonglobals.h"
#include "resolution.h"
#include "initcolors.h"
#include "initsystem.h"
#include "graphicsmode.h"
#include "welcome.h"
#include "defbuffers.h"
#include "loadhelp.h"
#include "loadgraphics.h"
#include "geometry.h"

// Class "Boundary"

#include "defclassBoundary.h"
#include "classBoundary1.h"
#include "classBoundary2.h"
#include "classBoundary3.h"

// User Numerical Input

#include "usernumericalinput.h"

// Structures for Initial Configuration

#include "initstate.h"

// Geometries of matrices of initial states

#include "initstategeometries.h"

// Dynamical Elements of the Animation

// Class "Pix"

#include "defclassPix.h"
#include "classPix1init.h"
#include "classPix2exy.h"
#include "classPix3boundary.h"

// Class "procPix"

#include "defclassprocPix.h"

// Class "pixM" - Global Pix Matrix - 

#include "defclasspixM.h"
#include "classpixM1init.h"
#include "classpixM2loadpixm.h"
#include "classpixM3setcolorscale.h"
#include "classpixM4addpix.h"
#include "classpixM5compute.h"
#include "classpixM6run.h"
#include "classpixM7getmass.h"
#include "classpixM8draw.h"

// Class "Animation"

#include "defclassAnimation.h"
#include "classAnimation1init.h"
#include "classAnimation2xx.h"
#include "classAnimation3exy.h"
#include "classAnimation4op.h"
#include "classAnimation5wa.h"
#include "classAnimation6ip.h"
#include "classAnimation7save.h"

// MAIN

#include "drawingop.h"
#include "drawingip.h"
#include "drawingwa.h"
#include "drawing.h"
#include "redrawing.h"
#include "buttonactions.h"

#include "cleaning.h"
#include "mainflow.h"
#include "threads.h"

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

