class FirstWorkbook:
    def first_task(self, a, b) -> int | float:
        """Введите с клавиатуры два числа и сложите их. Верните результат."""
        return a + b

    def second_task(self, x) -> int | float:
        """Найти значение функции f(x)=x^5-2x^3+1. Значение x вводится с клавиатуры."""
        return x ** 5 - 2 * x ** 3 + 1

    def third_task(self) -> type:
        """Напишите код для определения типа переменной strange, если strange = [ [],1]"""
        strange = [[], 1]
        return type(strange)

    def fourth_task(self) -> list[tuple]:
        """Найдите такие значения x и y, которые обратят (x or y) and (¬x or y) and ¬(x and y) в значение True."""
        from itertools import product
        values = []
        for x, y in product((True, False), repeat=2):
            if (x or y) and (not x or y) and not (x and y):
                values.append((x, y))
        return values

    def fifth_task(self) -> list:
        """Добавьте в пустой список четыре любых значения и выведете их на экран в обратном порядке."""
        return [__import__("random").randint(10, 100) for _ in range(4)][::-1]

    def sixth_task(self, n) -> float | None:
        """Запрограммируйте формулы Хартли. Количество состояний вводится с клавиатуры."""
        if n > 0:
            return __import__("math").log2(n)
        return

    def seventh_task(self, p1, p2) -> float | None:
        """Запрограммируйте вычисление энтропии по Шеннону для систем из двух состояний. Вероятности вводятся с клавиатуры."""
        if p1 > 0 and p2 > 0:
            return -(p1 * __import__("math").log2(p1) + p2 * __import__("math").log2(p2))
        return

    def eighth_task(self, x) -> float | None:
        """Напишите программу для вычисления tan(cos(x) * sin(2x) / (x * e^x))^log7(x)  , где x вводит пользователь с клавиатуры."""
        import math
        try:
            return math.tan((math.cos(x) * math.sin(2 * x)) / (x * math.e ** x)) ** math.log(x, 7)
        except Exception as _:
            return

    def ninth_task(self) -> str:
        """Напишите программу для добавления бита четности к байту. Байт можете записать в виде списка (list) нулей и единиц."""
        lst = "".join([str(__import__("random").randint(0, 1)) for _ in range(8)])
        lst += str(lst.count("1") % 2)
        return lst
