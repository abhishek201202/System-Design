/*
FR - 
1. create / delete group
2. add / remove friend in/out group
3. send invition of a group
4. add / remove expense in group
5. add / remove expense directly to a friend
6. split expense equally / unequally / % wise
7. Balance sheet of each user
*/

#include<bits/stdc++.h>
using namespace std;

/*
splitwise 
----------------
vector<User> users;
vector<Groups> groups;

createGroup(string groupName)
deleteGRoup(string groupName)
addFriend(User user);
removeFriend(User user);
inviteFriend(User user);

addExpense(Entity source, Entity destination, Expense expense);
removeExpense(Entity source, Entity destincation, Expense expense);

entity -> user 
       -> group
*/

class SplitWiseApp {
    UserController *userControllerObj;
    GroupController *grpControllerObj;
    SplitWise() {
        userControllerObj = new UserController();
        grpControllerObj = new GroupController();
    }
};

class User {
    string name;
    string phoneNumber;
    string emailId;
    BalanceSheet balancesheet;
};

class UserController {
    vector<User*> users;
    ExpenseController *expenseController;
    UserController() {
        expenseController = new ExpenseController();
    }
    void addFriend();
    void removeFriend();
    void inviteFriend();
};

class Groups {
    string groupName;
    vector<User*> users;
    vector<Expense*> expenses;
}

class GroupController {
    vector<Group*> groups;
    ExpenseController *expenseController;
    GroupController() {
        expenseController = new ExpenseController();
    }
    void createGrp();
    void deleteGrp();
};

class BalanceSheet {
    unordered_map<User*, Balance> userToAmt;
};

class Balance {
    double amt;
    BalanceType type;
}

enum BalanceType {
    TAKE, GIVE
};

class BalanceSheetController {
    void updateBalanceSheet(); // called for all the user on which split is happening, once expense is added or removed
}


class Expense {
    User *paidBy;
    Split *split;
};

class Split {
    unordered_map<int, User*> amtToUser;
};

class ExpenseController {
    void addExpense ();
    void removeExpense ();
};

class EqualSplitExpenseController: public ExpenseController {
    void addExpense () override;
    void removeExpense () override;
};

class UnEqualSplitExpenseController: public ExpenseController {
    void addExpense () override;
    void removeExpense () override;
};

