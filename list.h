#ifndef __LIST__
#define __LIST__

typedef struct {
	void	*data;
	void	*next;
} TListItem;

typedef void *TFunc(void*);

//создаЄт список
TListItem *list_create();

//создаЄт в пам€ти новый элемент и добавл€ет в конец списка
TListItem *list_append(TListItem *head, void *data);

//создаЄт в пам€ти новый элемент и вставл€ет его после заданного
TListItem *list_insert(TListItem *item, void *data);

//последовательно обходит список, примен€€ к каждому элементу функцию f
void list_traverse(TListItem *head, TFunc f);

//удал€ет из пам€ти список
void list_free(TListItem **head);

//ищет в списке элемент со значением needle, возвращает указатель на первый найденный, либо NULL
TListItem *list_search(TListItem *head, int needle);

//удал€ет из списка элемент item
void *list_delete(TListItem *head, TListItem *item);

#endif // !__LIST__

