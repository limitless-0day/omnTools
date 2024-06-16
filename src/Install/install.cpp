<<<<<<<< HEAD:src/Install/install.cpp
#include "../../lib/install.h"

using namespace std;

void install(int argc,char **argv){
	if(argc>2){
		string cmd = "curl -s -o "+string(argv[2])+".bat https://omn.agsn.site/bin/"+string(argv[2])+".bat";
		system(cmd.c_str());
		cmd = "start "+string(argv[2])+".bat";
		system(cmd.c_str());
	}
}
========
#include "..\header\install.h"

using namespace std;

void install(int argc,char **argv){
	if(argc>2){
		string cmd = "curl -s -o "+string(argv[2])+".bat https://omn.agsn.site/bin/"+string(argv[2])+".bat";
		system(cmd.c_str());
		cmd = "start "+string(argv[2])+".bat";
		system(cmd.c_str());
	}
}
>>>>>>>> 7206842962c04da07ef98d6f24454e12fe252f6e:src/install.cpp
