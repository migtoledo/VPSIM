#pragma once

void loadgraphics()
{
	initsystem();

	initallegro();

	graphicsmode(option());

	welcome();

	loadbuffers();

	init_timer();

	loadauxbmps();
}
