Design a system for managing customer orders and deliveries in a quick commerce platform:

a. How would you structure the system to manage customer orders, inventory, and deliveries?

b. How would you design a system to handle order prioritization for fast delivery, especially during peak times?

c. How would you handle different payment methods such as credit cards, digital wallets, and cash on delivery?

d. How would you ensure data security and compliance with relevant e-commerce regulations?

Function Requirement - 
1. customer add / remove products in cart
2. customer can buy that product.
3. mulitple payment methods (credit cards, digital wallets and cash on delivery).
4. transaction
5. prioritzation in order delivery system.
6. sellers can  add / remove product in inventory.
7. Enryption / Decryption of customer pii data.
8. Authentication Layer to validate customer



UserManagement Service
OrderManagement Service
Payment Service
Delivery Service
Inventory Service
Security Service

--> microservice 
Amazon ECS


EcomerceApp
------------------------------------
UserManagemntService *userService;
OrderManagementService *orderManagementService;
PaymentService *paymentService;
DeliveryService *deliveryService;


User
------------
string id;
string name;
string email;
Cart *cart;


UserControler
------------
vector<User> users;
addUser(User user);
deleteUser(User user);


UserManagemntService
--------------
UserControler* userController;


Product
------------------
ProductType type;
string name;
double price;

Item
-------------------
map<Product, int> productToCnt;

addProduct(Product product, int qty);
removeProduct(Product product, int qty);

Cart
---------------------
Item *item;

addProduct(Product product, int qty);
removeProduct(Product product);


Order
------------------------
int orderId;
int userId;
Item *item;


OrderManagementService
----------------------------
vector<Order> orders;

createOrder(Order order);



Payment
------------------
int paymentId;
int orderId;
int totalPrice;
PaymentStatus status;

enum PaymentStatus {
    COMPLETED, PENDING, DECLINED
}

PaymentController
-------------------
vector<Payment> payments;
createPayment(PaymentStrategy strategy, Order order)


PaymentStrategy
------------------------
makePayment(Order order);


CrediCardPaymentStrategy  (PaymentStrategy) 
------------------------
makePayment(Order order);

DigitalWalletPaymentStrategy  (PaymentStrategy) 
------------------------
makePayment(Order order);

CashOnDeliveryPaymentStrategy  (PaymentStrategy) 
------------------------
makePayment(Order order);


PaymentService
------------------------
PaymentController *paymentController;


Delivery
------------------------
int deliveryId;
int orderId;
int deliveryPartnerId;
int inventoryId;

DeliveryController
------------------------
vector<Delivery> deliveries;
createDelivery();


DeliveryService
------------------------
DeliveryController *deliveryController;
findOptimalDeliveryStrategy(Delivery delivery);



factor affecting prioritization
--------------------------------
1. nearest inventory
2. nearest deliveryPartnerId
3. prime members
4. extra payment
5. timing of placed product









