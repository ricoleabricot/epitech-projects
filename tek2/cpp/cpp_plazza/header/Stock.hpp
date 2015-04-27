#ifndef STOCK_HPP
# define STOCK_HPP

class Stock
{
private:
	int 	doe;
	int 	tomato;
	int 	gruyere;
	int 	ham;
	int 	mushrooms;
	int 	steak;
	int 	eggplant;
	int 	goatCheese;
	int 	chiefLove;
public:
	Stock();
	~Stock();
	void 	setDoe(int param);
	void 	setTomato(int param);
	void 	setGruyere(int param);
	void 	setHam(int param);
	void 	setMushrooms(int param);
	void 	setSteak(int param);
	void 	setEggplant(int param);
	void 	setGoatCheese(int param);
	void 	setChiefLove(int param);
	int 	getDoe() const;
	int 	getTomato() const;
	int 	getGruyere() const;
	int 	getHam() const;
	int 	getMushrooms() const;
	int 	getSteak() const;
	int 	getEggplant() const;
	int 	getGoatCheese() const;
	int 	getChiefLove() const;
};

#endif	/* STOCK_HPP */