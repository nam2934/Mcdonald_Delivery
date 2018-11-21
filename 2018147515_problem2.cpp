#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

//'Welcome' fucntion is start of the program
//user can selct menu
void Welcome(){
    //print Mcdonals Delivery System
    cout << "-----------------------------------" << endl
    << "-----Mcdonalds Delivery System-----" << endl
    << "-----------------------------------" << endl << endl
    << "1. Sign up" << endl
    << "2. Show Menu" << endl
    << "3. Order" << endl
    << "4. Order condition" << endl
    << "5. Refund" << endl
    << "0. Exit" << endl
    << "Select -> ";
}

//print Mcdonals menu
void Showmenu(){
    cout << "----------Mcdonalds Menu ----------" << endl
    << "1. Hamburger              - 1000" << endl
    << "2. Cheeseburger           - 1500" << endl
    << "3. Big Mac                - 3000" << endl
    << "4. Double Quarter Cheese  - 5000" << endl
    << "5. Fries                  - 1500" << endl
    << "6. Chicken McNuggets      - 2000" << endl
    << "7. Quarter Pounder Cheese - 4000" << endl
    << "8. Coke                   - 1500" << endl;
}

//Make Mcdonals_system
//It include member function and member variable
//Member function : 
// Set_Id -> set id by user input
// Set_Password -> set password by user input
// Set_Money -> set money by user input
class Mcdonals_system{
    public:
        Mcdonals_system();
        string Get_ID();
        string Get_PW();
        void Set_ID(string arrayID);
        void Set_Password();
        void Set_Money();
        void Set_Order();
        void Get_Order();
        int Get_money();
        bool Check_Money(int i);
        void Set_order(int i);
        int Get_sum(int i);
        void Set_sum(int i, int j);
        int Get_order(int i);
        void Get_first_money();
        int Get_Refund(int i);

    private:
        string ID;
        string Password;
        int Money;
        int Hamburger;
        int Cheeseburger;
        int Big_Mac;
        int Double_Quater_Cheese;
        int Fries;
        int Chicken_McNuggets;
        int Quarter_Pounder_Cheese;
        int Coke;
        int sum[8];
        int order[8];
        int first_money;

};

//Get initialize money
void Mcdonals_system::Get_first_money(){
    first_money = Money;
}

//input menu order
void Mcdonals_system::Set_order(int i){
    cin >> order[i];
}

//Get order(return)
int Mcdonals_system::Get_order(int i){
    return order[i];
}

//Get sum
int Mcdonals_system::Get_sum(int i){
    return sum[i];
}
//Set sum
void Mcdonals_system::Set_sum(int i, int j){
    sum[i] = j;
}

//default constructor of class Mcdonals_system
Mcdonals_system::Mcdonals_system(){

}

//Type of member function : Get_ID
string Mcdonals_system::Get_ID(){
    return ID;
}

//Type of member function : Get_PW
string Mcdonals_system::Get_PW(){
    return Password;
}

//Type of member function : Set_Id
void Mcdonals_system::Set_ID(string arrayID){
    ID = arrayID;
}

//Type of member function : Set_Password
void Mcdonals_system::Set_Password(){
    string password;
    cin >> password;
    Password = password;
}

//Type of member function : Set_Money
void Mcdonals_system::Set_Money(){
    int money;
    cin >> money;
    Money = money;
}

//Set order
void Mcdonals_system::Set_Order(){
    Hamburger = sum[0];
    Cheeseburger = sum[1];
    Big_Mac = sum[2];
    Double_Quater_Cheese = sum[3];
    Fries = sum[4];
    Chicken_McNuggets = sum[5];
    Quarter_Pounder_Cheese = sum[6];
    Coke = sum[7];
}

//Get order
void Mcdonals_system::Get_Order(){
    int count = 0;
    int count_i[8]={0,};
    int total_purchase = 0;
    string name[8] = {"Hamburger","Cheeseburger","Big_Mac","Double_Quater_Cheese","Fries", "Chicken_McNuggets" ,"Quarter_Pounder_Chees","Coke"};
    int price[8] = {1000, 1500, 3000, 5000, 1500, 2000, 4000, 1500};
    for(int i=0 ; i<8 ; i++){
        if(sum[i] != 0){
            count_i[count] = i;
            count++;
        }
    }
    for(int j = 0; j < count ; j++){
        cout << j+1 << ". " << name[count_i[j]] << ": " << sum[count_i[j]] << endl;
        total_purchase = total_purchase + sum[count_i[j]] * price[count_i[j]];
    }

    cout << endl;

    cout << "Your total purchase amount is " << total_purchase << endl;
    cout << "The balance is " << first_money - total_purchase << endl;
    cout << "Thanks" << endl;
}

