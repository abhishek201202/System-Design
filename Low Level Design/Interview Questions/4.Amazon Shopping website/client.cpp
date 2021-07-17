#include<bits/stdc++.h>
using namespace std;


class Customer {
	ShoppingCart cart;
	Search searchObj;
	int cutomerId;
public:
	ShoppingCart getShoppingCart(customerId);
	void addItemsToShoppingCart(Item item);
	void updateItemFromShoppingCart(Item item);
	void removeItemFromShoppingCart(Item item);
};

class Guest: public Customer {
public:
	Account createNewAccount();
};

class User: public Customer {
	Account account;
};


class Seller: public User {
public:
	void addProduct(Product product);
};


class Buyer: public User {
	Order orderObj;
public:
	void addReview(ProductReview review);
	OrderStatus placeOrder(ShoppingCart cart);
};






class Account {
	string name;
	string email;
	string phoneNumber;
	string userName;
	string password;
	vector<Address> shippingAddresses;
	AccountStatus accountStatus;
};


class Address {
	int pincode; // zipcode
	string street;
	string city;
	string state;
	string country;
};


enum AccountStatus {
	ACTIVE, BLOCKED, INACTIVE
};


class ShoppingCart {
	vector<Item> items;
	double cartValue;
public:
	void addItem(Item item);
	void updateItem(Item item);
	void deleteItem(Item item);
	void checkoutItems();
	vector<Item> getItems();
	double getCartValue();
};



class Item {
	Product product;
	int qty;
};


class Product {
	int productId;
	string productDescription;
	string name;
	ProductCategory productCategory;
	Seller seller;
	double cost;
	vector<ProductReview> productReviews;
};


enum ProductCategory {
	ELECTRONICS, FURNITURE, GROCERY, MOBILE
};


class ProductReview {
	string details;
	Buyer reviewer;
	int rating;
};


class Search {
public:
	vector<Product> searchByName(string name);
	vector<Product> searchByCategory(ProductCategory productCategory);
};




class Order {
	int orderId;
	vector<Item> orderItem;
	double orderValue;
	Buyer buyer;
	Date orderDate;
	NotificationService notificationService;

	vector<OrderLog> orderLog;

public:
	OrderStatus placeOrder();
	OrderStatus trackOrder();
	void addOrderLogs();
	PaymentStatus makePayment(PaymentType paymentType);
};



enum OrderStatus {
	PACKED, SHIPPEd, ENROUTE, OUT_FOR_DELIVERY, DELIVERED, CANCELLED
};

enum PaymentStatus {
	SUCCESS, ERROR, CANCELLED, REFUND_INITIATED, REFUDED
};

enum PaymentType {
	CREDIT_CARD, DEBIT_CARD, NET_BANKING, UPI
};


class OrderLog {
	string orderDetail;
	Date createdDate;
	OrderStatus status;
};


/********************************************************************
Notification Class
********************************************************************/


class NotificationService {
public:
	bool senNotification(NotificationDomain notificationDomain) {
		Notification notificationObject;
		MessageAttribute messageAttribute;
		switch(NotificationDomain.getNotification()) {
			case NotificationType.EMAIL:
				// (from address, to address, message)
				notificationObject = new EmailNotification();
				MessageAttribute = new messageAttribute("abcd@gmail.com", notificationDomain.getUser().getAccount().getEmail(),"Order Detail ...");
				break;
			case NotificationType.WHATSAPP:
				notificationObject = new WhatsappNotification();
				MessageAttribute = new messageAttribute("988888888", notificationDomain.getUser().getAccount().getPhoneNumber(),"Order Detail ...");
				break;
			default:
				notificationObject = new SMSNotification();
				messageAttribute = new MessageAttribute("988888888", notificationDomain.getUser().getAccount().getPhoneNumber(),"Order Detail ...");
				break;
		}
		return notificationObject.sendNotification(messageAttribute);
	}
};







class NotificationDomain {
	string notificationID;
	NotificationType NotificationType;
	User user;
};



class MessageAttributes {
	string to;
	string from;
	string message;
};


class Notification {
public:
	virtual bool sendNotification(messageAttribute messageAttribute);	
};

class EmailNotification: public Notification {
	bool sendNotification(messageAttribute messageAttribute);
}

class WhatsappNotification: public Notification {
	bool sendNotification(messageAttribute messageAttribute);
}

class SMSNotification: public Notification {
	bool sendNotification(messageAttribute messageAttribute);
}


int32_t main(){

}