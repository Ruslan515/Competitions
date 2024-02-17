"""
Обе функции имею линейную сложность и
зависит только от того насколько "глубокие" словари в списке.
"""
from typing import List, Dict


# если нам важен порядок ответов.
def solve(vals: List[Dict]) -> List[Dict]:
    set_frozen = set()
    answer = []
    for val in vals:
        key = frozenset(val.items())  # key = tuple(val.items())
        if key not in set_frozen:
            set_frozen.add(key)
            answer.append(val)

    return answer


# если порядок не важен
def solve(vals: List[Dict]) -> List[Dict]:
    answer = [
        dict(element)
        for element in {
            frozenset(val.items())
            for val in vals
        }
    ]

    return answer


def main():
    vals = [
        {"key1": "value1"}, {"k1": "v1", "k2": "v2", "k3": "v3"},
        {}, {}, {"key1": "value1"}, {"key1": "value1"},
        {"key2": "value2"}
    ]
    answer = [{"key1": "value1"}, {"k1": "v1", "k2": "v2", "k3": "v3"}, {}, {"key2": "value2"}]
    assert answer == solve(vals)


if __name__ == '__main__':
    main()
