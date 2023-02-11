class SecondWorkbook:
    def first_task(self, a) -> bool:
        """Дано двузначное число. Определить входит ли в него цифра 3."""
        return str(a).count("3") > 0

    def second_task(self, n) -> int:
        """Дано двузначное число. Определить какая из его цифр больше."""
        max_n = 0
        while n > 0:
            max_n = max(max_n, n % 10)
            n //= 10
        return max_n

    def third_task(self, a, b, c) -> str:
        """Найти корни квадратного уравнения и вывести их на экран, если они есть.
        Если корней нет, то вывести сообщение об этом.
        Конкретное квадратное уравнение определяется коэффициентами a, b, c, которые вводит пользователь."""
        d = b ** 2 - 4 * a * c
        if d < 0:
            return "Корней нет"
        else:
            x1 = (-b + d ** 0.5) / (2 * a)
            x2 = (-b - d ** 0.5) / (2 * a)
            return f"x1 = {x1}\nx2 = {x2}" if x1 != x2 else f"x1 = {x1}"

    def fourth_task(self, n) -> int:
        """Дано целое число, не меньшее 2. Выведите его наименьший натуральный делитель, отличный от 1."""
        i = 2
        while n % i != 0:
            i += 1
        return i

    def fifth_task(self, n) -> int | float:
        """Посчитать сумму числового ряда от 1 до N включительно (т.е. 0+1+2+3+…+ N). (N< 1000)."""
        return (1 + n) * n / 2

    def sixth_task(self, n) -> bool:
        """На вход программе подается число. Необходимо проверить является ли оно простым."""
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    def seventh_task(self, a, n) -> str:
        """Вводится десятичное число A (A< 231) и число n (2 ≤ n ≤ 9).
        Необходимо перевести введенное число A в систему счисления c основанием n."""
        s = ""
        while a > 0:
            s = str(a % n) + s
            a //= n
        return s
