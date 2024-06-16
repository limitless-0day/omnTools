#include <iostream>
#include <string>

#include "main.h"
#include "header\install.h"
#include "header\clist.h"
#include "header\mas.h"
#include "header\lang.h"

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
	install,
	clist,
	mas,
	lang
};

string tooln[] = {
	"v",
	"i",
	"l",
	"mas",
	"lang"
};

string toolh[] = {
	"\033[1;36;40mcommand lists\033[0m",
	"\033[1;32;40momn v\033[0m\tQuery the version",
	"\033[1;32;40momn i [name]\033[0m\tInstallation [name]",
	"\033[1;32;40momn l [lang/shell/os] <key>\033[0m\tTo print the [lang/shell/os] command prompt list, you can use the <key> specified command keyword",
	"\033[1;32;40momn mas\033[0m\tActivate Windows quickly",
	"\033[1;32;40momn lang <dir>\033[0m\tStatistical language, using <dir> the specified directory"
};

int main(int argc,char **argv){
	bool nocode = true;
	if(argc==1){
		for(int i=0;i<sizeof(toolh)/sizeof(string);i++)
			cout<<toolh[i]<<endl;
		return 0;
	}
	for(int i=0;i<sizeof(tooln)/sizeof(string);i++)
		if(argv[1]==tooln[i]){
			nocode = false;
			tool[i](argc,argv);
			return 0;
		}
	if(nocode)cout<<"Not found \""<<argv[1]<<"\".";
	return 0;
}
