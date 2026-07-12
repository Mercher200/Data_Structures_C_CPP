Реализация основных структур данных на C++ с примерами использования.
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()
[![License](https://img.shields.io/badge/license-MIT-blue)]()

Содержание
1. Односвязный список — namespace LinList
Описание
Односвязный список с операциями вставки, удаления, реверса (итеративного, рекурсивного, через стек) и вывода (итеративного/рекурсивного).

Структура


{
    Linked_list* next;
    int data;
};

Функции

Insert(pointer_to_head, x) – вставка в голову.

Insert_Into(pointer_to_head, data, position) – вставка по позиции (1‑based).

Delete_From(pointer_to_head, position) – удаление по позиции.

Print(head) – итеративный вывод.

Print_Recursion(p) – рекурсивный вывод.

Reverse_L(pointer_to_head) – итеративный реверс (три указателя).

Reverse_R(pointer_to_head, p) – рекурсивный реверс.

Reverse_Stack_LinList(pointer_to_head) – реверс через std::stack.

Особенности
Рекурсивный реверс может вызвать переполнение стека при большой длине списка.
