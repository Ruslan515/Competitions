# https://leetcode.com/problems/big-countries/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata
import pandas as pd

BIG_AREA = 3000000
BIG_POPULATION = 25000000


def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    mask = (
            (world.area >= BIG_AREA) |
            (world.population >= BIG_POPULATION)
    )
    return world.loc[mask, ["name", "population", "area"]]


if __name__ == "__main__":
    world = pd.DataFrame(
        {
            "name": ["Afghanistan", "Albania", "Algeria", "Andorra", "Angola"],
            "continent": ["Asia", "Europe", "Africa", "Europe", "Africa"],
            "area": [652230, 28748, 2381741, 468, 1246700],
            "population": [25500100, 2831741, 37100000, 78115, 20609294],
            "gdp": [20343000000, 12960000000, 188681000000, 3712000000, 100990000000]
        }
    )

    answer = pd.DataFrame(
        {
            "name": ["Afghanistan", "Algeria"],
            "population": [25500100, 37100000],
            "area": [652230, 2381741],
        }
    )

    assert answer.equals(big_countries(world)), "Not EQ"
