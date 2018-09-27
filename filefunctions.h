#pragma once



time_t rawtime=NULL;

struct tm *timeinfo=NULL;

char *_timeinfo = NULL;

void gettimeinfo()
{
	time(&rawtime);

	timeinfo = localtime(&rawtime);

	_timeinfo = asctime(timeinfo);
	
}


bool fileexist(const char* filename)
{
	std::ifstream inputfile(filename);

	return inputfile.good();
}


