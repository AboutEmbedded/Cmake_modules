#include <string>
#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "chrono" // for sending in loop
#include "thread" //


void PrintMainMsg()
{
    std::cout << ">>>main program loop" << std::endl;
}


int CreateThr(std::string path, std::string param)
{
    pid_t pid = fork();
    int err=0;
    if (pid == 0)
    {
        execl(path.c_str(), param.c_str(),NULL);        // вызовем какую-нибудь стандартную утилиту
        err=-2;
    }
    else if (pid < 0)
    {
        fprintf(stderr, "Some error on fork\n");
        
        err=-1;
    }
    return err;
}


int main(int argc, char const *argv[])
{
    std::cout << "main program is started" << std::endl;
    int cnt = 5;
    std::thread MainMsg([&](){
    while (cnt!=0) {
      PrintMainMsg();
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cnt--;
    } });
    
    
    CreateThr("./module_1/module_1"," hello");
    CreateThr("./module_2/module_2", "");

    printf("Success!\n");
    wait(NULL); // дожидаемся завершения
    printf("Done\n");

    //print_mod1();

    MainMsg.join();
    return 0;
}
