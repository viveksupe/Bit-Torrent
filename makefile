bt-client :	bt_lib.o Logger.o bt_setup.o ParseTorrent.o BitTorrent.cpp	
		g++ -g -std=c++0x bt_lib.o Logger.o bt_setup.o ParseTorrent.o BitTorrent.cpp -lssl -lcrypto -o bt-client

ParseTorrent.o:	ParseTorrent.cpp
		g++ -g -std=c++0x -c ParseTorrent.cpp -o ParseTorrent.o

bt_lib.o: bt_lib.cpp
		g++ -g -std=c++0x -c bt_lib.cpp -o bt_lib.o

bt_setup.o: bt_setup.cpp
		g++ -g -std=c++0x -c bt_setup.cpp -o bt_setup.o

Logger.o: Logger.cpp
		g++ -g -std=c++0x -c Logger.cpp -o Logger.o

clean:
	rm *.o bt-client















