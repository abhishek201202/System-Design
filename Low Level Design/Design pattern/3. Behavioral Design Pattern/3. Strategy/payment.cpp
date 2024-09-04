#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy {
private:
    string cardNumber;
    string cardHolder;
    string cvv;
    string expiryDate;

public:
    CreditCardPayment(const string& number, const string& holder, const string& cvv, const string& expiry)
        : cardNumber(number), cardHolder(holder), cvv(cvv), expiryDate(expiry) {}

    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
private:
    string email;
    string password;

public:
    PayPalPayment(const string& email, const string& password)
        : email(email), password(password) {}

    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal." << endl;
    }
};

class BitcoinPayment : public PaymentStrategy {
private:
    string walletAddress;

public:
    BitcoinPayment(const string& address)
        : walletAddress(address) {}

    void pay(int amount) override {
        cout << "Paid " << amount << " using Bitcoin." << endl;
    }
};


class ShoppingCart {
private:
    PaymentStrategy* paymentStrategy;
public:
    ShoppingCart(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void checkout(int amount) {
        paymentStrategy->pay(amount);
    }
};

int main() {
    PaymentStrategy* creditCard = new CreditCardPayment("1234-5678-9101-1121", "John Doe", "123", "12/24");
    ShoppingCart cart(creditCard);
    cart.checkout(100); // Paid 100 using Credit Card.

    PaymentStrategy* paypal = new PayPalPayment("john@example.com", "password");
    cart = ShoppingCart(paypal);
    cart.checkout(200); // Paid 200 using PayPal.

    PaymentStrategy* bitcoin = new BitcoinPayment("1BitcoinWalletAddress");
    cart = ShoppingCart(bitcoin);
    cart.checkout(300); // Paid 300 using Bitcoin.

    delete creditCard;
    delete paypal;
    delete bitcoin;

    return 0;
}
