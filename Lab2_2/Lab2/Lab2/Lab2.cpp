#pragma warning(disable: 4996)
#define maxStrSize 1024
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void PrintList() {
	printf("Нажмите на соответствующую клавишу чтобы выбрать нужную функцию\n");
	printf("0. Является ли число простым\n");
	printf("1. Сумма цифр числа в кубе равна самому числу, в диапозоне от 10 до 30000\n");
	printf("2. Простые числа в диапозоне до введённого числа\n");
	printf("3. Нахождение числа в массиве, которое больше половины и меньше половины\n");
	printf("4. Считает сумму с двух концов массива возвращает последний прибавленный элемент справа\n");
	printf("5. Найти максимальное число в массиве и отсортировать его\n");
	printf("6. Нахождение наименьшего элемента массива среди не отрицательных чисел\n");
	printf("7. Нахождение количество отрицательных чисел в массиве, после которых есть положительное число\n");
	printf("8. Находит количество положительных чисел в массиве\n");
	printf("9. Найти факториал введённого числа\n");
	printf("S. Показать статистику вызова функций\n");
	printf("Esc. Выход\n");
}
void PrintStat(int arr[]) {
	printf("0. %d раз вызвана функция: Является ли число простым\n", arr[0]);
	printf("1. %d раз вызвана функция: Сумма цифр числа в кубе равна самому числу, в диапозоне от 10 до 30000\n", arr[1]);
	printf("2. %d раз вызвана функция: Простые числа в диапозоне до введённого числа\n", arr[2]);
	printf("3. %d раз вызвана функция: Нахождение числа в массиве, которое больше половины и меньше половины\n", arr[3]);
	printf("4. %d раз вызвана функция: Cчитает сумму с двух концов массива возвращает последний прибавленный элемент справа\n", arr[4]);
	printf("5. %d раз вызвана функция: Найти максимальное число в массиве и отсортировать его\n", arr[5]);
	printf("6. %d раз вызвана функция: Нахождение наименьшего элемента массива среди не отрицательных чисел\n", arr[6]);
	printf("7. %d раз вызвана функция: Нахождение количество отрицательных чисел в массиве, после которых есть положительное число\n", arr[7]);
	printf("8. %d раз вызвана функция: Находит количество положительных чисел в массиве\n", arr[8]);
	printf("9. %d раз вызвана функция: Найти факториал введённого числа\n", arr[9]);
	system("pause");


}
int f1(a) { // 1 если число простое 0 если нет
	int n = 2;
	while (a % n != 0) {
		n++;
		if (n == a) return 1;
	} return 0;
}
int f2() {
	int A[maxStrSize] = { 0 };
	int j, a, n, s, k;
	for (j = 0, a = 10; a < 30000; a++) {
		for (n = a, s = 0; n != 0; n = n / 10)
		{
			k = n % 10; s = s + k; // сумма цифр числа
		}
		if (a == s * s * s) {
			A[j++] = a; // a = s в кубе
			printf("%d = %d в кубе\n", a, s);
		}

	}
}
int f3(int v) { // Простые числа в диапозоне до v
	int A[maxStrSize] = { 0 };
	int i, n, a;
	for (i = 0, a = 2; a < v; a++) {
		for (n = 2; n < a; n++)
		{
			if (a % n == 0) break;
		}
		if (n == a) {
			A[i++] = a;
			printf("%d ", a);
		}
	}
	A[i] = 0;
}
int f4(int n, int c[]) { // есть ли в массиве число большее половины чисел и меньше половины чисел, возвращает индекс этого числа
	int i, j, k1, k2;
	for (i = 0; i < n; i++) {
		for (j = k1 = k2 = 0; j < n; j++)
			if (c[i] != c[j])
			{
				if (c[i] < c[j]) {
					k1++;
				}
				else {
					k2++;
				}
			}
		if (k1 == k2) {
			return i;
		}

	}
	return -1;
}
int f5(int n, int A[]) { // считает сумму с двух концов массива если с одной стороны число меньше то прибавляет следующее число пока сумма с этой стороны не станет больше суммы с другой стороны, затем стороны меняются теперь прибавляется число ближе к этому краю пока сумма снова не станет больше
	int s1, s2, i, j;
	for (s1 = 0, s2 = 0, i = 0, j = n - 1; i <= j;) {
		if (s1 < s2) s1 += A[i], i++;
		else s2 += A[j], j--;
	}
	return i; // возвращает последний прибавленный элемент справа
}
int f6(int n, int A[]) {
	int k, i, c, s, p, g;
	g = n;
	while (n != 0) {
		for (k = 0, i = 1; i < n; i++)
			if (A[i] < A[k]) k = i;
		c = A[k]; A[k] = A[n - 1]; A[n - 1] = c;
		n--;
	}
	printf("Максимальное число в массиве = %d\n", c);
	printf("Отсортированный массив ");
	for (p = 0; p < g; p++) {
		printf("%d ", A[p]);
	}
}
int f7(int A[]) {
	int i, k;
	for (i = 0, k = -1; i < 10; i++) {
		if (A[i] < 0) continue;
		if (k == -1) k = i;
		else
			if (A[i] < A[k]) k = i;
	}
	printf("Наименьший элемент массива равен %d\n", A[k]);
}
int f8(int A[]) {
	int i, s, k;
	for (i = 0, s = 0, k = 0; i < 10; i++) {
		if (A[i] < 0) k = 1;
		else {
			if (k == 1) s++;
			k = 0;
		}
	}
	printf("Количество отрицательных чисел в массиве равно %d\n", s);
}
int f9(int A[]) {
	int s, i;
	for (i = 0, s = 0; i < 10; i++)
		if (A[i] > 0) s++;
	printf("Находит количество положительных чисел в массиве равно %d\n", s);
}
int f10(int n) {
	int s, i;
	for (s = 1, i = 1; i <= n; i++) s = s * i;
	printf("!%d = %d\n", n, s);
}
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	int arr[10] = { 0 };
	int k;
	while (1) {
		system("cls");
		PrintList();
		k = getch();
		switch (k) {
		case 48:
		{
			arr[0]++;
			system("cls");
			int b, a;
			printf("Введите число: ");
			scanf("%d", &b);
			a = f1(b);
			if (a == 1) {
				printf("Число является простым\n");
			}
			else {
				printf("Число не является простым\n");
			}
			system("pause");
			break;
		}
		case 49:
		{
			arr[1]++;
			system("cls");
			f2();
			system("pause");
			break;
		}
		case 50:
		{
			arr[2]++;
			system("cls");
			int b, a;
			printf("Введите число: ");
			scanf("%d", &b);
			f3(b);
			printf("\n");
			system("pause");
			break;
		}
		case 51:
		{
			arr[3]++;
			system("cls");
			int temparr[maxStrSize] = { 0 };
			int b, a, i;
			printf("Введите длину массива, затем заполните массив: ");
			scanf("%d", &b);
			for (i = 0; i < b; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			a = f4(b, temparr);
			if (a == -1) {
				printf("Нет такого числа");
			}
			else {
				printf("Число %d\n", temparr[a]);
			}
			system("pause");
			break;
		}
		case 52:
		{
			arr[4]++;
			system("cls");
			printf("Введите длину массива, затем заполните массив: ");
			int temparr[maxStrSize] = { 0 };
			int n;
			scanf("%d", &n);
			int i, a;
			for (i = 0; i < n; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			a = f5(n, temparr);
			printf("Последний прибавленный элемент справа равен %d\n", temparr[a]);
			system("pause");
			break;
		}
		case 53:
		{
			arr[5]++;
			system("cls");
			int temparr[maxStrSize] = { 0 };
			int b, a, i;
			printf("Введите длину массива, затем заполните массив: ");
			scanf("%d", &b);
			for (i = 0; i < b; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			f6(b, temparr);
			system("pause");
			break;
		}
		case 54:
		{
			arr[6]++;
			system("cls");
			int temparr[10] = { 0 };
			int i, a;
			printf("Заполните массив длинною в 10 элементов: ");
			for (i = 0; i < 10; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			f7(temparr);
			system("pause");
			break;
		}
		case 55:
		{
			arr[7]++;
			system("cls");
			int temparr[10] = { 0 };
			int i, a;
			printf("Заполните массив длинною в 10 элементов: ");
			for (i = 0; i < 10; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			f8(temparr);
			system("pause");
			break;
		}
		case 56:
		{
			arr[8]++;
			system("cls");
			int temparr[10] = { 0 };
			int i, a;
			printf("Заполните массив длинною в 10 элементов: ");
			for (i = 0; i < 10; i++) {
				scanf("%d", &a);
				temparr[i] = a;
			}
			f9(temparr);
			system("pause");
			break;
		}
		case 57:
		{
			arr[9]++;
			system("cls");
			printf("Введите число факториал которого хотите посчитать: ");
			int a;
			scanf("%d", &a);
			f10(a);
			system("pause");
			break;
		}
		case 27:
		{
			return 0;
			break;
		}
		case 115:
		{
			system("cls");
			PrintStat(arr);
			break;
		}
		case 235:
		{
			system("cls");
			PrintStat(arr);
			break;
		}
		}
	}
	return 0;
}