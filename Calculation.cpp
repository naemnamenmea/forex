#include "stdafx.h"

#include <iostream>
using namespace std;

#define LOT 1e5 // (����� ������ ����, ���������� � ������� ������ ���������)

inline float margin(float orderLots, float base_course, int leverage) {
	/*
	orderLots ~ (����� ������ (� �����))
	base_course ~ (���� ������� ������ � ������� ��� (� ��� ������, � ������� � ��� ������ �������� ����))
	leverage ~ (��������� �����)
	*/
	return orderLots * LOT * base_course / leverage;
}

inline float maxlot(float max_margin, float base_course, int leverage) {
	/*
	max_margin ~ (������������ ����� (10% �� ��������))
	*/
	return max_margin * leverage / base_course / LOT;
}

inline float pipsCost(string symbol) {
	//������ ��������� ������ ��� �������� ��� � �������� ����������.
	/*
	�������, ��� �������, ���������� ��������� 1 ������ ��� �������� ���� � �������� ���������� EURUSD (����������), ��� 1 (100000 ������ ������� ������), ������ ������ 0.0001 &#8212; ������������� ������:
	100000 * 0,0001 = 10 �������� ���
	*/
	//������ ��������� ������ ��� �������� ��� � ������ ����������.
	/*
	��������� ������ = (������ ���� * ������ ������) / ������� ��������� �������� ����
	������:
	�������� ����: USDCHF
	���: 1 (100000)
	������ ������: 0.0001
	���� USDCHF: 1.0295
	��������� ������ = (100000 * 0.0001) / 1.0295 = 9.71$
	*/
	//������ ��������� ������ ��� �����-������.
	/*
	��������� ������ = (������ ���� * ������ ������ * ������� ��������� ������� ������ � �������) / ������� ��������� �������� ����
	������:
	<p>�������� ����: EURJPY
	���: 1 (100000)
	������ ������: 0.01
	���� EURJPY = 130.42
	���� EURUSD = 1.0618
	��������� ������ = (100000 * 0.01 * 1.0618) / 130.42 = 8.14$
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
