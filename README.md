# Set_Of_Integers
Множество - это одно из самых базовых понятий в математике.
Множество представляет собой набор каких-либо объектов, которые называются элементами множества. Как правило, каждый элемент в множестве встречается только один раз, и эти элементы не упорядочены.
Часто множество определяется просто перечислением его элементов.
Множество целых чисел A может быть задано, например, так:

                    A = {3,8,46,5,11}

А другое множество целых чисел B может быть задано, например, так:

                    B = {18,8,90,11,2}

Множество - это набор элементов, коллекция. Другими представителями коллекций в C++ являются массивы, векторы, стеки.
У множества, как и у других видов коллекций, есть свой набор операций.

К таким операциям относятся:
* добавление и удаление элементов в множество

                    {3,8,46,5,11}+4={3,8,46,5,11,4}

                    {3,8,46,5,11}+3={3,8,46,5,11} - (элементы множества не повторяются!);

* сравнение множеств (множества равны, если они содержат одинаковый набор элементов);
* специальные операции с множествами:
    > объединение множеств (математическое обозначение: A ∪ B)

                    {3,8,46,5,11} ∪ {18,8,90,11,2} = {3,8,46,5,11,18,90,2} - (все элементы A + все элементы B)

    > пересечение множеств (математическое обозначение: A ∩ B)

                    {3,8,46,5,11} ∩ {18,8,90,11,2} = {8,11} - (элементы, которые содержатся и в A, и в B)

    > разность множеств (математическое обозначние A \ B)

                    {3,8,46,5,11} \ {18,8,90,11,2} = {3,46,5} - (элементы, которые содержатся в A, но не содержатся в B);+

В создаваемом классе "Множество целых чисел":
* элементы множества хранить в динамическом массиве;
* каждый элементы множества уникален (элементы не повторяются);
* элементы не упорядочены.

Реализовать методы:
* конструкторы (по умолчанию, с параметрами, копирования);
* деструктор;
* проверка принадлежности элемента множеству;

Реализовать операции:
* добавление элемента в множество (+,+=);
* объединение двух множеств (+,+=);
* удаление элемента (-,-=);
* разность множеств (-,-=);
* пересечение множеств (x,x=);
* присваивание (=);
* сравнение множеств (==);
* потоковый вывод и ввод (<<,>>).
