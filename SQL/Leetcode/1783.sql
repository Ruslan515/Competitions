-- https://leetcode.com/problems/grand-slam-titles/
with t1 as (
    select
        Wimbledon as id,
        count(*) as cnt
    from Championships
    group by Wimbledon
),
    t2 as (
        select
            Fr_open as id,
            count(*) as cnt
        from Championships
        group by Fr_open
    ),
    t3 as (
        select
            US_open as id,
            count(*) as cnt
        from Championships
        group by US_open
    ),
    t4 as (
        select
            Au_open as id,
            count(*) as cnt
        from Championships
        group by Au_open
    ),
    t5 as (
        select
            *
        from t1
        union all
        select
            *
        from t2
        union all
        select
            *
        from t3
        union all
        select
            *
        from t4
    ),
    t6 as (
        select
            id,
            sum(cnt) as grand_slams_count
        from t5
        group by id
    )

select
    p.*,
    t6.grand_slams_count
from Players p  join t6 on t6.id = p.player_id
