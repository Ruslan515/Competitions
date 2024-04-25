import time


class Timer:
    def __enter__(self):
        self.start_time = time.time()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        elapsed_time = time.time() - self.start_time
        print(f"Elapsed time: {elapsed_time} seconds")


# Пример использования контекстного менеджера
with Timer() as timer:
    # Ваш блок кода
    time.sleep(2)
