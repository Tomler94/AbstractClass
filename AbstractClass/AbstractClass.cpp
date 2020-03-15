#include <iostream> 
using namespace std;

class Pair
{
public:
	float a, b;
public:
	//Считывание данных с клавиатуры
	virtual void Read(Pair& number) = 0;
	//Вывод на экран
	virtual void Display(Pair& number) = 0;
	//Сложение
	virtual Pair& operator+(Pair* number) = 0;
	//Вычитание
	virtual Pair& operator-(Pair* number) = 0;
	//Умножение
	virtual Pair& operator*(Pair* number) = 0;
	//Деление
	virtual Pair& operator/(Pair* number) = 0;
	//Сравнение
	virtual void Comparison(Pair& number) = 0;
};

class Rational : public Pair
{
public:
	//Считывание данных с клавиатуры
	void Read(Pair& number) override;
	//Вывод на экран
	void Display(Pair& number) override;
	//Сложение
	Pair& operator+(Pair* number) override;
	//Вычитание
	Pair& operator-(Pair* number) override;
	//Умножение
	Pair& operator*(Pair* number) override;
	//Деление
	Pair& operator/(Pair* number) override;
	//Сравнение
	void Comparison(Pair& number) override;

private:
	//Сокращение дроби
	void reduce(Rational& drob);
};

class Complex : public Pair
{
public:
	//Считывание данных с клавиатуры
	void Read(Pair& number) override;
	//Вывод на экран
	void Display(Pair& number) override;
	//Сложение
	Pair& operator+(Pair* number) override;
	//Вычитание
	Pair& operator-(Pair* number) override;
	//Умножение
	Pair& operator*(Pair* number) override;
	//Деление
	Pair& operator/(Pair* number) override;
	//Сравнение двух комплексных чисел
	void Comparison(Pair& number);
	//Сопряженное число
	void Conj(Pair& number);
};

void Resolution(Pair* pair);

int main()
{
	setlocale(LC_ALL, "Russian");
	Pair* pair;
	Rational fraction[3];
	Complex complex[3];
	pair = &fraction[0];
	Resolution(pair);
	pair = &complex[0];
	Resolution(pair);
	complex->Conj(pair[0]);
	complex->Display(pair[0]);
}

void Resolution(Pair* pair)
{
	cout << endl;
	pair->Read(pair[0]);
	cout << endl;
	pair->Read(pair[1]);
	cout << endl;
	pair[2] = pair[0] + pair;
	pair->Display(pair[2]);
	pair[2] = pair[0] - pair;
	pair->Display(pair[2]);
	pair[2] = pair[0] * pair;
	pair->Display(pair[2]);
	pair[2] = pair[0] / pair;
	pair->Display(pair[2]);
	pair[0].Comparison(pair[1]);
}

//Рациональные дроби

void Rational::Read(Pair& number)
{
	cout << "Введите числитель и знаминатель дроби: " << endl;
	cin >> number.a >> number.b;
}

void Rational::Display(Pair& drob)
{
	if ((drob.a || drob.b) != 0)
		cout << drob.a << " / " << drob.b << endl;
}

Pair& Rational::operator+(Pair* number)
{
	Rational fraction;
	fraction.a = a * number[1].b + b * number[1].a;
	fraction.b = b * number[1].b;
	reduce(fraction);
	return number[2] = fraction;
}

Pair& Rational::operator-(Pair* number)
{
	Rational fraction;
	fraction.a = a * number[1].b - b * number[1].a;
	fraction.b = b * number[1].b;
	reduce(fraction);
	return number[2] = fraction;
}

Pair& Rational::operator*(Pair* number)
{
	Rational fraction;
	fraction.a = a * number[1].a;
	fraction.b = b * number[1].b;
	reduce(fraction);
	return number[2] = fraction;

}

Pair& Rational::operator/(Pair* number)
{
	Rational fraction;
	if (number[1].a != 0)
	{
		fraction.a = a * number[1].b;
		fraction.b = b * number[1].a;
	}
	else
	{
		fraction.a = 0;
		fraction.b = 0;
	}
	reduce(fraction);
	return number[2] = fraction;
}

void Rational::Comparison(Pair& number)
{
	if (float(a) / float(b)
	> (float(number.a) / float(number.b)))
		cout << "greate" << endl;
	else if (float(a) / float(b)
		< (float(number.a) / float(number.b)))
		cout << "less" << endl;
	else
		cout << "equal" << endl;
}

void Rational::reduce(Rational& drob)
{
	int num_x = drob.a,
		denom_y = drob.b,
		NOD = 1;
	if (num_x != 0)
	{
		if (num_x < 0)
			num_x = num_x * (-1);
		if (denom_y < 0)
			denom_y = denom_y * (-1);
		while (num_x != denom_y)
			if (num_x > denom_y)
				num_x = num_x - denom_y;
			else
				denom_y = denom_y - num_x;
		NOD = num_x;
	}
	if (((drob.a < 0) && (drob.b < 0)) ||
		((drob.a > 0) && (drob.b < 0)))
	{
		drob.a = drob.a * (-1);
		drob.b = drob.b * (-1);
	}
	drob.a /= NOD;
	drob.b /= NOD;
}

//Комплексные числа

void Complex::Read(Pair& complex)
{
	cout << "Введите действительную и мнимую часть комплексного числа : " << endl;
		cin >> complex.a >> complex.b;
}

void  Complex::Display(Pair& complex)
{
	cout << complex.a << "  " << complex.b << endl;
}

Pair& Complex::operator+(Pair* number)
{
	Complex complex;
	complex.a = a + number[1].a;
	complex.b = b + number[1].b;
	return number[2] = complex;
}

Pair& Complex::operator-(Pair* number)
{
	Complex complex;
	complex.a = a - number[1].a;
	complex.b = b - number[1].b;
	return number[2] = complex;
}

Pair& Complex::operator*(Pair* number)
{
	Complex complex;
	complex.a = number[1].a * a - number[1].b * b;
	complex.b = a * number[1].b + b * number[1].a;
	return number[2] = complex;
}

Pair& Complex::operator/(Pair* number)
{
	Complex complex;
	complex.a = a * number[1].a - b * number[1].b * (-1);
	complex.b = b * number[1].a - a * number[1].b;
	float value = number[1].a * number[1].a - number[1].b *
		number[1].b * (-1);
	complex.a = complex.a / value;
	complex.b = complex.b / value;
	return number[2] = complex;
}

void  Complex::Comparison(Pair& number)
{
	if ((a == number.a) && (b == number.b))
		cout << "Equal" << endl;
	else cout << "Not equal" << endl;
}

void Complex::Conj(Pair& number)
{
	number.b = number.b * (-1);
}
