# AbstractClass
## Задание

>В следующием задании требуется реализовать абстрактный базовый класс, определив в нем чистые виртуальные функции. Эти функции определяются в производных классах. В базовом классе должны быть объявлены чистые виртуальные функции ввод / вывод, >которые реализуются в производных классах.

Создать абстрактный базовый класс **Pair**  c виртуальными арифметическими операциями. Реализовать производные классы **Complex** и **Rational**.

1. Рациональная (несократимая) дробь представляется парой целых чисел (a,b), где a – числитель,  b – знаменатель.  Создать класс **Rational** для работы с рациональными дробями. Обязательно должны быть реализованы операции:
*	cложение *add*, (a, b) + (c,d) = (ad + bc, bd);
*	вычитание *sub*, (a, b) − (c,d) = (ad − bc, bd);
*	умножение *mul*, (a, b) *  (c,d) = (ac, bd);
*	деление *div*, (a, b) + (c,d) = (ad, bc);
*	сравнение *equal*, *greate*, *less**;

2. Комплексное число представляется парой действительных чисел (a,b), где a – действительная часть,  b – мнимая часть.  Реализовать класс Complex для работы с комплексными числами. Обязательно должны присутствовать операции:
*	cложение *add*, (a, b) + (c,d) = (a + b, c + d);
*	вычитание *sub*, (a, b) − (c,d) = (a − b, c - d);
*	умножение *mul*, (a, b) *  (c,d) = (ac - bd, ad + bc);
*	деление *div*, (a, b) / (c,d) = (ac + bd, bc - ad) / (c2 + d2);
*	сравнение *equ*, (a, b) = (c, d), если (a = c) и (b = d);
*	сопряженное число *conj*, (a, b) = (a, -b).

Должна быть реализована приватная функция сокращения дроби **reduce**, которая обязательно вызывается при выполнении арифметических операций.
