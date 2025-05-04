//Singleton - there should be only one instance.

#include<iostream>
#include<string>
#include<thread>
#include<mutex>

using namespace std;

class Logger
{
    static int counter;
    static Logger* loggerInstance;
    static mutex mt;
    Logger()
        {
            counter++;
            cout<<"New instance created. No of instances:"<<counter<<endl;
        }
    // we have to make copy constructor and operator overloading = also private.
    public:
        void Log(string msg)
        {
            cout<<msg<<endl;
        }
        static Logger *getLogger()
        {
            if(loggerInstance == NULL)  //putting lock is expensive; so doublecheck.
            {
                mt.lock();
                if(loggerInstance == NULL)
                {
                    loggerInstance=new Logger();
                }
                mt.unlock();
            }
            return loggerInstance;
        }
};

int Logger::counter=0;
Logger* Logger::loggerInstance=NULL;
mutex Logger::mt;

void user1logs(){
    Logger* logger1= Logger::getLogger();
    logger1->Log("this msg is from logger1");
}

void user2logs(){
    Logger* logger2= Logger::getLogger();
    logger2->Log("this msg is from logger2");
}

int main()
{
    thread t1(user1logs);
    thread t2(user2logs);

    t1.join();
    t2.join();

    return 0;
}