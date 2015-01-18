Project 2: BitTorrent Client
-----------------------

Name: Vivek Supe		
uname: vsupe

Name: Jay Modi	
uname: jmmodi

------------------------

This is a partial emulation of bittorrent peer to peer protocol which follows the protocol specifications mentioned on http://www.bittorrent.org/beps/bep_0003.html.We have implemented this client to support 1-N structure where N leechers request 1 seeder for files. We used select for the seeder to accept and send multiple piece simultaneously to the N leechers connected to it. We have also implemented this on mp3 file and have been successful doing so. 

Files Includes With This Project:
	BitTorrent.cpp		bt_lib.cpp		bt_lib.h		bt_setup.cpp		bt_setup.h	
	Logger.cpp		Logger.h		ParseTorrent.cpp	ParseTorrent.h

Tasks Accomplished:
	+ Implemented 1-N Architecture.
	+ Successful Sending Binary file Like Mp3.
	+ Successful Sending Text/Character Files.
	+ Successful Implementation of Select().

Guide:

1 - Type WIN:"echo %cd%: or for LINUX:"pwd" so check current directory. Now we use "cd" to change directory to the folder which has the Makefile & C File.
2 - We compile the file. To do so we have to get into current directory where the code is based and type "$make" command.
3 - Once the code has compiled we can go ahead with running the program. So do so we first understand the flags used.
          bt-client [OPTIONS] file.torrent
            -h             Print this help screen
            -b ip:port     Bind to this ip for incoming connections, ports
                           are selected automatically
            -s save_file   Save the torrent in directory save_dir (dflt: .)
            -l log_file    Save logs to log_filw (dflt: bt-client.log)
            -p ip:port     Instead of contacing the tracker for a peer list,
                           use this peer instead, ip:port (ip or hostname)
                           (include multiple -p for more than 1 peer)
            -v             verbose, print additional verbose info

Some valid commands are:
Seeder:	
	1- $bt-client -b IP:PORT file.torrent			-Start Seeder in normal mode.
	2- $bt-client -b IP:PORT -l log_file_name file.torrent			-Start Seeder in logging activty mode.
	3- $bt-client -b IP:PORT -v file.torrent		-Start Seeder in Verbose Mode.

Leecher:
	1- $bt-client -b IP:PORT -p IP:PORT<Multiple -p> -s save_file_name file.torrent			-Start Leecher in normal mode.
	2- $bt-client -b IP:PORT -p IP:PORT<Multiple -p> -s save_file_name -l log_file_name file.torrent-Start Leecher in logging activty mode.
	3- $bt-client -b IP:PORT -p IP:PORT<Multiple -p> -s save_file_name -v file.torrent		-Start Leecher in Verbose Mode.

Understanding Outputs:
	1- Seeder Output
		./bt-client -b localhost:8080 AP890109.trectext.torrent
		..............................................................................................................
		announce : foobar:6969
		creation date : 1413179754
		length : 1092683
		name : AP890109.trectext
		piece length : 262144
		'�ces :Tai}v �d�pCE�Wf*�7���Lt�p�?Tfo�U�7���=���"��a;G�:@�L"#
		..............................................................................................................
		8080
		Inside seeder
		Client Accept Val: 4
		Connection Accept Port: 9090
		Connection Accept I/P: 127.0.0.1
		Info Hash are equal..!!
		ID Hash are equal..!!
		Handshake message was authentic
		Handshake Message Sent
		Protocol Starts 
		Seeder Has Sent BITFIELD Msg
		Leecher is INTERESTED in receiving data
		Seeder is willing to Send Piece Msg On Request
		Recieved Piece 
		Recieved Piece 
		Recieved Piece 
		Recieved Piece 
		Recieved Piece 
		Data sent Perfectly

	2- Leecher Output
		./bt -b localhost:9090 -p localhost:8080 -s abc.txt AP890109.trectext.torrent
		..............................................................................................................
		announce : foobar:6969
		creation date : 1413179754
		length : 1092683
		name : AP890109.trectext
		piece length : 262144
		'�ces :Tai}v �d�pCE�Wf*�7���Lt�p�?Tfo�U�7���=���"��a;G�:@�L"#
		..............................................................................................................
		9090
		Inside leecher
		Connection Done On IP: 127.0.0.1 : 8080
		Handshake Message Sent
		Handshake Message Received
		Handshake Msg Received From Seeder: BitTorrent Protocol00000000�c�;�ξ�'�F��sV�
				                                                               |ئ���ST�>�H�H��U T�ޥ%�Z}d���e���\������Yͬ�<7�t������Jc��eB<��(�����l⍴�|�t�
		Size Of Handshake Msg Received From Seeder (Bytes): 68
		Info Hash are equal..!!
		ID Hash are equal..!!
		     Protocol started  
		Received BITFIELD Preping Interested Message
		Interested Message Sent 
		Requesting Random Pieces
		1th Request Piece Index: 1
		2th Request Piece Index: 4
		3th Request Piece Index: 2
		4th Request Piece Index: 3
		5th Request Piece Index: 5
		All Pieces Recieved
		perfect
