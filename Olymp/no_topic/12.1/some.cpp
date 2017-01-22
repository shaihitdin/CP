#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product;
struct Category;
struct Order;

void adminMenu();
void userMenu();
void addCategory();
void removeCategory();
void showCategories();
void editCategory();
void addProduct();
void removeProduct();
void editProduct();
void showProducts();
void printProduct(Product product);
void printCategory(Category category);
void changeNameOfCategory(int,int);
void addSubCategory(int,int);

void changeNameOfProduct(int,int);
void changePriceOfProduct(int,int);
void changeCategoryIdOfProduct(int,int);

#define USER_TYPE_ADMIN 0
#define USER_TYPE_USER 1

#define ADD_CATEGORY 0
#define REMOVE_CATEGORY 1
#define EDIT_CATEGORY 2
#define ADD_PRODUCT 3
#define REMOVE_PRODUCT 4
#define EDIT_PRODUCT 5
#define SHOW_ORDERS 6
#define SHOW_CATEGORIES 8
#define EXIT 7

#define SHOW_PRODUCTS 0

struct Product {
	string name;
	int id;
	int price;
	int categoryId;
};

struct Category {
	string name;
	int id;
	vector<Category*> subCategories;
	vector<Product> products;
};

vector<Category> categories;
vector<Product> products;

int main () {
	cout << "\nWelcome!, choose account";
	cout << "\n0. Admin";
	cout << "\n1. User\n";
	int userType; cin >> userType;

	if (userType == USER_TYPE_ADMIN) {
		adminMenu();
	} else if (userType == USER_TYPE_USER) {
		userMenu();
	} else {
		cout << "You're wrong!";
	}
	return 0;
}

void adminMenu () {
	while (true) {
		cout << "\nMain menu";
		cout << "\nChoose what do you want?";
		cout << "\n0. Add category";
		cout << "\n1. Remove category";
		cout << "\n2. Edit category";
		cout << "\n3. Add product";
		cout << "\n4. Remove product";
		cout << "\n5. Edit product";
		cout << "\n6. Show orders";
		cout << "\n7. Exit";
		cout << "\n8. Show categories\n";
		int command; cin >> command;
		switch (command) {
		case ADD_CATEGORY:
			addCategory();
			break;
		case REMOVE_CATEGORY:
			removeCategory();
			break;
		case EDIT_CATEGORY:
			editCategory();
			break;
		case SHOW_CATEGORIES:
			showCategories();
			break;
		case ADD_PRODUCT:
			addProduct();
			break;
		case REMOVE_PRODUCT:
			removeProduct();
			break;
		case EDIT_PRODUCT:
			editProduct();
			break;
		case EXIT:
			return;
		}
		cout << endl << "Do you want to continue? (y/n)" << endl;
		char c;
		cin >> c;
		if (c == 'n') {
			break;
		}
	}
}

void addCategory() {
	cout << "\nEnter the name of category: ";
	string name; cin >> name;
	Category category;
	category.name = name;
	category.id = categories.size();
	categories.push_back(category);
	cout << "\nNew category " + name + " created, id = " << category.id << endl;
}

void removeCategory() {
	cout << "\nEnter the id of category: ";
	int id; cin >> id;
	for (int i = 0; i < (int)categories.size(); ++i) {
		if (categories[i].id == id) {
			categories.erase(categories.begin() + i);
			break;
		}
	}
	cout << "\nCategory with " << id << "was removed";
}

void editCategory() {
	cout << "\nEnter the id of category: ";
	int id; cin >> id;
	int pos;
	for (int i = 0; i < (int)categories.size(); ++i) {
		if (categories[i].id == id) {
			pos = i;
			break;
		}
	}

	cout << "\nChoose what do you want?";
	cout << "\n0. Change name";
	cout << "\n1. Add subCategory";
	int type; cin >> type;
	switch(type) {
		case 0:
			changeNameOfCategory(pos, id);
			break;
		case 1:
			addSubCategory(pos, id);
			break;
		default:
			cout << "Wrong input!\n";
			break;
	}
}

