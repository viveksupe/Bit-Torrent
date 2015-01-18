/*
 * Logger.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: vivek
 */

#include "Logger.h"

Logger::Logger() {
	// TODO Auto-generated constructor stub

}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

void Logger::LogData(string LogInfo) {

	FILE * pFile;
	  pFile = fopen (logFileName.c_str(),"a+"); //logFileName.c_str()
	  if (pFile!=NULL)
	  {
		  time_t ltime;
		      struct tm *Tm;

		      ltime=time(NULL);
		      Tm=localtime(&ltime);
		   char Timestamp[22];
		   Timestamp[21]='\0';
		      sprintf(Timestamp,"[%d / %d / %d: %d:%d:%d]",

		              Tm->tm_mday,
		              Tm->tm_mon,
		              Tm->tm_year,
		              Tm->tm_hour,
		              Tm->tm_min,
		              Tm->tm_sec);
		      std::string str;
		      str.append(Timestamp);
		      str.append(LogInfo);
		      str.append("\n");
		      fputs (str.c_str() , pFile);
	    fclose (pFile);
	  }
	  return;
}
void Logger::setLogFileName(string FileName) {
	logFileName = FileName;
};
