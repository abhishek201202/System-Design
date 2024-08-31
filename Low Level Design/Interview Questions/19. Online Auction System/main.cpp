#include<bits/stdc++.h>
using namespace std;


// Item class representing an auction item
class Item {
private:
    string name;
    double highestBid;
    Bidder* highestBidder;
public:
    Item(const string& name) : name(name), highestBid(0.0), highestBidder(nullptr) {}
    string getName() const return name;
    double getHighestBid() const return highestBid;
    Bidder* getHighestBidder() const return highestBidder;
    void setHighestBid(double bid, Bidder* bidder) {
        highestBid = bid;
        highestBidder = bidder;
    }
};

// Bidder class
class Bidder {
private:
    string name;
    AuctionMediator* mediator;
public:
    Bidder(const string& name, AuctionMediator* mediator) : name(name), mediator(mediator) {}
    void placeBid(Item* item, double bidAmount) mediator->placeBid(this, item, bidAmount);
    string getName() const return name;
};

// Seller class
class Seller {
private:
    string name;
    AuctionMediator* mediator;
public:
    Seller(const string& name, AuctionMediator* mediator) : name(name), mediator(mediator) {}
    void auctionItem(Item* item) {
        mediator->registerSeller(this);
        cout << name << " is auctioning " << item->getName() << endl;
    }
    string getName() const return name;
};


// Mediator Interface
class AuctionMediator {
public:
    virtual void addBidder(Bidder* bidder) = 0;
    virtual void placeBid(Bidder* bidder, Item* item, double bidAmount) = 0;
    virtual void registerSeller(Seller* seller) = 0;
    virtual ~AuctionMediator() = default;
};

// Concrete Mediator class
class AuctionHouse : public AuctionMediator {
private:
    vector<Bidder*> bidders;
    vector<Seller*> sellers;
public:
    void addBidder(Bidder* bidder) override {
        bidders.push_back(bidder);
    }
    void registerSeller(Seller* seller) override {
        sellers.push_back(seller);
    }
    void placeBid(Bidder* bidder, Item* item, double bidAmount) override {
        if (bidAmount > item->getHighestBid()) {
            item->setHighestBid(bidAmount, bidder);
            cout << bidder->getName() << " placed a bid of $" << bidAmount << " on " << item->getName() << endl;
        } else {
            cout << "Bid of $" << bidAmount << " by " << bidder->getName() << " is lower than the current highest bid of $" << item->getHighestBid() << endl;
        }
    }
};


int main() {
    // Create the mediator
    AuctionHouse auctionHouse;

    // Create some bidders
    Bidder bidder1("Alice", &auctionHouse);
    Bidder bidder2("Bob", &auctionHouse);

    // Register bidders with the auction house
    auctionHouse.addBidder(&bidder1);
    auctionHouse.addBidder(&bidder2);

    // Create a seller
    Seller seller("John", &auctionHouse);

    // Auction an item
    Item item("Antique Vase");
    seller.auctionItem(&item);

    // Bidders place bids
    bidder1.placeBid(&item, 100.0);
    bidder2.placeBid(&item, 150.0);
    bidder1.placeBid(&item, 120.0);  // Lower bid, won't update highest bid

    // Output the final highest bid and bidder
    cout << "Final highest bid on " << item.getName() << " is $" << item.getHighestBid() << " by " << item.getHighestBidder()->getName() << endl;
    return 0;
}
