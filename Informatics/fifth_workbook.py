import random


class Warrior:
    def __init__(self, name, health=100):
        self.name = name
        self.health = health

    def attack(self, other):
        other.health -= 20
        print(f"{self.name} attacked {other.name}. {other.name} health is {other.health}")


warrior_1 = Warrior("Warrior 1")
warrior_2 = Warrior("Warrior 2")
while warrior_1.health > 0 and warrior_2.health > 0:  # пока у обоих есть здоровье
    if random.randint(0, 1) == 0:  # случайным образом выбираем, кто атакует
        warrior_1.attack(warrior_2)
    else:
        warrior_2.attack(warrior_1)

    if warrior_1.health <= 0:  # если у 1-го кончилось здоровье - 2-ой победил
        print("Warrior 2 won!")

    if warrior_2.health <= 0:  # если у 2-го - 1-ый
        print("Warrior 1 won!")
