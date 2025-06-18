class ContohBilRandom:
    def __init__(self, seed=None) -> None:
        self.m = 2 ** 31
        self.a = 1103515245
        self.c = 12345
        
        if seed is None:
            import time
            self.seed = int(time.time()) % (self.m - 1)
        else:
            self.seed = int(seed) % (self.m - 1)

    def next_int(self):
        self.seed = (self.a * self.seed + self.c) % self.m
        return self.seed

    def random(self):
        return self.next_int() / self.m

    def randint(self, low, high):
        return low + int(self.random() * (high - low + 1))

if __name__ == "__main__":
    contoh = ContohBilRandom(seed=30)

    print(f"nilai floatnya {contoh.random()}")
    print(f"nilai integernya adalah {contoh.randint(1, 100)}")
