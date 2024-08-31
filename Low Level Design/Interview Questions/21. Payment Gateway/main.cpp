/*
It act as a mediator between user and financial institution and helps to transfer money.
mediator as - 
1. peer to peer
2. peer to merchant
    - Refund
    - multi tenancy

peer to peer
FR - 
1. add / update / delete user
2. add / update / delete Instrument(back, card etc.)
3. make payment from user1 to user2
    - search user, whom amount need to be transfer
    - select amount and funding instrument
    - pass information to processor
4. Notification for operation like add / delete user, debit payment, credit payment etc.
5. users able to see transaction history.
*/

#include<bits/stdc++.h>
using namespace std;

/*
--------------------------
PaymentGateway
--------------------------
UserController userControllerObj;
InstrumentController instrumentControllerObj;
TransactionController transactionControllerObj;

--------------------------
User
--------------------------
int id;
string userName;
string emailId;

--------------------------
UserController
--------------------------
vector<User> users;
addUser(User user);
removeUser(User user)


--------------------------
InstrumentEntity
--------------------------
int id;
int userId;
InstrumentType type

enum InstrumentType {
    BANK, CARD
}

--------------------------
BankInstrumentEntity (InstrumentEntity) 
--------------------------
string bankAccountNumber;
string bankIFSCCode;

--------------------------
CardInstrumentEntity (InstrumentEntity) 
--------------------------
string cardNumber;
string cvvNumber;

--------------------------
InstrumentService
--------------------------
map<User, vector<Instrument>> userToInstrument;
addInstrument(instrumentDO obj)
getInstrument(int userId, int instrumentId)


// It follow "S" of SOLID principle
--------------------------
BankService (InstrumentService)
--------------------------
....

--------------------------
CardService (InstrumentService)
--------------------------
....

--------------------------
InstrumentServiceFactory
--------------------------
getInstrumentService(InstrumentType type)

--------------------------
InstrumentController (InstrumentServiceFactory)
--------------------------
InstrumentServiceFactory obj;
addInstrument(InstrumentDO obj);
getInstrument(InstrumentType type, int userId, int instrumentId);


--------------------------
TransactionController
--------------------------
InstrumentController instrumentControllerObj;
map<int, vector<Transaction>> userIdToTransactionMp;
Processor processorObj
makePayment(transactionDO obj);
getTransactionHistory(int userId);


--------------------------
Processor
--------------------------
processPayement(Transaction txn);

--------------------------
Transaction
--------------------------
int id;
int amt;
int senderId;
int recieverId;
int debitInstrumentId;
int creditInstrumentId;
TransactionStatus status;

enum TransactionStatus {
    PENDING, SUCCESS, DENIED
}
*/