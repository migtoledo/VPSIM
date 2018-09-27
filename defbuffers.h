#pragma once

// 3-Double Buffers System

// Buffers: Output panel, Work area, Input panel

ALLEGRO_BITMAP* ipbmp;
ALLEGRO_BITMAP* wabmp;
ALLEGRO_BITMAP* opbmp;

// Dimensions are based on Work Area height
// and global screen dimensions

// % from screen-height
#define hratio (hr)

// Work Area Height
#define wah (scrh*hratio)

// Height for op and ip:

// Output Panel Height
#define oph ((scrh-wah)*0.5) 

// Input Panel Height
#define iph oph

// Width for op, wa and ip = scrw

// Calculate (x0, y0) for op, wa, ip

// Y-Origin For Work Area
#define way0 (oph)
#define way1 (oph+wah)

// Y-Origin For Input panel
#define ipy0 (way0 + wah)
#define ipy1 (ipy0+iph)

// Origin (x, y)
#define ox ((scrw)/2)
#define oy ((wah)/2)

// (x, y) / (xx, yy) Transformations 

// Math coordinates (x, y) -> Work Area coordinates (xx, yy)
#define XX(x) (ox+x)

// Math coordinates (x, y) -> Work Area coordinates (xx, yy)
#define YY(y) (oy-y)

// Work Area coordinates (xx, yy) -> Math coordinates (x, y)
#define X(xx) (xx-ox)

// Work Area coordinates (xx, yy) -> Math coordinates (x, y)
#define Y(yy) (oy-yy)

// With Scale (sx, sy) in pixels / unit

// Math coordinates (x, y) -> Work Area coordinates (xx, yy)
#define XXS(x, sx) (ox+x*sx)

// Math coordinates (x, y) -> Work Area coordinates (xx, yy)
#define YYS(y, sy) (oy-y*sy)

// Work Area coordinates (xx, yy) -> Math coordinates (x, y)
#define XS(xx, sx) ((xx-ox)/sx)

// Work Area coordinates (xx, yy) -> Math coordinates (x, y)
#define YS(yy, sy) ((oy-yy)/sy)


void scrframe()
{
	al_draw_rectangle(1, 1, scrw, scrh, scrframecol, 1);
}

void opframe()
{
	al_draw_rectangle(1, 1, scrw, oph, opframecol, 1);
	al_draw_rectangle(2, 2, scrw - 1, oph-1, opframecol, 1);
	
}

void waframe()
{
	

}

void ipframe()
{
	al_draw_rectangle(1, 1, scrw, iph, ipframecol, 1);
	al_draw_rectangle(2, 2, scrw - 1, iph-1, ipframecol, 1);
	

}

void scrclean()
{
	al_clear_to_color(scrcolor);
	scrframe();
}

// Cleans Output Panel
void opclean()
{
	al_set_target_bitmap(opbmp);
	al_clear_to_color(opcolor);
	opframe();

	al_set_target_bitmap(al_get_backbuffer(display));
}

// Cleans Work Area
void waclean()
{
	al_set_target_bitmap(wabmp);
	al_clear_to_color(wacolor);
	waframe();
	al_set_target_bitmap(al_get_backbuffer(display));
}

// Cleans Input Panel
void ipclean()
{
	al_set_target_bitmap(ipbmp);
	al_clear_to_color(ipcolor);
	ipframe();
	al_set_target_bitmap(al_get_backbuffer(display));
}

void load_opbmp()
{
	opbmp = al_create_bitmap(scrw, oph);
	opclean();
}

void load_wabmp()
{
	wabmp = al_create_bitmap(scrw, wah);
	waclean();
}

void load_ipbmp()
{
	ipbmp = al_create_bitmap(scrw, iph);
	ipclean();
}


void cleanbuffers()
{
	opclean();
	ipclean();
	waclean();
}

void loadbuffers()
{
	load_opbmp();
	load_wabmp();
	load_ipbmp();

	cleanbuffers();
}