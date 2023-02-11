class FourthWorkbook:
    def first_task(self, k, n) -> int:
        """Даны два различных числа k и n. Выведите значение 2^k + 2^n, используя только битовые операции."""
        return (1 << k) + (1 << n)

    def second_task(self, n) -> str | None:
        """Если число n является точной степенью двойки, вывести “YES”, в противном случае “NO”. n > 0"""
        if n <= 0:
            return
        return "NO" if n & (n - 1) else "YES"

    def third_task(self, a, k) -> int:
        """Даны целые числа a и k. Выведите число, которое получается из а установкой значения k-го бита в 1."""
        return a | (1 << k)

    def fourth_task(self, n, k) -> int:
        """Дано целые числа n и k. Обнулите в числе n его последние k бит."""
        return (n >> k) << k
