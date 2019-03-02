#pragma once

#define COLORDEPTH 24

ALLEGRO_BITMAP *bmpsave = NULL;

// Timer Globals

// Frames-per-second
double FPS = 60.0;
// Seconds-per-frame 
double dt = 1 / FPS;
// Differential virtual-time
volatile double _dt = 0;
volatile double _last_dt = 0;
// Cycle-ticks
double ticks = 0;
// Loading elements
double ticksforloading = 100;
// Real-time in seconds
double rt = 0;
// Start-time-real
double t0 = 0;
// Start-time-virtual
double _t0 = 0;
// Virtual-time in seconds
double vt = 0;
// Get seconds from ticks
double get_seconds(double ticks)
{
	double retval = ticks / FPS;
	return retval;
}
// Timer
ALLEGRO_TIMER *timer = NULL;
// Time-out
ALLEGRO_TIMEOUT timeout;

#define __timeout ((1/FPS)/100.0)

// Screen Globals

// Graphic Resolution

int gmode = 0;

// Screen color
ALLEGRO_COLOR scrcolor = _white;

// Fonts

ALLEGRO_FONT *font = NULL;

// Font: Resolution Info

ALLEGRO_FONT *fontscrinfo;

// Font: Welcome Screen

ALLEGRO_FONT *fontwelcome;

// Fonts for Panels

// Default: Small Resolutions

ALLEGRO_FONT *fontdefault = NULL;

// Bigger: Higher Resolutions

ALLEGRO_FONT *fontb1 = NULL;

ALLEGRO_FONT *fontb2 = NULL;

ALLEGRO_FONT *fontlabels = NULL;

// Text color
ALLEGRO_COLOR text_color = _black;

// Colors for op, wa and ip

// Output Panel Color
ALLEGRO_COLOR opcolor = VERDE_CHARTREUSE;
// Work Area Color
ALLEGRO_COLOR wacolor = BLANCO_ALICEBLUE;
// Input Panel Color
ALLEGRO_COLOR ipcolor = ROJO_RED;

// Frame colors

ALLEGRO_COLOR scrframecol = GRIS_GRAY;
ALLEGRO_COLOR opframecol = VERDE_DARKGREEN;
ALLEGRO_COLOR waframecol = ROJO_DARKRED;
ALLEGRO_COLOR ipframecol = AMARILLO_YELLOW;

// Text Lines spaces
#define vspace(x) (al_get_text_width(font, "A")*(x)+4)

// Display
ALLEGRO_DISPLAY *display = NULL;
// Display data
ALLEGRO_DISPLAY_MODE display_data;

// Screen width
double scrw = 640;
// Screen height
double scrh = 480;

// Mouse Globals
//volatile double xxmouse = 0;
//volatile double yymouse = 0;
double xxmouse = 0;
double yymouse = 0;

// Height ratio for Work Area
double hr = 0.5;

const char* display_title;
ALLEGRO_BITMAP *icon;

// Globals Allegro Events

// Events Queue
ALLEGRO_EVENT_QUEUE *KeyboardEventsQueue = NULL;
ALLEGRO_EVENT_QUEUE *MouseEventsQueue = NULL;
ALLEGRO_EVENT_QUEUE *TimerEventsQueue = NULL;
ALLEGRO_EVENT_QUEUE *ScrEventsQueue = NULL;

// Events
ALLEGRO_EVENT ScrEvent;
ALLEGRO_EVENT KeyboardEvent;
ALLEGRO_EVENT MouseEvent;
ALLEGRO_EVENT TimerEvent;

// Events Booleans
bool NewScrEvent = false;
bool NewKeyboardEvent = false;
bool NewMouseEvent = false;
bool NewTimerEvent = false;

// Flow control
bool running = true;
bool redraw = true;



