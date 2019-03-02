#pragma once

// Buttons

/*

LINE 1

R = RUN
B = BACKWARDS
P = PAUSE
S = STOP
H = HELP
O = ABOUT
C = CLEAR
ESC = QUIT *

LINE 2

E = RESET
K = SET ELECTRIC CONSTANT
A = SHOW / HIDE AXES
G = SHOW / HIDE GRID
X = CHANGE X-SCALE
Y = CHANGE Y-SCALE

LINE 3

D = DARK
W = WHITE
F = SET GRAVITY
L = LABELS
V = SAVE

*/

enum BUTTONS { R, B, P, S, H, O, C, E, K, A, G, X, Y, D, W, F, L, V };

bool buttons[18] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
