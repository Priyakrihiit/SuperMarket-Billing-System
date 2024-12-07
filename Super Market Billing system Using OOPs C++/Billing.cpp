#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Billing{

    private:
    string Item;
    int Rate, Quantity;

    public:
    Billing(): Item(""), Rate(0), Quantity(0){   }
    
    void setItem(string item){
        Item=item;
    }
    void setRate(int rate){
        Rate = rate;
    }
    void setQuant(int quant){
        Quantity = quant;
    }  

    string getItem(){
        return Item;
    }

    int getRate(){
        return Rate;
    }

    int getQuant(){
        return Quantity;
    }


};

void addItem(Billing B){
    bool close = false;
    while(!close){
        int choice;
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.Close."<<endl;
        cout<<"\tEnter choice:";
        cin>>choice;

        if(choice==1){
            string item;
            int rate, quant;

            cout<<"\tEnter Item Name: ";
            cin>>item;
            B.setItem(item);

            cout<<"\tEnter Rate Of Item: ";
            cin>>rate;
            B.setRate(rate);

            cout<<"\tEnter Quantity Of Item: ";
            cin>>quant;
            B.setQuant(quant);

            ofstream out("D:/Bill.txt", ios::app);
            if(!out){
                cout<<"\tError: file can't open!"<<endl;
            }
            else{
                out<<"\t"<<B.getItem()<<" : "<<B.getRate()<<" : "<<B.getQuant()<<endl<<endl;
            }
            out.close();
            cout<<"\tItem Added Successfully"<<endl;
            Sleep(3000);

        }

        else if(choice==2){
            system("cls");
            close=true;
            cout<<"\t Back to Main Menu!"<<endl;
            Sleep(3000);

        }

    }
}

void printBilling(){
    system("cls");
    int count=0;
    bool close= false;
    while (!close){
        system("cls");
            int choice;
            cout<<"\t1.Add Bill."<<endl;
            cout<<"\t2.Close session."<<endl;
            cout<<"\tEnter Choice: "<<endl;
            cin>>choice;

            if(choice==1){
                string item;
                int quant;
                cout<<"\tEnter Item: "<<endl;
                cin>>item;
                cout<<"\tEnter Quantity: "<<endl;
                cin>>quant;

                ifstream in("D:/Bill.txt");
                ofstream out("D:/Bill Temp.txt");

                string line;
                bool found=false;

                while(getline(in, line)){
                    stringstream ss;
                    ss<<line;

                    string itemName;
                    int itemRate, itemQuant;
                    char delimiter;

                    ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;

                    if(item==itemName){
                        found =true;
                        if(quant<=itemQuant){
                        int amount =itemRate*quant;
                        cout<<"\tItem   ||    Rate   ||   Quantity   ||  Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;

                        int newQuant=itemQuant-quant;
                        itemQuant=newQuant;
                        count +=amount;
                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;
            
                    }
                    else{
                        cout<<"\tStory,"<<item<<"Ended!"<<endl;
                        
                    }
                    }
                    else{
                        out<<line<<endl;

                    }

                    


                }
                if(!found){
                    cout<<"\t Item Not Available!"<<endl;

                }
                out.close();
                in.close();
                remove("D:/Bill.txt");
                rename("D:/Bill Temp.txt", "D:/Bill.txt");

            }
            else if(choice==2){
                close=true;
                cout<<"\tCounting Total Bill"<<endl;
            }
            Sleep(3000);

        }

        system("cls");
        cout<<endl<<endl;
        cout<<"\tTotal Bill -----------------------: "<<count<<endl<<endl;
        cout<<"\t Thanks for Shopping!"<<endl;
        Sleep(5000);


    }


int main(){
    Billing B;
    bool exit = false;
    while(!exit){
        system("cls");
        int val;

        cout<<"\tWelcome to super market billing system"<<endl;
        cout<<"\t**************************************"<<endl;
        cout<<"\t\t1.Add Item."<<endl;
        cout<<"\t\t2.Print Bill."<<endl;
        cout<<"\t\t3.Exit."<<endl;
        cout<<"\t\t Enter Choice: ";
        cin>>val;

        if(val==1){
            system("cls");
            addItem(B);
            Sleep(3000);
        }

        else if(val==2){
            printBilling();
        }

        else if(val==3){
            system("cls");
            exit=true;
            cout<<"\tGood Luck!"<<endl;
            Sleep(3000);
        }





    }

    

}
