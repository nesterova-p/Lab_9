#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) 
{
	int n = mat -> r;
	double sum = 0.0;

	//return 2; nieprawidłowy rozmiar macierzy
	if (mat->r != mat->c || x->r != mat->r || b->c != 1 || b->r != mat->r || x->c != 1 )
	{
		/*
		mat->r != mat->c czy liczba wierszy (r) nie jest równa liczbie kolumb (c); tzn - macierz nie jest kwadratowa
		x->r != mat->r czy liczba wrs mac. X nie równa lb. wiersz. mac. Mat
		b->c != 1 czy liczba kolumn mac. b nie równa 1 
		b->r != mat->r czy liczba wier. mac. b nie równa lb. lb. wiers. mac. Mat
		x->c != 1 czy lb. kolumn mac. X nie równa 1 
		*/
		return 2;
	}

	for (int i = n - 1; i >= 0; i--) { // Итерация по строкам матрицы от последнего к первому
    double sum = 0.0;
    int j; // Объявление переменной j вне вложенного цикла

    for (j = i + 1; j < n; j++) { // Итерация по столбцам
        sum += mat->data[i][j] * x->data[j][0]; // Сумма произведений коэффициентов и значений x
    }

    if (mat->data[i][i] == 0.0) { // Проверка элемента на диагонали
        return 1;
    }

    // Вычисление решения x для текущей строки методом обратного подстановки
    x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
}

return 0;
}



