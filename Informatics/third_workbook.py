class ThirdWorkbook:
    def first_task(self, x, y) -> float:
        """Для введенных чисел x и y найти значение функции f(x, y) = ln|sin(x+y)|"""
        import math
        return math.log(math.fabs(math.sin(x + y)), math.e)

    def second_task(self, a, b, hx) -> list[float]:
        """Вычислить значение функции f(x) = cos^3(e*x) + sin|x| на отрезке [a, b] с шагом hx"""
        import math
        import numpy as np
        x_range = np.arange(a, b + 1, hx)
        values = []
        for x in x_range:
            values.append(math.cos(math.e * x) ** (1. / 3.) + math.sin(math.fabs(x)))
        return values
