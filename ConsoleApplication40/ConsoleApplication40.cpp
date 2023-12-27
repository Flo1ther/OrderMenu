#include <iostream>
using namespace std;
const int maxproducts = 100;
class product
{
private:
	char* productName;
	int productCost;
public:
	product(const char* productName_, int productCost_) : productName{ new char[strlen(productName_) + 1] }, productCost{ productCost }
	{
		for (int i = 0; i < strlen(productName_)+1; i++)
		{
			this->productName[i] = productName_[i];
		}
	}
	product(const char* productName_) : product(productName_, productCost) {}
	product() : product(""){}
	~product() {
		if (productName!=nullptr)
		{
			delete[]productName;
		}
	}
	char* getProductName()
	{
		return productName;
	}
	int getProductCost()
	{
		return productCost;
	}
	void setProductName(char* productName_)
	{
		for (int i = 0; i < strlen(productName_)+1; i++)
		{
			this->productName[i] = productName_[i];
		}
	}
	void setProductCost(int productCost_)
	{
		this->productCost = productCost_;
	}
	void displayProduct()
	{
		cout << "Product name: " << productName << '\n';
		cout << "Product cost: " << productCost << '\n';
	}
};

class order {
	product products[maxproducts];
private:
	char* name;
	char* address;
	char* ordernum;
	int ordercount;
	int newproductCost;
public:
	order() : ordercount{ 0 } {}
	order(const char* name_, const char* address_, const char* ordernum_) : name{ new char[strlen(name_) + 1] }, address{ new char[strlen(address_) + 1] }, ordernum{ new char[strlen(ordernum_) + 1] }
	{
		for (int i = 0; i < strlen(name_) + 1; i++)
		{
			this->name[i] = name_[i];
		}
		for (int i = 0; i < strlen(address_) + 1; i++)
		{
			this->address[i] = address_[i];
		}
		for (int i = 0; i < strlen(ordernum_) + 1; i++)
		{
			this->ordernum[i] = ordernum_[i];
		}
	}
	order(const char* name_, const char* address_) : order(name_, address_, "")
	{

	}
	order(const char* name_) : order(name_, "")
	{

	}
	

	
	~order()
	{
		delete[]name;
		delete[]address;
		delete[]ordernum;
	}
	char* getName()
	{
		return name;
	}
	char* getAddress()
	{
		return address;
	}
	char* getOrderNum()
	{
		return ordernum;
	}
	int getnewproductCost()
	{
		return newproductCost;
	}
	void setName(char* name_)
	{
		for (int i = 0; i < strlen(name_) + 1; i++)
		{
			this->name[i] = name_[i];
		}
	}
	void setAddress(char* address_)
	{
		for (int i = 0; i < strlen(address_) + 1; i++)
		{
			this->address[i] = address_[i];
		}
	}
	void setOrdernum(char* ordernum_)
	{
		for (int i = 0; i < strlen(ordernum_) + 1; i++)
		{
			this->ordernum[i] = ordernum_[i];
		}
	}
	void addProdToOrder(product& product)
	{
		if (ordercount < maxproducts)
		{
			cout << "Enter the name of product! \n";
			char productName[100];
			cin >> productName;
			products[ordercount].setProductName(productName);
			cout << "Enter the cost of product! \n";
			int productCost;
			cin >> productCost;
			products[ordercount].setProductCost(productCost);
			newproductCost += productCost;
		}
	}
	void RemoveProdFromOrderByName(char* product)
	{
		int removedcount = 0;
		if (ordercount > NULL)
		{
			for (int i = 0; i < ordercount; i++)
			{
				if (strcmp(products[i].getProductName(), product) == 0)
				{
					for (int j = 0; j < ordercount - 1; j++)
					{
						products[j] = products[j + 1];
					}
					removedcount++;
					ordercount--;
					i--;
					cout << "Product deleted \n";
					break;
				}
			}
		}
		if (removedcount < NULL)
		{
			cout << "There is no products to delete. \n";
		}
	}
	void TotalOrderValue(product& product)
	{
		if (product.getProductCost() != NULL && product.getProductCost() > NULL)
		{
			for (int i = 0; i < ordercount; i++)
			{
				products[ordercount].displayProduct();
				cout << "Total order value is: " << newproductCost << '\n';
			}
		}
	}

	void displayAllProducts(product& product)
	{
		if (ordercount != NULL)
		{
			for (int i = 0; i < ordercount; i++)
			{
				products[ordercount].displayProduct();
				cout << "Total count of products: " << ordercount << '\n';
			}
		}
	}
	void displayTotalOrderInfo(product& product)
	{
		if (ordercount>0)
		{
			for (int i = 0; i < ordercount; i++)
			{
				cout << "We`re almost finished, could you give us some info about you?\n";
				cout << "Please, enter your name\n";
				char name[100];
				cin >> name;
				setName(name);
				cout << "Nice to meet you " << name << "Please, give us some info about delivery address \n";
				char address[100];
				cin >> address;
				setAddress(address);
				cout << "Got it! Your order number is: "<<getOrderNum();
				
			}
		}
	}
};
int main()
{
	product products;
	order orders;
	while (true)
	{
		cout << "________________________" << endl;
		cout << "Welcome to Shop menu!" << endl;
		cout << "Press 1 to add product to order!" << endl;
		cout << "Press 2 to remove product from order!" << endl;
		cout << "Press 3 to display total value of your order!" << endl;
		cout << "Press 4 to display info about products and their count!" << endl;
		cout << "Press 5 to display all info about order!" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			orders.addProdToOrder(products);
			break;
		case 2:
			cout << "Enter the name of product you want to remove! \n";
			char productName[100];
			cin >> productName;
			orders.RemoveProdFromOrderByName(productName);
			break;
		case 3:
			orders.TotalOrderValue(products);
			break;
		case 4:
			orders.displayAllProducts(products);
			break;
		case 5:
			orders.displayTotalOrderInfo(products);
			break;
		default:
			break;
		}
	}
}
