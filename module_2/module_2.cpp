#include <string>
#include <iostream>
#include "module_2.h"


#include "chrono" // for sending in loop
#include "thread" //


void print_mod1()
{
    std::cout << "######\"module2\" loop" << std::endl;
}



int main(int argc, char const *argv[])
{
    std::cout << "module_2 is started" << std::endl;
    int cnt = 10;
    std::thread Mod1Msg([&](){
    while (cnt!=0) {
      print_mod1();
      std::this_thread::sleep_for(std::chrono::milliseconds(400));
      cnt--;
    } });
    Mod1Msg.join();
    return 0;
}
