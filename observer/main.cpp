#include <iostream>
#include <vector>

using namespace std;


class Publisher {
    vector <class Subscriber*> viewer;
    int inform;
public:
    int GetState(){
        return inform;
    };

    void Notify(int inf);

    void Subscribe(Subscriber *sub);

    void SetState(int inf){
        inform = inf;
        Notify(inform);
    };

};

class Subscriber {
    int data;
    Publisher *publ;
public:
    Publisher *GetSubs(){
        return publ;
    }
    int GetData(){
        return data;
    }

    void SetPublisher(Publisher *p){
        publ = p;
    }

    void SetData(int a){
        data = a;
    }

    virtual void Update() = 0;
};


void Publisher::Subscribe(Subscriber *sub){
    viewer.push_back(sub);
    sub->SetPublisher(this);
}


void Publisher::Notify(int inf){
    for (int i = 0; i < viewer.size(); i++){
        viewer[i]->Update();
    }
}

class SomeSubscriber1: public Subscriber{
public:
    void Update(){
        int a = GetData();
        int b = GetSubs()->GetState();
        SetData(b);
        cout << a << " меняется на " << b << endl;
    };
};

class SomeSubscriber2: public Subscriber{
public:
    void Update(){
        int a = GetData();
        int b = GetSubs()->GetState();
        SetData(b);
        cout << a << " меняется на " << b << endl;
    };
};

int main() {
    Publisher P;
    SomeSubscriber1 S1;
    SomeSubscriber2 S2;

    S1.SetData(10);
    S2.SetData(20);

    P.Subscribe(&S1);
    P.Subscribe(&S2);

    P.SetState(5);
    return 0;
}