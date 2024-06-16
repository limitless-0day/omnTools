#include "install.h"

using namespace std;

void install(int argc,char **argv){
	if(argc>2){
		string cmd = "curl -s -o "+string(argv[2])+".bat https://omn.agsn.site/bin/"+string(argv[2])+".bat";
		system(cmd.c_str());
		cmd = "start "+string(argv[2])+".bat";
		system(cmd.c_str());
	}
}
