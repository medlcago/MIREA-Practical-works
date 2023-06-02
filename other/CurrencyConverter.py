import requests


class CurrencyConverter:
    supported_currencies = ['USD', 'EUR', 'GBP', 'JPY', 'RUB']  # Поддерживаемые валюты

    def __init__(self, amount, from_currency, to_currency):
        self.amount = amount

        self.check_from_currency(from_currency)  # Проверяем, чтобы валюта была поддерживаемой
        self.from_currency = from_currency

        self.check_to_currency(to_currency)  # Проверяем, чтобы валюта была поддерживаемой
        self.to_currency = to_currency

        self.__url = 'https://api.exchangerate-api.com/v4/latest/' + from_currency

    def check_from_currency(self, from_currency):
        if from_currency not in self.supported_currencies:
            raise ValueError(f'Неподдерживаемая базовая валюта {from_currency}')

    def check_to_currency(self, to_currency):
        if to_currency not in self.supported_currencies:
            raise ValueError(f'Неподдерживаемая целевая валюта {to_currency}')

    def convert_currency(self):
        try:
            response = requests.get(self.__url)
            data = response.json()
            if 'error' in data:
                raise Exception(f'Error: {data["error"]}')
            rates = data['rates']
            converted_amount = self.amount * rates[self.to_currency]
            return converted_amount  # Возвращаем результат конвертации
        except requests.exceptions.RequestException as error:
            raise Exception(error)

    def __str__(self):
        result = self.convert_currency()
        if not result:
            raise Exception(f'Ошибка конвертации из {self.from_currency} в {self.to_currency}')
        return f'{self.amount} {self.from_currency} равно {result:.2f} {self.to_currency}'


if __name__ == '__main__':
    try:
        amount = float(input('Введите сумму: '))  # Вводим сумму
    except ValueError:
        print('Ошибка: неверная сумма')
    else:
        from_currency = input(
            f'Введите базовую валюту (выберите из {CurrencyConverter.supported_currencies}): ').upper()  # Вводим валюту, из которой нужно перевести
        to_currency = input(
            f'Введите целевую валюту (выберите из {CurrencyConverter.supported_currencies}): ').upper()  # Вводим валюту, в которую нужно перевести
        converter = CurrencyConverter(amount, from_currency, to_currency)
        print(converter)
