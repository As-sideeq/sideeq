#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BankAccount{
    private:
        int accountNo;
        string customerName, customerAddress;
        double accountBalance;

    public:
        BankAccount() : accountNo(0), customerName(""), customerAddress(""), accountBalance(0.0) {}

            void setAccountNo(int accNo){
                accountNo = accNo;
            }

            int getAccountNo(){
                return accountNo;
            }

            void setCustomerName(string cusName){
                customerName = cusName;
            }

            string getCustomerName(){
                return customerName;
            }

            void setCustomerAddress(string cusAddr){
                customerAddress = cusAddr;
            }

            string getCustomerAddress(){
                return customerAddress;
            }

            void setAccountBalance(double accBal){
                accountBalance = accBal;
            }

            double getAccountBalance(){
                return accountBalance;
            }

            virtual void transfer(BankAccount *a, double) = 0;

            virtual void printAccountInfo(){
                cout << "Your name is " << getCustomerName() << endl <<
                "Your account number is " << getAccountNo() << endl <<
                "Your address is " << getCustomerAddress() << endl <<
                "Your account balance is " << getAccountBalance() << endl;
            }

};

class StudentAccount : public BankAccount{
    string grade;
    double minumumBalance;

    public:
        StudentAccount() : grade(""), minumumBalance(0){}

        void transfer(BankAccount *account, double amount){
            double myAccountBalance = this->getAccountBalance();

            try{
            if(myAccountBalance == 0){
                throw 1;
            }else if(amount > 500000){
                throw 2;
            }else if(amount > myAccountBalance){
                throw 3;
                }

            double recipientBal = account->getAccountBalance();
            double myBal = this->getAccountBalance();
            double myAmountLeft = myBal - amount;
            double recepientAmountLeft = account->getAccountBalance() + amount;

            cout << this->getCustomerName() << " has " << myBal << " in his account" << endl;

            this->setAccountBalance(myAmountLeft);
            cout << "Transfering " << amount << " from " << this->getCustomerName()
            << " account to " << account->getCustomerName() << " account" << endl;
            account->setAccountBalance(recepientAmountLeft);


            cout << "Transfer success" << endl;

            cout << this->getCustomerName() << " now has " << this->getAccountBalance() << " in his account"
             << endl << "---------------------------------------------------------------" << endl;





            }catch(int errNum){
                if(errNum == 1){
                    cout << "Sorry! you do not money to transfer at all.." << endl;
                }else if(errNum == 2){
                    cout << "Sorry! the amount is too high!" << endl;
                }else if(errNum == 3){
                    cout << "Sorry, You cannot transfer more than " << myAccountBalance;
                }

            }



        }

        void printAccountInfo(){
            cout << "Your name is " << getCustomerName() << endl <<
                    "Your account number is " << getAccountNo() << endl <<
                    "Your address is " << getCustomerAddress() << endl <<
                    "Your account balance is " << getAccountBalance() << endl <<
                    "Your account type is a student account" << endl
                     << "-----------------------------------------------------------------" << endl;
        }
};


class Level2Account : public BankAccount{
    string grade;
    double minumumBalance;

    public:
        Level2Account() : grade(""), minumumBalance(10000){}

        void transfer(BankAccount *account, double amount){
            double myAccountBalance = this->getAccountBalance();

            try{
            if(myAccountBalance <= 10000){
                throw 1;
            }else if(amount > 2000000){
                throw 2;
            }else if(amount > myAccountBalance){
                throw 3;
            }

            double recipientBal = account->getAccountBalance();
            double myBal = this->getAccountBalance();
            double myAmountLeft = myBal - amount;
            double recepientAmountLeft = account->getAccountBalance() + amount;

            cout << this->getCustomerName() << " has " << myBal << " in his account" << endl;

            this->setAccountBalance(myAmountLeft);
            cout << "Transfering " << amount << " from " << this->getCustomerName() << " account to "
            << account->getCustomerName() << " account" << endl;
            account->setAccountBalance(recepientAmountLeft);


            cout << "Transfer success" << endl;

            cout << this->getCustomerName() << " now has " << this->getAccountBalance() << " in his account" <<
             endl << "---------------------------------------------------------------" << endl;


            }catch(int errNum){
                if(errNum == 1){
                    cout << "Sorry! you do cannot use more than 10000 from your account" << endl;
                }else if(errNum == 2){
                    cout << "Sorry! You cannot transfer more than 2million naira" << endl;
                }else if(errNum == 3){
                    cout << "You cant withdraw more than you have";
                }

            }


        }

        void printAccountInfo(){
            cout << "Your name is " << getCustomerName() << endl <<
                    "Your account number is " << getAccountNo() << endl <<
                    "Your address is " << getCustomerAddress() << endl <<
                    "Your account balance is " << getAccountBalance() << endl <<
                    "Your account type is a level2 account" << endl
                    << "-----------------------------------------------------------------" << endl;
        }

};

int main(void){
    BankAccount *studentAcc1, *level2acct1;


    studentAcc1 = new StudentAccount;
    level2acct1 = new Level2Account;

    studentAcc1->setCustomerName("Kennibravo");
    level2acct1->setCustomerName("Kenny");
    studentAcc1->setAccountNo(353333333);
    studentAcc1->setCustomerAddress("Ilorin");


    studentAcc1->setAccountBalance(500000);
    studentAcc1->transfer(level2acct1, 200000);
    studentAcc1->printAccountInfo();



    BankAccount *studentAcc2, *level2acct2;
    studentAcc2 = new StudentAccount;
    level2acct2 = new Level2Account;

    level2acct2->setCustomerName("John Doe");
    studentAcc2->setCustomerName("Jane Doe");

    level2acct2->setAccountNo(12345678);
    level2acct2->setCustomerAddress("Lagos");
    level2acct2->setAccountBalance(2000000);
    level2acct2->transfer(studentAcc2, 600000);


    level2acct2->printAccountInfo();



    //cout << "Your "

    // level2acct1->setAccountBalance(2000);
    // cout << level2acct1->getAccountBalance();


    //level2acct1->transfer(level2acct2, 200);
    // studentAcc1->setAccountBalance(1000);
    // cout << studentAcc1->getAccountBalance();
    // studentAcc1->transfer(studentAcc2, 1200);

}
