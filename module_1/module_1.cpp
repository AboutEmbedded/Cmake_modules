#include <string>
#include <iostream>
#include "module_1.h"


#include "chrono" // for sending in loop
#include "thread" //


void print_mod1(char const * param)
{
    std::cout << "###\"module1\" loop" <<param<< std::endl;
}



int main(int argc, char const *argv[])
{
    std::cout << "module_1 is started" << std::endl;

    char const *ExtMsg="";
    if(argc!=0) ExtMsg=argv[0];
    int cnt = 10;
    std::thread Mod1Msg([&](){
    while (cnt!=0) {
      print_mod1(ExtMsg);
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      cnt--;
    } });
    Mod1Msg.join();
    return 0;
}
