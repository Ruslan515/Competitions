-- https://leetcode.com/problems/consecutive-available-seats/
with t1 as (
    select
        *,
        case
            when free = true then 1
            else -1
        end as free_int
    from Cinema
),
    t2 as (
        select
            *,
            sum(free_int) over (order by seat_id rows between 1 preceding and current row )
        from t1
    ),
    t3 as (
        select
            c1.*,
            c2.seat_id as seat_id_c2,
            c2.free as free_c2,
            c3.seat_id as seat_id_c3,
            c3.free as free_c3
        from Cinema c1 left join Cinema c2 on c1.seat_id = (c2.seat_id + 1)
        left join Cinema c3 on c1.seat_id = (c3.seat_id -1)
        order by c1.seat_id
    )

select
    t3.seat_id
from t3
where (t3.free = true and t3.free_c2 = true)  or (t3.free = true and t3.free_c3 = true)
