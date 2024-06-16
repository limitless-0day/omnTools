<<<<<<<< HEAD:src/Install/mas.cpp
#include "../../lib/mas.h"

using namespace std;

void install_scripts_mas(int argc,char **argv){

	system("curl -s -o mas.cmd https://omn.agsn.site/cmd/mas.cmd");
	system("mas.cmd");
}
========
#include "..\header\mas.h"

using namespace std;

void mas(int argc,char **argv){
	system("curl -s -o mas.cmd https://omn.agsn.site/cmd/mas.cmd");
	system("mas.cmd");
}
>>>>>>>> 7206842962c04da07ef98d6f24454e12fe252f6e:src/mas.cpp
