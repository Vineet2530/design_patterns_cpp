
#include<iostream>
#include<string>
#include<list>
using namespace std;

class ISubscriber{
    public:
        virtual void notify(string msg)=0;
};

class User:public ISubscriber
{
    int userId;
    public:
        User(int userId)
        {
            this->userId=userId;
        }
        void notify(string msg)
        {
            cout<<"User: "<<userId<<" received msg - "<<msg<<endl;
        }
};

class Group
{
    list<ISubscriber*> users;
    public:
        void subscribe(ISubscriber* user)
        {
            users.push_back(user);
        }
        void unsubscribe(ISubscriber* user)
        {
            users.remove(user);
        }
        void notify(string msg)
        {
            for(auto user: users)
                user->notify(msg);
        }
};

int main()
{
    Group* group = new Group;

    User* user1=new User(1);
    User* user2=new User(2);
    User* user3=new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("New msg");

    group->unsubscribe(user1);

    group->notify("New New Msg");

    return 0;
}