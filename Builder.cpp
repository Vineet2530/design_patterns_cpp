
//creational design pattern.
#include<iostream>
#include<string>
using namespace std;

class Desktop       //product
{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherBoard;

    public:
        void setMonitor(string pMonitor){monitor=pMonitor;}
        void setKeyboard(string pKeyboard){keyboard=pKeyboard;}
        void setMouse(string pMouse){mouse=pMouse;}
        void setSpeaker(string pSpeaker){speaker=pSpeaker;}
        void setRam(string pRam){ram=pRam;}
        void setProcessor(string pProcessor){processor=pProcessor;}
        void setMotherBoard(string pMotherBoard){motherBoard=pMotherBoard;}

        void showSpecs()
        {
            cout<<"------------------------------------------"<<endl;
            cout<<"monitor: "<<monitor<<endl;
            cout<<"keyboard: "<<keyboard<<endl;
            cout<<"mouse: "<<mouse<<endl;
            cout<<"speaker: "<<speaker<<endl;
            cout<<"ram: "<<ram<<endl;
            cout<<"processor: "<<processor<<endl;
            cout<<"motherBoard: "<<motherBoard<<endl;
        }
};

class DesktopBuilder        //interface
{
    protected:
        Desktop* desktop;
    public:
        DesktopBuilder()
        {
            desktop=new Desktop();
        }
        virtual void buildMonitor()=0;
        virtual void buildKeyboard()=0;
        virtual void buildMouse()=0;
        virtual void buildSpeaker()=0;
        virtual void buildRam()=0;
        virtual void buildProcessor()=0;
        virtual void buildMotherBoard()=0;

        virtual Desktop* getDesktop()
        {
            return desktop;
        }
};

class DellDesktopBuilder:public DesktopBuilder  //basically we can configure parts here
{
     void buildMonitor(){
        desktop->setMonitor("Dell Monitor");
     }
     void buildKeyboard(){
        desktop->setKeyboard("Dell Keyboard");
     }
     void buildMouse(){
        desktop->setMouse("Dell Mouse");
     }
     void buildSpeaker(){
        desktop->setSpeaker("Dell Speaker");
     }
     void buildRam(){
        desktop->setRam("Dell RAM");
     }
     void buildProcessor(){
        desktop->setProcessor("Dell Processor");
     }
     void buildMotherBoard(){
        desktop->setMotherBoard("Dell MotherBoard");
     }
};

class HpDesktopBuilder : public DesktopBuilder
{
     void buildMonitor(){
        desktop->setMonitor("HP Monitor");
     }
     void buildKeyboard(){
        desktop->setKeyboard("HP Keyboard");
     }
     void buildMouse(){
        desktop->setMouse("HP Mouse");
     }
     void buildSpeaker(){
        desktop->setSpeaker("HP Speaker");
     }
     void buildRam(){
        desktop->setRam("HP RAM");
     }
     void buildProcessor(){
        desktop->setProcessor("HP Processor");
     }
     void buildMotherBoard(){
        desktop->setMotherBoard("HP MotherBoard");
     }
};

class DesktopDirector
{
    private:
        DesktopBuilder* desktopBuilder;
    public:
        DesktopDirector(DesktopBuilder* pDesktopBuilder)
        {
            desktopBuilder=pDesktopBuilder;
        }
        Desktop* BuildDesktop()
        {
            desktopBuilder->buildMonitor();
            desktopBuilder->buildKeyboard();
            desktopBuilder->buildMotherBoard();
            desktopBuilder->buildMouse();
            desktopBuilder->buildProcessor();
            desktopBuilder->buildRam();
            desktopBuilder->buildSpeaker();

            return desktopBuilder->getDesktop();
        }
};

int main()
{
    HpDesktopBuilder* hpDesktopBuilder= new HpDesktopBuilder();
    DellDesktopBuilder* dellDesktopBuilder=new DellDesktopBuilder();

    DesktopDirector* director1=new DesktopDirector(hpDesktopBuilder);
    DesktopDirector* director2=new DesktopDirector(dellDesktopBuilder);

    Desktop* desktop1 = director1->BuildDesktop();
    Desktop* desktop2 = director2->BuildDesktop();

    desktop1->showSpecs();
    desktop2->showSpecs();

    return 0;
}
