#include <iostream>
#include <string>

#include "main.h"
#include "lib\model\model.h"
#include "lib\tip\tip.h"

using namespace std;

void version(int argc,char **argv){
	cout << "omnTools [Version "<<omnTools_VERSION_MAJOR<<"."
								<<omnTools_VERSION_MINOR<<"."
								<<omnTools_VERSION_PATCH<<"."
								<<omnTools_VERSION_TWEAK<<"]"
								<< endl;
	cout << "Copyright by AGSN" << endl;
}

void (*tool[])(int,char**) = {
	version,
	model,
	tip
};

string tooln[] = {
	"version",
	"model",
	"tip"
};

string toolh[] = {
	"omn version",
	"omn model [modelname] <objname>",
	"omn tip [lang/shell]"
};

int main(int argc,char **argv){
	if(argc==1){
		for(int i=0;i<sizeof(toolh)/sizeof(string);i++)
			cout<<toolh[i]<<endl;
		return 0;
	}
	for(int i=0;i<sizeof(tooln)/sizeof(string);i++)
		if(argv[1]==tooln[i])
			tool[i](argc,argv);
	return 0;
}