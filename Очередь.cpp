// 3 лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct TList2 {
	int info;
	TList2 *prev, *next;
} ;

void Create(TList2 *&begin, TList2 *&end) {
	TList2* t = new TList2;
	cin >> t->info;
	t->prev = t->next = NULL;
	begin = end = t;

}
void AddtoHead(TList2 *& begin) {
	TList2* t = new TList2;
	cin >> t->info;
	t->prev = NULL;
	t->next = begin;
	begin->prev = t;
	begin = t;
	cout << t->info << " " << endl;

}

void AddtoEnd(TList2 *&end) {
	TList2* t = new TList2;
	cin >> t->info;
	t->prev = end;
	t->next = NULL;

	end->next = t;
	end = t;
	cout << t->info << " " << endl;

}

void ShowHead(TList2* begin) {
	TList2* t = new TList2;
	t = begin;

	if (!begin) {
		cout << "Queue is empty\n" << endl;
		return;
	}
	while (t != NULL) {
		cout << t->info << " " << endl;
		t = t->next;
	}
}

void ShowEnd(TList2* end) {
	TList2* t = new TList2;
	t = end;
	if (!end) {
		cout << "Queue is empty\n" << endl;
		return;
	}

	while (t != NULL) {
		cout << t->info << " " << endl;
		t = t->prev;
	}
}

void Task(TList2*& begin, TList2*& end) {
	TList2* t = new TList2;
	t = begin->next;
	TList2* del;
	while (t->next) {
		if (t->info % 2 != 0) {
			del = t;

			t->prev->next = t->next;
			t->next->prev = t->prev;

			t = del->next;
			delete del;
		}
		else t = t->next;

		if (begin->info % 2 != 0) {
			del = begin;
			begin = begin->next;
			begin->prev = NULL;
			delete del;
		}

		if (end->info % 2 != 0) {
			if (begin == end) {
				cout << "Queue is empty" << endl;
				delete end;
				begin = end = NULL;
			}
			else {
				del = end;
				end = end->prev;
				delete del;
			}
		}
	}
}

void DeleteAll(TList2 **begin,TList2 **end) {
	TList2* metka;
	while (*begin != NULL) {
		metka = *begin;
		*begin = (*begin)->next;
		delete metka;
	}*begin = *end = NULL;
}

int main()
{
	int in, out, n, kol;
	TList2* begin = NULL, * end = NULL;
	while (true) {
		cout << "\n\tCreate-1.\n\tAdd to Head-2.\n\tAdd to End-3\n\tView from begin-4.\n\tView from end-5.\n\tIndividual task-6.\n\tDelete all-7.\n\tExit-8. " << endl;;
		cin >> n;

		switch (n)
		{
		case 1:

			Create(begin,end);
			break;
		case 2:
			cout << "Enter kolichestvo=";
			cin >> kol;
			for (int i = 1; i <= kol; i++) {
				 AddtoHead(begin);

			}
			break;
		case 3:

			cout << "Enter kolichestvo=";
			cin >> kol;
			for (int i = 1; i <= kol; i++) {
				AddtoEnd(end);

			}
			break;
		case 4:

			ShowHead(begin);
			break;
		case 5:

			ShowEnd(end);
			break;
		case 6:

			Task(begin, end);
			ShowHead(begin);
			break;
		case 7:
			DeleteAll(&begin, &end);
		case 8:
			return 0;
		}




	}
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
