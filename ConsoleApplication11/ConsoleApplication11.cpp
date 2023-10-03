#include <iostream>
#include <string.h>
using namespace std;

class QueuePriority
{
	// Очередь
	string* Wait;
	// Приоритет
	int* Pri;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueuePriority(int m);

	//Деструктор
	~QueuePriority();

	// Добавление элемента
	void Add(string c, int p);

	// Извлечение элемента
	string Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
	void PrintOrder();
};

void QueuePriority::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new string[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}
void QueuePriority::PrintOrder()
{
	cout << "Print Order" << endl;
	QueuePriority temp(QueueLength);
	temp.QueueLength = QueueLength;
	for (size_t i = 0; i < QueueLength; i++)
	{
		temp.Wait[i] = Wait[i];
		temp.Pri[i] = Pri[i];
	}
	for (int i = 0; i < QueueLength; i++)
	{
		for (int j = QueueLength - 1; j > i; j--)
		{
			if (temp.Pri[j - 1] < temp.Pri[j])
			{
				swap(temp.Pri[j - 1], temp.Pri[j]);
				swap(temp.Wait[j - 1], temp.Wait[j]);
			}
		}
	}
	temp.Show();
}
void QueuePriority::Add(string c, int p)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

string QueuePriority::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {


		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		string temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		return temp1;

	}
	else return " ";
}

void main()
{
	srand(time(0));

	//создание очереди
	QueuePriority QUP(5);
	QUP.Add("User", 5);
	QUP.Add("User", 7);
	QUP.Add("User", 8);
	QUP.Add("User", 10);
	QUP.Add("User", 1);
	QUP.Show();
	QUP.PrintOrder();
}

