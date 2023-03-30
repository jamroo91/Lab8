#include <iostream>
#include <string>
using namespace std;


class Product {
public:
	Product(string name, double price) : name(name), price(price) {}
	string getName() const { return name; }
	double getPrice() const { return price; }
private:
	string name;
	double price;
};


class PriceLimit {
public:
	PriceLimit(double minPrice, double maxPrice) : minPrice(minPrice), maxPrice(maxPrice) {}
	bool isPriceWithinLimit(double price) const {
		return price >= minPrice && price <= maxPrice;
	}
private:
	double minPrice;
	double maxPrice;
};


class Market {
public:
	static bool isPriceWithinLimits(const Product& product, const PriceLimit& limit) {
		return limit.isPriceWithinLimit(product.getPrice());
	}
};

int main() {

	Product laptop("Laptop Dell", 3200.0);
	PriceLimit laptopPriceLimit(2000.0, 5000.0);

	Product phone("Telefon Samsung", 1300.0);
	PriceLimit phonePriceLimit(1000.0, 2000.0);

	Product book("Ksiażka \"Wiedzmin\"", 50.0);
	PriceLimit bookPriceLimit(10.0, 100.0);


	cout << laptop.getName() << " - cena: " << laptop.getPrice() << " z³ - ";
	if (Market::isPriceWithinLimits(laptop, laptopPriceLimit)) {
		cout << "cena w granicach przyzwoitości\n";
	}
	else {
		cout << "cena poza granicami przyzwoitosci\n";
	}

	cout << phone.getName() << " - cena: " << phone.getPrice() << " z³ - ";
	if (Market::isPriceWithinLimits(phone, phonePriceLimit)) {
		cout << "cena w granicach przyzwoitosci\n";
	}
	else {
		cout << "cena poza granicami przyzwoitosci\n";
	}

	cout << book.getName() << " - cena: " << book.getPrice() << " z³ - ";
	if (Market::isPriceWithinLimits(book, bookPriceLimit)) {
		cout << "cena w granicach przyzwoitosci\n";
	}
	else {
		cout << "cena poza granicami przyzwoitosci\n";
	}

	return 0;
}