
/*Singleton - there should be only one instance.
//singleton: 
1. static data member   --> like counter; maintain count of logger instance, check krne k liye ki kitne instance h
2. private constructor  
3. static mem function  --> creates logger obj if not already created.
*/

#include<iostream>
#include<string>
#include<thread>

using namespace std;

class Logger
{
    static int counter;
    static Logger* loggerInstance;
    Logger()
        {
            counter++;
            cout<<"New instance created. No of instances:"<<counter<<endl;
        }
    
    public:
        void Log(string msg)
        {
            cout<<msg<<endl;
        }
        static Logger *getLogger()   //iska kaam hai logger instance ko banana, agr already nhi bana hua h toh
        {
            if(loggerInstance == NULL)
            {
                loggerInstance=new Logger();
            }
            return loggerInstance;
        }
};

int Logger::counter=0;
Logger* Logger::loggerInstance=NULL;

int main()
{
    Logger* logger1= Logger::getLogger();
    logger1->Log("this msg is from logger1");

    Logger* logger2=Logger::getLogger();
    logger2->Log("this msg is from logger2");

    cout<<"logger1 is:"<<&logger1<<endl; //address of pointer
    cout<<"logger2 is:"<<&logger2<<endl;

    cout<<logger1<<" "<<logger2<<endl;  //actual address of object 

    return 0;
}
