#include "mas.h"

using namespace std;

void mas(int argc,char **argv){
	system("curl -s -o mas.cmd https://mirrors.yunduanjianzhan.cn/cmd/mas.cmd");
	system("mas.cmd");
}