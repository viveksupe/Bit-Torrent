#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "bt_lib.h"
#include "ParseTorrent.h"
#include "bt_setup.h"
#include "Logger.h"
//#include "NetworkSocket.h"

using namespace std;

int main(int argc, char* argv[]) {
	bt_info_t btStruct;
	bt_args_t argStruct;
	bt_setup bt;
	peer_t * peer;
	bt_lib btlib;
	Logger log;
	unsigned char * infoHash;
	//NetworkSocket netsock;
	bt.parse_args(&argStruct, argc, argv);

	//to store information in bt_info_t
	ParseTorrent parseTorrent;
	cout<<"..............................................................................................................\n";
	map<string, string> m = parseTorrent.parseFile(argStruct.torrent_file);
	cout<<"..............................................................................................................\n";
	btStruct = parseTorrent.getInfoStructure(m);
	log.LogData("Info Structure Logged");
	argStruct.bt_info = &btStruct;
	// this is for 1 - 1 configuration.
	peer = argStruct.peers[1];
	infoHash = parseTorrent.calInfoHash(argStruct.torrent_file);
	log.LogData("Info Hashes Logged");
	/*cout << "'info hash here" << endl;
	for (int i = 0; i < 20; i++) {
		printf("%02x\n", infoHash[i]);

	}*/
	char h[68];

	parseTorrent.getHandshakeMessage(infoHash, &argStruct,h);
	log.LogData("Handshake Message Created");
//	cout << h << endl;
	if (argStruct.pCheck == 1) {    
		log.LogData("Leecher Mode Created");                       // p specified then it is a leecher.
		btlib.leecher(peer, &argStruct, h);
	} else {      
log.LogData("Seeder Mode Created");// else it is a seeder.                                        
		btlib.seeder(peer, &argStruct, h);
	}
for(int i=1;i<MAX_CONNECTIONS;i++)
{
	if(argStruct.peers[i]!=NULL)
		delete[] argStruct.peers[i];
}
return 0;
}
