-- https://leetcode.com/problems/rectangles-area/
with t1 as (
    select
        p1.id as id_1,
        p2.id as id_2,
        p1.x_value as x_1,
        p2.x_value as x_2,
        p1.y_value as y_1,
        p2.y_value as y_2
    from Points p1 join Points p2 on p1.x_value <> p2.x_value
                                         and p1.y_value <> p2.y_value and p1.id < p2.id
),
    t2 as (
        select
            id_1 as p1,
            id_2 as p2,
--             abs(x_1 - x_2) as xx,
--             abs(y_1 - y_2) as yy,
            abs(x_1 - x_2) * abs(y_1 - y_2) as area
        from t1
        order by area desc, p1, p2
    )
select
    *
from t2