//Get Refund
int Mcdonals_system::Get_Refund(int k){
    int count = 0;
    int count1 = 0;
    int count_i[8]={0,};
    int total_purchase = 0;
    k = k - 1;

    //menu stiring array
    string name[8] = {"Hamburger","Cheeseburger","Big_Mac","Double_Quater_Cheese","Fries", "Chicken_McNuggets" ,"Quarter_Pounder_Chees","Coke"};
    int price[8] = {1000, 1500, 3000, 5000, 1500, 2000, 4000, 1500};
    for(int i=0 ; i<8 ; i++){
        if(sum[i] != 0){
            count_i[count] = i;
            count++;
        }
    }

    //refund method
    if(k <= count-1){
        sum[count_i[k]] = 0;
        for(int i=0 ; i<8 ; i++){
            if(sum[i] != 0){
                count_i[count1] = i;
                count1++;
            }
        }
        for(int j = 0; j < count1 ; j++){
            cout << j+1 << ". " << name[count_i[j]] << ": " << sum[count_i[j]] << endl;
            total_purchase = total_purchase + sum[count_i[j]] * price[count_i[j]];
        }
        cout << "Successfully refunded" << endl;
        return 0;
    }
    
    //error handling
    else{
        cout << "Wrong Input!" << endl;
        return 1;
    }

    cout << endl;

    cout << "Your total purchase amount is " << total_purchase << endl;
    cout << "The balance is " << first_money - total_purchase << endl;
    cout << "Thanks" << endl;
}

//Get money
int Mcdonals_system::Get_money(){
    return Money;
}

//Check_Money
bool Mcdonals_system::Check_Money(int i){
    int price[8] = {1000, 1500, 3000, 5000, 1500, 2000, 4000, 1500};
    Money = Money - order[i]*price[i];
    if(Money < 0){
        cout << "Over budget" << endl;
        Money = Money + order[i]*price[i];
        return true;
    }
    return false;
    
}

