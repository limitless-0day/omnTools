#include <iostream>
#include <string>

#include "main.h"
#include "header\install.h"
#include "header\tip.h"
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
	tip,
	mas,
	lang
};

string tooln[] = {
	"v",
	"i",
	"tip",
	"mas",
	"lang"
};

string toolh[] = {
	"omn v\n\tQuery the version",
	"omn i [name]\n\tInstallation [name]",
	"omn tip [lang/shell/os] <key>\n\tTo print the [lang/shell/os] command prompt list, you can use the <key> specified command keyword",
	"omn mas\n\tActivate Windows quickly",
	"omn lang <dir>\n\tStatistical language, using <dir> the specified directory"
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
