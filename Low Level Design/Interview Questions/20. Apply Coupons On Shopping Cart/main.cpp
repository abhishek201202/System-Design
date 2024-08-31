/*
Given shopping cart with products and coupons and calculate the net price after applying coupons on product.
Coupon can be of different types with certain conditions - 
1. N% off that is 10% off for all the individual.
2. P% on next item.
3. D% off on Nth item on Type T.
Sequentially want to apply coupons on all the cart and get the total amount.
*/

#include<bits/stdc++.h>
using namespace std;

class Product {
private:
    string name;
    double price;
public:
    Product(const string& name, double price) : name(name), price(price) {}
    double getPrice() const return price;
    string getName() const return name;
};

class Cart {
public:
    virtual double getTotalPrice() const = 0;
    virtual const vector<Product>& getProducts() const = 0;
    virtual ~Cart() = default;
};

class ConcreteCart : public Cart {
private:
    vector<Product> products;
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    double getTotalPrice() const override {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        return total;
    }
    const vector<Product>& getProducts() const override {
        return products;
    }
};

class CouponDecorator : public Cart {
protected:
    Cart* cart;
public:
    CouponDecorator(Cart* cart) : cart(cart) {}
    virtual ~CouponDecorator() {
        delete cart;
    }
    double getTotalPrice() const override {
        return cart->getTotalPrice();
    }
    const vector<Product>& getProducts() const override {
        return cart->getProducts();
    }
};

class PercentOffCoupon : public CouponDecorator {
private:
    double percentOff;
public:
    PercentOffCoupon(Cart* cart, double percentOff) : CouponDecorator(cart), percentOff(percentOff) {}
    double getTotalPrice() const override {
        double total = 0.0;
        for (const auto& product : cart->getProducts()) {
            total += product.getPrice() * (1.0 - percentOff / 100.0);
        }
        return total;
    }
};


class PercentOffNextItemCoupon : public CouponDecorator {
private:
    double percentOff;
public:
    PercentOffNextItemCoupon(Cart* cart, double percentOff) : CouponDecorator(cart), percentOff(percentOff) {}
    double getTotalPrice() const override {
        double total = 0.0;
        const auto& products = cart->getProducts();
        if (!products.empty()) {
            total += products[0].getPrice();
            for (int i = 1; i < products.size(); ++i) {
                total += products[i].getPrice() * (1.0 - percentOff / 100.0);
            }
        }
        return total;
    }
};

class PercentOffNthItemTypeCoupon : public CouponDecorator {
private:
    double percentOff;
    int nthItem;
    string itemType;
public:
    PercentOffNthItemTypeCoupon(Cart* cart, double percentOff, int nthItem, const string& itemType) : CouponDecorator(cart), percentOff(percentOff), nthItem(nthItem), itemType(itemType) {}
    double getTotalPrice() const override {
        double total = 0.0;
        int count = 0;
        for (const auto& product : cart->getProducts()) {
            if (product.getName() == itemType) {
                ++count;
                if (count == nthItem) {
                    total += product.getPrice() * (1.0 - percentOff / 100.0);
                    continue;
                }
            }
            total += product.getPrice();
        }
        return total;
    }
};

int main() {
    // Create a shopping cart and add products
    Cart* cart = new ConcreteCart();
    dynamic_cast<ConcreteCart*>(cart)->addProduct(Product("Laptop", 1000));
    dynamic_cast<ConcreteCart*>(cart)->addProduct(Product("Phone", 500));
    dynamic_cast<ConcreteCart*>(cart)->addProduct(Product("Headphones", 150));
    dynamic_cast<ConcreteCart*>(cart)->addProduct(Product("Laptop", 1000));
    cout << cart->getTotalPrice() << endl;
    // Apply coupons sequentially
    cart = new PercentOffCoupon(cart, 10);                  // 10% off on all items
    cout << cart->getTotalPrice() << endl;
    cart = new PercentOffNextItemCoupon(cart, 20);          // 20% off on the next item
    cout << cart->getTotalPrice() << endl;
    cart = new PercentOffNthItemTypeCoupon(cart, 15, 2, "Laptop");  // 15% off on the 2nd "Laptop"

    // Calculate the total price after applying all coupons
    double totalPrice = cart->getTotalPrice();
    cout << "Total Price after applying all coupons: $" << totalPrice << endl;

    // Clean up
    delete cart;

    return 0;
}
