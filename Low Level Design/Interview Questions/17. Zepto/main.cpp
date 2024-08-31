/*
FR - 
1. search / view product
2. add / remove product in cart
3. place order
4. payment / checkout
5. multiple warehouse and if customer 
    has order multplie products then all will be 
    delivered from a same warehouse.
*/

#include<bits/stdc++.h>
using namespace std;

/*

------------------------------------
WareHouse
------------------------------------
Inventory inventories;
Address address;
addInventory(Inventory inventory)
removeInventory(Inventory inventory)


------------------------------------
WarehouseContorller
------------------------------------
vector<WareHouse> warehouses;
WareHouseSelectionStrategy strategy;
addWareHouse(WareHouse warehouse)
removeWareHouse(WareHouse warehouse)


------------------------------------
WareHouseSelectionStrategy (Nearest, cheapest)
------------------------------------
selectWareHouse();

------------------------------------
Inventory
------------------------------------
vector<ProductCategory> productCategories;
addProductCategory(ProductCategory category)
removeProductCategory(ProductCategory category)


------------------------------------
ProductCategory
------------------------------------
int categoryId;
string categoryName;
vector<Product> products;
double price;
int quantity;
addProduct(Product product);
removeProduct(Product product)

------------------------------------
Product
------------------------------------
int id;
string productName;


------------------------------------
User
------------------------------------
int id;
string name;
Cart cart;
vector<int> orderIds;

------------------------------------
UserController
------------------------------------
vector<User> users;
addUser(User user)
removeUser(User user)

------------------------------------
Cart
------------------------------------
map<int, int> categoryIdCnt;
addItem();
removeItem();
viewCart();
emptyCart();


------------------------------------
OrderController
------------------------------------
vector<Order> orders;
getOrderById(int id);


------------------------------------
Order
------------------------------------
int id;
User user;
Address address;
map<int, int> categoryIdCnt;
WareHouse warehouse;
Invoice invoice;
Payment payment;
OrderStatus stauts;


------------------------------------
Invoice
------------------------------------
int totalPrice;
int tax;


------------------------------------
Payment
------------------------------------
PaymentMode mode;


------------------------------------
ZeptoApp
------------------------------------
UserController uc;
WareHouseController wc;
OrderController oc;

*/