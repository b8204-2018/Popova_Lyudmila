#ifndef OOP_RESTAURANT_H
#define OOP_RESTAURANT_H

#include <iostream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define Newbie 0
#define Ordinary 15
#define Master 30

enum MOOD {terrible, bad, neutral, good, great};
enum STATUS {waiting_for_food, ready_to_pay};
enum QUALITY {like_a_poison, disqusting, not_bad, yummy};



class Food {
public:
    string name;
    QUALITY quality;
    bool status = false;

    bool IsTasty();
};

class Human {
protected:
    int cash;
    string name;
public:
    MOOD mood;

    virtual void PrintData() = 0;

    void MoodGetsBetter();

    void MoodGetsWorse();
};

class Guest: public Human {
protected:
    STATUS status;
public:
    vector<Food> order;

    Guest(string name);

    void Pay();

    void Eat(Food food);

    void PrintData();
    int GiveTips(){
        return (cash*(int)mood/20);
    };
};

class Waiter: public Human {
private:
    int waiter_exp = Newbie;
public:
    Waiter(string name);
    void BringOrder(Guest &guest);
    void PrintData();
};

class Cook: public Human {
public:
    Cook(string name);

    int cook_exp = Newbie;

    void PrepareFood(string &name, map <string, int> &menu);

    void PrintPreparedFood(string &name);

    void PrintData();
};

class Restaurant {
public:
    map <string, int> menu;
    vector <Cook> cooks;
};


class Chief: public Cook {
public:
    friend class Restaurant;
    //friend class Cook;
    Chief(string name);

    void AddCook(string name, int exp);

    void LayOffCook(string name);

    void AddInRestaurant(Restaurant r, string name, int price);

    void DeleteFromRestaurant(Restaurant r, string name);

    void GiveLesson(Cook &cook);
};


    
#endif //OOP_RESTAURANT_H