void changeNameOfCategory(int pos, int id) {
	cout << "\nEnter new name: ";
	string name; cin >> name;
	categories[pos].name = name;
	cout << "\nCategory with id " << id << " was changed\n";
}

void addSubCategory(int pos, int id) {
	cout << "\nEnter the name of category: ";
	string name; cin >> name;
	Category *category;
	category -> name = name;
	category -> id = categories.size();
	Category copy = *category;
	categories.push_back(copy);
	cout << "\nNew category " + name + " created, id = " << category -> id << endl;
	categories[pos].subCategories.push_back(category);
}

// ADD_PRODUCT:
// REMOVE_PRODUCT:
// EDIT_PRODUCT:

void showCategories() {
	for (int i = 0; i < categories.size(); ++i) {
		printCategory(categories[i]);
	}
}

void printCategory(Category category) {
	cout << "Category: " << category.name << endl;
	cout << "Id: " << category.id << endl;
	cout << "subCategories: ";
	for (int i = 0; i < category.subCategories.size(); ++i) {
		Category cur = *category.subCategories[i];
		cout << "               Category: " << category.name << endl;
		cout << "               Id: " << category.id << endl;
	}
	cout << endl;
}

void addProduct() {
	cout << "\nEnter the name of product: ";
	string name; cin >> name;
	Product product;
	product.name = name;
	product.id = products.size();
	cout << "\nEnter the price of product: ";
	int price; cin >> price;
	product.price = price;
	cout << "\nEnter category id of product: ";
	int categoryId; cin >> categoryId;
	product.categoryId = categoryId;

	for (int i = 0; i < categories.size(); ++i) {
		if (categories[i].id == categoryId) {
			categories[i].products.push_back(product);
		}
	}

	products.push_back(product);
	cout << "\nNew product " + name + " created, id = " << product.id << endl;
}

void removeProduct() {
	cout << "\nEnter the id of product: ";
	int id; cin >> id;
	for (int i = 0; i < products.size(); ++i) {
		if (products[i].id == id) {
			for (int j = 0; j < categories.size(); ++j) {
				if (categories[j].id == products[i].categoryId) {
					for (int k = 0; k < categories[j].products.size(); ++k) {
						if (categories[j].products[k].id == id) {
							categories[j].products.erase(categories[j].products.begin() + k);
						}
					}
				}
			}
			products.erase(products.begin() + i);

			break;
		}
	}
	cout << "\nProduct with " << id << "was removed\n";
}

void editProduct() {
	cout << "\nEnter the id of product: ";
	int id; cin >> id;
	int pos;
	for (int i = 0; i < products.size(); ++i) {
		if (products[i].id == id) {
			pos = i;
			break;
		}
	}

	cout << "\nChoose what do you want?";
	cout << "\n0. Change name";
	cout << "\n1. Change price";
	cout << "\n2. Change category id";

	int type; cin >> type;
	switch(type) {
		case 0:
			changeNameOfProduct(pos, id);
			break;
		case 1:
			changePriceOfProduct(pos, id);
			break;
		case 2:
			changeCategoryIdOfProduct(pos, id);
			break;
		default:
			cout << "Wrong input!\n";
			break;
	}
}

void changeNameOfProduct(int pos, int id) {
	cout << "\nEnter new name: ";
	string name; cin >> name;
	products[pos].name = name;
	cout << "\nProduct with id " << id << " was changed\n";
}

void changePriceOfProduct(int pos, int id) {
	cout << "\nEnter new price: ";
	int price; cin >> price;
	products[pos].price = price;
	cout << "\nProduct with id " << id << " was changed\n";
}

void changeCategoryIdOfProduct(int pos, int id) {
	cout << "\nEnter new category id: ";
	int newId; cin >> newId;
	for (int i = 0; i < categories.size(); ++i) {
		if (categories[i].id == products[pos].categoryId) {
			for (int j = 0; j < categories[i].products.size(); ++j) {
				if (categories[i].products[j].id == id) {
					categories[i].products.erase(categories[i].products.begin() + j);
				}
			}
		}
	}
	products[pos].categoryId = newId;
	cout << "\nProduct with id " << id << " was changed\n";
}


void userMenu() {
	cout << "Not implemented :(\n";
}
