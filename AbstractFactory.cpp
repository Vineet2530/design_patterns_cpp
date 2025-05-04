#include<iostream>
#include<string>
using namespace std;

class IButton
{
    public:
        virtual void press()=0;

};

class MacButton: public IButton
{
    public:
        void press()
        {
            cout<<"Mac button pressed.";
        }
};

class WinButton: public IButton
{
    public:
        void press()
        {
            cout<<"Win button pressed.";
        }
};

class ITextBox
{
    public:
        virtual void showText()=0;

};

class MacTextBox: public ITextBox
{
    public:
        void showText()
        {
            cout<<"Mac TextBox.";
        }
};

class WinTextBox: public ITextBox
{
    public:
        void showText()
        {
            cout<<"Win TextBox.";
        }
};

class IFactory
{
    public:
        virtual IButton* CreateButton()=0;
        virtual ITextBox* CreateTextBox()=0;
};

class MacFactory:public IFactory
{
    public:
        IButton* CreateButton()
        {
            return new MacButton();
        }
        ITextBox* CreateTextBox()
        {
            return new MacTextBox();
        }
};

class WinFactory:public IFactory
{
    public:
        IButton* CreateButton()
        {
            return new WinButton();
        }
        ITextBox* CreateTextBox()
        {
            return new WinTextBox();
        }
};

class GUIAbstractFactory
{
    public:
        static IFactory* CreateFactory(string osType)
        {
            if(osType=="windows")
                return new WinFactory();
            return new MacFactory();
        }
};

int main()
{
    cout<<"Enter you machine OS (Mac/Win): "<<endl;
    string osType;
    cin>>osType;

    IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* textBox = fact->CreateTextBox();
    textBox->showText();

    return 0;
}
