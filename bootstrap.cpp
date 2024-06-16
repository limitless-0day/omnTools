#include <iostream>
#include <string>

#include "main.h"
#include "lib\install.h"
#include "lib\tip.h"
#include "lib\mas.h"
#include "lib\statistics.h"

using namespace std;

void version(int argc,char **argv){
	cout << "omnTools [Version "<<omn_VERSION_MAJOR<<"."
								<<omn_VERSION_MINOR<<"."
								<<omn_VERSION_PATCH<<"."
								<<omn_VERSION_TWEAK<<"]"
								<< endl;
	cout << "Copyright by AGSN" << endl;
}

void (*tool[])(int,char**) = {
	version,
	install,
	tip,
	install_scripts_mas,
	code_statistics
	
};

string tool_argc[] = {
	"version",
	"install",
	"tip",
	"mas",
	"lang"
};

string tool_use_print[] = { // 增加输出文本颜色


	"\033[1;34mFrequently used commands\033[0m",
	"omn version",
	"omn install [installname] <objname>",
	"omn tip [lang/shell/os] <key>",
	"omn mas",
	"omn lang <dir>"
};

int main(int argc,char **argv){
	if(argc==1){
		for(int i=0;i<sizeof(tool_use_print)/sizeof(string);i++)
			cout<<tool_use_print[i]<<endl;
		return 0;
	}   

// 仅有1个参数omn时，显示命令类型


// 注意不匹配命令的异常处理
	for(int i=0;i<sizeof(tool_argc)/sizeof(string);i++)
		if(argv[1]==tool_argc[i])
			tool[i](argc,argv);

	return 0;

}
