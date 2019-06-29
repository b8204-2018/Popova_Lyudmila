#include "Restaurant.h"
#include "Rest.h"

bool Food:: IsTasty(){
    if ((int)quality <= 1)
        return false;
    else
        return true;
}


void Guest::PrintData(){
    cout << name << " with " << cash << "dollars in his/her pocket, has " << mood << " mood" << endl;
}

Guest::Guest(string name){
    this->name = name;
    this->mood = MOOD(rand()%4);
    this->cash = rand()%1000;
    PrintData();
}

void Waiter::PrintData(){
    cout << "Waiter " << name << " has " << mood << " mood" << endl;
}

Waiter::Waiter(string name){
    this->name = name;
    this->mood = MOOD(rand()%4);
    this->exp_lvl = rand()%15;
    PrintData();
}

void Cook::PrintData(){
    cout << "Cook " << name << " has " << mood << " mood" << endl;
}

Cook::Cook(string name){
    this->name = name;
    this->mood = MOOD(rand()%4);
    this->exp_lvl = rand()%15;
    PrintData();
}

void Human::MoodGetsBetter(){
    if((int)mood < 4){
        mood = MOOD(mood + 1);
    }
}

void Human::MoodGetsWorse(){
    if((int)mood > 0){
        mood = MOOD(mood - 1);
    }
}

void Guest::Pay(){
    int pr;
    for (int i = 0; i < sizeof(order); i++){
        string name = order[i].name;
        cash = cash - menu.menu.find(order[i].name)->second;
    }
    cash -= GiveTips();
}

void Guest::Eat(Food food){
    if (((int)food.quality == 0) && (rand()%100 <= 20)){
        "Congrats, you killed a guest";
        delete[] this;
        exit(1);
    } else {
        if (food.IsTasty()) {
            MoodGetsBetter();
        } else {
            MoodGetsWorse();
        }
        status = ready_to_pay;
    }
    Pay();
}

void Waiter::BringOrder(Guest &guest){
    int prob = rand()&100;
    if (waiter_exp < 60/Ordinary)
        if (prob > (waiter_exp) && guest.mood != terrible){
            guest.mood = MOOD(guest.mood - 1);
        }
    if (waiter_exp > Ordinary)
        if ((prob > 3*waiter_exp) && (guest.mood != terrible)){
            guest.mood = MOOD(guest.mood + 1);
        }
    waiter_exp++;
}

void Cook::PrepareFood(string &name, map <string, int> &menu){
    if (menu.count(name) == 1)
        cook_exp++;
    PrintPreparedFood(name);
}

void Cook::PrintPreparedFood(string &name){
    cout << "Cook " << name << " just cooked " << name;
}


void Chief::AddCook(string name, int exp){
    res.cooks.push_back(new Cook(name));
}

void Chief::PrintData(){
    cout << "Cook " << name << " has " << mood << " mood" << endl;
}

Chief::Chief(string name){
    this->name = name;
    this->mood = MOOD(rand()%4);
    this->exp_lvl = rand()%15;
    PrintData();
}

void Chief::AddInRestaurant(Restaurant menu, string name, int price){
    menu.menu.insert(pair<string, int>(name, price));
}

void Chief::DeleteFromRestaurant(Restaurant menu, string name){
    menu.menu.erase(name);
}

void Chief::GiveLesson(Cook &cook){
    if (rand()%100 > 40 && cook.cook_exp < Master) {
        cook.cook_exp += 3;
    }
}
