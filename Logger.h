/*
 * Logger.h
 *
 *  Created on: Oct 18, 2014
 *      Author: vivek
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <ctime>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <fstream>
#include <openssl/sha.h> //hashing pieces
#include <map>
#include <cmath>
#include <arpa/inet.h>
#include <iomanip>
#include <string>
#include "bt_lib.h"

using namespace std;

class Logger {
public:
	string logFileName;
	Logger();
	virtual ~Logger();
	void LogData(string LogInfo);
	void setLogFileName(string logFilName);
};

#endif /* LOGGER_H_ */