int main(){
    //make USER object array, USER array can be store 100 object.
    Mcdonals_system USER[100];
    string ID[100];
    string PW[100];
    int i=0;
    int count = 1;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int h;
    int ar;
    int ah;
    string loginID;
    string loginPW;
    bool flag = true;
    string id;
    char order_option;
    int refund;

    //recive user input(about option)
    char option;
    while(true){
        Welcome();
        cin >> option;
        cout << endl;
        switch(option){
            
            //case1 : Sign up
            case '1':
                while(flag){
                    cout << "Input your ID(0-to main menu) : ";
                    cin >> id;
                    if(id != "0"){
                        ID[i] = id;
                        for(int j=0; j<i; j++){
                            if(ID[j] == ID[i]){
                                count = count * 0;
                            }
                        }
                        if(count == 1){
                            flag = false;
                        }
                        else{
                            cout << "Duplicated user" << endl;
                            count = 1;
                        }
                    }
                    else break;
                }
                if(id != "0"){
                    USER[i].Set_ID(ID[i]);
                    cout << "Input your Password : ";
                    USER[i].Set_Password();
                    cout << "Input your Initial money: ";
                    USER[i].Set_Money();
                    USER[i].Get_first_money();
                    cout << "Welcome, " << USER[i].Get_ID() << endl;
                    i++;
                    flag = true;
                }
                break;
            
            //Show menu
            case '2':
                Showmenu();
                break;
            
            //Order
            case '3':
                
                for(int j=0; j<i; j++){
                    PW[j] = USER[j].Get_PW();
                }
                count2 = 0;
                count3 = 0;
                while((count2 == 0) || (count3 == 0)){
                    count2 = 0;
                    count3 = 0;
                    cout << "Input your ID(0-to main menu) : ";
                    cin >> loginID;
                    if(loginID == "0"){
                        break;
                    }
                    cout << "Input your password : ";
                    cin >> loginPW;
                    cout << endl;
                    for(int j = 0; j < i; j++){
                        if(ID[j] == loginID){
                            count2 = 1;
                        }
                        if(PW[j] == loginPW){
                            count3 = 1;
                        }
                    }
                    if((count2 == 0) || (count3 == 0)){
                        cout << "Wrong Id, Password!!!" << endl;
                    }
                }
                for(h = 0 ; h < i; h++){
                    if(ID[h] == loginID){
                        ar = h;
                        break;
                    }
                }
                
                if(loginID == "0"){
                    break;
                }
                order_option = 1;
                while(order_option != '0'){
                    cout << "Select menu number(0-to main menu) : ";
                    cin >> order_option;
                    switch(order_option){
                        case '1':
                            cout << "How many 'Hamburger' do you want? : ";
                            USER[ar].Set_order(0);
                            cout << endl;
                            if(USER[ar].Check_Money(0)) break;
                            USER[ar].Set_sum(0,(USER[ar].Get_sum(0) + USER[ar].Get_order(0)));
                            break;
                        case '2':
                            cout << "How many 'Cheeseburger' do you want? : ";
                            USER[ar].Set_order(1);
                            cout << endl;
                            if(USER[ar].Check_Money(1)) break;
                            USER[ar].Set_sum(1,(USER[ar].Get_sum(1) + USER[ar].Get_order(1)));
                            break;
                        case '3':
                            cout << "How many 'Big_Mac' do you want? : ";
                            USER[ar].Set_order(2);
                            cout << endl;
                            if(USER[ar].Check_Money(2)) break;
                            USER[ar].Set_sum(2,(USER[ar].Get_sum(2) + USER[ar].Get_order(2)));
                            
                            break;
                        case '4':
                            cout << "How many 'Double_Quater_Cheese' do you want? : ";
                            USER[ar].Set_order(3);
                            cout << endl;
                            if(USER[h].Check_Money(3)) break;
                            USER[ar].Set_sum(3,(USER[ar].Get_sum(3) + USER[ar].Get_order(3)));
                            
                            break;
                        case '5':
                            cout << "How many 'Fries' do you want? : ";
                            USER[ar].Set_order(4);
                            cout << endl;
                            if(USER[h].Check_Money(4)) break;
                            USER[ar].Set_sum(4,(USER[ar].Get_sum(4) + USER[ar].Get_order(4)));
                            
                            break;
                        case '6':
                            cout << "How many 'Chicken_McNuggets' do you want? : " ;
                            USER[ar].Set_order(5);
                            cout << endl;
                            if(USER[ar].Check_Money(5)) break;
                            USER[ar].Set_sum(5,(USER[ar].Get_sum(5) + USER[ar].Get_order(5)));
                            
                            break;
                        case '7':
                            cout << "How many 'CQuarter_Pounder_Cheese' do you want? : ";
                            USER[ar].Set_order(6);
                            cout << endl;
                            if(USER[ar].Check_Money(6)) break;
                            USER[ar].Set_sum(6,(USER[ar].Get_sum(6) + USER[ar].Get_order(6)));
                            
                            break;
                        case '8':
                            cout << "How many 'Coke' do you want? : ";
                            USER[ar].Set_order(7);
                            cout << endl;
                            if(USER[ar].Check_Money(7)) break;
                            USER[ar].Set_sum(7,(USER[ar].Get_sum(7) + USER[ar].Get_order(7)));
                            
                            break;
                        case '0':
                            break;
                    }
                }
                USER[ar].Set_Order();
                USER[ar].Get_Order();
                break;
            
            //Order condition
            case '4':
                for(int j=0; j<i; j++){
                    PW[j] = USER[j].Get_PW();
                }
                count4 = 0;
                count5 = 0;
                while((count4 == 0) || (count5 == 0)){
                    count4 = 0;
                    count5 = 0;
                    cout << "Input your ID(0-to main menu) : ";
                    cin >> loginID;
                    if(loginID == "0"){
                        break;
                    }
                    cout << "Input your password : ";
                    cin >> loginPW;
                    cout << endl;
                    for(int j = 0; j < i; j++){
                        if(ID[j] == loginID){
                            count4 = 1;
                        }
                        if(PW[j] == loginPW){
                            count5 = 1;
                        }
                    }
                    if((count4 == 0) || (count5 == 0)){
                        cout << "Wrong Id, Password!!!" << endl;
                    }
                }
                for(h = 0 ; h < i; h++){
                    if(ID[h] == loginID){
                        ar = h;
                        break;
                    }
                }
                if(loginID == "0"){
                    break;
                }

                USER[ar].Set_Order();
                USER[ar].Get_Order();
            
                break;

            //Refund
            case '5':
                for(int j=0; j<i; j++){
                    PW[j] = USER[j].Get_PW();
                }
                count4 = 0;
                count5 = 0;
                while((count4 == 0) || (count5 == 0)){
                    cout << "Input your ID(0-to main menu) : ";
                    cin >> loginID;
                    if(loginID == "0"){
                        break;
                    }
                    cout << "Input your password : ";
                    cin >> loginPW;
                    cout << endl;
                    for(int j = 0; j < i; j++){
                        if(ID[j] == loginID){
                            count4 = 1;
                        }
                        if(PW[j] == loginPW){
                            count5 = 1;
                        }
                    }
                    if((count4 == 0) || (count5 == 0)){
                        cout << "Wrong Id, Password!!!" << endl;
                    }
                }
                for(h = 0 ; h < i; h++){
                    if(ID[h] == loginID){
                        ar = h;
                        break;
                    }
                }
                if(loginID == "0"){
                    break;
                }
                USER[ar].Set_Order();

                while(1){
                    cout << "Choose number(0 - to main menu) : ";
                    cin >> refund;
                    if(USER[ar].Get_Refund(refund) == 0) break;
                }
                break;
            
            //End the program
            case '0':
                cout << "End the program" << endl;
                cout << endl;
                return 0;
            default :
                break;
        }
    }
}
