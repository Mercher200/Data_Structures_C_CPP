# Реализация основных структур данных на C++ с примерами использования.

## Содержание
1. Односвязный список — namespace LinList
Описание
Односвязный список с операциями вставки, удаления, реверса и вывода.

Структура

cpp
struct Linked_list {
    Linked_list* next;
    int data;
};
Функции

Insert(pointer_to_head, x) – вставка в голову.

Insert_Into(pointer_to_head, data, position) – вставка по позиции (1‑based).

Delete_From(pointer_to_head, position) – удаление по позиции.

Print(head) – итеративный вывод.

Print_Recursion(p) – рекурсивный вывод.

Reverse_L(pointer_to_head) – реверс итеративный (три указателя).

Reverse_R(pointer_to_head, p) – реверс рекурсивный.

Reverse_Stack_LinList(pointer_to_head) – реверс через std::stack.

Особенности

Рекурсивный реверс может вызвать переполнение стека при большой длине.

Реализация через стек использует стандартную библиотеку.
