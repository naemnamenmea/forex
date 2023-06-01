#include "stdafx.h"

#include <iostream>
using namespace std;

#define LOT 1e5 // (объем одного лота, выраженный в базовой валюте котировки)

inline float margin(float orderLots, float base_course, int leverage) {
	/*
	orderLots ~ (Объем ордера (в лотах))
	base_course ~ (Курс базовой валюты к доллару США (к той валюте, в которой у нас открыт торговый счет))
	leverage ~ (Кредитное плечо)
	*/
	return orderLots * LOT * base_course / leverage;
}

inline float maxlot(float max_margin, float base_course, int leverage) {
	/*
	max_margin ~ (Максимальная маржа (10% от депозита))
	*/
	return max_margin * leverage / base_course / LOT;
}

inline float pipsCost(string symbol) {
	//Расчёт стоимости пункта для валютных пар с обратной котировкой.
	/*
	Давайте, для примера, рассчитаем стоимость 1 пункта для валютной пары с обратной котировкой EURUSD (евродоллар), лот 1 (100000 единиц базовой валюты), размер пункта 0.0001 &#8212; четырёхзначный брокер:
	100000 * 0,0001 = 10 долларов США
	*/
	//Расчёт стоимости пункта для валютных пар с прямой котировкой.
	/*
	Стоимость пункта = (размер лота * размер пункта) / текущая котировка валютной пары
	Пример:
	Валютная пара: USDCHF
	Лот: 1 (100000)
	Размер пункта: 0.0001
	Курс USDCHF: 1.0295
	Стоимость пункта = (100000 * 0.0001) / 1.0295 = 9.71$
	*/
	//Расчёт стоимости пункта для кросс-курсов.
	/*
	Стоимость пункта = (размер лота * размер пункта * текущая котировка базовой валюты к доллару) / текущая котировка валютной пары
	Пример:
	<p>Валютная пара: EURJPY
	Лот: 1 (100000)
	Размер пункта: 0.01
	Курс EURJPY = 130.42
	Курс EURUSD = 1.0618
	Стоимость пункта = (100000 * 0.01 * 1.0618) / 130.42 = 8.14$
	*/
	return 0.;
}

int main() {
	string symbol = "EURUSD";
	float orderLots = 0.5;
	float base_course = 1.0559;
	int leverage = 500;
	float risk = 1e3 / leverage / 100;
	float SL = 150.;
	float depo = 3000.;
	float order_risk = depo * risk;

	float standart_lot = maxlot(depo, base_course, leverage) * risk;
	float fix_risk_lot = order_risk / SL / pipsCost(symbol);

	cout << margin(orderLots, base_course, leverage) << endl;
	cout << endl;
	cout << maxlot(depo, base_course, leverage) << endl;
	cout << endl;
	cout << "standart lot " << standart_lot << endl;
	cout << endl;
	cout << "fix_risk_lot " << fix_risk_lot << endl;
return 0;
}
