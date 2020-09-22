#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#define PI 3.1415926535897932


typedef struct
{
	int  value;
	struct list* next;
}list;

list* getLast(list* l_head)
{

	while (l_head->next)
	{
		l_head = l_head->next;
	}
	return l_head;
}

void add_random_value(list* l_head)
{
	
	list* l = getLast(l_head);
	l->next = (list*)malloc(sizeof(list));
	l = l->next;
	l->next = NULL;
	l->value = rand()%100;


}

void add_before_value(list* l_head)
{
	srand(time(NULL));
	list* l = l_head;
	int  val;
	printf_s("число перед которым добавть число :\n");
	scanf_s("%d", &val);
	int n = 0, k = 0;

	while (l->next)
	{
		k++;
		l = l->next;
		if (l->value <= val)
		{
			n++;
			break;
		}
	}
	if (n == 0)
	{
		printf_s("нет значение перед которым можно добавить");
		exit(0);
		
	}
	n = 0;
	l = l_head;
	while (n < k - 1 && l->next)
	{
		l = l->next;
		n++;
	}
	list* tmp, * p;
	tmp = (list*)malloc(sizeof(list));
	p = l->next;
	l->next = tmp;
	tmp->value =rand() % 100;
	tmp->next = p;
}

list* create_list(int n)
{

	/*srand(time(NULL));*/
	list* l_head = NULL;
	list* l = NULL;
	l_head = (list*)malloc(sizeof(list));
	l = l_head;
	l->next = NULL;
	scanf_s("%d", &l->value);
	for (int i = 1; i < n; i++)
	{
		l->next = (list*)malloc(sizeof(list));
		l = l->next;
		l->next = NULL;
		scanf_s("%d", &l->value);
	}
	return l_head;
}

void outputList(list* l_head)
{
	list* l = l_head;
	while (l != NULL)
	{
		printf("|%d| ", l->value);
		l = l->next;

	}
	printf_s("\n");
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "Rus");
	//заданеи 1
	int a;
	srand(time(NULL));
	scanf_s("%d", &a);
	list* l1 = create_list(a);
	printf_s("начальный список:\n");
	outputList(l1);
	add_random_value(l1);
	add_before_value(l1);
	printf_s("список после изменений :\n");
	outputList(l1);
	

	//задание 2
	/*int StoronaOgoroda=0, r=0;
	StoronaOgoroda= atoi(argv[1]);
	r= atoi(argv[2]);
	printf("%d\t", StoronaOgoroda);
	printf("%d\n", r);

	double Square = PI * r * r;

	if (r <= StoronaOgoroda / 2)
	{
		printf("%.3f\n", Square);
	}
	else if (r <= StoronaOgoroda * sqrt(2.0) / 2)
	{
		double O = 2 * acos(StoronaOgoroda / (2.0 * r));
		double Square1 = 2 * r * r * (O - sin(O));

		printf("%.3f\n", Square - Square1);
	}
	else
	{
		double Square2 = StoronaOgoroda * StoronaOgoroda;
		printf("%.3f\n", Square2);
	}*/




	return(0);

}