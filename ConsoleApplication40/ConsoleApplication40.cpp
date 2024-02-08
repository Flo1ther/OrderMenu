#include <iostream>

using namespace std;

const int maxproducts = 100;

class product
{
private:
	string productName;
	int productCost;
public:

	product()
	{
		this->productCost = 0;
		this->productName = "";
	}

	product(string name, int cost)
	{
		setProductCost(cost);
		setProductName(name);
	}

	void setProductName(const string name)
	{
		this->productName = name;
	}

	void setProductCost(const int cost)
	{
		this->productCost = cost;
	}

	string getProductName()
	{
		return this->productName;
	}

	int getProductCost()
	{
		return this->productCost;
	}

	void displayProduct()
	{
		cout << "Product name: " << productName << '\n';
		cout << "Product cost: " << productCost << '\n';
	}
};

class order
{
private:
	product products[maxproducts];
	string name;
	string address;
	int orderNumber;
	int totalCost;
	int orderCount;
public:
	order()
	{
		this->name = "";
		this->address = "";
		this->orderNumber = 0;
		this->totalCost = 0;
		this->orderCount = 0;
	}



	void addProduct(string name, int cost)
	{

		this->products[orderCount].setProductName(name);
		this->products[orderCount].setProductCost(cost);
		this->totalCost += products[orderCount].getProductCost();
		this->orderCount += 1;
	}

	void deleteProduct(string name)
	{
		for (size_t i = 0; i < orderCount; i++)
		{
			if (name == this->products[i].getProductName())
			{
				this->products[i].setProductCost(0);
				this->products[i].setProductName("");
			}
			else
			{
				cout << "problem" << endl;
				break;
			}
		}
	}

	int getTotalCost()
	{
		return this->totalCost;
	}

	void getInfo()
	{
		for (size_t i = 0; i < orderCount; i++)
		{
			if (this->products[i].getProductCost() != 0)
			{
				cout << this->products[i].getProductName() << "\t" << this->products[i].getProductCost();
			}
			else
			{
				break;
			}
		}
	}

	void makeOrder()
	{
		cin >> this->name;
		cin >> this->address;
		this->orderNumber++;
	}

	void getOrderInfo()
	{
		cout << this->name << "\t" << this->address << "\t" << this->orderNumber << "\t" << this->totalCost;
		cout << "\n\n";
		getInfo();
	}


};



int main()
{
	order _order;
	while (true)
	{
		cout << "________________________" << endl;
		cout << "Welcome to Shop menu!" << endl;
		cout << "Press 1 to add product to order!" << endl;
		cout << "Press 2 to remove product from order!" << endl;
		cout << "Press 3 to display total value of your order!" << endl;
		cout << "Press 4 to display info about products and their count!" << endl;
		cout << "Press 5 to make order" << endl;
		int choice;
		cin >> choice;
		string name;
		int cost;
		string productName;
		switch (choice)
		{
		case 1:

			cin >> name >> cost;
			_order.addProduct(name, cost);
			break;
		case 2:
			cout << "Enter the name of product you want to remove! \n";
			cin >> productName;
			_order.deleteProduct(productName);
			break;
		case 3:
			cout << _order.getTotalCost() << endl;
			break;
		case 4:
			_order.getInfo();
			break;
		case 5:
			_order.makeOrder();
			_order.getOrderInfo();
			break;
		default:
			break;
		}
	}
}
