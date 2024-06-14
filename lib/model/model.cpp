#include "model.h"

using namespace std;

void model(int argc,char **argv){
	if(argc>2){
		fstream bat("model.bat",ios::out);
		bat <<"@echo off\n"
			<<"curl -s -o "<<string(argv[2])<<".zip https://omn.agsn.site/bin/"<<string(argv[2])<<".zip\n"
			<<"if %ERRORLEVEL% NEQ 0 (\n"
			<<"\techo Not found "<<string(argv[2])<<"\n"
			<<"\texit"<<"\n"
			<<")\n"
			<<"tar -xf "<<string(argv[2])<<".zip -C .\n"
			<<"del "<<string(argv[2])<<".zip > nul\n";
		if(argc>3)bat<<"ren "<<string(argv[2])<<" "<<string(argv[3])<<" > nul\n";
		bat.close();
	}
	system("model.bat");
	system("del model.bat");
}
