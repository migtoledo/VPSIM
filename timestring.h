#pragma once

string gettimestring()
{
	string retval;
	string strdate;

	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	uint64_t _year = timeinfo->tm_year - 100;
	uint64_t _month = timeinfo->tm_mon + 1;
	uint64_t _mday = timeinfo->tm_mday;
	uint64_t _hour = timeinfo->tm_hour;
	uint64_t _min = timeinfo->tm_min;
	uint64_t _sec = timeinfo->tm_sec;

	strdate = to_string(_hour);
	strdate = strdate + "_" + to_string(_min);
	strdate = strdate + "_" + to_string(_sec);
	strdate = strdate + "_" + to_string(_mday);
	strdate = strdate + "_" + to_string(_month);
	strdate = strdate + "_" + to_string(_year);
	
	retval = strdate;

	return retval;
}
